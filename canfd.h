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

	extern char can_buffer[MAX_B_BUF];
	void can_fd_tx(void);

#ifdef	__cplusplus
}
#endif

#endif	/* CANFD_H */

