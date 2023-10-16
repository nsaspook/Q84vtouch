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

#define DATA_DEBUG

#ifdef CAN_REMOTE
#define LCD_MIRROR
#endif

#define USE_FD	// select classic or FD
#define CANFD_BYTES     64
#define CANFD_NBUF      3
#define CAN_RX_TRIES	8
#define CAN_REC_BUFFERS	4
#define CAN_LOW_BUF     0
#define CAN_HIGH_BUF	1
#define CAN_INFO_BUF	2
#define CAN_ERROR_BUF	3
#define CAN_MIRRORS	4

#define	EMON_M	0x1	// FM80 host
#define EMON_SL	0x2	// remote display lower data
#define EMON_SU	0x3	// remote display upper data
#define EMON_MR	0x4	// LCD mirror data [0..3]]
#define EMON_TM	0xA	// remote time from time server
#define EMON_DS	0xB	// remote display server
#define EMON_ER	0xF	// error reporting
#define EMON_CO	0xC	// configuration reporting
#define EMON_DA	0xD	// 64 byte binary blob

#define MIRR0R_BUF	CANFD_NBUF-1 // LCD mirror CANBUS buffer
#define LCD_BUF_SIZ	22

	typedef struct {
		uint32_t rec_count;
		bool rec_flag;
	} can_rec_count_t;

	typedef struct {
		volatile uint8_t blob[CANFD_BYTES];
		volatile bool tx_flag, rx_flag;
	} blob_type;

	/*
	 * testing blob data feature for logs
	 */
	union blob_log {
		blob_type blob;
		mx_logpage_t log;
	};

	extern volatile can_rec_count_t can_rec_count;
	extern CAN_MSG_OBJ msg[3];
	extern volatile uint8_t rxMsgData[CAN_REC_BUFFERS][CANFD_BYTES];
	extern time_t can_timer;
	extern struct tm *can_newtime;

	void TXQNotFullHandler(void);
	void Can1FIFO1NotEmptyHandler(void);

	extern char info_buffer[MAX_B_BUF], log_buffer[MAX_B_BUF];
	void can_fd_tx(void);
	void can_setup(void);
	void can_fd_lcd_mirror(const uint8_t, char *);
	void can_mirror_print(void);
	void can_blob_set(blob_type*);
	blob_type* can_blob_get(blob_type*);
	bool get_blob_tx(void);
	bool get_blob_rx(void);

#ifdef	__cplusplus
}
#endif

#endif	/* CANFD_H */

