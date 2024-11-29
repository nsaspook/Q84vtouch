#include "modbus_master.h"

#define	ON	1
#define	OFF	0

volatile uint8_t cc_stream_file, cc_buffer[MAX_DATA], cc_buffer_tx[MAX_DATA], dcu_data[MAX_DATA]; // RX and TX command buffers
/*
 * various PVP protocol read-only messages
 */
P_data P_read = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '0',
	.para0 = '9',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

P_data P_read_S = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '0',
	.para0 = '8',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

P_data P_read_I = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '1',
	.para0 = '0',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

P_data P_read_A = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '0',
	.para0 = '7',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

P_data P_read_P = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '0',
	.para0 = '2',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

P_data P_read_L = {// Link Voltage
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '1',
	.para0 = '3',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

P_data P_read_N = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '4',
	.para0 = '9',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

P_data P_read_V = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '1',
	.para0 = '2',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

P_data P_read_E = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '0',
	.para0 = '3',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

/*
 * PVP position set/read messages
 */
P_data P_action1 = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '0',
	.action0 = '0',
	.para2 = '3',
	.para1 = '3',
	.para0 = '1',
	.dl1 = '0',
	.dl0 = '2',
	.data1 = '=',
	.data0 = '?',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

P_data_r3 P_action2 = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '1',
	.action0 = '0',
	.para2 = '0',
	.para1 = '2',
	.para0 = '7',
	.dl1 = '0',
	.dl0 = '3',
	.data[2] = '0',
	.data[1] = '0',
	.data[0] = '0',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};
P_data_r3 P_action3 = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '1',
	.action0 = '0',
	.para2 = '7',
	.para1 = '0',
	.para0 = '8',
	.dl1 = '0',
	.dl0 = '3',
	.data[2] = '5',
	.data[1] = '9',
	.data[0] = '0',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};
P_data_r P_action4 = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '1',
	.action0 = '0',
	.para2 = '7',
	.para1 = '0',
	.para0 = '0',
	.dl1 = '0',
	.dl0 = '6',
	.data[5] = '0',
	.data[4] = '6',
	.data[3] = '0',
	.data[2] = '0',
	.data[1] = '0',
	.data[0] = '0',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};
P_data_r P_action5 = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '1',
	.action0 = '0',
	.para2 = '7',
	.para1 = '0',
	.para0 = '7',
	.dl1 = '0',
	.dl0 = '6',
	.data[5] = '0',
	.data[4] = '0',
	.data[3] = '5',
	.data[2] = '9',
	.data[1] = '0',
	.data[0] = '0',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};
P_data_r P_action6 = {
	.addr2 = '0',
	.addr1 = '0',
	.addr0 = '1',
	.action1 = '1',
	.action0 = '0',
	.para2 = '0',
	.para1 = '2',
	.para0 = '3',
	.dl1 = '0',
	.dl0 = '6',
	.data[5] = '1',
	.data[4] = '1',
	.data[3] = '1',
	.data[2] = '1',
	.data[1] = '1',
	.data[0] = '1',
	.chk2 = '0',
	.chk1 = '0',
	.chk0 = '0',
	.cr = 13, // EOF CR
};

volatile M_data M = {
	.blink_lock = false,
	.power_on = true,
};

volatile M_time_data MT = {
	.clock_500ahz = 0,
	.clock_2hz = 0,
	.clock_500hz = 0,
};

C_data C = {
	.mcmd = G_ID,
	.cstate = CLEAR,
	.modbus_command = G_ID,
	.req_length = 0,
	.trace = 0,
	.config_ok = false,
	.id_ok = false,
	.passwd_ok = false,
	.link_ok = false,
	.M.blink_lock = false,
	.M.power_on = true,
	.tm_ok = false,
	.set_ok = false,
	.speed = "OFFLINE",
	.mon = "OFFLINE",
	.current = "OFFLINE",
	.accel = " ",
	.dname = "OFFLINE",
	.dsoft = "OFFLINE",
	.link = "OFFLINE",
	.error = "OFFLINE",
	.sspeed = "OFFLINE",
	.set = "OFFLINE",
	.tmsc = " ",
	.aset = " ",
	.dcu_online = false,
	.dcu_setting = false,
	.motor_run = false,
	.crc_err = 0,
};

volatile struct V_type V = {
	.StartTime = 1,
	.TimeUsed = 1,
	.pacing = 1,
	.pwm_update = true,
	.pwm_stop = true,
	.fault_active = false,
	.fault_count = 0,
	.dmt_sosc_flag = false,
};

