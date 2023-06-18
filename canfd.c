#include "canfd.h"

static void DefaultFIFO1NotEmptyHandler(void)
{
	CAN_MSG_OBJ EchoMessage; //create a message object for holding the data
	while (1) {
		if (CAN1_ReceivedMessageCountGet() > 0) //check for received message
		{
			if (true == CAN1_Receive(&EchoMessage)) //receive the message
			{
				break;
			}
		}
	}
	EchoMessage.msgId = 0x222; //Change the ID to 0x222 then echo the message back out
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(TXQ) & CAN_TX_FIFO_AVAILABLE)) {
		CAN1_Transmit(TXQ, &EchoMessage); //Send the message
	}
}

static void DefaultFIFO2NotEmptyHandler(void)
{
	CAN_MSG_OBJ InternalMessage; //create a message object for holding data
	uint8_t DataIndex = 0; //placeholder variable for calculations
	while (1) {
		if (CAN1_ReceivedMessageCountGet() > 0) //check for received message
		{
			if (true == CAN1_Receive(&InternalMessage)) //receive the message
			{
				break;
			}
		}
	}
	DataIndex = InternalMessage.data[0] / 32; //calculate which data byte to use
	LATA = InternalMessage.data[DataIndex]; //output the data byte to the LEDs
}

void can_fd_tx(void)
{
	CAN_MSG_OBJ Transmission; //create the CAN message object
	Transmission.field.brs = CAN_BRS_MODE; //Transmit the data bytes at data bit rate
	Transmission.field.dlc = DLC_64; //8 data bytes
	Transmission.field.formatType = CAN_FD_FORMAT; //CAN FD frames 
	Transmission.field.frameType = CAN_FRAME_DATA; //Data frame
	Transmission.field.idType = CAN_FRAME_STD; //Standard ID
	Transmission.msgId = 0x100; //ID of 0x100
	Transmission.data = (uint8_t*) can_buffer; //transmit the data from the data bytes
	if (CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(TXQ) & CAN_TX_FIFO_AVAILABLE))//ensure that the TXQ has space for a message
	{
		CAN1_Transmit(TXQ, &Transmission); //transmit frame
	}

}
