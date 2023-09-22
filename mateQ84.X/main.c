/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
    Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
    Device            :  PIC18F14Q41
    Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
 */
#pragma warning disable 520
#pragma warning disable 1090
#pragma warning disable 1498
#pragma warning disable 2053

// PIC18F47Q84 Configuration Bit Settings
// 'C' source line config statements
// CONFIG1
#pragma config FEXTOSC = ECH    // External Oscillator Selection (EC (external clock) above 8 MHz)
#pragma config RSTOSC = EXTOSC_4PLL// Reset Oscillator Selection (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)

// CONFIG2
#pragma config CLKOUTEN = ON    // Clock out Enable bit (CLKOUT function is enabled)
#pragma config PR1WAY = OFF     // PRLOCKED One-Way Set Enable bit (PRLOCKED bit can be set and cleared repeatedly)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config JTAGEN = OFF     // JTAG Enable bit (Disable JTAG Boundary Scan mode, JTAG pins revert to user functions)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config FCMENP = ON      // Fail-Safe Clock Monitor -Primary XTAL Enable bit (FSCM timer will set FSCMP bit and OSFIF interrupt on Primary XTAL failure)
#pragma config FCMENS = ON      // Fail-Safe Clock Monitor -Secondary XTAL Enable bit (FSCM timer will set FSCMS bit and OSFIF interrupt on Secondary XTAL failure)

// CONFIG3
#pragma config MCLRE = EXTMCLR  // MCLR Enable bit (If LVP = 0, MCLR pin is MCLR; If LVP = 1, RE3 pin function is MCLR )
#pragma config PWRTS = PWRT_OFF // Power-up timer selection bits (PWRT is disabled)
#pragma config MVECEN = ON      // Multi-vector enable bit (Multi-vector enabled, Vector table used for interrupts)
#pragma config IVT1WAY = ON     // IVTLOCK bit One-way set enable bit (IVTLOCKED bit can be cleared and set only once)
#pragma config LPBOREN = OFF    // Low Power BOR Enable bit (Low-Power BOR disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled , SBOREN bit is ignored)

// CONFIG4
#pragma config BORV = VBOR_1P9  // Brown-out Reset Voltage Selection bits (Brown-out Reset Voltage (VBOR) set to 1.9V)
#pragma config ZCD = OFF        // ZCD Disable bit (ZCD module is disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON)
#pragma config PPS1WAY = OFF    // PPSLOCK bit One-Way Set Enable bit (PPSLOCKED bit can be set and cleared repeatedly (subject to the unlock sequence))
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (HV on MCLR/VPP must be used for programming)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Extended Instruction Set and Indexed Addressing Mode disabled)

// CONFIG5
#pragma config WDTCPS = WDTCPS_31// WDT Period selection bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled; SWDTEN is ignored)

// CONFIG6
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)

// CONFIG7
#pragma config BBSIZE = BBSIZE_512// Boot Block Size selection bits (Boot Block size is 512 words)
#pragma config BBEN = OFF       // Boot Block enable bit (Boot block disabled)
#pragma config SAFEN = OFF      // Storage Area Flash enable bit (SAF disabled)
#pragma config DEBUG = OFF      // Background Debugger (Background Debugger disabled)

// CONFIG8
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block not Write protected)
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers not Write protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not Write protected)
#pragma config WRTSAF = OFF     // SAF Write protection bit (SAF not Write Protected)
#pragma config WRTAPP = OFF     // Application Block write protection bit (Application Block not write protected)

// CONFIG9
#pragma config BOOTPINSEL = RC5 // CRC on boot output pin selection (CRC on boot output pin is RC5)
#pragma config BPEN = OFF       // CRC on boot output pin enable bit (CRC on boot output pin disabled)
#pragma config ODCON = OFF      // CRC on boot output pin open drain bit (Pin drives both high-going and low-going signals)

// CONFIG10
#pragma config CP = OFF         // PFM and Data EEPROM Code Protection bit (PFM and Data EEPROM code protection disabled)