/*
 * send and receive Pfeiffer Vacuum Protocol messages
 */

static void half_dup_tx(const bool);
static void half_dup_rx(const bool);
static bool serial_trmt(void);
static uint16_t modbus_rtu_send_msg_crc(volatile uint8_t *, uint16_t);
static uint16_t crc16_receive(C_data *);
static void log_crc_error(const uint16_t, const uint16_t);
static void UART1_DefaultFramingErrorHandler_mb(void);
static void UART1_DefaultOverrunErrorHandler_mb(void);
static void UART1_DefaultErrorHandler_mb(void);

static bool modbus_write_check(C_data *, bool*, uint16_t);
static bool modbus_read_check(C_data *, bool*, uint16_t, void (* DataHandler)(void));
static bool modbus_read_id_check(C_data *, bool*, uint16_t);
static void em_data_handler(void);
static void emt_data_handler(void);
static void ems_data_handler(void);
static void emv_data_handler(void);

static bool modbus_read_dcu_check(C_data *, bool*, uint16_t);
static bool modbus_action_dcu_check(C_data *, bool*, uint16_t);

/*
 * constructs a properly formatted DCU message with CHK from a program memory array to the data memory array buffer
 */
uint16_t modbus_dcu_send_msg(void *cc_buffer, const void *modbus_cc_mode, const uint16_t req_length)
{
	char tmp_chk[6];
	P_data *P_ptr;
	P_data_r *P_ptr_r;
	P_data_r3 *P_ptr_r3;

	memcpy((void*) cc_buffer, (const void *) modbus_cc_mode, req_length);

	/*
	 * add the checksum to the 'telegram'
	 */
	if (req_length == sizeof(P_read)) { // data request
		P_ptr = cc_buffer;
		snprintf(tmp_chk, 4, "%03d", dcu_crc_r(cc_buffer));
		P_ptr->chk2 = tmp_chk[0];
		P_ptr->chk1 = tmp_chk[1];
		P_ptr->chk0 = tmp_chk[2];
	}
	if (req_length == sizeof(P_action)) { // position request
		P_ptr_r = cc_buffer;
		snprintf(tmp_chk, 4, "%03d", dcu_crc_a(cc_buffer));
		P_ptr_r->chk2 = tmp_chk[0];
		P_ptr_r->chk1 = tmp_chk[1];
		P_ptr_r->chk0 = tmp_chk[2];
	}
	if (req_length == sizeof(P_action3)) { // position request
		P_ptr_r3 = cc_buffer;
		snprintf(tmp_chk, 4, "%03d", dcu_crc_a3(cc_buffer));
		P_ptr_r3->chk2 = tmp_chk[0];
		P_ptr_r3->chk1 = tmp_chk[1];
		P_ptr_r3->chk0 = tmp_chk[2];
	}

	return req_length;
}

/*
 * calculate a CRC16 from the data buffer
 */
uint16_t crc16(volatile uint8_t *buffer, uint16_t buffer_length)
{
	uint8_t crc_hi = 0xFF; /* high CRC byte initialized */
	uint8_t crc_lo = 0xFF; /* low CRC byte initialized */
	uint8_t i; /* will index into CRC lookup */
	uint16_t crc16t;

	/* pass through message buffer */
	while (buffer_length--) {
		i = crc_hi ^ *buffer++; /* calculate the CRC  */
		crc_hi = crc_lo ^ table_crc_hi[i];
		crc_lo = table_crc_lo[i];
	}

	crc16t = (uint16_t) crc_hi << (uint16_t) 8 | (uint16_t) crc_lo;
	return crc16t;
}

/*
 * callback for UART received character from MODBUS client
 * for each RX byte received on the RS485 serial port
 */
void my_modbus_rx_32(void)
{
	static uint8_t m_data = 0;

	INT_TRACE;
	M.rx = true;
	/*
	 * process received controller data stream
	 */
	m_data = Srbuffer; // receiver data buffer
	cc_buffer[M.recv_count] = m_data;
	if (++M.recv_count >= MAX_DATA) {
		M.recv_count = 0; // reset buffer position
	}
}

uint8_t init_stream_params(void)
{
	M.config = false;
	return 0;
}

/*
 * state machine hardware timers interrupt ISR functions setup
 */
void init_mb_master_timers(void)
{
	TMR5_SetInterruptHandler(timer_500ms_tick);
	TMR5_StartTimer();
	TMR6_SetInterruptHandler(timer_2ms_tick);
	TMR6_StartTimer();
}

