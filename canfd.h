/* 
 * File:   canfd.h
 * Author: root
 *
 * Created on June 16, 2023, 12:55 PM
 */

#ifndef CANFD_H
#define	CANFD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "qconfig.h"
#include "mateQ84.X/mxcmd.h"
#include "modbus_master.h"

#define	EMON_M	0x157
#define EMON_S	0x161

	void Can1FIFO1NotEmptyHandler(void);
	void Can1FIFO2NotEmptyHandler(void);

	extern char can_buffer[MAX_B_BUF];
	void can_fd_tx(void);
	void can_fd_rx(void);

#ifdef	__cplusplus
}
#endif

#endif	/* CANFD_H */

