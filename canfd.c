#include "canfd.h"

CAN_MSG_OBJ msg[CANFD_NBUF];
volatile uint8_t rxMsgData[CAN_REC_BUFFERS][CANFD_BYTES] = {
	"     no data        ",
	" no_data            ",
	" no info1           ",
	" no info2           ",
};

volatile can_rec_count_t can_rec_count = {
	.rec_count = 0,
	.rec_flag = false,
};

/*
 * 16-bit word to 2 bytes
 */
union {
	uint16_t Word;

	struct {
		uint8_t Byte1 : 8;
		uint8_t Byte2 : 8;
	} structBytes;
} myVar;

static EB_data *EB = &EBD;

#ifdef CAN_REMOTE	
static volatile char s_buffer[CAN_MIRRORS][LCD_BUF_SIZ + 1] = {
	"                     ",
	"                     ",
	"                     ",
	"                     ",
};
static volatile bool mirror_print[CAN_MIRRORS] = {false, false, false, false};
static char *token;
#endif

/*
 * process the FIFO data into msg structure
 * interrupt context ISR
 */
void Can1FIFO1NotEmptyHandler(void)
{
	uint8_t tries = 0;
	static uint8_t half = CAN_LOW_BUF;

	INT_TRACE; // GPIO interrupt scope trace

	while (true) {
		can_rec_count.rec_count++;
		if (CAN1_ReceiveFrom(FIFO1, &msg[half])) //receive the message
		{
			memcpy(&msg[MIRR0R_BUF], &msg[half], sizeof(CAN_MSG_OBJ));
			if ((msg[half].msgId & 0xf) == EMON_SL || (msg[half].msgId & 0xf) == EMON_SU) {
				memcpy((void *) &rxMsgData[half][0], msg[half].data, CANFD_BYTES);
				if ((msg[half].msgId & 0xf) == EMON_SL) {
					half = CAN_HIGH_BUF;
					break;
				}
				if ((msg[half].msgId & 0xf) == EMON_SU) {
					half = CAN_LOW_BUF;
					can_rec_count.rec_flag = true;
					break;
				}
			}
			if ((msg[half].msgId & 0xf) == EMON_CO) {
				memcpy((void *) &rxMsgData[CAN_INFO_BUF][0], msg[half].data, CANFD_BYTES);
#ifdef CAN_REMOTE	// parse the relay bits from the info string into the local LATE
				token = strtok((char*) &rxMsgData[CAN_INFO_BUF][0], ",");
				if (token != NULL) {
					token = strtok(NULL, ",");
					LATE = (uint8_t) atoi(token);
				}
#endif
				break;
			}
			if ((msg[half].msgId & 0xf) == EMON_ER) {
				memcpy((void *) &rxMsgData[CAN_ERROR_BUF][0], msg[half].data, CANFD_BYTES);
				break;
			}
			if ((msg[MIRR0R_BUF].msgId & 0xf) == EMON_TM) {
				memcpy((void *) &can_timer, msg[MIRR0R_BUF].data, sizeof(time_t)); // load 32-bit linux time from canbus packet
				EB->fm80_time = can_timer; // save remote Unix time from canbus packets
				can_newtime = localtime(&can_timer);
				update_time(can_newtime, EB);
				/*
				 * update the FM80 time and data message values with a proper checksum
				 * this is sent to the FM80 but am unsure if it changes anything on the device
				 */
				myVar.Word = EB->time;
				cmd_time[5] = myVar.structBytes.Byte1; // store time
				cmd_time[4] = myVar.structBytes.Byte2;
				myVar.Word = calc_checksum((uint8_t *) & cmd_time[1], CMD_CRC_LEN);
				cmd_time[7] = myVar.structBytes.Byte1; // store crc
				cmd_time[6] = myVar.structBytes.Byte2;
				myVar.Word = EB->date;
				cmd_date[5] = myVar.structBytes.Byte1;
				cmd_date[4] = myVar.structBytes.Byte2;
				myVar.Word = calc_checksum((uint8_t *) & cmd_date[1], CMD_CRC_LEN);
				cmd_date[7] = myVar.structBytes.Byte1;
				cmd_date[6] = myVar.structBytes.Byte2;
				if (B.canbus_online && B.FM80_online) {
					C.tm_ok = true; // FM80 time date data valid to send flag
				}
				break;
			}
#ifdef CAN_REMOTE
			if ((msg[MIRR0R_BUF].msgId & 0xf) == EMON_MR + LCD0) {
				memcpy((void *) &s_buffer[LCD0][0], msg[MIRR0R_BUF].data, LCD_BUF_SIZ); // load LCD mirror packet
				mirror_print[LCD0] = true;
				break;
			}
			if ((msg[MIRR0R_BUF].msgId & 0xf) == EMON_MR + LCD1) {
				memcpy((void *) &s_buffer[LCD1][0], msg[MIRR0R_BUF].data, LCD_BUF_SIZ); // load LCD mirror packet
				mirror_print[LCD1] = true;
				break;
			}
			if ((msg[MIRR0R_BUF].msgId & 0xf) == EMON_MR + LCD2) {
				memcpy((void *) &s_buffer[LCD2][0], msg[MIRR0R_BUF].data, LCD_BUF_SIZ); // load LCD mirror packet
				mirror_print[LCD2] = true;
				break;
			}
			if ((msg[MIRR0R_BUF].msgId & 0xf) == EMON_MR + LCD3) {
				memcpy((void *) &s_buffer[LCD3][0], msg[MIRR0R_BUF].data, LCD_BUF_SIZ); // load LCD mirror packet
				mirror_print[LCD3] = true;
				break;
			}
#endif
		}
		if (++tries >= CAN_RX_TRIES) {
			break;
		}
	}
}

