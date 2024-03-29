/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * canfdtest.c - Full-duplex test program (DUT and host part)
 *
 * (C) 2009 by Vladislav Gribov, IXXAT Automation GmbH, <gribov@ixxat.de>
 * (C) 2009 Wolfgang Grandegger <wg@grandegger.com>
 * (C) 2021 Jean Gressmann, IAV GmbH, <jean.steven.gressmann@iav.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the version 2 of the GNU General Public License
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * Send feedback to <linux-can@vger.kernel.org>
 */

/*
 * Logging only version for EM540 data from the mateQ84 controller module
 * presets have been defaulted for proper CANFD operation using the
 * PU2CANFD USB adapter with 64 byte payloads
 *
 * MQTT and JSON code and examples
 * https://www.geeksforgeeks.org/cjson-json-file-write-read-modify-in-c/
 */

#define _DEFAULT_SOURCE
#include <errno.h>
#include <getopt.h>
#include <libgen.h>
#include <limits.h>
#include <sched.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <cjson/cJSON.h>
#include "MQTTClient.h"

#include <linux/can.h>
#include <linux/can/raw.h>

#define CAN_MSG_ID_PING  0x80000002
#define CAN_MSG_ID_PING_X 0x80000003
#define EMON_SL   0x80000002 // config reporting
#define EMON_SU   0x80000003 // config reporting
#define EMON_SH   0x80000004 // config reporting
#define EMON_ER   0x8000000F // error reporting
#define EMON_CO   0x8000000C // config reporting
#define EMON_DA   0x8000000D // blob reporting
#define EMON_TM   0x8000000A // send time to mateQ84
#define CAN_MSG_ID_PONG  0x3
#define CAN_MSG_LEN 64
#define CAN_FULL_BUFFER CAN_MSG_LEN+CAN_MSG_LEN+CAN_MSG_LEN+1
#define CAN_MSG_COUNT 1
#define CAN_MSG_WAIT 27
#define CAN_TM_TIME 30
#define HR_SEC  3600
#define DAY_SEC  HR_SEC*24

#define LOG_VERSION     "v1.02"
#define MQTT_VERSION    "V3.11"
#define ADDRESS         "tcp://10.1.1.172:1883"
#define CLIENTID        "MateQ84_Mqtt"
#define TOPIC_P         "mateq84/data/solar"
#define TOPIC_S         "mateq84/data/solar/sub"
#define QOS             1
#define TIMEOUT         10000L
#define SPACING_USEC    500 * 1000
#define MQTT_TIMEOUT    150

#define E_MONTH         2266.0f // Kwh
#define G_MONTH         1000.0f // kWh
#define E_DAYS          31.0f
#define E_PER_DAY       E_MONTH/E_DAYS
#define E_PER_HOUR      E_PER_DAY/24.0f
#define G_PER_DAY       G_MONTH/E_DAYS
#define G_PER_HOUR      G_PER_DAY/24.0f

#define PGE_ZERO

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
int sec_30;
char *token;
cJSON *json;

volatile MQTTClient_deliveryToken deliveredtoken, receivedtoken = false;
volatile bool runner = false;

MQTTClient client;
MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
MQTTClient_message pubmsg = MQTTClient_message_initializer;
MQTTClient_deliveryToken mtoken;

long long current_timestamp(void);
time_t start_time = 0, hour_time = 0, day_time = 0;

double benergy, acenergy, load, solar, bvolts, bamps, pvolts, pamps, pwatts, runtime, bat_energy_scaled, bat_energy_kw;
double gridin = 0.001, gridout = 0.001, gasenergy = 0.001, watergal = 0.1;
int32_t ccmode = 0;

void timer_callback(int32_t);
void delivered(void *, MQTTClient_deliveryToken);
int32_t msgarrvd(void *, char *, int, MQTTClient_message *);
void connlost(void *, char *);