// CONFIG11
#pragma config BOOTSCEN = OFF   // CRC on boot scan enable for boot area (CRC on boot will not include the boot area of program memory in its calculation)
#pragma config BOOTCOE = HALT   // CRC on boot Continue on Error for boot areas bit (CRC on boot will stop device if error is detected in boot areas)
#pragma config APPSCEN = OFF    // CRC on boot application code scan enable (CRC on boot will not include the application area of program memory in its calculation)
#pragma config SAFSCEN = OFF    // CRC on boot SAF area scan enable (CRC on boot will not include the SAF area of program memory in its calculation)
#pragma config DATASCEN = OFF   // CRC on boot Data EEPROM scan enable (CRC on boot will not include data EEPROM in its calculation)
#pragma config CFGSCEN = OFF    // CRC on boot Config fuses scan enable (CRC on boot will not include the configuration fuses in its calculation)
#pragma config COE = HALT       // CRC on boot Continue on Error for non-boot areas bit (CRC on boot will stop device if error is detected in non-boot areas)
#pragma config BOOTPOR = OFF    // Boot on CRC Enable bit (CRC on boot will not run)

// CONFIG12
#pragma config BCRCPOLT = hFF   // Boot Sector Polynomial for CRC on boot bits 31-24 (Bits 31:24 of BCRCPOL are 0xFF)

// CONFIG13
#pragma config BCRCPOLU = hFF   // Boot Sector Polynomial for CRC on boot bits 23-16 (Bits 23:16 of BCRCPOL are 0xFF)

// CONFIG14
#pragma config BCRCPOLH = hFF   // Boot Sector Polynomial for CRC on boot bits 15-8 (Bits 15:8 of BCRCPOL are 0xFF)

// CONFIG15
#pragma config BCRCPOLL = hFF   // Boot Sector Polynomial for CRC on boot bits 7-0 (Bits 7:0 of BCRCPOL are 0xFF)

// CONFIG16
#pragma config BCRCSEEDT = hFF  // Boot Sector Seed for CRC on boot bits 31-24 (Bits 31:24 of BCRCSEED are 0xFF)

// CONFIG17
#pragma config BCRCSEEDU = hFF  // Boot Sector Seed for CRC on boot bits 23-16 (Bits 23:16 of BCRCSEED are 0xFF)

// CONFIG18
#pragma config BCRCSEEDH = hFF  // Boot Sector Seed for CRC on boot bits 15-8 (Bits 15:8 of BCRCSEED are 0xFF)

// CONFIG19
#pragma config BCRCSEEDL = hFF  // Boot Sector Seed for CRC on boot bits 7-0 (Bits 7:0 of BCRCSEED are 0xFF)

// CONFIG20
#pragma config BCRCEREST = hFF  // Boot Sector Expected Result for CRC on boot bits 31-24 (Bits 31:24 of BCRCERES are 0xFF)

// CONFIG21
#pragma config BCRCERESU = hFF  // Boot Sector Expected Result for CRC on boot bits 23-16 (Bits 23:16 of BCRCERES are 0xFF)

// CONFIG22
#pragma config BCRCERESH = hFF  // Boot Sector Expected Result for CRC on boot bits 15-8 (Bits 15:8 of BCRCERES are 0xFF)

// CONFIG23
#pragma config BCRCERESL = hFF  // Boot Sector Expected Result for CRC on boot bits 7-0 (Bits 7:0 of BCRCERES are 0xFF)

// CONFIG24
#pragma config CRCPOLT = hFF    // Non-Boot Sector Polynomial for CRC on boot bits 31-24 (Bits 31:24 of CRCPOL are 0xFF)

// CONFIG25
#pragma config CRCPOLU = hFF    // Non-Boot Sector Polynomial for CRC on boot bits 23-16 (Bits 23:16 of CRCPOL are 0xFF)

// CONFIG26
#pragma config CRCPOLH = hFF    // Non-Boot Sector Polynomial for CRC on boot bits 15-8 (Bits 15:8 of CRCPOL are 0xFF)

// CONFIG27
#pragma config CRCPOLL = hFF    // Non-Boot Sector Polynomial for CRC on boot bits 7-0 (Bits 7:0 of CRCPOL are 0xFF)

// CONFIG28
#pragma config CRCSEEDT = hFF   // Non-Boot Sector Seed for CRC on boot bits 31-24 (Bits 31:24 of CRCSEED are 0xFF)

// CONFIG29
#pragma config CRCSEEDU = hFF   // Non-Boot Sector Seed for CRC on boot bits 23-16 (Bits 23:16 of CRCSEED are 0xFF)

// CONFIG30
#pragma config CRCSEEDH = hFF   // Non-Boot Sector Seed for CRC on boot bits 15-8 (Bits 15:8 of CRCSEED are 0xFF)

// CONFIG31
#pragma config CRCSEEDL = hFF   // Non-Boot Sector Seed for CRC on boot bits 7-0 (Bits 7:0 of CRCSEED are 0xFF)