void can_mirror_print(void)
{
#ifdef CAN_REMOTE
	if (mirror_print[LCD0]) {
		eaDogM_WriteStringAtPos(LCD0, 0, (char*) &s_buffer[LCD0][0]);
		mirror_print[LCD0] = false;
	}
	if (mirror_print[LCD1]) {
		eaDogM_WriteStringAtPos(LCD1, 0, (char*) &s_buffer[LCD1][0]);
		mirror_print[LCD1] = false;
	}
	if (mirror_print[LCD2]) {
		eaDogM_WriteStringAtPos(LCD2, 0, (char*) &s_buffer[LCD2][0]);
		mirror_print[LCD2] = false;
	}
	if (mirror_print[LCD3]) {
		eaDogM_WriteStringAtPos(LCD3, 0, (char*) &s_buffer[LCD3][0]);
		mirror_print[LCD3] = false;
	}
#endif
}

/*
 * send 64 byte CAN packets with the ASCII battery data in CSV format
 * EMON_SL [0..63], EMON_SU [64..127] bytes of data
 * ^ for ASCII start of string, ~ for end of data string
 * also send aux error and config packets if flagged
 */
void can_fd_tx(void)
{
	CAN_MSG_OBJ Transmission; //create the CAN message object
	Transmission.field.brs = CAN_BRS_MODE; //Transmit the data bytes at data bit rate
	Transmission.field.dlc = DLC_64; // 64 data bytes
	Transmission.field.formatType = CAN_FD_FORMAT; //CAN FD frames
	Transmission.field.frameType = CAN_FRAME_DATA; //Data frame
	Transmission.field.idType = CAN_FRAME_EXT; //Standard ID
	Transmission.msgId = EMON_SL; // packet type ID of client
	Transmission.data = (uint8_t*) can_buffer; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO2) & CAN_TX_FIFO_AVAILABLE))//ensure that the FIFO has space for a message
	{
		CAN1_Transmit(FIFO2, &Transmission); //transmit frame
	}
	Transmission.msgId = (EMON_SU);
	Transmission.data = (uint8_t*) can_buffer + CANFD_BYTES; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO2) & CAN_TX_FIFO_AVAILABLE))//ensure that the FIFO has space for a message
	{
		CAN1_Transmit(FIFO2, &Transmission); //transmit frame
	}

	Transmission.msgId = (EMON_ER); // error packet type ID
	Transmission.data = (uint8_t*) info_buffer; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO3) & CAN_TX_FIFO_AVAILABLE))//ensure that the FIFO has space for a message
	{
		CAN1_Transmit(FIFO3, &Transmission); //transmit frame
	}

	if (C.serial_ok && C.version_ok) {
		Transmission.msgId = (EMON_CO); // config packet type ID
		snprintf(info_buffer, MAX_B_BUF, "SN: %s %u FW: 0X%X,%X", ems.serial, ems.year, emv.firmware, LATE);
		Transmission.data = (uint8_t*) info_buffer; //transmit the data from the data bytes
		if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO3) & CAN_TX_FIFO_AVAILABLE))//ensure that the FIFO has space for a message
		{
			CAN1_Transmit(FIFO3, &Transmission); //transmit frame
		}
	}
