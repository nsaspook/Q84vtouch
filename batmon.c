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
},
EBD_ptr;

uint16_t EBD_update = 0; // EEPROM write counter for BM_UPDATE

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

void wr_bm_data(uint8_t * EB)
{
	EB[0] = BM_CM;
	EBD.crc = 0;
	EBD.crc = crc16(EB, sizeof(EBD) - 2); // exclude crc bytes
	EBD.bat_time = ++EBD.bat_time;

	for (uint16_t i = 0; i < sizeof(EBD); i++) {
		DATAEE_WriteByte(i, EB[i]);
	}
}

void get_bm_data(EB_data * EB)
{
	EB->ENac = lp_filter(((float) em.vl1l2) / 10.0f, F_ac, false);
	EB->ENva = lp_filter(((float) em.val1) / 10.0f, F_wva, false);
	EB->ENw = lp_filter(((float) em.wl1) / 10.0f, F_wac, false);
	EB->ENvar = lp_filter(((float) em.varl1) / 10.0f, F_var, false);
	EB->FMw = (float) panel_watts;
	EB->FMpv = (float) volt_whole;
	EB->cc_mode = cc_mode;
	EB->bat_amp_whole = (float) bat_amp_whole;
	EB->volt_whole = (float) vw;
}

void compute_bm_data(EB_data * EB)
{
	EB->bat_energy = EB->bat_energy + (EB->FMw - EB->ENva);
	if (EB->bat_energy > BAT_ENERGY) {
		EB->bat_energy = BAT_ENERGY;
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
