#include "canfd.h"

CAN_MSG_OBJ msg[2];
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
 * process the FIFO data into msg structure
 */
void Can1FIFO1NotEmptyHandler(void)
{
	uint8_t tries = 0;
	static uint8_t half = 0;
	char s_buffer[21];

	while (true) {
		can_rec_count.rec_count++;
		if (CAN1_ReceiveFrom(FIFO1, &msg[half])) //receive the message
		{
			if ((msg[half].msgId & 0xf) == EMON_SL || (msg[half].msgId & 0xf) == EMON_SU) {
				memcpy((void *) &rxMsgData[half][0], msg[half].data, CANFD_BYTES);
				if ((msg[half].msgId & 0xf) == EMON_SL) {
					half = 1;
#ifdef CAN_DEBUG
					MLED_Toggle();
#endif
					break;
				}
				if ((msg[half].msgId & 0xf) == EMON_SU) {
					half = 0;
					can_rec_count.rec_flag = true;
#ifdef CAN_DEBUG
					MLED_Toggle();
#endif
					break;
				}
#ifdef CAN_DEBUG
				MLED_Toggle();
#endif
			}
			if ((msg[half].msgId & 0xf) == EMON_CO) {
				memcpy((void *) &rxMsgData[CAN_INFO_BUF][0], msg[half].data, CANFD_BYTES);
			}
			if ((msg[half].msgId & 0xf) == EMON_ER) {
				memcpy((void *) &rxMsgData[CAN_ERROR_BUF][0], msg[half].data, CANFD_BYTES);
			}
			if ((msg[half].msgId & 0xf) == EMON_TM) {
				memcpy((void *) &can_timer, msg[half].data, 4);
				can_newtime = localtime(&can_timer);
				snprintf(s_buffer, 20, "%s", asctime(can_newtime));
				eaDogM_Scroll_String(s_buffer);
			}
			break;
		}
		if (++tries >= CAN_RX_TRIES) {
			break;
		}
	}
}

/*
 * send 64 byte CAN packets with the ASCII battery data in CSV format
 * EMON_SL [0..63], EMON_SU [64..127] bytes of data
 * ^ for ASCII start of string, ~ for end of data string
 * also send aux error and config packets if flagged
 */
void can_fd_tx(void)
{
	//	IO_RB7_Toggle(); // canbus timing
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
		snprintf(info_buffer, MAX_B_BUF, "SN: %s %u FW: 0X%X", ems.serial, ems.year, emv.firmware);
		Transmission.data = (uint8_t*) info_buffer; //transmit the data from the data bytes
		if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO3) & CAN_TX_FIFO_AVAILABLE))//ensure that the FIFO has space for a message
		{
			CAN1_Transmit(FIFO3, &Transmission); //transmit frame
		}
	}

#ifdef CAN_DEBUG
	if (CAN1_IsRxErrorActive()) {
		MLED_Toggle();
	}
#endif
	IO_RB5_SetLow();
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