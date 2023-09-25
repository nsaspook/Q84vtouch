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

#define TEN_SEC_HOUR	360.0f
#define BM_CM	0x57
#define BM_VER	1
#define BM_UPDATE	3600	// seconds between EEPROM updates, sleeping
#define BM_UPDATE_RUN	1800	// while running

	/*
	 * Energy Battery Bank 
	 * 24V LiFePO4 Battery Parameters
	 */
#define BAT_VOLT	25.6f
#define BAT_AH		200.0f	
#define BAT_ENERGY	BAT_VOLT*BAT_AH*TEN_SEC_HOUR // nominal battery voltage and AH rating for 10 second updates
#define BAT_ENERGY_LOW	BAT_ENERGY/0.5f
#define BAT_OVER_VOLT	30.0f
#define BAT_OVER_RECON	28.4f
#define BAT_UNDER_VOLT	23.2f
#define BAT_LOW_DISC	21.6f
#define BAT_LOW_RECON	24.8f
#define BAT_EFF_VAL	0.985f	//  battery storage energy efficiency
#define BAT_CYCLES	8
#define BAT_CHARGED_W	BAT_AH
#define BAT_DAY_COUNT	3	// number of reports before updates
	/*
	 * System correction factors
	 */
#define IDLE_DRAIN	10.0f	// system operational drain losses in Wh
#define INV_EFF_VAL	1.06f	// DC watts to AC watt inverter correction

	// EEPROM data storage structure

	typedef struct EB_data {
		uint8_t checkmark;
		uint8_t version;
		bool loaded;
		float FMw, FMpv, FMa, FMbv, ENw, ENva, ENvar, ENac;
		float volt_whole, bat_amp_whole;
		float bat_energy;
		uint16_t cc_mode, bat_cycles, bat_mode, time, date;
		uint32_t bat_time, fm80_time;
		uint16_t crc;
	} EB_data;

	/*
	 * logging data format for printf and variables
	 */
	const char log_format[] = "^,%d.%01d,%d.%01d,%d,%d.%01d,%d,%.1f,%.1f,%d,%.1f,%.1f,%.1f,%4.1f,%.2f,%u,%5.3f,%5.3f,%u,%s,~\r\n";
#define LOG_VARS	abuf[3] - 128, abuf[1]&0x0f, vw, vf, abuf[2] - 128, volt_whole, volt_fract, panel_watts, pv_Wh_daily, ac_Wh_daily, cc_mode, ((float) em.wl1) / 10.0f, ((float) em.val1) / 10.0f, ((float) em.varl1) / 10.0f, ((float) em.vl1l2) / 10.0f, EBD.bat_energy / 3600.0f, EBD.bat_cycles, ((float) em.pfl1) / 1000.0f, ((float) emt.hz) / 1000.0f, B.rx_count++,buffer

#define BVSOC_SLOTS     12      // 24V LiFePO4 Battery to SOC data table slots
	const uint32_t BVSOC_TABLE[BVSOC_SLOTS][2] = {
		20000, 0,
		24000, 5,
		25000, 14,
		25600, 17,
		25800, 20,
		26000, 30,
		26200, 40,
		26400, 70,
		26600, 90,
		26800, 99,
		27200, 100,
		29200, 100 // charging voltage guess
	};

	typedef uint16_t device_id_data_t;
	typedef uint24_t device_id_address_t;
	device_id_data_t DeviceID_Read(device_id_address_t);

	extern EB_data EBD, EBD_ptr;
	extern uint16_t EBD_update;
	extern struct tm *can_newtime;
	extern float pv_Wh_daily, pv_Wh_daily_prev, ac_Wh_daily, ac_Wh_daily_prev;
	extern void run_night_to_day(void);
	extern void run_day_to_night(void);

	bool initbm_data(uint8_t *);
	void wr_bm_data(uint8_t *);
	void get_bm_data(EB_data *);
	void compute_bm_data(EB_data *);
	void update_time(struct tm *, EB_data *);

	void DATAEE_WriteByte(const uint16_t, const uint8_t);
	uint8_t DATAEE_ReadByte(const uint16_t);

	uint16_t Volts_to_SOC(const uint16_t, const uint16_t);

#ifdef	__cplusplus
}
#endif

#endif	/* BATMON_H */