#ifdef CAN_REMOTE_ERR
	if (CAN1_IsRxErrorActive()) {
	}
#endif
}

/*
 * complete and correct the MCC CANBUS configuration
 */
void can_setup(void)
{
	/*
	 * don't trust MCC for nothing
	 */
	CAN1_OperationModeSet(CAN_CONFIGURATION_MODE);
	/*
	 * interrupt handlers, both receive data from the FIFO
	 */
	CAN1_SetFIFO1NotEmptyHandler(Can1FIFO1NotEmptyHandler);
	CAN1_SetRxBufferOverFlowInterruptHandler(Can1FIFO1NotEmptyHandler);
	CAN1_SetTXQNotFullHandler(TXQNotFullHandler);

	/*
	 * user mod filter and masking
	 * SID to allow all system id's to pass
	 */
	C1FLTOBJ0L = 0x00;
	C1FLTOBJ0H = 0x00;
	C1FLTOBJ0U = 0x00;
	C1FLTOBJ0T = 0x40;
	/*
	 * user MASK mod
	 */
	C1MASK0L = 0xFF;
	C1MASK0H = 0x00;
	C1MASK0U = 0xFF;
	C1MASK0T = 0x5F;
	C1FLTCON0L = 0x81;

	C1FIFOCON1Lbits.TFNRFNIE = 1; // not empty FIFO interrupt
	/*
	 * enable CAN receiver interrupts, again, to fix one of the many MCC bugs
	 */
	C1INTUbits.RXIE = 1; // The stupid MCC sets this back to off when setting the error interrupts
	PIR4bits.CANRXIF = 0; // clear flags and set interrupt controller again, just to be sure
	PIE4bits.CANRXIE = 1;
	CAN1_OperationModeSet(CAN_NORMAL_FD_MODE);
}

/*
 * send LCD line buffer data via CANBUS to remote displays
 */
void can_fd_lcd_mirror(const uint8_t r, char *strPtr)
{
#ifndef CAN_REMOTE	// don't repeat a received message
	if (!B.FM80_io) {
		CAN_MSG_OBJ Transmission; //create the CAN message object
		Transmission.field.brs = CAN_BRS_MODE; //Transmit the data bytes at data bit rate
		Transmission.field.dlc = DLC_64; // 64 data bytes
		Transmission.field.formatType = CAN_FD_FORMAT; // CAN FD frames
		Transmission.field.frameType = CAN_FRAME_DATA; // Data frame
		Transmission.field.idType = CAN_FRAME_EXT; // EXT ID
		Transmission.msgId = EMON_MR + r; // packet type ID of client
		Transmission.data = (uint8_t*) strPtr; //transmit the data from the data bytes
		if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(TXQ) & CAN_TX_FIFO_AVAILABLE))//ensure that the FIFO has space for a message
		{
			CAN1_Transmit(TXQ, &Transmission); //transmit frame
		}
	}
#endif
#ifdef CAN_REMOTE_ERR
	if (CAN1_IsRxErrorActive()) {
	}
#endif
}

void TXQNotFullHandler(void)
{
	INT_TRACE; // GPIO interrupt scope trace
	C1INTUbits.TXIE = 0;
}