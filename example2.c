
// PIC18F45K80 Configuration Bit Settings

#include <p18f45k80.h>

// CONFIG1L
#pragma config RETEN = OFF      // VREG Sleep Enable bit (Ultra low-power regulator is Disabled (Controlled by REGSLP bit))
#pragma config INTOSCSEL = HIGH // LF-INTOSC Low-power Enable bit (LF-INTOSC in High-power mode during Sleep)
#pragma config SOSCSEL = HIGH   // SOSC Power Selection and mode Configuration bits (High Power SOSC circuit selected)
#pragma config XINST = ON      // Extended Instruction Set (Disabled)

// CONFIG1H
#pragma config FOSC = HS2       // Oscillator (HS oscillator (High power, 16 MHz - 25 MHz))
#pragma config PLLCFG = OFF     // PLL x4 Enable bit (Disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor (Disabled)
#pragma config IESO = OFF       // Internal External Oscillator Switch Over Mode (Disabled)

// CONFIG2L
#pragma config PWRTEN = OFF     // Power Up Timer (Disabled)
#pragma config BOREN = SBORDIS  // Brown Out Detect (Enabled in hardware, SBOREN disabled)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (1.8V)
#pragma config BORPWR = ZPBORMV // BORMV Power level (ZPBORMV instead of BORMV is selected)

// CONFIG2H
#pragma config WDTEN = ON       // Watchdog Timer (WDT controlled by SWDTEN bit setting)
#pragma config WDTPS = 1024     // Watchdog Postscaler (1:1024)

// CONFIG3H
#pragma config CANMX = PORTB    // ECAN Mux bit (ECAN TX and RX pins are located on RB2 and RB3, respectively)
#pragma config MSSPMSK = MSK7   // MSSP address masking (7 Bit address masking mode)
#pragma config MCLRE = ON       // Master Clear Enable (MCLR Enabled, RE3 Disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Overflow Reset (Enabled)
#pragma config BBSIZ = BB2K     // Boot Block Size (2K word Boot Block size)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protect 00800-01FFF (Disabled)
#pragma config CP1 = OFF        // Code Protect 02000-03FFF (Disabled)
#pragma config CP2 = OFF        // Code Protect 04000-05FFF (Disabled)
#pragma config CP3 = OFF        // Code Protect 06000-07FFF (Disabled)

// CONFIG5H
#pragma config CPB = OFF        // Code Protect Boot (Disabled)
#pragma config CPD = OFF        // Data EE Read Protect (Disabled)

// CONFIG6L
#pragma config WRT0 = OFF       // Table Write Protect 00800-03FFF (Disabled)
#pragma config WRT1 = OFF       // Table Write Protect 04000-07FFF (Disabled)
#pragma config WRT2 = OFF       // Table Write Protect 08000-0BFFF (Disabled)
#pragma config WRT3 = OFF       // Table Write Protect 0C000-0FFFF (Disabled)

// CONFIG6H
#pragma config WRTC = OFF       // Config. Write Protect (Disabled)
#pragma config WRTB = OFF       // Table Write Protect Boot (Disabled)
#pragma config WRTD = OFF       // Data EE Write Protect (Disabled)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protect 00800-03FFF (Disabled)
#pragma config EBTR1 = OFF      // Table Read Protect 04000-07FFF (Disabled)
#pragma config EBTR2 = OFF      // Table Read Protect 08000-0BFFF (Disabled)
#pragma config EBTR3 = OFF      // Table Read Protect 0C000-0FFFF (Disabled)

// CONFIG7H
#pragma config EBTRB = OFF      // Table Read Protect Boot (Disabled)

/*
 * This program converts the rs-232 output from a carroltouch ELO 1939 touch-screen
 * to a format that can be used with the Varian Viision 80 Implanter
 * The LCD controller must be first programmed to the correct emulation
 *
 * Fred Brooks, Microchip Inc 2007
 * Version 1.02 COMM port and IRQ fixes Sept 7, 2011
 * Version 1.03 for the 45K80 chip and 1939L screen 2/12/2013
 *
 *
 * This application is designed for use with the
 * Oricom BOT40-II board, and the PIC18F45K80 device with cap on pin 6 for Vcore
 * regulator. 
 * requires a 9 pin male null-modem cable to connect the LCD serial to the
 * controller serial port, light-link host port is connected to TX2 pin 29
 */