// CONFIG32
#pragma config CRCEREST = hFF   // Non-Boot Sector Expected Result for CRC on boot bits 31-24 (Bits 31:24 of CRCERES are 0xFF)

// CONFIG33
#pragma config CRCERESU = hFF   // Non-Boot Sector Expected Result for CRC on boot bits 23-16 (Bits 23:16 of CRCERES are 0xFF)

// CONFIG34
#pragma config CRCERESH = hFF   // Non-Boot Sector Expected Result for CRC on boot bits 15-8 (Bits 15:8 of CRCERES are 0xFF)

// CONFIG35
#pragma config CRCERESL = hFF   // Non-Boot Sector Expected Result for CRC on boot bits 7-0 (Bits 7:0 of CRCERES are 0xFF)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>
#include "mxcmd.h"
#include "../timers.h"
#include "../modbus_master.h"
#include "../canfd.h"
#include "../batmon.h"

#define PACE	31000	// commands delay in count units
#define CMD_LEN	8
#define REC_LEN 5
#define REC_STATUS_LEN	16
#define REC_LOG_LEN	17

enum state_type {
	state_init,
	state_status,
	state_panel,
	state_batteryv,
	state_batterya,
	state_watts,
	state_fwrev,
	state_time,
	state_date,
	state_mx_log,
	state_misc,
	state_mx_status,
	state_last,
};

static uint16_t abuf[FM_BUFFER], cbuf[FM_BUFFER + 2];
volatile uint16_t cc_mode = STATUS_LAST, mx_code = 0x00;
uint16_t volt_whole, bat_amp_whole = AMP_WHOLE_ZERO, panel_watts, volt_fract, vf, vw;
volatile enum state_type state = state_init;
char buffer[MAX_B_BUF] = "Boot Init Display   ", can_buffer[MAX_C_BUF], info_buffer[MAX_B_BUF];
const char *build_date = __DATE__, *build_time = __TIME__;
volatile uint16_t tickCount[TMR_COUNT];
uint8_t fw_state = 0;

time_t can_timer = 1694196350; /* default epoch time */
struct tm *can_newtime;

#ifdef DATA_DEBUG
bool show_can;
uint8_t time_show_can;
#endif

B_type B = {
	.one_sec_flag = false,
	.ten_sec_flag = false,
	.pacing = 0,
	.rx_count = 0,
	.flush = 0,
	.canbus_online = 0,
	.modbus_online = 0,
	.log.select = 1,
};

mx_logpage_t mx_log;

/*
 * show fixed point fractions
 */
static void volt_f(const uint16_t);

/*
 * FM80 send/recv functions
 */
static void send_mx_cmd(const uint16_t *);
static void rec_mx_cmd(void (* DataHandler)(void), const uint8_t);

/*
 * callbacks to handle FM80 register data
 */
void state_init_cb(void);
void state_status_cb(void);
void state_panelv_cb(void);
void state_batteryv_cb(void);
void state_batterya_cb(void);
void state_watts_cb(void);
void state_misc_cb(void);
void state_mx_status_cb(void);
void state_mx_log_cb(void);
static void state_fwrev_cb(void);
static void state_time_cb(void);
static void state_date_cb(void);

/*
 * busy loop delay with WDT reset
 */
void wdtdelay(const uint32_t delay)
{
	uint32_t dcount;

	for (dcount = 0; dcount <= delay; dcount++) { // delay a bit
		ClrWdt(); // reset the WDT timer
	};
}

/*
 * Main application
 */