/*
 * helper functions
 * received CRC16 bytes from client
 */
static uint16_t crc16_receive(C_data * client)
{
	uint16_t crc16r;

	crc16r = ((uint16_t) cc_buffer[client->req_length - 2] << (uint16_t) 8) | ((uint16_t) cc_buffer[client->req_length - 1] & 0x00ff);
	return crc16r;
}

static void log_crc_error(const uint16_t c_crc, const uint16_t c_crc_rec)
{
	M.crc_calc = c_crc;
	M.crc_data = c_crc_rec;
	M.crc_error++;
	M.error++;
}

/*
 * reorder 16-bit word bytes for int32_t
 * https://control.com/forums/threads/endianness-for-32-bit-data.48584/
 * https://ctlsys.com/support/common_modbus_protocol_misconceptions/
 * https://iotech.force.com/edgexpert/s/article/Byte-and-Word-Swapping-in-Modbus
 *
 * "Little Endian" slaves or "Big Endian" slaves
 * Byte endianness with Word endianness?
 * Lions and Tigers and Bears!
 */
int32_t mb32_swap(const int32_t value)
{
	uint8_t i;
	union MREG32 dvalue;

	// program it simple and easy to understand way, let the compiler optimize the expressions
	dvalue.value = value;
	i = dvalue.bytes[0];
	dvalue.bytes[0] = dvalue.bytes[1];
	dvalue.bytes[1] = i;
	i = dvalue.bytes[2];
	dvalue.bytes[2] = dvalue.bytes[3];
	dvalue.bytes[3] = i;
	return dvalue.value;
}

int16_t mb16_swap(const int16_t value)
{
	uint8_t i;
	union MREG dvalue;

	// program it simple and easy to understand way, let the compiler optimize the expressions
	dvalue.value = value;
	i = dvalue.bytes[0];
	dvalue.bytes[0] = dvalue.bytes[1];
	dvalue.bytes[1] = i;
	return dvalue.value;
}

/*
 * Simple MODBUS master state machine for soft DCU
 * this needs to run in the main programming loop
 * to handle RS485 serial I/O exchanges
 */
