

/** \file ha_canfd.c
 * HA_CANFD
 * the mateq84 board sends the collected solar energy data via canbus
 * to the PU2CANFD USB adapter on the Linux HA server. This program
 * posts JSON formatted data the the Home Assistant MQTT server
 *
 * Logging only version for EM540 data from the mateQ84 controller module
 * presets have been defaulted for proper CANFD operation using the
 * PU2CANFD USB adapter with 64 byte payloads
 *
 * MQTT and JSON code and examples
 * https://www.geeksforgeeks.org/cjson-json-file-write-read-modify-in-c/
 * Daemon example code:
 * https://github.com/pasce/daemon-skeleton-linux-c
 */

#define _DEFAULT_SOURCE
#include "ha_canfd/ha_canfd.h"
#include "MQTTClient.h"

static int running = 1;
static int verbose = 2;
static int sockfd;
static int test_loops;
static int exit_sig;
static int inflight_count = CAN_MSG_COUNT;
static canid_t can_id_ping = CAN_MSG_ID_PING;
static canid_t can_id_pingx = CAN_MSG_ID_PING_X;
static canid_t can_id_pong = CAN_MSG_ID_PONG;
static int has_pong_id = 0;
static int is_can_fd = 1;
static int bit_rate_switch = 1;
static int print_hex = 0;
static int msg_len = CAN_MSG_LEN;
static int is_extended_frame_format = 1;
uint8_t full_buffer[CAN_FULL_BUFFER], data_buffer[CAN_FULL_BUFFER];
int32_t sec_30;
char *token;
cJSON *json;
FILE* fout;

volatile MQTTClient_deliveryToken deliveredtoken, receivedtoken = false;
volatile bool runner = false;

MQTTClient client;
MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
MQTTClient_message pubmsg = MQTTClient_message_initializer;
MQTTClient_deliveryToken mtoken;

long long current_timestamp(void);
time_t start_time = 0, hour_time = 0, day_time = 0;

double benergy, acenergy, load, solar, bvolts, bamps, pvolts, pamps, pwatts, runtime, bat_energy_scaled, bat_energy_kw, acvolts, achz, acpf;
double gridin = 0.001, gridout = 0.001, gasenergy = 0.001, watergal = 0.1;
int32_t ccmode = 0, sequence;

static const char *const FW_Date = __DATE__;
static const char *const FW_Time = __TIME__;

void timer_callback(int32_t);
void delivered(void *, MQTTClient_deliveryToken);
int32_t msgarrvd(void *, char *, int, MQTTClient_message *);
void connlost(void *, char *);
static void signal_handler(int);
char * log_time(bool);
void showIP(void);

void showIP(void)
{
	struct ifaddrs *ifaddr, *ifa;
	int s;
	char host[NI_MAXHOST];

	if (getifaddrs(&ifaddr) == -1) {
		perror("getifaddrs");
		exit(EXIT_FAILURE);
	}


	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
		if (ifa->ifa_addr == NULL)
			continue;

		s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

		if (/*(strcmp(ifa->ifa_name,"wlan0")==0)&&( */ ifa->ifa_addr->sa_family == AF_INET) // )
		{
			if (s != 0) {
				//                printf("getnameinfo() failed: %s\n", gai_strerror(s));
				exit(EXIT_FAILURE);
			}
			printf("\tInterface : <%s>\n", ifa->ifa_name);
			printf("\t  Address : <%s>\n", host);
		}
	}

	freeifaddrs(ifaddr);
}

static void skeleton_daemon()
{
	pid_t pid;

	/* Fork off the parent process */
	pid = fork();

	/* An error occurred */
	if (pid < 0)
		exit(EXIT_FAILURE);

	/* Success: Let the parent terminate */
	if (pid > 0)
		exit(EXIT_SUCCESS);

	/* On success: The child process becomes session leader */
	if (setsid() < 0)
		exit(EXIT_FAILURE);

	/* Catch, ignore and handle signals */
	/*TODO: Implement a working signal handler */
	signal(SIGTERM, signal_handler);
	signal(SIGHUP, signal_handler);
	signal(SIGINT, signal_handler);

	/* Fork off for the second time*/
	pid = fork();

	/* An error occurred */
	if (pid < 0)
		exit(EXIT_FAILURE);

	/* Success: Let the parent terminate */
	if (pid > 0)
		exit(EXIT_SUCCESS);

	/* Set new file permissions */
	umask(0);

	/* Change the working directory to the root directory */
	/* or another appropriated directory */
	chdir("/");

	/* Close all open file descriptors */
	int x;
	for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--) {
		close(x);
	}

}

