#include "batmon.h"

EB_data EBD = {
	.checkmark = BM_CM,
	.version = BM_VER,
	.loaded = false,
	.bat_cycles = 0,
	.bat_energy = BAT_ENERGY,
	.bat_mode = 0,
	.bat_time = 0,
	.crc = 0,
};

uint16_t EBD_update = 0; // EEPROM write counter for BM_UPDATE

/*
 * load EEPROM data to energy if correctly formatted
 */
bool initbm_data(uint8_t * EB)
{
	if (DATAEE_ReadByte(0) != BM_CM) {
		EBD.loaded = false;
		return false;
	} else {
		for (uint16_t i = 0; i < sizeof(EBD); i++) {
			EB[i] = DATAEE_ReadByte(i);
		}
		EBD.loaded = true;
	}
	return true;
}

/*
 * write energy array to EEPROM
 */
void wr_bm_data(uint8_t * EB)
{
	EB[0] = BM_CM;
	EBD.crc = 0;
	EBD.crc = crc16(EB, sizeof(EBD) - 2); // exclude crc bytes
	EBD.bat_time = ++EBD.bat_time;

	if ((EBD.bat_time) % BAT_CYCLES == 0) {
		EBD.bat_cycles++;
	}

	for (uint16_t i = 0; i < sizeof(EBD); i++) {
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
		case 'F':
			EB->bat_energy = BAT_ENERGY;
			EBD.bat_cycles++;
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

	net_balance = EB->FMw - (EB->ENw * INV_EFF_VAL); // make the energy comparison AC -> DC watts equal using inverter losses
	if (net_balance > 0.0001) { // more energy from panels than current load usage
		net_balance = net_balance * BAT_EFF_VAL; // actual battery energy storage correction, energy in vs energy out losses
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
	if (EB->bat_energy <= 0.0f) { // limit down energy
		EB->bat_energy = 0.0001f;
	}
}

void DATAEE_WriteByte(uint16_t bAdd, uint8_t bData)
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

uint8_t DATAEE_ReadByte(uint16_t bAdd)
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