void main(void)
{
	// Initialize the device
	SYSTEM_Initialize();

	// If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
	// If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
	// Use the following macros to:

	// Enable high priority global interrupts
	INTERRUPT_GlobalInterruptHighEnable();

	// Enable low priority global interrupts.
	INTERRUPT_GlobalInterruptLowEnable();

	// Disable high priority global interrupts
	//INTERRUPT_GlobalInterruptHighDisable();

	// Disable low priority global interrupts.
	//INTERRUPT_GlobalInterruptLowDisable();

	TMR4_SetInterruptHandler(FM_io);
	TMR4_StartTimer();
	TMR0_SetInterruptHandler(onesec_io);
	TMR0_StartTimer();
	TMR2_SetInterruptHandler(tensec_io);
	TMR2_StartTimer();

#ifdef MB_MASTER
	init_mb_master_timers(); // pacing, spacing and timeouts
	UART5_SetRxInterruptHandler(my_modbus_rx_32); // install custom serial receive ISR
	StartTimer(TMR_MBTEST, 20);
	void mb_setup(); // serial error handlers
#endif
	StartTimer(TMR_SPIN, SPINNER_SPEED);

	init_display();
	//	snprintf(buffer, MAX_B_BUF, "%s ", "                        ");
	//	eaDogM_WriteStringAtPos(0, 0, buffer);
	snprintf(buffer, MAX_B_BUF, "%s   ", build_version);
	eaDogM_WriteStringAtPos(0, 0, buffer);
	snprintf(buffer, MAX_B_BUF, "%s   ", build_date);
	eaDogM_WriteStringAtPos(1, 0, buffer);
	if (initbm_data((void*) &EBD)) {
		snprintf(buffer, MAX_B_BUF, "Battery data loaded   ");
	} else {
		/* display build time and boot status codes 67 34 07, WDT reset 67 24 07 */
		snprintf(buffer, MAX_B_BUF, "%s B:%X %X %X   ", build_time, STATUS, PCON0, PCON1);
	}
	eaDogM_WriteStringAtPos(2, 0, buffer);
	snprintf(buffer, MAX_B_BUF, "%s ", "Start Up            ");
	eaDogM_WriteStringAtPos(3, 0, buffer);
	wdtdelay(1000000);
	snprintf(buffer, MAX_B_BUF, "%s ", "Polling FM80        ");
	eaDogM_WriteStringAtPos(2, 0, buffer);

	/*
	 * complete and correct the MCC CANBUS configuration
	 */
	can_setup();
	can_fd_tx(); // send the testing packet via CANBUS

	/*
	 * read and store the CPU_ID for PCB tracing
	 */
	for (uint8_t i = 0; i <= 8; i++) {
		B.mui[i] = DeviceID_Read(DIA_MUI + (i * 2)); // Read CPU ID from memory and store in array
	}
	{
		char s_buffer[22];
		snprintf(s_buffer, 21, "0X%X%X%X%X%X%X%X%X         ", B.mui[0], B.mui[1], B.mui[2], B.mui[3], B.mui[4], B.mui[5], B.mui[6], B.mui[7]);
		eaDogM_Scroll_String(s_buffer);
		can_newtime = localtime(&can_timer);
#ifdef SDEBUG
		snprintf(s_buffer, 21, "%s", asctime(can_newtime));
		eaDogM_Scroll_String(s_buffer);
		snprintf(s_buffer, 21, "CheckSum %X", calc_checksum((uint8_t *) & cmd_panelv[1], 10));
		eaDogM_Scroll_String(s_buffer);
#endif
	}
	while (true) {
		IO_RD5_SetHigh(); // main loop timing
		// Add your application code
#ifdef MB_MASTER
		master_controller_work(&C); // master MODBUS processing
#endif
		switch (state) {
		case state_init:
			send_mx_cmd(cmd_id);
			rec_mx_cmd(state_init_cb, REC_LEN);
			break;
		case state_status:
			send_mx_cmd(cmd_status);
			rec_mx_cmd(state_status_cb, REC_LEN);
			break;
		case state_panel:
			send_mx_cmd(cmd_panelv);
			rec_mx_cmd(state_panelv_cb, REC_LEN);
			break;
		case state_batteryv:
			send_mx_cmd(cmd_batteryv);
			rec_mx_cmd(state_batteryv_cb, REC_LEN);
			break;
		case state_batterya:
			send_mx_cmd(cmd_batterya);
			rec_mx_cmd(state_batterya_cb, REC_LEN);
			break;
		case state_watts:
			send_mx_cmd(cmd_watts);
			rec_mx_cmd(state_watts_cb, REC_LEN);
			break;
		case state_mx_status: // wait for ten second flag in this state for logging
			send_mx_cmd(cmd_mx_status);
			rec_mx_cmd(state_mx_status_cb, REC_STATUS_LEN);
			break;
		case state_fwrev:
			switch (fw_state) {
			case 0:
				send_mx_cmd(cmd_fwreva);
				rec_mx_cmd(state_fwrev_cb, REC_LEN);
				break;
			case 1:
				send_mx_cmd(cmd_fwrevb);
				rec_mx_cmd(state_fwrev_cb, REC_LEN);
				break;
			case 2:
				send_mx_cmd(cmd_fwrevc);
				rec_mx_cmd(state_fwrev_cb, REC_LEN);
			default:
				fw_state = 0;
				break;
			}
			break;
		case state_mx_log: // FM80 log data
			send_mx_cmd(cmd_mx_log);
			rec_mx_cmd(state_mx_log_cb, REC_LOG_LEN);
			break;
		case state_time: // FM80 send time data
			send_mx_cmd(cmd_time);
			rec_mx_cmd(state_time_cb, REC_LEN);
			break;
		case state_date: // FM80 send date data
			send_mx_cmd(cmd_date);
			rec_mx_cmd(state_date_cb, REC_LEN);
			break;
		case state_misc:
			send_mx_cmd(cmd_misc);
			rec_mx_cmd(state_misc_cb, REC_LEN);
			break;
		default:
			send_mx_cmd(cmd_id);
			rec_mx_cmd(state_init_cb, REC_LEN);
			break;
		}

		if (B.one_sec_flag) { // one second tasks
			eaDogM_Scroll_Task();
			B.one_sec_flag = false;
			B.canbus_online = (!C1TXQCONHbits.TXREQ)&0x01;
			if (!B.canbus_online) {
				C.tm_ok = false;
			}
			B.modbus_online = C.data_ok;
#ifdef CAN_DEBUG
			snprintf(buffer, MAX_B_BUF, "%X %X %X %X  %lu %lu %lu      ", C1BDIAG0T, C1BDIAG0U, C1BDIAG0H, C1BDIAG0L, can_rec_count.rec_count, msg[0].msgId, msg[1].msgId);
			//			eaDogM_WriteStringAtPos(0, 0, buffer);
			can_newtime = localtime(&can_timer);
			snprintf(buffer, 21, "%s", asctime(can_newtime));
			//			eaDogM_WriteStringAtPos(1, 0, buffer);
#endif
		}
		if (TimerDone(TMR_SPIN)) { // LCD status spinner for charger MODE
			{
#define E_UPDATE	10
#define E_SAVE		3
				static uint8_t s_update = 0, e_update = 0;
				static float ac = 0.0f;
				static float wac = 0.0f;
				static float wva = 0.0f;
				static uint32_t error_save = E_SAVE;

				if (s_update++ >= SPIN_VAL_UPDATE) {
					ac = lp_filter(((float) em.vl1l2) / 10.0f, F_ac, false);
					wac = lp_filter(((float) em.wl1) / 10.0f, F_wac, false);
					wva = lp_filter(((float) em.val1) / 10.0f, F_wva, false);
					s_update = 0;
				}
				StartTimer(TMR_SPIN, SPINNER_SPEED);
				if (C.data_ok && (M.error > error_save)) {
					snprintf(buffer, MAX_B_BUF, "EMon  %4.1fVAC   %c%c    ", lp_filter(ac, F_ac, false), spinners((uint8_t) 5 - (uint8_t) cc_mode, 0), spinners((uint8_t) 5 - (uint8_t) cc_mode, 0));
					eaDogM_WriteStringAtPos(1, 0, buffer);
					snprintf(info_buffer, MAX_B_BUF, " error logged \r\n");
					if (e_update == 0) {
#ifdef SHOW_MODBUS_DEBUG
						snprintf(buffer, MAX_B_BUF, "C%u CRC%lu RC%u EC%u          ", C.modbus_command, M.crc_error, M.recv_count, C.req_length);
#else
						snprintf(buffer, MAX_B_BUF, "%6.1fW %6.1fVA %c%c%c   ", lp_filter(wac, F_wac, false), lp_filter(wva, F_wva, false), state_name[cc_mode][0], canbus_name[B.canbus_online][0], modbus_name[B.modbus_online][0]);
#endif
						eaDogM_WriteStringAtPos(0, 0, buffer);
					}
					if (e_update++ >= E_UPDATE) {
						error_save = M.error + E_SAVE;
						e_update = 0;
					}
				} else {
					M.error = 0;
#ifdef CAN_DEBUG
#ifdef DATA_DEBUG
#ifdef LCD_MIRROR
#else
					if (show_can) {
						rxMsgData[0][42] = 0;
						snprintf(buffer, MAX_B_BUF, "%s          ", &rxMsgData[CAN_LOW_BUF][2]);
						eaDogM_WriteStringAtPos(2, 0, buffer);
						rxMsgData[0][42] = 0;
						snprintf(buffer, MAX_B_BUF, "%s          ", &rxMsgData[CAN_LOW_BUF][22]);
						eaDogM_WriteStringAtPos(3, 0, buffer);
					} else {
						snprintf(buffer, MAX_B_BUF, "%s          ", &rxMsgData[CAN_INFO_BUF][3]);
						eaDogM_WriteStringAtPos(2, 0, buffer);
						snprintf(buffer, MAX_B_BUF, "%s          ", &rxMsgData[CAN_INFO_BUF][22]);
						eaDogM_WriteStringAtPos(3, 0, buffer);
					}
					if (time_show_can++ >= 64) {
						show_can = !show_can;
						time_show_can = 0;
					}
#endif
#else
					snprintf(buffer, MAX_B_BUF, "%X %X %X %X %X %X %X %X           ", C1INTL, C1INTH, C1INTU, C1INTT, C1TRECL, C1FLTOBJ0T, C1FLTCON0L, CAN1_OperationModeGet());
					eaDogM_WriteStringAtPos(2, 0, buffer);
					snprintf(buffer, MAX_B_BUF, "%X %X %X %X %X %X %X %X           ", C1FIFOCON1L, C1FIFOCON1H, C1FIFOCON1U, C1FIFOCON1T, C1FIFOSTA1L, C1FIFOSTA1H, C1FIFOSTA1U, C1FIFOSTA1T);
					eaDogM_WriteStringAtPos(3, 0, buffer);
#endif
#else
					snprintf(buffer, MAX_B_BUF, "EMon  %6.1fWh   %c%c    ", EBD.bat_energy / 360.0f, spinners((uint8_t) 5 - (uint8_t) cc_mode, 0), spinners((uint8_t) 5 - (uint8_t) cc_mode, 0));
					eaDogM_WriteStringAtPos(1, 0, buffer);
					snprintf(buffer, MAX_B_BUF, "%6.1fW %6.1fVA %c%c%c   ", lp_filter(wac, F_wac, false), lp_filter(wva, F_wva, false), state_name[cc_mode][0], canbus_name[B.canbus_online][0], modbus_name[B.modbus_online][0]);
					eaDogM_WriteStringAtPos(0, 0, buffer);
#endif
				}
			}
		}
		IO_RD5_SetLow();
	}
}