static void print_usage(char *prg)
{
	fprintf(fout,
		"%s - Full-duplex test program (DUT and host part).\n"
		"Usage: %s [options] <can-interface>\n"
		"\n"
		"Options:\n"
		"         -b       (enable CAN FD Bit Rate Switch)\n"
		"         -d       (use CAN FD frames instead of classic CAN)\n"
		"         -e       (use 29-bit extended frame format instead of classic 11-bit one)\n"
		"         -f COUNT (number of frames in flight, default: %d)\n"
		"         -g       (generate messages)\n"
		"         -i ID    (CAN ID to use for frames to DUT (ping), default %x)\n"
		"         -l COUNT (test loop count)\n"
		"         -o ID    (CAN ID to use for frames to host (pong), default %x)\n"
		"         -s SIZE  (frame payload size in bytes)\n"
		"         -v       (low verbosity)\n"
		"         -vv      (high verbosity)\n"
		"         -x       (ignore other frames on bus)\n"
		"\n"
		"With the option '-g' CAN messages are generated and checked\n"
		"on <can-interface>, otherwise all messages received on the\n"
		"<can-interface> are sent back incrementing the CAN id and\n"
		"all data bytes. The program can be aborted with ^C.\n"
		"\n"
		"Examples:\n"
		"\ton DUT:\n"
		"%s -v can0\n"
		"\ton Host:\n"
		"%s -g -v can2\n",
		prg, prg, CAN_MSG_COUNT, CAN_MSG_ID_PING, CAN_MSG_ID_PONG, prg, prg);

	exit(1);
}

/*
 * read the canbus data, format to json and post to the MQTT topic
 */
