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

#define CAN_DEBUG	// can status on LCD
#define USE_FD	// select classic or FD

#define	EMON_M	0x1	// FM80 host
#define EMON_S	0x2	// remote display 

	typedef struct {
		uint32_t rec_count;
		bool rec_flag;
	} can_rec_count_t;

	extern volatile can_rec_count_t can_rec_count;
	extern CAN_MSG_OBJ msg;

	void Can1FIFO1NotEmptyHandler(void);

	extern char can_buffer[MAX_B_BUF];
	void can_fd_tx(void);

#ifdef	__cplusplus
}
#endif

#endif	/* CANFD_H */

