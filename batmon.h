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
#define BAT_ENERGY	24.0*25.0*360 // nominal battery voltage and AH rating for 10 second updates
	
#define BM_UPDATE	3600	// seconds between EEPROM updates

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