static void print_frame(canid_t id, const uint8_t *data, int dlc, int inc_data)
{
	int32_t i;

	if (print_hex) {
		printf("%04x: ", id);
	}
	if (id & CAN_RTR_FLAG) {
		fprintf(fout, "remote request");
	} else {
		if (print_hex) {
			fprintf(fout, "[%d]", dlc);
		}
		for (i = 0; i < dlc; i++) {
			if (print_hex) {
				fprintf(fout, " %02x", (uint32_t) (data[i] + inc_data));
			}
			if (id == EMON_ER || id == EMON_CO || id == EMON_DA) {
				full_buffer[i] = (uint8_t) (data[i] + inc_data);
			}
			if (id == EMON_SL) {
				data_buffer[i] = (uint8_t) (data[i] + inc_data);
			}
			if (id == EMON_SU) {
				data_buffer[i + CAN_MSG_LEN] = (uint8_t) (data[i] + inc_data);
			}
			if (id == EMON_SH) {
				data_buffer[i + CAN_MSG_LEN + CAN_MSG_LEN] = (uint8_t) (data[i] + inc_data);
			}
		}

		if (id == EMON_SU) {
			hour_time = time(NULL); // update the current time in seconds
			if (hour_time >= (start_time + HR_SEC)) { // check for a hour of seconds
				start_time = time(NULL);
				gridin += E_PER_HOUR; // update the tracked energy values
				gasenergy += G_PER_HOUR;
				day_time += HR_SEC; // add a hour of seconds to the day variable
				if (day_time >= DAY_SEC) { // check for a day of seconds
					day_time = 0;
#ifdef PGE_ZERO
					gridin = 0.0f;
#else
					gridin = 0.001f;
#endif
					gasenergy = 0.001f;
				}
			}
#ifdef PGE_ZERO
			gridout = 0.0f;
#endif
			fprintf(fout, "%s log %s", log_time(false), data_buffer);
			token = strtok(data_buffer, ",");
			if (token != NULL) {
				/*
				 * parse the string for variable values
				 */
				token = strtok(NULL, ",");
				bamps = atof(token);
				token = strtok(NULL, ",");
				bvolts = atof(token);
				token = strtok(NULL, ",");
				pamps = atof(token);
				token = strtok(NULL, ",");
				pvolts = atof(token);
				token = strtok(NULL, ",");
				pwatts = atof(token);
				token = strtok(NULL, ",");
				/*
				 * convert this token into a double variable for the JSON data
				 */
				solar = atof(token);
				fprintf(fout, "%s %s %s log variable: %s ", log_time(false), TOPIC_P, ADDRESS, token);
				token = strtok(NULL, ",");
				acenergy = atof(token);
				fprintf(fout, " %s ", token);
				token = strtok(NULL, ",");
				runtime = atof(token);
				fprintf(fout, " %s ", token);
				token = strtok(NULL, ",");
				benergy = atof(token);

				fprintf(fout, " %s ", token);
				token = strtok(NULL, ",");
				ccmode = atoi(token);
				fprintf(fout, " %s\r\n", token);
				token = strtok(NULL, ",");
				load = atof(token);
				token = strtok(NULL, ",");
				token = strtok(NULL, ",");
				token = strtok(NULL, ",");
				acvolts = atof(token);
				token = strtok(NULL, ",");
				bat_energy_scaled = atof(token);
				bat_energy_kw = bat_energy_scaled * 10.0;
				token = strtok(NULL, ",");
				token = strtok(NULL, ",");
				acpf = atof(token);
				token = strtok(NULL, ",");
				achz = atof(token);

				sequence++;
				json = cJSON_CreateObject();
				cJSON_AddStringToObject(json, "name", "mateq84");
				cJSON_AddNumberToObject(json, "sequence", sequence);
				cJSON_AddNumberToObject(json, "benergy", benergy);
				cJSON_AddNumberToObject(json, "acenergy", acenergy);
				cJSON_AddNumberToObject(json, "load", load);
				cJSON_AddNumberToObject(json, "runtime", runtime);
				cJSON_AddNumberToObject(json, "solar", solar);
				cJSON_AddNumberToObject(json, "acvolts", acvolts);
				cJSON_AddNumberToObject(json, "achz", achz);
				cJSON_AddNumberToObject(json, "acpf", acpf);
				cJSON_AddNumberToObject(json, "batenergykw", bat_energy_kw);
				cJSON_AddNumberToObject(json, "batenergyscaled", bat_energy_scaled);
				cJSON_AddNumberToObject(json, "bamps", bamps);
				cJSON_AddNumberToObject(json, "bvolts", bvolts);
				cJSON_AddNumberToObject(json, "pamps", pamps);
				cJSON_AddNumberToObject(json, "pvolts", pvolts);
				cJSON_AddNumberToObject(json, "pwatts", pwatts);
				cJSON_AddNumberToObject(json, "pccmode", ccmode);
				// fake data for HA
				cJSON_AddNumberToObject(json, "gridin", gridin);
				cJSON_AddNumberToObject(json, "gridout", gridout);
				cJSON_AddNumberToObject(json, "gasenergy", gasenergy);
				cJSON_AddNumberToObject(json, "watergal", watergal);
				cJSON_AddStringToObject(json, "system", "FM80 solar monitor");
				cJSON_AddStringToObject(json, "build_date", FW_Date);
				cJSON_AddStringToObject(json, "build_time", FW_Time);
				// convert the cJSON object to a JSON string
				char *json_str = cJSON_Print(json);

				pubmsg.payload = json_str;
				pubmsg.payloadlen = strlen(json_str);
				pubmsg.qos = QOS;
				pubmsg.retained = 0;
				deliveredtoken = 0;
				MQTTClient_publishMessage(client, TOPIC_P, &pubmsg, &mtoken);
				// a busy, wait loop for the async delivery thread to complete
				{
					uint32_t waiting = 0;
					while (deliveredtoken != mtoken) {
						usleep(100);
						if (waiting++ > MQTT_TIMEOUT) {
							fprintf(fout, "\r\nStill Waiting, timeout");
							break;
						}
					};
				}

				cJSON_free(json_str);
				cJSON_Delete(json);
			}
		}
		fflush(fout);
		if (id == EMON_ER) {
			fprintf(fout, "%s %s", log_time(false), full_buffer);
		}
		if (id == EMON_DA) {
			fprintf(fout, "%s BLOB \r", log_time(false));
		}
		if (id == EMON_CO) {
			token = strtok(full_buffer, ",");
			if (token != NULL) {
				fprintf(fout, "%s %s ", log_time(false), token);
				token = strtok(NULL, ",");
				fprintf(fout, " relay outputs: %s Software Version: %s %s %s\r\n", token, LOG_VERSION, FW_Date, FW_Time);
			}
		}

	}
	if (print_hex) {
		fprintf(fout, "\n");
	}
	fflush(fout);
}