int8_t master_controller_work_dcu(C_data * client)
{
	static uint32_t spacing = 0;

	if (spacing++ <SPACING && !M.rx) {
		return T_spacing;
	}
	spacing = 0;

	client->trace = T_begin;
	switch (client->cstate) {
	case CLEAR:
		client->trace = T_clear;
		clear_2hz();
		clear_500ahz();
		client->cstate = INIT;
		client->modbus_command = client->mcmd++; // sequence modbus commands to client
		if (client->mcmd > G_LAST) {
			client->mcmd = G_ID;
		}
		/*
		 * command specific tx buffer setup
		 */
		switch (client->modbus_command) {
		case G_CONFIG: // write code request
			client->trace = T_config;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_read_N, sizeof(P_read_N));
			break;
		case G_DATA1: // read code request
			client->trace = T_data;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_read_I, sizeof(P_read_I));
			break;
		case G_DATA2: // read code request
			client->trace = T_data;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_read_A, sizeof(P_read_A));
			break;
		case G_DATA3: // read code request
			client->trace = T_data;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_read_P, sizeof(P_read_P));
			break;
		case G_LINK: // read code request
			client->trace = T_link;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_read_L, sizeof(P_read_L));
			break;
		case G_VERSION: // read code request
			client->trace = T_version;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_read_V, sizeof(P_read_V));
			break;
		case G_PASSWD: // read code request
			client->trace = T_version;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_read_E, sizeof(P_read_E));
			break;
		case G_SSPEED: // read code request
			client->trace = T_sspeed;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_read_S, sizeof(P_read_S));
			break;
		case G_SET1:
			client->trace = T_set;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_action1, sizeof(P_action1));
			break;
		case G_SET2:
			if (client->dcu_setting) {
				client->trace = T_set;
				client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_action2, sizeof(P_action2));
			} else {
				client->cstate = CLEAR; // don't start message FSM
				client->mcmd = G_LAST;
			}
			break;
		case G_SET3:
			if (client->dcu_setting) {
				client->trace = T_set;
				client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_action3, sizeof(P_action3));
			} else {
				client->cstate = CLEAR; // don't start message FSM
				client->mcmd = G_LAST;
			}
			break;
		case G_SET4:
			if (client->dcu_setting) {
				client->trace = T_set;
				client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_action4, sizeof(P_action4));
			} else {
				client->cstate = CLEAR; // don't start message FSM
				client->mcmd = G_LAST;
			}
			break;
		case G_SET5:
			if (client->dcu_setting) {
				client->trace = T_set;
				client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_action5, sizeof(P_action5));
			} else {
				client->cstate = CLEAR; // don't start message FSM
				client->mcmd = G_LAST;
			}
			break;
		case G_SET6:
			if (client->dcu_setting && client->motor_run) {
				client->trace = T_set;
				client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_action6, sizeof(P_action6));
			} else {
				client->cstate = CLEAR; // don't start message FSM
				client->mcmd = G_LAST;
			}
			break;
		case G_LAST: // end of command sequences
			client->cstate = CLEAR;
			client->mcmd = G_ID; // what do we run next
			break;
		case G_ID: // operating mode request
		default:
			client->trace = T_id;
			client->req_length = modbus_dcu_send_msg((void*) cc_buffer_tx, (const void *) &P_read, sizeof(P_read));
			break;
		}
		break;
	case INIT:
		client->trace = T_init;
		/*
		 * MODBUS master query speed
		 */
		if (get_500ahz(false) >= CDELAY) {
			half_dup_tx(false); // no delays here
			M.recv_count = 0;
			client->cstate = SEND;
			clear_500hz();
			client->trace = T_init_d;
		}
		break;
	case SEND:
		client->trace = T_send;
		if (get_500hz(false) >= TEDELAY) {
			for (uint8_t i = 0; i < client->req_length; i++) {
				Swrite(cc_buffer_tx[i]);
			}
			client->cstate = RECV;
			clear_500hz(); // state machine execute background timer clear
			client->trace = T_send_d;
			M.sends++;
			M.rx = false;
			if (serial_trmt()) { // check for serial UART transmit shift register and buffer empty
				clear_500hz(); // clear timer until buffer empty
			}
			delay_ms(TDELAY + client->req_length);
			DERE_SetLow(); // enable modbus receiver
		}
		break;
	case RECV:
		client->trace = T_recv;
		if (get_500hz(false) >= TEDELAY) { // state machine execute timer test

			client->trace = T_recv_r;
			half_dup_rx(false); // no delays here

			/*
			 * check received response data for size and format for each command sent
			 */
			switch (client->modbus_command) {
			case G_VERSION: // 
				modbus_read_dcu_check(client, &client->version_ok, sizeof(P_action));
				break;
			case G_PASSWD: // 
				modbus_read_dcu_check(client, &client->passwd_ok, sizeof(P_action));
				break;
			case G_LINK: // 
				modbus_read_dcu_check(client, &client->link_ok, sizeof(P_action));
				break;
			case G_CONFIG: // 
				modbus_read_dcu_check(client, &client->config_ok, sizeof(P_action));
				break;
			case G_DATA1: //
				modbus_read_dcu_check(client, &client->data_ok, sizeof(P_action));
				break;
			case G_DATA2: // 
				modbus_read_dcu_check(client, &client->data_ok, sizeof(P_action));
				break;
			case G_DATA3: // 
				modbus_read_dcu_check(client, &client->data_ok, sizeof(P_action));
				break;
			case G_SSPEED: // 
				modbus_read_dcu_check(client, &client->sspeed_ok, sizeof(P_action));
				break;
			case G_SET1: // 
				modbus_read_dcu_check(client, &client->set_ok, sizeof(P_action));
				break;
			case G_SET2:
			case G_SET3:
				modbus_read_dcu_check(client, &client->set_ok, sizeof(P_action1)); // need to check for returned data format
				break;
			case G_SET4: // 
			case G_SET5:
			case G_SET6:
				modbus_read_dcu_check(client, &client->set_ok, sizeof(P_action));
				break;
			case G_ID: // check for client module type
			default:
				modbus_read_dcu_check(client, &client->id_ok, sizeof(P_action));
				break;
			}
		}
		break;
	default:
		break;
	}
	return client->trace;
}

/*
 * state machine no busy wait timers
 */
void clear_2hz(void)
{
	MT.clock_2hz = 0;
}

void clear_500ahz(void)
{
	MT.clock_500ahz = 0;
}

void clear_500hz(void)
{
	MT.clock_500hz = 0;
}

uint32_t get_2hz(const uint8_t mode)
{
	static uint32_t tmp = 0;

	if (mode) {
		return tmp;
	}

	tmp = MT.clock_2hz;
	return tmp;
}

