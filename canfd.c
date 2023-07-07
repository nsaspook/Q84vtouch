#include "canfd.h"

CAN_MSG_OBJ msg;

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
	while (true) {
		if (CAN1_ReceiveFrom(FIFO1, &msg)) //receive the message
		{
			can_rec_count.rec_count++;
			if (msg.msgId == EMON_SU) {
				can_rec_count.rec_flag = true;
			}
#ifdef CAN_DEBUG
			MLED_Toggle();
#endif
			break;
		}
		if (++tries >= 8) {
			break;
		}
	}
}

void can_fd_tx(void)
{
	CAN_MSG_OBJ Transmission; //create the CAN message object
#ifdef USE_FD
	Transmission.field.brs = CAN_BRS_MODE; //Transmit the data bytes at data bit rate
	Transmission.field.dlc = DLC_64; // 64 data bytes
	Transmission.field.formatType = CAN_FD_FORMAT; //CAN FD frames 
	Transmission.field.frameType = CAN_FRAME_DATA; //Data frame
	Transmission.field.idType = CAN_FRAME_EXT; //Standard ID
	Transmission.msgId = EMON_SL; //ID of client
#else
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
	Transmission.msgId = (EMON_SU); //ID of client
	Transmission.data = (uint8_t*) can_buffer + 64; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(FIFO2) & CAN_TX_FIFO_AVAILABLE))//ensure that the TXQ has space for a message
	{
		CAN1_Transmit(FIFO2, &Transmission); //transmit frame
	}

#ifdef CAN_DEBUG
	if (CAN1_IsRxErrorActive()) {
		MLED_Toggle();
	}
#endif
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