static void print_compare(
	canid_t exp_id,
	const uint8_t *exp_data,
	uint8_t exp_dlc,
	canid_t rec_id,
	const uint8_t *rec_data,
	uint8_t rec_dlc,
	int inc)
{
	fprintf(fout, "expected: ");
	print_frame(exp_id, exp_data, exp_dlc, inc);
	fprintf(fout, "received: ");
	print_frame(rec_id, rec_data, rec_dlc, 0);
}

static int compare_frame(const struct canfd_frame *exp, const struct canfd_frame *rec, int inc)
{
	int err = 0;
	const canid_t expected_can_id = inc ? can_id_pong : can_id_ping;

	if (0 && rec->can_id != expected_can_id) {
		fprintf(fout, "Message ID mismatch!\n");
		print_compare(expected_can_id, exp->data, exp->len,
			rec->can_id, rec->data, rec->len, inc);
		running = 0;
		err = -1;
	} else if (rec->len != exp->len) {
		fprintf(fout, "Message length mismatch!\n");
		print_compare(expected_can_id, exp->data, exp->len,
			rec->can_id, rec->data, rec->len, inc);
		running = 0;
		err = -1;
	} else {
	}
	return err;
}

static void millisleep(int msecs)
{
	struct timespec rqtp, rmtp;
	int err;

	/* sleep in ms */
	rqtp.tv_sec = msecs / 1000;
	rqtp.tv_nsec = msecs % 1000 * 1000000;

	do {
		err = clock_nanosleep(CLOCK_MONOTONIC, 0, &rqtp, &rmtp);
		if (err != 0 && err != EINTR) {
			fprintf(fout, "t\n");
			break;
		}
		rqtp = rmtp;
	} while (err != 0);
}

static void echo_progress(unsigned char data)
{
	if (data == 0xff) {
		syslog(LOG_NOTICE, ".");
	}
}

static void signal_handler(int signo)
{
	close(sockfd);
	running = 0;
	exit_sig = signo;
}

static int recv_frame(struct canfd_frame *frame)
{
	ssize_t ret, len;

	if (is_can_fd) {
		len = sizeof(struct canfd_frame);
	} else {
		len = sizeof(struct can_frame);
	}

	ret = recv(sockfd, frame, len, 0);
	if (ret != len) {
		if (ret < 0) {
			syslog(LOG_ERR, "perror recv failed %s", strerror(errno));
		} else {
			fprintf(fout, "recv returned %zd", ret);
			fflush(fout);
		}
		return -1;
	}
	return 0;
}

static int send_frame(struct canfd_frame *frame)
{
	ssize_t ret, len;

	if (is_can_fd) {
		len = sizeof(struct canfd_frame);
	} else {
		len = sizeof(struct can_frame);
	}

	if (bit_rate_switch) {
		frame->flags |= CANFD_BRS;
	}

	while ((ret = send(sockfd, frame, len, 0)) != len) {
		if (ret >= 0) {
			fprintf(fout, "send returned %zd", ret);
			fflush(fout);
			return -1;
		}
		if (errno != ENOBUFS) {
			syslog(LOG_ERR, "perror send failed %s", strerror(errno));
			return -1;
		}
		if (verbose) {
			syslog(LOG_NOTICE, "N");
		}
	}
	return 0;
}