/*
 * 500Hz updates
 * used for fast updates timing
 */
uint32_t get_500ahz(const uint8_t mode)
{
	static uint32_t tmp = 0;

	if (mode) {
		return tmp;
	}

	tmp = MT.clock_500ahz;
	return tmp;
}

uint32_t get_500hz(const uint8_t mode)
{
	static uint32_t tmp = 0;

	if (mode) {
		return tmp;
	}

	tmp = MT.clock_500hz;
	return tmp;
}

// switch RS transceiver to transmit mode and wait if not tx

static void half_dup_tx(const bool delay)
{
	if (DERE_GetValue()) {
		return;
	}
	DERE_SetHigh(); // enable modbus transmitter

	if (delay) {
		delay_ms(DUPL_DELAY); // busy waits
	}
}

// switch RS transceiver to receive mode and wait if not rx

static void half_dup_rx(const bool delay)
{
	if (!DERE_GetValue()) {
		return;
	}
	if (delay) {
		delay_ms(DUPL_DELAY); // busy waits
	}
	DERE_SetLow(); // enable modbus receiver
}

// ISR function for TMR5

void timer_500ms_tick(void)
{
	INT_TRACE;
	MT.clock_2hz++;
}

// ISR function for TMR6

void timer_2ms_tick(void)
{
	INT_TRACE;
	MT.clock_500hz++;
	MT.clock_500ahz++;
}

/*
 * check if we are done with interrupt background buffered transmission of serial data with FIFO
 *
 * TRMT: Transmit Shift Register is Empty bit (read-only)
 * 1 = Transmit shift register is empty and transmit buffer is empty (the last transmission has completed)
 * 0 = Transmit shift register is not empty, a transmission is in progress or queued in the transmit buffer
 *
 * ? 8-level deep First-In-First-Out (FIFO) transmit data buffer, ? 8-level deep FIFO receive data buffer
 * Interrupt is generated and asserted while the transmit buffer is empty
 *
 * so this will return 'true' after the buffer is empty 'interrupt' and after the last bit is on the wire
 */

static bool serial_trmt(void)
{
	return !(Strmt); // note, we invert the TRMT bit so it's true while transmitting
}

static void UART1_DefaultFramingErrorHandler_mb(void)
{
	INT_TRACE; // GPIO interrupt scope trace
	MM_ERROR_S;
}

static void UART1_DefaultOverrunErrorHandler_mb(void)
{
	INT_TRACE; // GPIO interrupt scope trace
	MM_ERROR_S;
}

static void UART1_DefaultErrorHandler_mb(void)
{
	INT_TRACE; // GPIO interrupt scope trace
	MM_ERROR_S;
}

void mb_setup(void)
{
	UART1_SetFramingErrorHandler(UART1_DefaultFramingErrorHandler_mb);
	UART1_SetOverrunErrorHandler(UART1_DefaultOverrunErrorHandler_mb);
	UART1_SetErrorHandler(UART1_DefaultErrorHandler_mb);
}