static void print_usage(char *prg)
{
	fprintf(stderr,
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

static void print_frame(canid_t id, const uint8_t *data, int dlc, int inc_data)
{
	int i;
	static int j = 0;

	if (print_hex) {
		printf("%04x: ", id);
	}
	if (id & CAN_RTR_FLAG) {
		printf("remote request");
	} else {
		if (print_hex) {
			printf("[%d]", dlc);
		}
		for (i = 0; i < dlc; i++) {
			if (print_hex) {
				printf(" %02x", (uint32_t) (data[i] + inc_data));
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
					gridin = 0.001f;
					gasenergy = 0.001f;
				}
			}
#ifdef PGE_ZERO
			gridin = 0.0f;
			gridout = 0.0f;
#endif
			fprintf(stdout, "log %s", data_buffer);
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
				fprintf(stderr, " %s %s log variable: %s ", TOPIC_P, ADDRESS, token);
				token = strtok(NULL, ",");
				acenergy = atof(token);
				fprintf(stderr, " %s ", token);
				token = strtok(NULL, ",");
				runtime = atof(token);
				fprintf(stderr, " %s ", token);
				token = strtok(NULL, ",");
				benergy = atof(token);

				fprintf(stderr, " %s ", token);
				token = strtok(NULL, ",");
				ccmode = atoi(token);
				fprintf(stderr, " %s\r\n", token);
				token = strtok(NULL, ",");
				load = atof(token);
				token = strtok(NULL, ",");
				token = strtok(NULL, ",");
				token = strtok(NULL, ",");
				token = strtok(NULL, ",");
				bat_energy_scaled = atof(token);
				bat_energy_kw = bat_energy_scaled * 10.0;

				json = cJSON_CreateObject();
				cJSON_AddStringToObject(json, "name", "mateq84");
				cJSON_AddNumberToObject(json, "benergy", benergy);
				cJSON_AddNumberToObject(json, "acenergy", acenergy);
				cJSON_AddNumberToObject(json, "load", load);
				cJSON_AddNumberToObject(json, "runtime", runtime);
				cJSON_AddNumberToObject(json, "solar", solar);
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
							printf("\r\nStill Waiting, timeout");
							break;
						}
					};
				}

				cJSON_free(json_str);
				cJSON_Delete(json);
			}
		}
		if (id == EMON_ER) {
			fprintf(stderr, "%s", full_buffer);
		}
		if (id == EMON_DA) {
			fprintf(stderr, "BLOB \r");
		}
		if (id == EMON_CO) {
			token = strtok(full_buffer, ",");
			if (token != NULL) {
				fprintf(stderr, "%s ", token);
				token = strtok(NULL, ",");
				fprintf(stderr, " relay outputs: %s\r\n", token);
			}
		}

	}
	if (print_hex) {
		printf("\n");
	}
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
	printf("expected: ");
	print_frame(exp_id, exp_data, exp_dlc, inc);
	printf("received: ");
	print_frame(rec_id, rec_data, rec_dlc, 0);
}

static int compare_frame(const struct canfd_frame *exp, const struct canfd_frame *rec, int inc)
{
	int err = 0;
	const canid_t expected_can_id = inc ? can_id_pong : can_id_ping;

	if (0 && rec->can_id != expected_can_id) {
		printf("Message ID mismatch!\n");
		print_compare(expected_can_id, exp->data, exp->len,
			rec->can_id, rec->data, rec->len, inc);
		running = 0;
		err = -1;
	} else if (rec->len != exp->len) {
		printf("Message length mismatch!\n");
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
			printf("t\n");
			break;
		}
		rqtp = rmtp;
	} while (err != 0);
}

static void echo_progress(unsigned char data)
{
	if (data == 0xff) {
		printf(".");
		fflush(stdout);
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
			perror("recv failed");
		} else {
			fprintf(stderr, "recv returned %zd", ret);
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
			fprintf(stderr, "send returned %zd", ret);
			return -1;
		}
		if (errno != ENOBUFS) {
			perror("send failed");
			return -1;
		}
		if (verbose) {
			printf("N");
			fflush(stdout);
		}
	}
	return 0;
}