static int check_frame(const struct canfd_frame *frame)
{
	int err = 0;

	if (frame->can_id != can_id_ping && frame->can_id != can_id_pingx && frame->can_id != EMON_ER && frame->can_id != EMON_CO) {
		fprintf(fout, "Unexpected Message ID 0x%04x!\n", frame->can_id);
		err = -1;
	}

	if (frame->len != msg_len) {
		fprintf(fout, "Unexpected Message length %d!\n", frame->len);
		err = -1;
	}

	return err;
}

static void inc_frame(struct canfd_frame *frame)
{
	int i;

	if (has_pong_id) {
		frame->can_id = can_id_pong;
	} else {
		frame->can_id++;
	}

	for (i = 0; i < frame->len; i++) {
		frame->data[i]++;
	}
}

static int can_echo_dut(void)
{
	unsigned int frame_count = 0;
	struct canfd_frame frame;
	int err = 0;

	while (running) {
		if (recv_frame(&frame)) {
			return -1;
		}
		frame_count++;
		if (verbose == 1) {
			echo_progress(frame.data[0]);
		} else if (verbose > 1) {
			print_frame(frame.can_id, frame.data, frame.len, 0);
		}

		inc_frame(&frame);

		/*
		 * to force a interlacing of the frames send by DUT and PC
		 * test tool a waiting time is injected
		 */
		if (frame_count == CAN_MSG_WAIT) {
			frame_count = 0;
			millisleep(3);
		}
	}

	return err;
}

static int can_echo_gen(void)
{
	struct canfd_frame *tx_frames;
	int *recv_tx;
	struct canfd_frame rx_frame;
	unsigned char counter = 0;
	int send_pos = 0, recv_rx_pos = 0, recv_tx_pos = 0, unprocessed = 0, loops = 0;
	int err = 0;
	time_t t, timeofs;

	tx_frames = calloc(inflight_count, sizeof(* tx_frames));
	if (!tx_frames) {
		return -1;
	}

	recv_tx = calloc(inflight_count, sizeof(* recv_tx));
	if (!recv_tx) {
		err = -1;
		goto out_free_tx_frames;
	}

	while (running) {
		if (unprocessed < inflight_count) {
			/* still send messages */
			tx_frames[send_pos].len = msg_len;
			tx_frames[send_pos].can_id = EMON_TM;
			t = time(NULL); // get gmt
			timeofs = timegm(localtime(&t)); // convert to local TZ
			memcpy(tx_frames[send_pos].data, &timeofs, sizeof(time_t));
			recv_tx[send_pos] = 0;

			if (t >= (sec_30 + CAN_TM_TIME)) {
				sec_30 = time(NULL);
				if (send_frame(&tx_frames[send_pos])) {
					err = -1;
					goto out_free;
				}
			}

			send_pos++;
			if (send_pos == inflight_count)
				send_pos = 0;
			unprocessed++;
			if (verbose == 1)
				echo_progress(counter);
			counter++;

			if ((counter % 33) == 0)
				millisleep(3);
			else
				millisleep(1);
		} else {
			if (recv_frame(&rx_frame)) {
				err = -1;
				goto out_free;
			}

			if (verbose > 1) {
				print_frame(rx_frame.can_id, rx_frame.data, rx_frame.len, 0);
			}

			/* own frame */
			if (rx_frame.can_id == can_id_ping) {
				err = compare_frame(&tx_frames[recv_tx_pos], &rx_frame, 0);
				recv_tx[recv_tx_pos] = 1;
				recv_tx_pos++;
				if (recv_tx_pos == inflight_count)
					recv_tx_pos = 0;
				continue;
			}

			/* compare with expected */
			err = compare_frame(&tx_frames[recv_rx_pos], &rx_frame, 1);
			recv_rx_pos++;
			if (recv_rx_pos == inflight_count) {
				recv_rx_pos = 0;
			}

			loops++;
			if (test_loops && loops >= test_loops) {
				break;
			}

			unprocessed--;
		}
	}

	fprintf(fout, "\nTest messages sent and received: %d\n", loops);

out_free:
	free(recv_tx);
out_free_tx_frames:
	free(tx_frames);

	return err;
}

/*
 * Async processing threads
 */

/*
 * Comedi data update timer flag
 */
void timer_callback(int32_t signum)
{
	signal(signum, timer_callback);
	runner = true;
}

/*
 * set the broker has message token
 */
