/* 
 * File:   batmon.h
 * Author: root
 *
 * Created on June 25, 2023, 10:39 AM
 */

#ifndef BATMON_H
#define	BATMON_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "qconfig.h"
#include "modbus_master.h"
#include "mateQ84.X/mxcmd.h"

#define BM_CM	0x57
#define BM_VER	1
#define BAT_ENERGY	25.6f*200.0f*360.0f // nominal battery voltage and AH rating for 10 second updates

#define BAT_OVER_VOLT	30.0f
#define BAT_OVER_RECON	28.4f
#define BAT_UNDER_VOLT	23.2f
#define BAT_LOW_DISC	21.6f
#define BAT_LOW_RECON	24.8f
#define IDLE_DRAIN	10.0f	// system operational losses in watts

#define INV_EFF_VAL	1.06f	// DC watts to AC watt inverter correction
#define BAT_EFF_VAL	0.985f	//  battery storage energy efficiency

#define BM_UPDATE	3600	// seconds between EEPROM updates, sleeping
#define BM_UPDATE_RUN	1800	// while running

#define BAT_CYCLES	12

	typedef struct EB_data {
		uint8_t checkmark;
		uint8_t version;
		bool loaded;
		float FMw, FMpv, FMa, FMbv, ENw, ENva, ENvar, ENac;
		float volt_whole, bat_amp_whole;
		float bat_energy;
		uint16_t cc_mode, bat_cycles, bat_mode;
		uint32_t bat_time;
		uint16_t crc;
	} EB_data;

	extern EB_data EBD, EBD_ptr;
	extern uint16_t EBD_update;

	bool initbm_data(uint8_t *);
	void wr_bm_data(uint8_t *);
	void get_bm_data(EB_data *);
	void compute_bm_data(EB_data *);

	void DATAEE_WriteByte(uint16_t, uint8_t);
	uint8_t DATAEE_ReadByte(uint16_t);

#ifdef	__cplusplus
}
#endif

#endif	/* BATMON_H */