/*
 * display  div 10 integer to fraction without FP
 * %d.%01d  volt_whole, volt_fract
 */
static void volt_f(const uint16_t voltage)
{
	volt_fract = (uint16_t) abs(voltage % 10);
	volt_whole = voltage / 10;
}

/*
 * transmit the cmd data
 */
static void send_mx_cmd(const uint16_t * cmd)
{
	if (FM_tx_empty()) {
		if (B.pacing++ > PACE) {
			FM_tx(cmd, CMD_LEN); // send 8 9-bits command data stream
			B.pacing = 0;
		}
	}
}

/*
 * process received data from the FM80 9n1 serial in abuf 16-bit buffer array with callbacks
 */
static void rec_mx_cmd(void (* DataHandler)(void), const uint8_t rec_len)
{
	static uint16_t online_count = 0;

	if (FM_rx_ready()) {
		if (FM_rx_count() >= rec_len) {
			online_count = 0;
			if (rec_len == REC_LOG_LEN) {
				FM_rx(cbuf);
			} else {
				FM_rx(abuf);
			}
			B.FM80_io = false;
			DataHandler(); // execute callback to process data in abuf
		} else {
			if (online_count++ > ONLINE_TIMEOUT) {
				online_count = 0;
				B.FM80_online = false;
				B.FM80_io = false;
				cc_mode = STATUS_LAST;
				state = state_init;
			}
		}
	}
	if ((B.FM80_online == false) && online_count++ > ONLINE_TIMEOUT) {
		online_count = 0;
		B.FM80_online = false;
		B.FM80_io = false;
		cc_mode = STATUS_LAST;
		state = state_watts;
		mx_code = 0x0;
		DataHandler();
	}

}

