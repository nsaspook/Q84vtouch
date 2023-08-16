#include "canfd.h"

CAN_MSG_OBJ msg[2];
volatile uint8_t rxMsgData[2][CANFD_BYTES] = {
	"     no data   ",
	" no_data   ",
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

	while (true) {
		if (CAN1_ReceiveFrom(FIFO1, &msg[half])) //receive the message
		{
			memcpy((void *) &rxMsgData[half][0], msg[half].data, CANFD_BYTES);
			can_rec_count.rec_count++;
			if (msg[half].msgId == EMON_SL) {
				half = 1;
#ifdef CAN_DEBUG
				MLED_Toggle();
#endif
				break;
			}
			if (msg[half].msgId == EMON_SU) {
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
	IO_RB5_SetHigh();
	CAN_MSG_OBJ Transmission; //create the CAN message object
#ifdef USE_FD
	Transmission.field.brs = CAN_BRS_MODE; //Transmit the data bytes at data bit rate
	Transmission.field.dlc = DLC_64; // 64 data bytes
	Transmission.field.formatType = CAN_FD_FORMAT; //CAN FD frames
	Transmission.field.frameType = CAN_FRAME_DATA; //Data frame
	Transmission.field.idType = CAN_FRAME_EXT; //Standard ID
	Transmission.msgId = EMON_SL; // packet type ID of client
#else
	return; // don't try to send classic packets
	Transmission.field.brs = CAN_NON_BRS_MODE; //Transmit the data bytes at data bit rate
	Transmission.field.dlc = DLC_8; // 8 data bytes
	Transmission.field.formatType = CAN_2_0_FORMAT; // CAN operation mode
	Transmission.field.frameType = CAN_FRAME_DATA; //Data frame
	Transmission.field.idType = CAN_FRAME_STD; //Standard ID
	Transmission.msgId = (EMON_SL); //ID of client
#endif
	Transmission.data = (uint8_t*) can_buffer; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO2) & CAN_TX_FIFO_AVAILABLE))//ensure that the TXQ has space for a message
	{
		CAN1_Transmit(FIFO2, &Transmission); //transmit frame
	}
	Transmission.msgId = (EMON_SU);
	Transmission.data = (uint8_t*) can_buffer + CANFD_BYTES; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO2) & CAN_TX_FIFO_AVAILABLE))//ensure that the TXQ has space for a message
	{
		CAN1_Transmit(FIFO2, &Transmission); //transmit frame
	}

	Transmission.msgId = (EMON_ER); // error packet type ID
	Transmission.data = (uint8_t*) info_buffer; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO2) & CAN_TX_FIFO_AVAILABLE))//ensure that the TXQ has space for a message
	{
		CAN1_Transmit(FIFO2, &Transmission); //transmit frame
	}

	Transmission.msgId = (EMON_CO); // error packet type ID
	Transmission.data = (uint8_t*) build_version; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO2) & CAN_TX_FIFO_AVAILABLE))//ensure that the TXQ has space for a message
	{
		CAN1_Transmit(FIFO2, &Transmission); //transmit frame
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
	 * interrupt handlers, both receive data from the FIFO
	 */
	CAN1_SetFIFO1NotEmptyHandler(Can1FIFO1NotEmptyHandler);
	CAN1_SetRxBufferOverFlowInterruptHandler(Can1FIFO1NotEmptyHandler);

	/*
	 * don't trust MCC for nothing
	 */
	CAN1_OperationModeSet(CAN_CONFIGURATION_MODE);
	C1FIFOCON1Lbits.TFNRFNIE = 1; // not empty FIFO interrupt
	/*
	 * enable CAN receiver interrupts, again, to fix one of the many MCC bugs
	 */
	C1INTUbits.RXIE = 1; // The stupid MCC sets this back to off when setting the error interrupts
	PIR4bits.CANRXIF = 0; // clear flags and set interrupt controller again, just to be sure
	PIE4bits.CANRXIE = 1;
#ifdef	USE_FD
	CAN1_OperationModeSet(CAN_NORMAL_FD_MODE);
#else
	CAN1_OperationModeSet(CAN_NORMAL_2_0_MODE);
#endif
}