void delivered(void *context, MQTTClient_deliveryToken dt)
{
	deliveredtoken = dt;
}

/*
 * data received on topic from the broker
 */
int32_t msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
	int32_t i;
	char* payloadptr;
	char buffer[1024];

#ifdef DEBUG_REC
	fprintf(fout, "Message arrived\n");
#endif
	payloadptr = message->payload;
	for (i = 0; i < message->payloadlen; i++) {
		buffer[i] = *payloadptr++;
	}
	buffer[i] = 0; // make C string

	// parse the JSON data
	cJSON *json = cJSON_ParseWithLength(buffer, message->payloadlen);
	if (json == NULL) {
		const char *error_ptr = cJSON_GetErrorPtr();
		if (error_ptr != NULL) {
			fprintf(fout, "Error: %s\n", error_ptr);
		}
		goto error_exit;
	}

	receivedtoken = true;
error_exit:
	// delete the JSON object
	cJSON_Delete(json);

	MQTTClient_freeMessage(&message);
	MQTTClient_free(topicName);
	return 1;
}

/*
 * Broker errors
 */
void connlost(void *context, char *cause)
{
	fprintf(fout, "\nConnection lost\n");
	fprintf(fout, "     cause: %s\n", cause);
	exit(EXIT_FAILURE);
}

char * log_time(bool log)
{
	static char time_log[512] = {0};
	uint32_t len = 0;
	time_t rawtime_log;

	tzset();
	timezone = 0;
	daylight = 0;
	time(&rawtime_log);
	sprintf(time_log, "%s", ctime(&rawtime_log));
	len = strlen(time_log);
	time_log[len - 1] = 0; // munge out the return character
	if (log) {
		fprintf(fout, "%s ", time_log);
		fflush(fout);
	}
	return time_log;
}

