#include "canfd.h"

CAN_MSG_OBJ msg;

void Can1FIFO1NotEmptyHandler(void)
{
	CAN_MSG_OBJ EchoMessage; //create a message object for holding the data

	while (true) {
		if (CAN1_ReceivedMessageCountGet() > 0) //check for received message
		{
			if (true == CAN1_Receive(&EchoMessage)) //receive the message
			{
				break;
			}
		}
	}
	EchoMessage.msgId = EMON_M; //Change the ID to master, echo
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(TXQ) & CAN_TX_FIFO_AVAILABLE)) {
		CAN1_Transmit(TXQ, &EchoMessage); //Send the message
	}
	//	em.wl1 = 12345;
	MLED_Toggle();
}

void Can1FIFO2NotEmptyHandler(void)
{
	CAN_MSG_OBJ InternalMessage; //create a message object for holding data
	uint8_t DataIndex = 0; //placeholder variable for calculations

	while (true) {
		if (CAN1_ReceivedMessageCountGet() > 0) //check for received message
		{
			if (true == CAN1_Receive(&InternalMessage)) //receive the message
			{
				break;
			}
		}
	}
	DataIndex = InternalMessage.data[0] / 32; //calculate which data byte to use
	//	em.wl1 = 31415;
	MLED_Toggle();
}

void can_fd_tx(void)
{
	CAN_MSG_OBJ Transmission; //create the CAN message object
	Transmission.field.brs = CAN_BRS_MODE; //Transmit the data bytes at data bit rate
	Transmission.field.dlc = DLC_64; // 64 data bytes
	Transmission.field.formatType = CAN_FD_FORMAT; //CAN FD frames 
	Transmission.field.frameType = CAN_FRAME_DATA; //Data frame
	Transmission.field.idType = CAN_FRAME_EXT; //Standard ID
	Transmission.msgId = EMON_M; //ID of client
	Transmission.data = (uint8_t*) can_buffer; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(TXQ) & CAN_TX_FIFO_AVAILABLE))//ensure that the TXQ has space for a message
	{
		CAN1_Transmit(TXQ, &Transmission); //transmit frame
	}

	if (CAN1_IsRxErrorActive()) {
		MLED_Toggle();
	}
}

void can_fd_rx(void)
{
	if (CAN1_ReceivedMessageCountGet() > 0) {
		CAN1_Receive(&msg);
	}
}