static bool modbus_read_dcu_check(C_data * client, bool* cstate, const uint16_t rec_length)
{
	uint16_t c_crc = 0, c_crc_rec = 1; // mismatch by default
	uint8_t data_len;

	client->req_length = rec_length;
	if (DBUG_R((M.recv_count >= client->req_length))) {

		data_len = dcu_buffer_len((uint8_t *) cc_buffer);
		if (data_len == 6) {
			c_crc = dcu_chk_buffer((uint8_t*) cc_buffer, (uint8_t) rec_length); // use data from crc from rec buffer crc data
			c_crc_rec = dcu_crc_a((uint8_t*) cc_buffer); // from computed data from total rec buffer
		}

		if (data_len == 3) { // check returned data length for P_data_r3 setting commands
			c_crc = dcu_chk_buffer((uint8_t*) cc_buffer, (uint8_t) rec_length); // use data from crc from rec buffer crc data
			c_crc_rec = dcu_crc_a3((uint8_t*) cc_buffer); // from computed data from total rec buffer
		}

		if (data_len > 3) {
			c_crc_rec = c_crc;
			data_len = 6;
		}

		if (DBUG_R c_crc == c_crc_rec) {
			/*
			 * parse commands and save data 
			 */
			if (dcu_param_num((uint8_t *) cc_buffer) == Error_code) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->error[i] = cc_buffer[10 + i];
				}
				client->error[data_len] = 0;
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == TMS_ActTmp) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->tmsc[i] = cc_buffer[10 + i];
				}
				client->tmsc[data_len] = 0;
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == ActualSpd) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->speed[i] = cc_buffer[10 + i];
				}
				client->speed[data_len] = 0;
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == SetRotSpd) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->sspeed[i] = cc_buffer[10 + i];
				}
				client->sspeed[data_len] = 0;
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == MotorPump) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->mon[i] = cc_buffer[10 + i];
				}
				client->mon[data_len] = 0;
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == DrvCurrent) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->current[i] = cc_buffer[10 + i];
				}
				client->current[data_len] = 0;
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == TMP_DClink) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->link[i] = cc_buffer[10 + i];
				}
				client->link[data_len] = 0;
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == AccelDecel) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->accel[i] = cc_buffer[10 + i];
				}
				client->accel[1] = 0; // shortened to single boolean char
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == AttainedSet) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->aset[i] = cc_buffer[10 + i];
				}
				client->aset[1] = 0; // shortened to single boolean char
			}

			if (dcu_param_num((uint8_t *) cc_buffer) == DrvName) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->dname[i] = cc_buffer[10 + i];
				}
				client->dname[data_len] = 0;
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == DrvSoftw) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->dsoft[i] = cc_buffer[10 + i];
				}
				client->dsoft[data_len] = 0;
			}
			if (dcu_param_num((uint8_t *) cc_buffer) == Gas_mode) {
				for (uint8_t i = 0; i < data_len; i++) {
					client->set[i] = cc_buffer[10 + i];
				}
				client->set[data_len] = 0;
			}
			MM_ERROR_C;
			*cstate = true;
			client->dcu_online = true;
			MLED_SetLow();
		} else {
			MM_ERROR_S;
			*cstate = false;
			client->id_ok = false;
			client->config_ok = false;
			client->passwd_ok = false;
			client->data_ok = false;
			client->link_ok = false;
			client->version_ok = false;
			client->serial_ok = false;
			log_crc_error(c_crc, c_crc_rec);
			client->crc_err = dcu_param_num((uint8_t *) cc_buffer);
			MLED_SetHigh();
		}
		client->cstate = CLEAR;
	} else {
		if (get_500hz(false) >= RDELAY) {
			client->cstate = CLEAR;
			client->mcmd = G_ID;
			M.to_error++;
			M.error++;
			client->id_ok = false;
			*cstate = false;
			client->config_ok = false;
			client->passwd_ok = false;
			client->data_ok = false;
			client->link_ok = false;
			client->version_ok = false;
			client->serial_ok = false;
			client->crc_err = dcu_param_num((uint8_t *) cc_buffer);
			MLED_SetHigh();
		}
	}
	return *cstate;
}

uint8_t dcu_crc_r(uint8_t * p)
{
	uint8_t crc_num = 0;

	for (uint8_t i = 0; i < 12; i++) {
		crc_num += (uint8_t) p[i];
	}
	return crc_num;
}

uint8_t dcu_crc_a(uint8_t * p)
{
	uint8_t crc_num = 0;

	for (uint8_t i = 0; i < 16; i++) {
		crc_num += (uint8_t) p[i];
	}
	return crc_num;
}

uint8_t dcu_crc_a3(uint8_t * p)
{
	uint8_t crc_num = 0;

	for (uint8_t i = 0; i < 13; i++) {
		crc_num += (uint8_t) p[i];
	}
	return crc_num;
}

uint8_t dcu_chk_buffer(uint8_t * p, uint8_t count)
{
	uint8_t chk_num = 0;
	char tmp_chk[6] = "000";

	tmp_chk[0] = p[count - 4];
	tmp_chk[1] = p[count - 3];
	tmp_chk[2] = p[count - 2];

	chk_num = (uint8_t) atoi(tmp_chk);

	return chk_num;
}

/*
 * length of returned data string
 */
uint8_t dcu_buffer_len(uint8_t * p)
{
	uint8_t len_num = 0;
	char tmp_len[6] = "00";

	tmp_len[0] = p[8];
	tmp_len[1] = p[9];

	len_num = (uint8_t) atoi(tmp_len);

	return len_num;
}

uint16_t dcu_param_num(uint8_t * p)
{
	uint16_t chk_num = 0;
	char tmp_chk[6] = "000";

	tmp_chk[0] = p[5];
	tmp_chk[1] = p[6];
	tmp_chk[2] = p[7];

	chk_num = (uint16_t) atoi(tmp_chk);

	return chk_num;
}