#include <usart.h>
#include <timers.h>
#include <stdlib.h>
#include <EEP.h>

void rx_handler(void);

#define BUF_SIZE 16
#define BUF_SIZE_I 128
#define PUF_SIZE 256
#define	CMD_SIZE 4					// size of command in bytes from touch screen
#define	CMD_SIZE_I 6					// size of command in bytes from touch screen
#define	HOST_CMD_SIZE	6
#define	CMD_OVERFLOW	CMD_SIZE+1
#define	CMD_OVERFLOW_I	CMD_SIZE_I+1
#define ELO_SEQ 10
#define ELO_SIZE 14					// number of bytes to send from elocodes_s configuration string
#define ELO_SIZE_I 10
#define FALSE	0
#define TRUE	1
#define	BLINK_RATE	35000
#define	X_SCALE	1.90				// scaling factor to host screen X logical coords
#define	Y_SCALE 1.75				// scaling factor to host screen Y logical coords
#define	X_LOGICAL	119				// LCD touchscreen logical X frame coords
#define	Y_LOGICAL	94				// LCD touchscreen logical Y frame coords
#define	X_TOOL	202
#define	Y_TOOL	164

#define	TIMEROFFSET	26474			// timer0 16bit counter value for 1 second to overflow
#define	TIMERFAST	58974			// fast flash or testing
#define	COMM_CHK_TIME	30			// LCD comm heartbeat
#define	LCD_CHK_TIME	36			// LCD heartbeat timeout

volatile unsigned char CATCH = FALSE, LED_UP = TRUE, TOUCH = FALSE, UNTOUCH = FALSE, LCD_OK = FALSE, comm_check = 0, init_check = 0,
        SCREEN_INIT = FALSE, I_TOUCH = FALSE, SEND_PACKET = FALSE;

long alive_led = 0;
volatile long j = 0;
volatile float xs = X_SCALE, ys = Y_SCALE; // defaults
volatile unsigned int timer0_off = TIMEROFFSET;

/*
 * Step #1  The data is allocated into its own section.
 */
#pragma udata randdata
far unsigned char sram_key[PUF_SIZE];
#pragma udata

volatile unsigned char elobuf_out[BUF_SIZE], elobuf_in[BUF_SIZE], testing_data, xl = X_LOGICAL, yl = Y_LOGICAL,
        elobuf[BUF_SIZE_I];

unsigned char elocodes_s[] = {
        0x0d, 0x0d, 0x0d, 0x0d, 0x0d, 0x3c, 0x2b, 0x44, 0x26, 0x29, 0x44, 0x3d, 0x2a, 0x37
}; // initial carrol-touch config codes, tracking, add end point modifier, get frame size report

unsigned char elocodes[ELO_SEQ][ELO_SIZE_I] = {// elo 2210/2216 program codes
        'U', 'M', 0x00, 0x85, 0x08, '0', '0', '0', '0', '0', // initial touch,Single Point,untouch,Z-axis,scaling
        'U', 'S', 'x', 0xf6, 0xff, 0x04, 0x01, 0xff, 0x0f, '0', // scale x
        'U', 'S', 'y', 0xf6, 0xff, 0xc3, 0x00, 0xff, 0x0f, '0', // scale y
        'U', 'S', 'z', 0x01, 0x00, 0x0e, 0x00, 0xff, 0x00, '0', // scale z
        'U', 'E', '1', '6', '0', '0', '0', '0', '0', '0', // emulation E281A-4002 Binary (Z=0 on untouch)
        'U', 'N', '1', '7', '0', '0', '0', '0', '0', '0' // nvram save
}; // initial intelli-touch codes												//

