/*******************************************************************************
Main Source File

Company:
Microchip Technology Inc.

File Name:
main.c

Summary:
This file contains the "main" function for a project.

Description:
This file contains the "main" function for a project.  The
"main" function calls the "SYS_Initialize" function to initialize the state
machines of all modules in the system
 *******************************************************************************/

/*******************************************************************************
 * Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software
 * and any derivatives exclusively with Microchip products. It is your
 * responsibility to comply with third party license terms applicable to your
 * use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
 * ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdarg.h>
#include <proc/p32mk0512mcj064.h>
#include "definitions.h"                // SYS function prototypes
#include "../../../../../firmware/src/imu.h"

#define SHOW_DATA
#define USE_SERIAL_DMA

#ifdef USE_SERIAL_DMA
#include "config/pic32mk_mcj_curiosity_pro/peripheral/dmac/plib_dmac.h"
#endif

/* Application's state machine enum */
typedef enum {
	APP_STATE_CAN_RECEIVE,
	APP_STATE_CAN_TRANSMIT,
	APP_STATE_CAN_IDLE,
	APP_STATE_CAN_USER_INPUT,
	APP_STATE_CAN_XFER_SUCCESSFUL,
	APP_STATE_CAN_XFER_ERROR
} APP_STATES;

typedef enum {
	CAN_NULL,
	CAN_IMU_DATA,
	CAN_IMU_INFO,
	CAN_IMU_RAW,
	CAN_IMU_GET,
	CAN_IMU_SET,
	CAN_STAT,
	CAN_MISC,
	CAN_FFT_LO,
	CAN_FFT_HI,
} CANFD_MESSAGE;

sSensorData_t *accel;
imu_cmd_t *imu;
sFFTData_t *fft;


/* set format attribute for the vararg function */
void PrintFormattedData(const char * format, ...) __attribute__((format(printf, 1, 2)));

uint32_t fft_bin_total(sFFTData_t *, uint32_t);

/* Variable to save application state */
static APP_STATES state = APP_STATE_CAN_USER_INPUT;
/* Variable to save Tx/Rx transfer status and context */
static volatile uint32_t status = 0;
static volatile uint32_t xferContext = 0;
/* Variable to save Tx/Rx message */
static uint32_t messageID = 0;
static uint8_t message[64];
static uint8_t messageLength = 0;
static uint8_t rx_message[64];
static uint32_t rx_messageID = 0;
static uint8_t rx_messageLength = 0;
static uint32_t timestamp = 0;
static CANFD_MSG_RX_ATTRIBUTE msgAttr = CANFD_MSG_RX_DATA_FRAME;

const char *build_date = __DATE__, *build_time = __TIME__;
uint64_t host_cpu_serial_id = 0x1957;
uint8_t rxe, txe;
uint32_t times = 0;

uint8_t spid[] = {0xb5, 0x62, 0x0A, 0x04, 0x00};

static volatile bool uart1_dma_busy = false, uart2_dma_busy = false;
char uart_buffer[256];

// *****************************************************************************
// *****************************************************************************
// Section: Local functions
// *****************************************************************************
// *****************************************************************************

/* This function will be called by CAN PLIB when transfer is completed */
// *****************************************************************************

/* void APP_CAN_Callback(uintptr_t context)

  Summary:
    Function called by CAN PLIB upon transfer completion

  Description:
    This function will be called by CAN PLIB when transfer is completed.
    In this function, current state of the application is obtained by context
    parameter. Based on current state of the application and CAN error
    state, next state of the application is decided.

  Remarks:
    None.
 */
void APP_CAN_Callback(uintptr_t context)
{
	xferContext = context;

	/* Check CAN Status */
	status = CAN1_ErrorGet();
#ifndef SHOW_DATA
	printf("\rCB status %d\r\n", status);
#endif

	if ((status & (CANFD_ERROR_TX_RX_WARNING_STATE | CANFD_ERROR_RX_WARNING_STATE |
		CANFD_ERROR_TX_WARNING_STATE | CANFD_ERROR_RX_BUS_PASSIVE_STATE |
		CANFD_ERROR_TX_BUS_PASSIVE_STATE | CANFD_ERROR_TX_BUS_OFF_STATE)) == CANFD_ERROR_NONE) {
		switch ((APP_STATES) context) {
		case APP_STATE_CAN_RECEIVE:
		case APP_STATE_CAN_TRANSMIT:
		{
			state = APP_STATE_CAN_XFER_SUCCESSFUL;
			break;
		}
		default:
			break;
		}
	} else {
		state = APP_STATE_CAN_XFER_ERROR;

	}
}

