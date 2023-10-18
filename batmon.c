#include "batmon.h"
#include "dio.h"

EB_data EBD = {
	.checkmark = BM_CM,
	.version = BM_EEPROM_VER,
	.loaded = false,
	.bat_cycles = 0,
	.bat_energy = BAT_ENERGY,
	.bat_mode = 0,
	.bat_time = 0,
	.crc = 0,
	.alt_display = 0,
};

uint16_t EBD_update = 0; // EEPROM write counter for BM_UPDATE
float pv_Wh_daily = 0.0f, pv_Wh_daily_prev = 0.0f, ac_Wh_daily = 0.0f, ac_Wh_daily_prev = 0.0f;

/*
 * get the pointer to the system EEPROM save data
 */
EB_data *get_EEPROM(void)
{
	return &EBD;
}

/*
 * load EEPROM data to energy if correctly formatted
 */
bool initbm_data(uint8_t * EB)
{
	EB_data *ebd = (EB_data*) EB;

	if (DATAEE_ReadByte(0) != BM_CM) {
		ebd->loaded = false;
		return false;
	} else {
		for (uint16_t i = 0; i < sizeof(EB_data); i++) {
			EB[i] = DATAEE_ReadByte(i);
		}
		ebd->loaded = true;
	}
	return true;
}

/*
 * write energy array to EEPROM
 */
void wr_bm_data(uint8_t * EB)
{
	EB_data *ebd = (EB_data*) EB;

	EB[0] = BM_CM;
	ebd->crc = 0;
	ebd->crc = crc16(EB, sizeof(EB_data) - 2); // exclude crc bytes
	ebd->bat_time = ++ebd->bat_time;

	if ((ebd->bat_time) % BAT_CYCLES == 0) {
		ebd->bat_cycles++;
	}

	for (uint16_t i = 0; i < sizeof(EB_data); i++) {
		DATAEE_WriteByte(i, EB[i]);
	}
}

/*
 * update energy values and
 * READ commands from the logging serial port
 * F top-off bank energy to MAX
 */
void get_bm_data(EB_data * EB)
{
	uint8_t rxData = 0;
	char s_buffer[22];

	EB->ENac = (float) em.vl1l2 / 10.0f;
	EB->ENva = (float) em.val1 / 10.0f;
	EB->ENw = (float) em.wl1 / 10.0f;
	EB->ENvar = (float) em.varl1 / 10.0f;
	EB->FMw = (float) panel_watts;
	EB->FMpv = (float) volt_whole;
	EB->cc_mode = cc_mode;
	EB->bat_amp_whole = (float) bat_amp_whole;
	EB->volt_whole = (float) vw;

	/*
	 * check for commands using the logging serial port
	 * 'F' FULL,	reset battery energy to max and increase one battery charge cycle
	 */
	if (UART2_is_rx_ready()) {
		rxData = UART2_Read();
		switch (rxData) {
		case 'A': // alternative data display for rows 2 and 3
			B.alt_display = MAX_ALT_DIS;
		case 'a':
			B.alt_display++;
			if (B.alt_display > MAX_ALT_DIS) {
				B.alt_display = 0;
			}
			EB->alt_display = B.alt_display;
			break;
		case 'D': // display time
		case 'd':
			snprintf(s_buffer, 21, "%s", asctime(can_newtime));
			eaDogM_Scroll_String(s_buffer);
			break;
		case 'f': // set energy to Full
		case 'F':
			EB->bat_energy = BAT_ENERGY;
			EB->bat_cycles++;
			break;
		case 'e': // set energy to Empty
		case 'E':
			EB->bat_energy = 1;
			EB->bat_cycles++;
			break;
		case 'i': // start Info scroll on display
		case 'I':
			snprintf(s_buffer, 21, "%s %u                  ", ems.serial, ems.year);
			eaDogM_Scroll_String(s_buffer);
			snprintf(s_buffer, 21, "0X%X                   ", emv.firmware);
			eaDogM_Scroll_String(s_buffer);
			snprintf(s_buffer, 21, "0X%X%X%X%X%X%X%X%X         ", B.mui[0], B.mui[1], B.mui[2], B.mui[3], B.mui[4], B.mui[5], B.mui[6], B.mui[7]);
			eaDogM_Scroll_String(s_buffer);
			snprintf(s_buffer, 21, "FM80 FW %X.%X.%X                ", B.fwrev[0], B.fwrev[1], B.fwrev[2]);
			eaDogM_Scroll_String(s_buffer);
			break;
		case 'R': // reset log data command state
		case 'r':
			B.log.select = 0;
		case 'L':// send day log date t logging serial port
		case 'l':
			B.log.select++; // pull the next days log data
			snprintf(s_buffer, 21, "Pwr %5.2fkWpk %5.2fkWh              ", (float) B.log.kilowatts_peak / 1000.0, (float) B.log.kilowatt_hours / 10.0);
			eaDogM_Scroll_String(s_buffer);
			if (rxData == 'L') {
				snprintf(s_buffer, 21, "#,%5.2f,%5.2f,", (float) B.log.kilowatts_peak / 1000.0, (float) B.log.kilowatt_hours / 10.0);
				printf("%s", s_buffer);
			}
			snprintf(s_buffer, 21, "Chg F%imin A%imin                ", B.log.float_time, B.log.absorb_time);
			eaDogM_Scroll_String(s_buffer);
			if (rxData == 'L') {
				snprintf(s_buffer, 21, "%i,%i,", B.log.float_time, B.log.absorb_time);
				printf("%s", s_buffer);
			}
			snprintf(s_buffer, 21, "%iVpk %4.1fApk %iAh       ", B.log.volts_peak, (float) B.log.amps_peak / 10.0, B.log.amp_hours);
			eaDogM_Scroll_String(s_buffer);
			if (rxData == 'L') {
				snprintf(s_buffer, 21, "%i,%4.1f,%i,", B.log.volts_peak, (float) B.log.amps_peak / 10.0, B.log.amp_hours);
				printf("%s", s_buffer);
			}
			snprintf(s_buffer, 21, "%4.1fV %4.1fV :Day %i       ", (float) B.log.bat_max / 10.0, (float) B.log.bat_min / 10.0, B.log.day);
			eaDogM_Scroll_String(s_buffer);
			if (rxData == 'L') {
				snprintf(s_buffer, 21, "%4.1f,%4.1f,%i,", (float) B.log.bat_max / 10.0, (float) B.log.bat_min / 10.0, B.log.day);
				printf("%s^\r\n", s_buffer);
			}
			break;
		case 'W': // Write current state to EEPROM data
		case 'w':
			wr_bm_data((void*) EB);
			MM_ERROR_S;
			break;
		case 'V': // charger on
			CHARGER_RELAY_ON;
			break;
		case 'v': // charger off
			CHARGER_RELAY_OFF;
			break;
		case '!': // all relays off
			all_relays_off();
			break;
		default:
			break;
		}
	}
}