const rom char *build_date = __DATE__, *build_time = __TIME__, build_version[] = " V1.03 8722 Varian touch-screen converter. Fred Brooks, Microchip Inc.";

/******************************************************************************
 *  Make CRC 16 Look-up Table.                                            *
 ******************************************************************************/

const rom unsigned int far crc_table[0x100] = {
        0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
        0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
        0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
        0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
        0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
        0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
        0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
        0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
        0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
        0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
        0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
        0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
        0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
        0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
        0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
        0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
        0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
        0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
        0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
        0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
        0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
        0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
        0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
        0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
        0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
        0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
        0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
        0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
        0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
        0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
        0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
        0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};

volatile unsigned int tchar, uchar;

#pragma code rx_interrupt = 0x8

void rx_int(void)
{
        _asm goto rx_handler _endasm
}
#pragma code

#pragma interrupt rx_handler

void rx_handler(void) // all normal serial data transform functions are handled here
{
        static unsigned char c1 = 0, c2 = 0, testc = 0, c = 0, *data_ptr;
        static int i = 0, data_pos, data_len;

        /* start with data_ptr pointed to address of data, data_len to length of data in bytes, data_pos to 0 to start at the beginning of data block */
        /* then enable the interrupt and wait for the interrupt enable flag to clear
        /* send buffer and count xmit data bytes for host link */
        if (PIE3bits.TX2IE && PIR3bits.TX2IF) { // send data to host USART TX2
                if (data_pos >= data_len) { // buffer has been sent
                        if (TXSTA2bits.TRMT) { // last bit has been shifted out
                                PIE3bits.TX2IE = 0; // stop data xmit
                                SEND_PACKET = FALSE;
                        }
                } else {
                        TXREG2 = *data_ptr; // send data and clear PIR3bits.TX2IF 
                        LATEbits.LATE0 = !LATEbits.LATE0; // flash external led
                        data_pos++; // move the data pointer
                        data_ptr++; // move the buffer pointer position
                }
        }

        if (INTCONbits.TMR0IF) { // check timer0 irq 1 second timer
                //check for TMR0 overflow
                INTCONbits.TMR0IF = 0; //clear interrupt flag
                WriteTimer0(timer0_off);
                LATEbits.LATE0 = !LATEbits.LATE0; // flash external led

                if (!LCD_OK && (init_check++ >LCD_CHK_TIME)) {
                        init_check = 0; // reset screen init code counter
                        SCREEN_INIT = TRUE; // set init code flag so it can be sent in main loop
                }

                if ((comm_check++ >COMM_CHK_TIME) && !CATCH) { // check for LCD screen connection
                        comm_check = 0; // reset connect heartbeat counter
                        LCD_OK = FALSE; // reset the connect flag while waiting for response from controller.
                        while (!TXSTA1bits.TRMT) {
                        }; // wait until the usart is clear
                        if (I_TOUCH) {
                        } else {
                                TXREG1 = 0x37; // send frame size request to LCD touch TX1
                        }
                        LATEbits.LATE1 = !LATEbits.LATE1; // flash  led
                        LATEbits.LATE2 = 1; // connect  led OFF
                }
        }

        if (PIR3bits.RC2IF) { // is data from host RX2
                if (RCSTA2bits.OERR) {
                        RCSTA2bits.CREN = 0; //	clear overrun
                        RCSTA2bits.CREN = 1; // re-enable
                }
                c1 = RCREG2;
        }

        if (I_TOUCH) { // future LCD touchscreen type here
                if (PIR1bits.RCIF) { // is data from touchscreen RX1
                        if (RCSTA1bits.OERR) {
                                RCSTA1bits.CREN = 0; //	clear overrun
                                RCSTA1bits.CREN = 1; // re-enable
                        }

                        /* Get the character received from the USART */
                        c = RCREG1;
                        tchar = c;
                        LATEbits.LATE0 = !LATEbits.LATE0; // flash external led

                        if (((tchar & 0xc0) == 0xc0) || CATCH) { // start of touch sequence
                                CATCH = TRUE; // found elo touch command start of sequence
                                j = 0; // reset led timer
                                elobuf[i++] = c; // start stuffing the command buffer
                        }
                        if (i == CMD_SIZE_I) { // see if we should send it
                                i = 0; // reset i to start of cmd
                                CATCH = FALSE; // reset buffering now
                                tchar = elobuf[i]; // just save it for now
                                uchar = elobuf[i + 5]; // check the Z data for 0 , load into uchar

                                if (uchar == 0x00) {
                                        UNTOUCH = TRUE; // untouch seqence found
                                        elobuf[i] = 0xc0; // restuff the buffer with varian untouch sequence
                                        elobuf[i + 1] = 0x80;
                                        elobuf[i + 2] = 0x40;
                                        elobuf[i + 3] = 0x00;
                                        elobuf[i + 4] = 0x00;
                                        elobuf[i + 5] = 0x00;
                                }

                                if ((TOUCH) && (UNTOUCH == FALSE)) { // reset index i
                                        i = 0;
                                } else {

                                        while (SEND_PACKET);
                                        data_ptr = elobuf;
                                        data_pos = 0;
                                        data_len = HOST_CMD_SIZE;
                                        SEND_PACKET = TRUE;
                                        PIE3bits.TX2IE = 1; // start sending data on TX2 to host
                                        i = 0;
                                        TOUCH = TRUE; // first touch sequence has been sent
                                }

                                if (UNTOUCH) { // After untouch is sent dump buffer and clear all.
                                        TOUCH = FALSE;
                                        UNTOUCH = FALSE;
                                        CATCH = FALSE;
                                        i = 0;
                                }
                        }

                        if (i > CMD_OVERFLOW_I) {
                                i = 0; // just incase i is greater than overflow_i somehow
                                CATCH = FALSE;
                                TOUCH = FALSE;
                                UNTOUCH = FALSE;
                        }
                }
        } else {
                if (PIR1bits.RCIF) { // is data from touchscreen RX1
                        if (RCSTA1bits.OERR) {
                                RCSTA1bits.CREN = 0; //	clear overrun
                                RCSTA1bits.CREN = 1; // re-enable
                        }
                        /* Get the character received from the USART */
                        c2 = RCREG1;
                        tchar = c2;

                        LATEbits.LATE0 = !LATEbits.LATE0; // flash external led

                        // touch 'FE X Y FF',    untouch 'FD X Y FF' from screen,    'F4 X Y FF' frame size report

                        if (CATCH || (tchar == 0xFE) || (tchar == 0xFD) || (tchar == 0xF4)) { // in frame or start of touch or untouch sequence or frame size report
                                CATCH = TRUE; // found elo CT touch command start of sequence, we hope
                                elobuf_in[i++] = tchar; // start stuffing the command buffer
                                j = 0; // reset led timer
                        }

                        if ((i == CMD_SIZE) && (elobuf_in[3] == 0xFF)) { // see if we should send it, right size and end char

                                i = 0; // reset i to start of cmd frame
                                CATCH = FALSE; // reset buffering now
                                uchar = elobuf_in[i]; //  load into uchar

                                if (uchar == 0xFE) { // touch sequence found restuff the buffer with varian touch sequence
                                        elobuf_in[2] = yl - elobuf_in[2]; // FLIP Y
                                        elobuf_in[1] = (unsigned char) ((float) elobuf_in[1]* (float) xs); // X scale
                                        elobuf_in[2] = (unsigned char) ((float) elobuf_in[2]* (float) ys); // Y scale
                                        elobuf_out[i ] = 0xc0 + ((elobuf_in[1]&0xc0) >> 6); // stuff into binary 4002 format
                                        elobuf_out[i + 1] = 0x80 + (elobuf_in[1]&0x3f);
                                        elobuf_out[i + 2] = 0x40 + ((elobuf_in[2]&0xc0) >> 6);
                                        elobuf_out[i + 3] = 0x00 + (elobuf_in[2]&0x3f);
                                        elobuf_out[i + 4] = 0x00;
                                        elobuf_out[i + 5] = 0x0F; // Z value = 15 "hard touch"
                                }

                                if (uchar == 0xFD) { // this is a untouch command
                                        UNTOUCH = TRUE; // untouch sequence found
                                        elobuf_out[i] = 0xc0; // restuff the buffer with varian binary 4002 untouch sequence
                                        elobuf_out[i + 1] = 0x80;
                                        elobuf_out[i + 2] = 0x40;
                                        elobuf_out[i + 3] = 0x00;
                                        elobuf_out[i + 4] = 0x00;
                                        elobuf_out[i + 5] = 0x00;
                                }

                                if (!TOUCH && !UNTOUCH) { // check for proper touch frames
                                        if (uchar == 0xF4) { // check for frame size report
                                                LCD_OK = TRUE; // looks like a screen controller is connected
                                                SCREEN_INIT = FALSE; // command code has been received by lcd controller
                                                init_check = 0; // reset init code timer
                                                LATEbits.LATE2 = 0; // connect  led ON
                                        }
                                }
                                if ((TOUCH) && (UNTOUCH == FALSE)) {
                                        i = 0; // reset index on multi-touch before untouch
                                } else {
                                        if ((uchar) == 0xFE || (uchar == 0xFD)) {
                                                while (SEND_PACKET);
                                                data_ptr = elobuf_out;
                                                data_pos = 0;
                                                data_len = HOST_CMD_SIZE;
                                                SEND_PACKET = TRUE;
                                                PIE3bits.TX2IE = 1; // start sending data on TX2 to host
                                                i = HOST_CMD_SIZE;
                                        }
                                }
                                if (uchar == 0xFE) TOUCH = TRUE; // set TOUCH flag after first touch
                                if (UNTOUCH) {
                                        TOUCH = FALSE;
                                        UNTOUCH = FALSE;
                                        CATCH = FALSE;
                                        i = 0;
                                }
                        }

                        if (i > CMD_OVERFLOW) {
                                i = 0; // just incase i is greater than overflow somehow
                                CATCH = FALSE;
                                TOUCH = FALSE;
                                UNTOUCH = FALSE;
                        }
                }
        }
}

void wdtdelay(unsigned long delay)
{
        unsigned long dcount;
        for (dcount = 0; dcount <= delay; dcount++) { // delay a bit
                ClrWdt(); // reset the WDT timer
        };
}

void elocmdout(unsigned char *elostr)
{
        int e;
        for (e = 0; e < ELO_SIZE; e++) { // send buffered data
                while (Busy1USART()) {
                }; // wait until the usart is clear
                putc1USART(elostr[e]); // send to LCD touch
                LATEbits.LATE0 = !LATEbits.LATE0; // flash external led
                wdtdelay(10000); // inter char delay
        }
        wdtdelay(50000); // wait for LCD controller reset
}

/******************************************************************************
 *  Make CRC 16 Calculation Function.                                     *
 ******************************************************************************/

unsigned int Make_Crc16(unsigned char *data, unsigned int length)
{
        unsigned int accum, len;

        /* Pre-conditioning */
        accum = 0xFFFF;
        len = length;


        ClrWdt(); // reset the WDT timer
        while (len--) {
                accum = ((accum & 0x00FF) << 8) ^
                        crc_table[((accum >> 8) ^ *data++) & 0x00FF];
        }

        ClrWdt(); // reset the WDT timer
        return(accum);
}

/* get random data for sram powerup bits */
unsigned int puf_sram(unsigned char cmode) // look at random SRAM data for PRNG seed
{
        unsigned int e;
        static unsigned int seed = 0; // if cmode is TRUE  return 0

        if (seed != 0) return seed;

        for (e = 0; e < PUF_SIZE; e++) {
                seed = seed + sram_key[e];
                ClrWdt(); // reset the WDT timer
        }

        for (e = 0; e<sizeof(build_version); e++) {
                Busy_eep();
                Write_b_eep(e, build_version[e]); //	write eeprom data
                ClrWdt(); // reset the WDT timer
        }

        seed = Make_Crc16(sram_key, PUF_SIZE); // make seed from crc16 of sram
        if (cmode) seed = 0; // cmode return 0
        return(seed);
}

void main(void)
{
        unsigned char z;
        /* Configure  PORT pins for output */
        TRISA = 0;
        LATA = 0;

        TRISB = 0;
        LATB = 0;

        TRISC = 0;
        LATC = 0;

        TRISD = 0;
        LATD = 0;

        TRISE = 0;
        LATE = 0xFF;


        sram_key[0] = 0x0; // set PUF SRAM address 0 byte to 0

        /*
         * Open the USART configured as
         * 8N1, 9600 baud, in /transmit/receive INT mode
         */
        /* TOUCHSCREEN */
        Open1USART(USART_TX_INT_OFF &
                USART_RX_INT_ON &
                USART_ASYNCH_MODE &
                USART_EIGHT_BIT &
                USART_CONT_RX &
                USART_BRGH_HIGH, 129); // 20mhz osc HS		9600 baud

        /* HOST */
        Open2USART(USART_TX_INT_ON &
                USART_RX_INT_ON &
                USART_ASYNCH_MODE &
                USART_EIGHT_BIT &
                USART_CONT_RX &
                USART_BRGH_HIGH, 129); // 20mhz osc HS		9600 baud

        OpenTimer0(TIMER_INT_ON & T0_16BIT & T0_SOURCE_INT & T0_PS_1_256);
        WriteTimer0(timer0_off); //	start timer0 at 1 second ticks

        /* Enable interrupt priority */
        RCONbits.IPEN = 1;

        /* Make receive interrupt high priority */
        IPR1bits.RC1IP = 1;
        IPR3bits.RC2IP = 1;

        wdtdelay(700000); // wait for LCD controller reset on power up
        /* Display a prompt to the USART */
        putrs2USART(
                (const far rom char *) "\n\rVarian touch-screen converter. Fred Brooks, Microchip Inc. Sat Jul 7 07:07:07 2007 \n\r");

        while (DataRdy1USART()) { // dump rx data
                z = Read1USART();
        };
        while (DataRdy2USART()) { // dump rx data
                z = Read2USART();
        };
        /* Enable all high priority interrupts */
        INTCONbits.TMR0IE = 1;
        INTCONbits.RBIE = 0; // disable B int
        INTCONbits.INT0IE = 0; // clear external ints
        INTCON3bits.INT1IE = 0;
        INTCON3bits.INT2IE = 0;
        INTCON3bits.INT3IE = 0;
        INTCONbits.GIEL = 0; // disable low ints
        INTCONbits.GIEH = 1; // enable high ints

        srand(puf_sram(FALSE)); // init PRNG from sram seed

        /* Loop forever */
        PORTB = 0x0f;
        elocmdout(&elocodes_s[0]); // send touchscreen setup data, causes a frame size report to be send from screen
        // set leds to on at powerup/reset
        while (TRUE) { // busy loop BSG style

                if (j++ >= BLINK_RATE) { // delay a bit ok
                        PORTB = alive_led & 0x0e; // roll leds cylon style
                        if (LED_UP && (alive_led != 0)) {
                                alive_led = alive_led * 2;
                        } else {
                                if (alive_led != 0) alive_led = alive_led / 2;
                        }
                        if (alive_led < 2) {
                                alive_led = 2;
                                LED_UP = TRUE;
                        } else {
                                if (alive_led > 8) {
                                        alive_led = 8;
                                        LED_UP = FALSE;
                                }
                        }
                        j = 0;
                        ClrWdt(); // reset the WDT timer
                        if (SCREEN_INIT) { // if this flag is set send elo commands
                                INTCONbits.GIEH = 0;
                                elocmdout(&elocodes_s[0]); // send touchscreen setup data, causes a frame size report to be send from screen
                                INTCONbits.GIEH = 1;
                                SCREEN_INIT = FALSE; // commands sent, now wait for reply to set LCD_OK flag
                        }
                }
                ClrWdt(); // reset the WDT timer
        };
}