static int check_frame(const struct canfd_frame *frame)
{
	int err = 0;

	if (frame->can_id != can_id_ping && frame->can_id != can_id_pingx && frame->can_id != EMON_ER && frame->can_id != EMON_CO) {
		printf("Unexpected Message ID 0x%04x!\n", frame->can_id);
		err = -1;
	}

	if (frame->len != msg_len) {
		printf("Unexpected Message length %d!\n", frame->len);
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

		//		err = check_frame(&frame);
		inc_frame(&frame);
		/*
		 * don't echo or send canbus frames
		 */
		//		if (send_frame(&frame))
		//			return -1;

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

			if (!recv_tx[recv_rx_pos]) {
				//				printf("RX before TX!\n");
				//				print_frame(rx_frame.can_id, rx_frame.data, rx_frame.len, 0);
				//				running = 0;
			}
			/* compare with expected */
			err = compare_frame(&tx_frames[recv_rx_pos], &rx_frame, 1);
			recv_rx_pos++;
			if (recv_rx_pos == inflight_count) {
				recv_rx_pos = 0;
			}

			loops++;
			if (test_loops && loops >= test_loops)
				break;

			unprocessed--;
		}
	}

	printf("\nTest messages sent and received: %d\n", loops);

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
	printf("Message arrived\n");
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
			printf("Error: %s\n", error_ptr);
		}
		goto error_exit;
		return 1;
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
	printf("\nConnection lost\n");
	printf("     cause: %s\n", cause);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	struct sockaddr_can addr;
	char *intf_name;
	int family = PF_CAN, type = SOCK_RAW, proto = CAN_RAW;
	int echo_gen = 1;
	int opt, err;
	int enable_socket_option = 1;
	int filter = 0;
	uint32_t rc;

	signal(SIGTERM, signal_handler);
	signal(SIGHUP, signal_handler);
	signal(SIGINT, signal_handler);

	sec_30 = time(NULL);
	start_time = time(NULL);

	printf("\r\n log version %s : mqtt version %s\r\n", LOG_VERSION, MQTT_VERSION);

	MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
	conn_opts.keepAliveInterval = 20;
	conn_opts.cleansession = 1;

	MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);
	if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
		printf("Failed to connect, return code %d\n", rc);
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
		printf("Bit rate switch (-b) needs CAN FD (-d) to be enabled\n");
		return 1;
	}

	/* Make sure the message length is valid */
	if (msg_len <= 0) {
		printf("Message length must > 0\n");
		return 1;
	}
	if (is_can_fd) {
		if (msg_len > CANFD_MAX_DLEN) {
			printf("Message length must be <= %d bytes for CAN FD\n", CANFD_MAX_DLEN);
			return 1;
		}
	} else {
		if (msg_len > CAN_MAX_DLEN) {
			printf("Message length must be <= %d bytes for CAN 2.0B\n", CAN_MAX_DLEN);
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
		print_usage(basename(argv[0]));
	}
	intf_name = argv[optind];

	printf("interface = %s, family = %d, type = %d, proto = %d\n",
		intf_name, family, type, proto);

	if ((sockfd = socket(family, type, proto)) < 0) {
		perror("socket");
		return 1;
	}

	if (echo_gen) {
		if (setsockopt(sockfd, SOL_CAN_RAW, CAN_RAW_RECV_OWN_MSGS,
			&enable_socket_option, sizeof(enable_socket_option)) == -1) {
			perror("setsockopt CAN_RAW_RECV_OWN_MSGS");
			return 1;
		}
	}

	if (is_can_fd) {
		if (setsockopt(sockfd, SOL_CAN_RAW, CAN_RAW_FD_FRAMES,
			&enable_socket_option, sizeof(enable_socket_option)) == -1) {
			perror("setsockopt CAN_RAW_FD_FRAMES");
			return 1;
		}
	}

	addr.can_family = family;
	addr.can_ifindex = if_nametoindex(intf_name);
	if (!addr.can_ifindex) {
		perror("if_nametoindex");
		close(sockfd);
		return 1;
	}

	if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
		perror("bind");
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
			perror("setsockopt()");
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
		printf("Exiting...\n");
		//		mqtt_exit();
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
