/*
 * File:   canfd.h
 * Author: root
 *
 * Created on June 16, 2023, 12:55 PM
 */

/*
 * simple CAN FD transfers using blocking TX and interrupts for RX
 */
#ifndef CANFD_H
#define	CANFD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "qconfig.h"
#include "mateQ84.X/mxcmd.h"
#include "modbus_master.h"
#include "batmon.h"

//	#define CAN_DEBUG	// can received data on LCD for remote mate board
#define DATA_DEBUG

#define USE_FD	// select classic or FD
#define CANFD_BYTES	64
#define CAN_RX_TRIES	8
#define CAN_REC_BUFFERS	4
#define CAN_LOW_BUF	0
#define CAN_HIGH_BUF	1
#define CAN_INFO_BUF	2
#define CAN_ERROR_BUF	3

#define	EMON_M	0x1	// FM80 host
#define EMON_SL	0x2	// remote display lower data
#define EMON_SU	0x3	// remote display upper data
#define EMON_TM	0xA	// remote time from time server
#define EMON_DS	0xB	// remote display server
#define EMON_ER	0xF	// error reporting
#define EMON_CO	0xC	// configuration reporting

	typedef struct {
		uint32_t rec_count;
		bool rec_flag;
	} can_rec_count_t;

	extern volatile can_rec_count_t can_rec_count;
	extern CAN_MSG_OBJ msg[2];
	extern volatile uint8_t rxMsgData[CAN_REC_BUFFERS][CANFD_BYTES];
	extern time_t can_timer;
	extern struct tm *can_newtime;

	void Can1FIFO1NotEmptyHandler(void);

	extern char can_buffer[MAX_C_BUF], info_buffer[MAX_B_BUF];
	void can_fd_tx(void);
	void can_setup(void);

#ifdef	__cplusplus
}
#endif

#endif	/* CANFD_H */

