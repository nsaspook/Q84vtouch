/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef QCONFIG_H
#define	QCONFIG_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//#define CAN_REMOTE	// can received data on LCD for remote mate board
//#define CAN_REMOTE_NODMA
#define TRACE

#ifdef TRACE
#define INT_TRACE	IO_RB6_Toggle()
#else
#define INT_TRACE	""
#endif

//#define DEBUG_DISP0
//#define DEBUG_DISP1
//#define SDEBUG		// scrolling text debug messages
#define NHD		// 4x20 SPI display

/* spinner defines */
#define MAX_SHAPES  6
const char spin[MAX_SHAPES][20] = {
	"||//--", // classic LCD version with no \ character
	"||//--\\\\", // classic
	"OOOOOO--__-", // eye blink
	"vv<<^^>>", // point spinner
	"..**x#x#XX||--", // warp portal
	"..ooOOoo" // ball bouncer
};

#define SPIN_VAL_UPDATE	5

struct spi_link_type { // internal SPI state table
	uint8_t SPI_LCD : 1;
	uint8_t SPI_AUX : 1;
	uint8_t LCD_TIMER : 1;
	volatile uint8_t LCD_DATA : 1;
	uint16_t delay;
	uint8_t config;
	uint8_t * txbuf;
	volatile int32_t int_count;
};

extern volatile uint16_t cc_mode;
extern uint16_t panel_watts, volt_whole, bat_amp_whole, volt_fract, vw;
extern char spinners(uint8_t, const uint8_t);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

	// TODO If C++ is being used, regular C code needs function names to have C 
	// linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */