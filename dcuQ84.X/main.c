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

/*
 * this is the mateQ84 version that used CANbus to connect to the remote and Linux server
 */

#include <xc.h>
#include "mxcmd.h"
#include "../timers.h"
#include "../modbus_master.h"
#include "../canfd.h"
#include "../batmon.h"

#define PACE            31000	// commands delay in count units
#define CMD_LEN         8
#define REC_LEN         5
#define REC_STATUS_LEN	16
#define REC_LOG_LEN     17

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
char buffer[MAX_B_BUF] = "Boot Init Display   ", info_buffer[MAX_B_BUF], log_buffer[MAX_B_BUF];
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
	.pv_high = false,
	.pv_prev = STATUS_SLEEPING,
	.pv_update = false,
	.once = false,
	.log.type = 1, // mxlog type
	.display_dim = false,
	.display_update = false,
	.dim_delay = DIM_DELAY,
};

/*
 * testing blob data feature for logs
 */
union blob_log *mxlog_ptr = (void*) & B.log;

static EB_data *EB = &EBD;

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

	/*
	 * complete and correct the MCC CANBUS configuration
	 */
	can_setup();

	// Enable high priority global interrupts
	INTERRUPT_GlobalInterruptHighEnable();

	// Enable low priority global interrupts.
	INTERRUPT_GlobalInterruptLowEnable();

	TMR4_SetInterruptHandler(FM_io);
	TMR4_StartTimer();
	TMR0_SetInterruptHandler(onesec_io);
	TMR0_StartTimer();
	TMR2_SetInterruptHandler(tensec_io);
	TMR2_StartTimer();

	// switch pressed ISR handlers
	init_all_switch();

	init_mb_master_timers(); // pacing, spacing and timeouts
	UART5_SetRxInterruptHandler(my_modbus_rx_32); // install custom serial receive ISR
	StartTimer(TMR_MBTEST, 20);
	mb_setup(); // serial error handlers

	StartTimer(TMR_SPIN, SPINNER_SPEED);

	init_display();
	snprintf(buffer, MAX_B_BUF, "%s   ", build_version);
	eaDogM_WriteStringAtPos(0, 0, buffer);
	snprintf(buffer, MAX_B_BUF, "%s   ", build_date);
	eaDogM_WriteStringAtPos(1, 0, buffer);
	if (initbm_data((void*) EB)) {
		B.alt_display = EB->alt_display;
		snprintf(buffer, MAX_B_BUF, "Battery data loaded   ");
	} else {
		/* display build time and boot status codes 67 34 07, WDT reset 67 24 07 */
		snprintf(buffer, MAX_B_BUF, "%s B:%X %X %X   ", build_time, STATUS, PCON0, PCON1);
	}
	eaDogM_WriteStringAtPos(2, 0, buffer);

	snprintf(buffer, MAX_B_BUF, "%s ", "Start Up            ");
	eaDogM_WriteStringAtPos(3, 0, buffer);
	wdtdelay(1000000);
	snprintf(buffer, MAX_B_BUF, "%s ", "Polling Pump        ");
	eaDogM_WriteStringAtPos(2, 0, buffer);

	/*
	 * read and store the CPU_ID for PCB tracing
	 */
	B.node_id = 0;
	for (uint8_t i = 0; i <= 8; i++) {
		B.mui[i] = DeviceID_Read(DIA_MUI + (i * 2)); // Read CPU ID from memory and store in array
		B.node_id += B.mui[i];
	}

#ifdef NO_NODE_ID
	B.node_id = 0; // set to zero to only use EMON type number as the CAN packet ID
#else
	B.node_id = B.node_id & 0xf;
#endif

	{
		char s_buffer[22];
		snprintf(s_buffer, 21, "%X%X%X%X%X%X%X%X         ", B.mui[0], B.mui[1], B.mui[2], B.mui[3], B.mui[4], B.mui[5], B.mui[6], B.mui[7]);
		eaDogM_Scroll_String(s_buffer);
		can_newtime = localtime(&can_timer);
	}
	while (true) {
#ifdef TRACE
		PROG_TRACE_SetHigh(); // main loop timing
#endif
		// Add your application code
		master_controller_work(&C); // master MODBUS processing

		if (B.one_sec_flag) { // one second tasks
			eaDogM_Scroll_Task();
			B.one_sec_flag = false;
			B.canbus_online = (!C1TXQCONHbits.TXREQ)&0x01;
			if (!B.canbus_online) {
				C.tm_ok = false;
			}
			B.modbus_online = C.data_ok;
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
					snprintf(buffer, MAX_B_BUF, "DCU 1");
					eaDogM_WriteStringAtPos(1, 0, buffer);
					snprintf(info_buffer, MAX_B_BUF, " error logged \r\n");
					if (e_update == 0) {
						snprintf(buffer, MAX_B_BUF, "C%u CRC%lu RC%u EC%u          ", C.modbus_command, M.crc_error, M.recv_count, C.req_length);
						eaDogM_WriteStringAtPos(0, 0, buffer);
					}
					if (e_update++ >= E_UPDATE) {
						error_save = M.error + E_SAVE;
						e_update = 0;
					}
				} else {
					M.error = 0;
					snprintf(buffer, MAX_B_BUF, "DCU 1");
					eaDogM_WriteStringAtPos(1, 0, buffer);
					snprintf(buffer, MAX_B_BUF, "DCU 0");
					eaDogM_WriteStringAtPos(0, 0, buffer);

				}
			}
		}
		/*
		 * check command switches
		 */
		if (B.a_switch[D_SW_A]) {
			MM_ERROR_S;
			B.a_switch[D_SW_A] = false;
			B.alt_display++;
			if (B.alt_display > MAX_ALT_DIS) {
				B.alt_display = 0;
			}
			EB->alt_display = B.alt_display;
			snprintf(buffer, MAX_B_BUF, "%d %s", B.alt_display, "Alt Button \337\364       ");
			eaDogM_WriteStringAtPos(2, 0, buffer);
			B.display_update = true;
		}
		if (B.a_switch[D_SW_L]) {
			MM_ERROR_S;
			B.a_switch[D_SW_L] = false;
			snprintf(buffer, MAX_B_BUF, "%s", "Log Button Pressed        ");
			eaDogM_WriteStringAtPos(2, 0, buffer);
			B.LOG = true;
			B.display_update = true;
		}
		if (B.a_switch[D_SW_M]) {
			MM_ERROR_S;
			B.a_switch[D_SW_M] = false;
			snprintf(buffer, MAX_B_BUF, "%s", "MISC Button Pressed        ");
			eaDogM_WriteStringAtPos(2, 0, buffer);
			B.display_update = true;
		}
#ifdef TRACE
		PROG_TRACE_SetLow();
#endif
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
			FM_tx(cmd, CMD_LEN); // send 9-bit command data stream
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

void run_day_to_night(void)
{
	char s_buffer[22];

	snprintf(s_buffer, 21, "DN %.1fWh PV        ", pv_Wh_daily);
	eaDogM_Scroll_String(s_buffer);
	snprintf(s_buffer, 21, "DN %.1fWh AC        ", ac_Wh_daily);
	eaDogM_Scroll_String(s_buffer);
	eaDogM_Scroll_String(s_buffer);
	eaDogM_Scroll_String(s_buffer);
	DAY_RELAY_OFF;
	NIGHT_RELAY_ON;
}

void run_night_to_day(void)
{
	char s_buffer[22];

	snprintf(s_buffer, 21, "ND %.1fWh PV        ", pv_Wh_daily_prev);
	eaDogM_Scroll_String(s_buffer);
	snprintf(s_buffer, 21, "ND %.1fWh AC        ", ac_Wh_daily_prev);
	eaDogM_Scroll_String(s_buffer);
	eaDogM_Scroll_String(s_buffer);
	eaDogM_Scroll_String(s_buffer);
	NIGHT_RELAY_OFF;
	DAY_RELAY_ON;
}
/**
 End of File
 */