/*
 * track energy usage and storage of the system
 * with LiFePO4 battery chem this is simple, direct with no major secondary effects over the discharge/charge curve
 *
 */
void compute_bm_data(EB_data * EB)
{
	float net_energy, net_balance;

	pv_Wh_daily += (EB->FMw / TEN_SEC_HOUR); // integrate Wh for 10 second updates
	ac_Wh_daily += (EB->ENw / TEN_SEC_HOUR);

	net_balance = EB->FMw - (EB->ENw * INV_EFF_VAL); // make the energy comparison AC -> DC watts equal using inverter losses
	if (net_balance > 0.0001f) { // more energy from panels than current load usage
		net_balance = net_balance * BAT_EFF_VAL; // actual battery energy storage correction, energy in vs energy out losses
		B.net_balance = net_balance;
		B.run_time = (EB->bat_energy / TEN_SEC_HOUR) / IDLE_DRAIN;
		if (B.run_time > BAT_RUN_MAX) {
			B.run_time = BAT_RUN_MAX;
		}
		if (B.run_time < 0.0001f) {
			B.run_time = 0.0001f;
		}
		/*
		 * try to sync BMS charged condition to monitor charged condition and set full energy levels
		 */
		if ((cc_mode == STATUS_FLOATING) && (EB->FMw > BAT_CHARGED_W) && (EB->ENw > BAT_CHARGED_W)) {
			if (!B.FM80_charged) {
				B.FM80_charged = true;
				EB->bat_energy = BAT_ENERGY;
			}
		}
	} else {
		net_balance = net_balance; // net drain, inverter correction already applied: possible future second order corrections here
		B.net_balance = net_balance;
		B.run_time = (EB->bat_energy / TEN_SEC_HOUR) / fabs(net_balance);
		if (B.run_time > BAT_RUN_MAX) {
			B.run_time = BAT_RUN_MAX;
		}
		if (B.run_time < 0.0001f) {
			B.run_time = 0.0001f;
		}
		/*
		 * reset possible battery energy sync function
		 */
		if (cc_mode != STATUS_FLOATING) {
			if (B.FM80_charged && (EB->bat_energy < BAT_ENERGY_LOW)) {
				B.FM80_charged = false;
			}
		}
	}
	net_energy = EB->bat_energy + net_balance; // inverter/battery power conversion correction
	/*
	 * set battery energy limits
	 */
	EB->bat_energy = net_energy - IDLE_DRAIN; // system electronic power drain

	if (EB->bat_energy > BAT_ENERGY) { // limit up energy
		EB->bat_energy = BAT_ENERGY;
	}
	if (EB->bat_energy <= 0.0001f) { // limit down energy
		EB->bat_energy = 0.0001f;
	}

	if (B.pv_update) { // solar day status has changed
		B.pv_update = false;
		if (B.pv_prev == STATUS_SLEEPING) { // day to night update
			run_day_to_night();
		} else { // night to day update
			pv_Wh_daily_prev = pv_Wh_daily;
			ac_Wh_daily_prev = ac_Wh_daily;
			pv_Wh_daily = 0.0001f;
			ac_Wh_daily = 0.0001f;
			run_night_to_day();
		}
	}
}