void state_init_cb(void)
{
	float Soc;
	static uint8_t off_delay = 0;

	mx_code = abuf[2]&0xf;
	if (mx_code == FM80_ID) {
		printf("\r\n\r\n%5d %3x %3x %3x %3x %3x   INIT: FM80 Online\r\n", B.rx_count++, abuf[0], abuf[1], abuf[2], abuf[3], abuf[4]);
		if (!B.FM80_online) { // try to guess battery energy by looking at battery voltage
			Soc = ((float) Volts_to_SOC(vw, vf) * 0.01f);
			EBD.bat_energy = BAT_ENERGY*Soc;
		}
		B.FM80_online = true;
		off_delay = 0;
		snprintf(buffer, MAX_B_BUF, "FM80 Online         ");
#ifndef LCD_MIRROR
		eaDogM_WriteStringAtPos(3, 0, buffer);
#endif
	} else {
		snprintf(buffer, MAX_B_BUF, "FM80 Offline        ");
#ifndef LCD_MIRROR
		eaDogM_WriteStringAtPos(3, 0, buffer);
#endif
		if (off_delay++ > 3) {
			B.FM80_online = false;
			cc_mode = STATUS_LAST;
		}
	}
	state = state_status;
}

void state_status_cb(void)
{
#ifdef debug_data
	printf("%5d: %3x %3x %3x %3x %3x STATUS: FM80 %s mode\r\n", rx_count++, abuf[0], abuf[1], abuf[2], abuf[3], abuf[4], state_name[abuf[2]]);
#endif
	if (FMxx_STATE != STATUS_SLEEPING) {
		state = state_watts;
	} else {
		state = state_watts;
	}
	if (B.FM80_online) { // don't update when offline
		cc_mode = FMxx_STATE;
	}
}

