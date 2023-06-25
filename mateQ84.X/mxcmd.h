/* 
 * File:   mxcmd.h
 * Author: root
 *
 * Created on June 2, 2023, 6:16 AM
 */

#ifndef MXCMD_H
#define	MXCMD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "../eadog.h"
#include "../timers.h"

#define VER	1
	const char build_version[] = "V1.19 FM80 Q84";

#define MAX_B_BUF	96
#define IO_TEST

#define	FM_BUFFER	32
#define BUFFER_SPACING	2
#define SPINNER_SPEED	200
#define LP_BUFFER_SIZE	9

	const uint16_t cmd_id[] = {0x100, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02};
	const uint16_t cmd_status[] = {0x100, 0x02, 0x01, 0xc8, 0x00, 0x00, 0x00, 0xcb};
	const uint16_t cmd_mx_status[] = {0x100, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x05};
	const uint16_t cmd_panelv[] = {0x100, 0x02, 0x01, 0xc6, 0x00, 0x00, 0x00, 0xc9};
	const uint16_t cmd_batteryv[] = {0x100, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0a};
	const uint16_t cmd_batterya[] = {0x100, 0x02, 0x01, 0xc7, 0x00, 0x00, 0x00, 0xca};
	const uint16_t cmd_watts[] = {0x100, 0x02, 0x01, 0x6a, 0x00, 0x00, 0x00, 0x6d};
	const uint16_t cmd_misc[] = {0x100, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02}; // example MX80 command ID request

	enum status_type {
		STATUS_SLEEPING = 0,
		STATUS_FLOATING = 1,
		STATUS_BULK = 2,
		STATUS_ABSORB = 3,
		STATUS_EQUALIZE = 4,
		STATUS_LAST,
	};

	const char state_name [][12] = {
		"Sleeping",
		"Floating",
		"Bulk",
		"Absorb",
		"Equalize",
		"Last",
	};

	const char canbus_name [][12] = {
		" Offline",
		"CANBUS",
	};

	const char modbus_name [][12] = {
		" Offline",
		"MODBUS",
	};

	typedef struct {
		uint8_t a[16]; // raw_ah(part2)
	} mx_status_packed_t;

	typedef struct B_type {
		volatile bool ten_sec_flag, one_sec_flag;
		uint16_t pacing, rx_count, flush;
		volatile bool mx80_online;
		volatile uint8_t canbus_online, modbus_online;
	} B_type;

	extern void onesec_io(void);
	extern void tensec_io(void);
	extern void FM_io(void);
	extern uint8_t FM_tx(const uint16_t *, uint8_t);
	extern bool FM_tx_empty(void);
	extern uint8_t FM_rx(uint16_t *);
	extern bool FM_rx_ready(void);
	extern uint8_t FM_rx_count(void);
	extern void FM_restart(void);
	extern void wdtdelay(const uint32_t);
	extern float lp_filter(const float, const uint8_t, const int8_t);

	extern B_type B;

#ifdef	__cplusplus
}
#endif

#endif	/* MXCMD_H */