void DATAEE_WriteByte(const uint16_t bAdd, const uint8_t bData)
{
	uint8_t GIEBitValue = INTCON0bits.GIE;

	//Set NVMADR with the target word address (0x380000 - 0x3803FF)
	NVMADRU = 0x38;
	NVMADRH = (uint8_t) ((bAdd & 0xFF00) >> 8);
	NVMADRL = (uint8_t) (bAdd & 0x00FF);

	//Load NVMDATL with desired byte
	NVMDATL = bData;

	//Set the NVMCMD control bits for DFM Byte Write operation
	NVMCON1bits.NVMCMD = 0b011;

	//Disable all interrupts
	INTCON0bits.GIE = 0;

	//Perform the unlock sequence and start Page Erase
	NVMLOCK = 0x55;
	NVMLOCK = 0xAA;

	//Start DFM write and wait for the operation to complete
	NVMCON0bits.GO = 1;
	while (NVMCON0bits.GO);

	//Restore all the interrupts
	INTCON0bits.GIE = GIEBitValue;

	//Set the NVMCMD control bits for Word Read operation to avoid accidental writes
	NVMCON1bits.NVMCMD = 0b000;
}

uint8_t DATAEE_ReadByte(const uint16_t bAdd)
{
	//Set NVMADR with the target word address (0x380000 - 0x3803FF)
	NVMADRU = 0x38;
	NVMADRH = (uint8_t) ((bAdd & 0xFF00) >> 8);
	NVMADRL = (uint8_t) (bAdd & 0x00FF);

	//Set the NVMCMD control bits for DFM Byte Read operation
	NVMCON1bits.NVMCMD = 0b000;
	NVMCON0bits.GO = 1;

	return NVMDATL;
}

/*
 * static SOC table for LiFePO4
 */
uint16_t Volts_to_SOC(const uint16_t bvw, const uint16_t bvf)
{
	uint8_t slot;
	uint16_t soc = 0;

	/*
	 * walk up the table
	 */
	for (slot = 0; slot < BVSOC_SLOTS; slot++) {
		if ((bvw * 1000 + bvf * 100) > BVSOC_TABLE[slot][0]) {
			soc = (uint16_t) BVSOC_TABLE[slot][1];
		}
	}
	return soc;
}

device_id_data_t DeviceID_Read(device_id_address_t address)
{
	device_id_data_t deviceID;

	//Save the table pointer
	uint32_t tablePointer = ((uint32_t) TBLPTRU << 16) | ((uint32_t) TBLPTRH << 8) | ((uint32_t) TBLPTRL);

	//Load table pointer with Device ID address
	TBLPTRU = (uint8_t) (address >> 16);
	TBLPTRH = (uint8_t) (address >> 8);
	TBLPTRL = (uint8_t) address;

	//Execute table read and increment table pointer
	asm("TBLRD*+");

	deviceID = (device_id_data_t) TABLAT;

	//Execute table read
	asm("TBLRD*");

	deviceID |= (device_id_data_t) (TABLAT << 8);

	//Restore the table pointer
	TBLPTRU = (uint8_t) (tablePointer >> 16);
	TBLPTRH = (uint8_t) (tablePointer >> 8);
	TBLPTRL = (uint8_t) tablePointer;

	return deviceID;
}

/*
 * pack UNIX tm time/date into FM80 compatible 16-bit values
 */
void update_time(struct tm * ts, EB_data * EB)
{
	EB->time = (
		(uint16_t) ((ts->tm_hour & 0x1F) << 11) |
		(uint16_t) ((ts->tm_min & 0x3F) << 5) |
		(uint16_t) ((ts->tm_sec & 0x1F) >> 1)
		);
	EB->date = (
		(uint16_t) (((ts->tm_year - 2000) & 0x7F) << 9) |
		(uint16_t) ((ts->tm_mon & 0x0F) << 5) |
		(uint16_t) (ts->tm_mday & 0x1F)
		);
}