void state_panelv_cb(void)
{
#ifdef debug_data
	printf("%5d: %3x %3x %3x %3x %3x   DATA: Panel Voltage %iVDC\r\n", rx_count++, abuf[0], abuf[1], abuf[2], abuf[3], abuf[4], (abuf[2] + (abuf[1] << 8)));
#endif
	state = state_batteryv;
}

void state_batteryv_cb(void)
{
	volt_f((abuf[2] + (abuf[1] << 8)));
#ifdef debug_data
	printf("%5d: %3x %3x %3x %3x %3x   DATA: Battery Voltage %d.%01dVDC\r\n", rx_count++, abuf[0], abuf[1], abuf[2], abuf[3], abuf[4], volt_whole, volt_fract);
#endif
	state = state_batterya;
}

void state_batterya_cb(void)
{
	volt_f((abuf[2] + (abuf[1] << 8)));
#ifdef debug_data
	printf("%5d: %3x %3x %3x %3x %3x   DATA: Battery Amps %dADC\r\n", rx_count++, abuf[0], abuf[1], abuf[2], abuf[3], abuf[4], abuf[2] - 128);
#endif
	state = state_watts;
}

void state_watts_cb(void)
{
#ifdef debug_data
	printf("%5d: %3x %3x %3x %3x %3x   DATA: Panel Watts %iW\r\n", rx_count++, abuf[0], abuf[1], abuf[2], abuf[3], abuf[4], (abuf[2] + (abuf[1] << 8)));
#endif
	panel_watts = (abuf[2] + (abuf[1] << 8));
	if (B.FM80_online) {
		state = state_mx_log; // only get log data once state_init_cb has run
	} else {
		state = state_mx_status;
	}
}

void state_mx_log_cb(void)
{
	B.log.volts_peak = (int16_t) cbuf[5];
	B.log.day = (int16_t) cbuf[14];
	B.log.kilowatt_hours = (int16_t) (((uint16_t) (cbuf[3] & 0xF0) >> 4) | (uint16_t) (cbuf[4] << 4));
	B.log.kilowatts_peak = (int16_t) (((uint16_t) (cbuf[13] & 0xFC) >> 2) | (uint16_t) (cbuf[12] << 6));
	B.log.bat_max = (int16_t) (((uint16_t) (cbuf[2] & 0xFC) >> 2) | (uint16_t) ((cbuf[3] & 0x0F) << 6));
	B.log.bat_min = (int16_t) (((uint16_t) (cbuf[10] & 0xC0) >> 6) | (uint16_t) ((cbuf[11] << 2) | ((cbuf[12] & 0x03) << 10)));
	B.log.amps_peak = (int16_t) (cbuf[1] | ((cbuf[2] & 0x03) << 8));
	B.log.amp_hours = (int16_t) (cbuf[9] | ((cbuf[10] & 0x3F) << 8));
	B.log.absorb_time = (int16_t) (cbuf[6] | ((cbuf[7] & 0x0F) << 8));
	B.log.float_time = (int16_t) (((cbuf[7] & 0xF0) >> 4) | (cbuf[8] << 4));

	cmd_mx_log[5] = B.log.select;
	cmd_mx_log[7] = 0x16 + B.log.select; // update the checksum

	state = state_mx_status;
}