void APP_CAN_Error_Callback(uintptr_t context)
{
	xferContext = context;

	/* Check CAN Status */
	status = CAN1_ErrorGet();
#ifndef SHOW_DATA
	printf("\rCEB status %d\r\n", status);
#endif
	LED_Set();
}

void print_menu(void)
{
#ifndef SHOW_DATA
	printf("Menu :\r\n"
		"  -- Select the action:\r\n"
		"  1: Send FD standard message with ID: 0x45A and 64 byte data 0 to 63. \r\n"
		"  2: Send normal standard message with ID: 0x469 and 8 byte data 0 to 7. \r\n"
		"  3: To receive CAN FD or Normal message \r\n"
		"  m: Display menu \r\n\r\n");
#endif
}

void PrintFormattedData(const char * format, ...)
{
	va_list args = {0};
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#ifdef USE_SERIAL_DMA
void UART1DmaChannelHandler_State(DMAC_TRANSFER_EVENT, uintptr_t);
void UART1DmaWrite(char *, uint32_t);

/*
 * end of uart buffer complete flag handler callback
 * interrupt handler for the completion of buffer transfer.
 */
void UART1DmaChannelHandler_State(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
	uart1_dma_busy = false;
	//	LEDY_Clear(); // serial trace signal
}

/*
 * DMA uart serial function
 * triggers the DMA transfer and returns, only one interrupt happens at the end of transfer
 */
void UART1DmaWrite(char * buffer, uint32_t len)
{
	while (uart1_dma_busy || U1STAbits.UTXBF) { // should never wait in normal operation
	};

	uart1_dma_busy = true; // in process flag
	DMAC_ChannelTransfer(DMAC_CHANNEL_7, (const void *) buffer, (size_t) len, (const void*) &U1TXREG, (size_t) 1, (size_t) 1);
}

void UART2DmaChannelHandler_State(DMAC_TRANSFER_EVENT, uintptr_t);
void UART2DmaWrite(char *, uint32_t);

/*
 * end of uart buffer complete flag handler callback
 * interrupt handler for the completion of buffer transfer.
 */
void UART2DmaChannelHandler_State(DMAC_TRANSFER_EVENT event, uintptr_t contextHandle)
{
	uart2_dma_busy = false;
	LEDY_Clear(); // serial trace signal
}

/*
 * DMA uart serial function
 * triggers the DMA transfer and returns, only one interrupt happens at the end of transfer
 * RC2 pin 4 connector J503
 */
void UART2DmaWrite(char * buffer, uint32_t len)
{
	while (uart2_dma_busy || U2STAbits.UTXBF) { // should never wait in normal operation
	};

	uart2_dma_busy = true; // in process flag
	DMAC_ChannelTransfer(DMAC_CHANNEL_0, (const void *) buffer, (size_t) len, (const void*) &U2TXREG, (size_t) 1, (size_t) 1);
}
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main(void)
{
	uint8_t user_input = 0;
	uint8_t count = 0;
	bool msg_ready = false;
	uint64_t * hcid = (uint64_t *) & DEVSN0; // set pointer to 64-bit cpu serial number

	/* Initialize all modules */
	SYS_Initialize(NULL);

	host_cpu_serial_id = *hcid; // get the CPU device 64-bit serial number and use that as a HOST ID

#ifdef USE_SERIAL_DMA
	DMAC_ChannelCallbackRegister(DMAC_CHANNEL_7, UART1DmaChannelHandler_State, 0); // end of UART buffer transfer interrupt function
	DMAC_ChannelCallbackRegister(DMAC_CHANNEL_0, UART2DmaChannelHandler_State, 0); // end of UART buffer transfer interrupt function
#endif

#ifndef SHOW_DATA
	printf("\r\nPIC32 %s Host Controller %s %s %s ---\r\n", IMU_ALIAS, IMU_DRIVER, build_date, build_time);
	print_menu();
#endif
	/* Prepare the message to send */
	for (count = 0; count < 64; count++) {
		message[count] = count;
	}

	LED_Clear();
	LEDY_Clear();

	UART1_ErrorGet(); // clear UART junk
	while (true) {
		if (state == APP_STATE_CAN_USER_INPUT) {
			user_input = 'n';
			/* Read user input */
			if (UART1_ReceiverIsReady()) {
				UART1_Read((void *) &user_input, 1);
			} else {
				if (CAN1_InterruptGet(2, 0x1f)) {
					user_input = '3';
				}
			}

			switch (user_input) {
			case '1':
#ifndef SHOW_DATA
				printf(" Transmitting CAN FD Message:");
#endif
				CAN1_CallbackRegister(APP_CAN_Callback, (uintptr_t) APP_STATE_CAN_TRANSMIT, 1);
				CAN1_ErrorCallbackRegister(APP_CAN_Error_Callback, (uintptr_t) APP_STATE_CAN_RECEIVE);
				state = APP_STATE_CAN_IDLE;
				messageID = 0x45A;
				messageLength = 64;
				if (CAN1_MessageTransmit(messageID, messageLength, message, 1, CANFD_MODE_FD_WITH_BRS, CANFD_MSG_TX_DATA_FRAME) == false) {
#ifndef SHOW_DATA
					printf("CAN1_MessageTransmit request has failed\r\n");
#endif
				}
				break;
			case '2':
#ifndef SHOW_DATA
				printf(" Transmitting CAN Normal Message:");
#endif
				CAN1_CallbackRegister(APP_CAN_Callback, (uintptr_t) APP_STATE_CAN_TRANSMIT, 1);
				CAN1_ErrorCallbackRegister(APP_CAN_Error_Callback, (uintptr_t) APP_STATE_CAN_RECEIVE);
				state = APP_STATE_CAN_IDLE;
				messageID = 0x469;
				messageLength = 8;
				if (CAN1_MessageTransmit(messageID, messageLength, message, 1, CANFD_MODE_NORMAL, CANFD_MSG_TX_DATA_FRAME) == false) {
#ifndef SHOW_DATA
					printf("CAN1_MessageTransmit request has failed\r\n");
#endif
				}
				break;
			case '3':
				msg_ready = CAN1_InterruptGet(2, 0x1f);
				if (msg_ready) {
#ifndef SHOW_DATA
					printf(" Waiting for message: \r\n");
#endif
					CAN1_CallbackRegister(APP_CAN_Callback, (uintptr_t) APP_STATE_CAN_RECEIVE, 2);
					state = APP_STATE_CAN_IDLE;
					memset(rx_message, 0x00, sizeof(rx_message));

					/* Receive New Message */
					if (CAN1_MessageReceive(&rx_messageID, &rx_messageLength, rx_message, &timestamp, 2, &msgAttr) == false) {
#ifndef SHOW_DATA
						printf("CAN1_MessageReceive request has failed\r\n");
#endif
					}
					LEDY_Clear();
				} else {
					state = APP_STATE_CAN_USER_INPUT;
#ifndef SHOW_DATA
					printf(" No message: \r\n");
					print_menu();
#endif
				}
				break;
			case 'm':
#ifndef SHOW_DATA
				print_menu();
#endif
				break;
			case 'n':
				break;
			default:
#ifndef SHOW_DATA
				printf(" Invalid Input \r\n");
				print_menu();
#endif
				break;
			}
		}
		/* Check the application's current state. */
		switch (state) {
		case APP_STATE_CAN_IDLE:
		{
			/* Application can do other task here */
			break;
		}
		case APP_STATE_CAN_XFER_SUCCESSFUL:
		{
			while (uart1_dma_busy || U1STAbits.UTXBF) { // should never wait in normal operation
			};
			while (uart2_dma_busy || U2STAbits.UTXBF) { // should never wait in normal operation
			};
			if ((APP_STATES) xferContext == APP_STATE_CAN_RECEIVE) {

				/* Print message to Console */
				uint8_t length = rx_messageLength;
				uint16_t * mtype = (uint16_t *) & rx_message[0];
#ifndef SHOW_DATA    
				PrintFormattedData(" Message - Timestamp : 0x%x ID : 0x%x Length : 0x%x ", timestamp, (unsigned int) rx_messageID, (unsigned int) rx_messageLength);
				printf("Message : ");
#endif
				sprintf(uart_buffer, "-1, Bad  Message ID code\r\n");
				if (*mtype == CAN_IMU_DATA) {
					accel = (sSensorData_t *) rx_message;
#ifndef SHOW_DATA
					printf("%6.3f,%6.3f,%6.3f,%6.2f,%6.2f,%6.2f, sensor TS 0X%x, %u, %u\r\n", accel->x, accel->y, accel->z, accel->xa, accel->ya, accel->za, accel->sensortime, length, rx_message[0]);
#else
					length++;
					sprintf(uart_buffer, "%3d,%7X,%7.4f,%7.4f,%7.4f,%7.4f,%7.4f,%7.4f,%7.4f,%7.4f,%7.4f,%7.1f,%s\r\n", accel->id, rx_messageID, accel->x, accel->y, accel->z, accel->xa, accel->ya, accel->za, accel->xerr, accel->yerr, accel->zerr, (double) accel->sensortime, IMU_ALIAS);
#endif
				}
				if (*mtype == CAN_IMU_INFO) {
					imu = (imu_cmd_t *) rx_message;
					imu->host_serial_id = host_cpu_serial_id;
					sprintf(uart_buffer, "%3d,%7X,%7X,%3d,%3d,%3d,%18llX,%s\r\n", imu->id, imu->board_serial_id, rx_messageID, imu->device, imu->acc_range, imu->features, host_cpu_serial_id, IMU_ALIAS);
#ifndef SHOW_DATA
					printf("%u,%u,%u,%u sensor info %u\r\n", imu->device, imu->acc_range, imu->acc_range_scl, imu->angles, rx_message[0]);
#endif
				}
				if (*mtype == CAN_FFT_LO) {
					fft = (sFFTData_t *) rx_message;
					sprintf(uart_buffer, "%3d,%7X,%3d,%s\r\n", fft->id, rx_messageID, fft_bin_total(fft, 16), IMU_ALIAS);
#ifndef SHOW_DATA
#endif
				}
				if (*mtype == CAN_FFT_HI) {
					fft = (sFFTData_t *) rx_message;
					sprintf(uart_buffer, "%3d,%7X,%3d,%s\r\n", fft->id, rx_messageID, fft_bin_total(fft, 0), IMU_ALIAS);
#ifndef SHOW_DATA
#endif
				}
				if (*mtype == CAN_NULL) {
					sprintf(uart_buffer, "0,NULL Message with 0 ID code\r\n");
				}
				LED_Set(); // cpu trace signal
				LEDY_Set(); // serial trace signal
//				UART1DmaWrite(uart_buffer, strlen(uart_buffer));
				UART2DmaWrite(uart_buffer, strlen(uart_buffer)); // send data to the ETH module
				LED_Clear();
#ifndef SHOW_DATA
				CAN1_ErrorCountGet(&txe, &rxe);
				printf("ErrorT %d ", txe);
				printf("ErrorR %d ", rxe);
				printf("Can INT %d ", CAN1_InterruptGet(1, 0x1f));
				printf("FIFO %X ", CFD1FIFOSTA2);
				printf("Update %u ", ++times);
				printf("ERR %X ", CFD1TREC);
				printf("Ce0 %X ", CFD1BDIAG0);
				printf("Ce1 %X \r\n", CFD1BDIAG1);
				printf("\r\n");
#endif
			} else if ((APP_STATES) xferContext == APP_STATE_CAN_TRANSMIT) {
			}
#ifndef SHOW_DATA
			print_menu();
#endif
			state = APP_STATE_CAN_USER_INPUT;
			break;
		}
		case APP_STATE_CAN_XFER_ERROR:
		{
			if ((APP_STATES) xferContext == APP_STATE_CAN_RECEIVE) {
#ifndef SHOW_DATA
				printf("Error in received message");
#endif
			} else {
#ifndef SHOW_DATA
				printf("Failed \r\n");
#endif
			}
#ifndef SHOW_DATA
			print_menu();
#endif
			state = APP_STATE_CAN_USER_INPUT;
			break;
		}
		default:
			break;
		}

	}

	/* Execution should not come here during normal operation */

	return( EXIT_FAILURE);
}

uint32_t fft_bin_total(sFFTData_t * fftt, uint32_t trim)
{
	uint32_t total = 0;

	if (trim > 25) {
		trim = 25;
	}

	for (int32_t i = trim; i < 50; i++) {
		total += fftt->buffer[i];
	}
	return total;
}
/*******************************************************************************
 End of File
 */