int main(int argc, char *argv[])
{
	struct sockaddr_can addr;
	char *intf_name = "can0", buffer[512];
	int family = PF_CAN, type = SOCK_RAW, proto = CAN_RAW;
	int echo_gen = 1;
	int opt, err;
	int enable_socket_option = 1;
	int filter = 0;
	int32_t rc;

	showIP();
	skeleton_daemon();

	signal(SIGTERM, signal_handler);
	signal(SIGHUP, signal_handler);
	signal(SIGINT, signal_handler);

	sec_30 = time(NULL);
	start_time = time(NULL);

#ifdef LOG_TO_FILE
	fout = fopen(LOG_TO_FILE, "a");
	if (fout == NULL) {
		snprintf(buffer, 511, "\r\nUnable to open LOG file %s \r\n", LOG_TO_FILE);
		syslog(LOG_NOTICE, buffer);
		exit(EXIT_FAILURE);
	}
#else
	fout = stdout;
#endif
	fprintf(fout, "\r\n%s LOG Version %s : MQTT Version %s\r\n", log_time(false), LOG_VERSION, MQTT_VERSION);
	snprintf(buffer, 511, "\r\n%s LOG version %s : MQTT version %s\r\n", log_time(false), LOG_VERSION, MQTT_VERSION);
	fflush(fout);
	syslog(LOG_NOTICE, buffer);

	MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
	conn_opts.keepAliveInterval = 20;
	conn_opts.cleansession = 1;

	MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);
	if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
		fprintf(fout, "Failed to connect, return code %d\n", rc);
		exit(EXIT_FAILURE);
	}

	/*
	 * on topic received data will trigger the msgarrvd function
	 */
	MQTTClient_subscribe(client, TOPIC_S, QOS);

	while ((opt = getopt(argc, argv, "bdef:gi:l:o:s:vx?")) != -1) {
		switch (opt) {
		case 'b':
			bit_rate_switch = 1;
			break;

		case 'd':
			is_can_fd = 1;
			break;

		case 'e':
			is_extended_frame_format = 1;
			break;

		case 'f':
			inflight_count = atoi(optarg);
			break;

		case 'g':
			echo_gen = 1;
			break;

		case 'i':
			can_id_ping = strtoul(optarg, NULL, 16);
			break;

		case 'l':
			test_loops = atoi(optarg);
			break;

		case 'o':
			can_id_pong = strtoul(optarg, NULL, 16);
			has_pong_id = 1;
			break;

		case 's':
			msg_len = atoi(optarg);
			break;

		case 'v':
			verbose++;
			break;

		case 'x':
			filter = 1;
			break;

		case '?':
		default:
			print_usage(basename(argv[0]));
			break;
		}
	}

	/* BRS can be enabled only if CAN FD is enabled */
	if (bit_rate_switch && !is_can_fd) {
		fprintf(fout, "Bit rate switch (-b) needs CAN FD (-d) to be enabled\n");
		return 1;
	}

	/* Make sure the message length is valid */
	if (msg_len <= 0) {
		fprintf(fout, "Message length must > 0\n");
		return 1;
	}
	if (is_can_fd) {
		if (msg_len > CANFD_MAX_DLEN) {
			fprintf(fout, "Message length must be <= %d bytes for CAN FD\n", CANFD_MAX_DLEN);
			return 1;
		}
	} else {
		if (msg_len > CAN_MAX_DLEN) {
			fprintf(fout, "Message length must be <= %d bytes for CAN 2.0B\n", CAN_MAX_DLEN);
			return 1;
		}
	}

	if (is_extended_frame_format) {
		can_id_ping &= CAN_EFF_MASK;
		can_id_ping |= CAN_EFF_FLAG;
		can_id_pong &= CAN_EFF_MASK;
		can_id_pong |= CAN_EFF_FLAG;
	} else {
		can_id_ping &= CAN_SFF_MASK;
		can_id_pong &= CAN_SFF_MASK;
	}

	if ((argc - optind) != 1) {
	} else {
		intf_name = argv[optind];
	}

	fprintf(fout, "interface = %s, family = %d, type = %d, proto = %d\n",
		intf_name, family, type, proto);

	if ((sockfd = socket(family, type, proto)) < 0) {
		syslog(LOG_ERR, "perror socket %s", strerror(errno));
		return 1;
	}

	if (echo_gen) {
		if (setsockopt(sockfd, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS,
			&enable_socket_option, sizeof(enable_socket_option)) == -1) {
			syslog(LOG_ERR, "perror setsocketopt CAN %s", strerror(errno));
			return 1;
		}
	}

	if (is_can_fd) {
		if (setsockopt(sockfd, SOL_CAN_RAW, CAN_RAW_FD_FRAMES,
			&enable_socket_option, sizeof(enable_socket_option)) == -1) {
			syslog(LOG_ERR, "perror CAN FRAME %s", strerror(errno));
			return 1;
		}
	}

	addr.can_family = family;
	addr.can_ifindex = if_nametoindex(intf_name);
	if (!addr.can_ifindex) {
		syslog(LOG_ERR, "perror if_nametoindex %s", strerror(errno));
		close(sockfd);
		return 1;
	}

	if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
		syslog(LOG_ERR, "perror bind %s", strerror(errno));
		close(sockfd);
		return 1;
	}

	if (!has_pong_id) {
		can_id_pong = can_id_ping + 1;
	}

	if (filter) {
		const struct can_filter filters[] = {
			{
				.can_id = can_id_ping,
				.can_mask = CAN_EFF_FLAG | CAN_RTR_FLAG | CAN_SFF_MASK,
			},
			{
				.can_id = can_id_pong,
				.can_mask = CAN_EFF_FLAG | CAN_RTR_FLAG | CAN_SFF_MASK,
			},
		};

		if (setsockopt(sockfd, SOL_CAN_RAW, CAN_RAW_FILTER, filters,
			sizeof(struct can_filter) * (1 + echo_gen))) {
			syslog(LOG_ERR, "perror %s", strerror(errno));
			close(sockfd);
			return 1;
		}
	}

	if (echo_gen) {
		err = can_echo_gen();
	} else {
		err = can_echo_dut();
	}

	if (verbose) {
		fprintf(fout, "Exiting...\n");
	}

	close(sockfd);

	if (exit_sig) {
		return 128 + exit_sig;
	}

	return err;
}

long long current_timestamp(void)
{
	struct timeval te;
	gettimeofday(&te, NULL); // get current time
	long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // calculate milliseconds
	return milliseconds;
}