void state_mx_status_cb(void)
{
	volt_f((abuf[11] + (abuf[10] << 8))); // set battery voltage here in volt_whole and volt_frac
	vw = volt_whole;
	vf = volt_fract;
	volt_f((abuf[13] + (abuf[12] << 8))); // set panel voltage here in volt_whole and volt_frac
	if ((abuf[1] &0x0f) > 9) { // check for whole Amp
		abuf[2]++; // add extra Amp for fractional overflow.
		abuf[1] = (abuf[1]&0x0f) - 10;
	}
	if (B.FM80_online) { // don't update when offline
		bat_amp_whole = abuf[3] - 128;
	}
#ifdef debug_data
	printf("%5d: %3x %3x %3x %3x %3x  SDATA: FM80 Data mode %3x %3x %3x %3x %3x %3x %3x %3x %3x\r\n",
		rx_count++, abuf[0], abuf[1], abuf[2], abuf[3], abuf[4], abuf[5], abuf[6], abuf[7], abuf[8], abuf[9], abuf[10], abuf[11], abuf[12], abuf[13]);
#endif
	if (B.ten_sec_flag) {
		B.ten_sec_flag = false;
		if (B.FM80_online || B.modbus_online) { // log for MX80 and EM540
			MM_ERROR_C;
			/*
			 * log CSV values to the comm ports for data storage and processing
			 */
			snprintf(buffer, 25, "%s", asctime(can_newtime));
			buffer[26] = 0; // remove newline
			snprintf(can_buffer, MAX_C_BUF, log_format, LOG_VARS);
			printf("%s", can_buffer); // log to USART
			snprintf(buffer, MAX_B_BUF, "%d Watts %d.%01d Volts   ", panel_watts, volt_whole, volt_fract);
			eaDogM_WriteStringAtPos(2, 0, buffer);
			if (B.FM80_online) {
				bat_amp_whole = abuf[3] - 128;
			}
			snprintf(buffer, MAX_B_BUF, "%d.%01d Amps %d.%01d Volts   ", bat_amp_whole, abuf[1]&0x0f, vw, vf);
			eaDogM_WriteStringAtPos(3, 0, buffer);
			can_fd_tx(); // send the logging packet via CANBUS
			snprintf(info_buffer, MAX_B_BUF, " Data OK\r\n");
			/*
			 * update EEPROM energy history structure and check for serial commands on the logging port
			 */
			get_bm_data(&EBD);
			compute_bm_data(&EBD); // calculate battery energy at 10 second update rate
			if (!EBD.loaded) // save a copy to EEPROM if it wasn't loaded at boot
			{
				EBD.loaded = true;
				wr_bm_data((void*) &EBD);
				MM_ERROR_S;
			}
			if ((EBD_update++ >= BM_UPDATE) || ((EBD_update >= BM_UPDATE_RUN) && (cc_mode != STATUS_SLEEPING))) {
				EBD.loaded = true;
				wr_bm_data((void*) &EBD);
				EBD_update = 0;
				MM_ERROR_S;
			}
		}
	}
	state = state_fwrev;
}

static void state_fwrev_cb(void)
{
	B.fwrev[fw_state++] = abuf[2];
	if (!C.tm_ok) {
		state = state_misc;
	} else {
		C.tm_ok = false;
		state = state_time;
	}
}

static void state_time_cb(void)
{
	IO_RB6_Toggle(); // GPIO scope trace
#ifdef SDEBUG
	char s_buffer[22];
	snprintf(s_buffer, 21, "Time CSum %X        ", calc_checksum((uint8_t *) & cmd_time[1], 10));
	eaDogM_Scroll_String(s_buffer);
#endif
	IO_RB6_Toggle(); // GPIO scope trace
	state = state_date;
}

static void state_date_cb(void)
{
#ifdef SDEBUG
	char s_buffer[22];
	snprintf(s_buffer, 21, "Date CSum %X        ", calc_checksum((uint8_t *) & cmd_date[1], 10));
	eaDogM_Scroll_String(s_buffer);
#endif
	state = state_misc;
}

/*
 * testing online status while waiting for 10 second flag callback
 */
void state_misc_cb(void)
{
	if (mx_code == FM80_ID) { // only set FM80 offline here
	} else {
		B.FM80_online = false;
		cc_mode = STATUS_LAST;
		state = state_init;
		return;
	}
	if (!B.ten_sec_flag) {
		state = state_misc;
	} else {
		state = state_status;
	}
}

/* Misc ACSII spinner character generator, stores position for each shape */
char spinners(uint8_t shape, const uint8_t reset)
{
	static uint8_t s[MAX_SHAPES];
	char c;

	if (shape > (MAX_SHAPES - 1))
		shape = 0;
	if (reset)
		s[shape] = 0;
	c = spin[shape][s[shape]];
	if (++s[shape] >= strlen(spin[shape]))
		s[shape] = 0;
	return c;
}


/**
 End of File
 */