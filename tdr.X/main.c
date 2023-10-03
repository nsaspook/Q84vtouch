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
	Device            :  PIC18F25K22
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

#include "mcc_generated_files/mcc.h"
#include "tdr.h"

volatile bool printout = false;
volatile adc_result_t tdr_adc = 0;

void blinker(void);
void wdtdelay(uint32_t);

/*
			 Main application
 */
void main(void)
{
	// Initialize the device
	SYSTEM_Initialize();

	// If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
	// If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
	// Use the following macros to:

	// Enable high priority global interrupts
	INTERRUPT_GlobalInterruptHighEnable();

	// Enable low priority global interrupts.
	INTERRUPT_GlobalInterruptLowEnable();

	// Disable high priority global interrupts
	//INTERRUPT_GlobalInterruptHighDisable();

	// Disable low priority global interrupts.
	//INTERRUPT_GlobalInterruptLowDisable();

	// Enable the Peripheral Interrupts
	INTERRUPT_PeripheralInterruptEnable();

	// Disable the Peripheral Interrupts
	//INTERRUPT_PeripheralInterruptDisable();

	TMR5_SetInterruptHandler(blinker);
	TMR5_StartTimer();

	/* CTMU pins setup */
	TRISBbits.TRISB2 = HIGH; //CTED1
	TRISBbits.TRISB3 = HIGH; //CTED2


	//CTMUCONH/1 - CTMU Control registers
	CTMUCONH = 0x04; //make sure CTMU is disabled and ready for edge 1 before 2
	CTMUICON = 0x03; //.55uA*100, Nominal - No Adjustment default
	CTMUCONLbits.EDG1SEL = 3; // Set Edge CTED1
	CTMUCONLbits.EDG2SEL = 2; // CTED2
	CTMUCONLbits.EDG1POL = HIGH; // Set Edge
	CTMUCONLbits.EDG2POL = HIGH; // positive edges
	CTMUCONHbits.EDGSEQEN = HIGH;
	CTMUCONHbits.CTMUEN = HIGH; //Enable the CTMU
	CTMUCONHbits.IDISSEN = HIGH; // drain the circuit
	CTMUCONHbits.CTTRIG = LOW; // disable trigger

	ADC_SelectChannel(channel_AN0);


	while (1) {
		// Add your application code
		if (printout) {
			printout = false;
			printf("\rTDR %4u", tdr_adc);
		}
	}
}

void blinker(void)
{
	uint32_t del = 0;

	DLED2_SetLow();
	CTMUCONHbits.CTMUEN = LOW;
	CTMUICON = 0x03; // 55uA
	CTMUCONHbits.CTMUEN = HIGH;
	CTMUCONHbits.IDISSEN = HIGH; // start drain
	wdtdelay(100); // time to drain the internal cap for measurements
	CTMUCONHbits.IDISSEN = LOW; // end drain
	CTMUCONLbits.EDG1STAT = 0; // Set Edge status bits to zero
	CTMUCONLbits.EDG2STAT = 0;
	CTMUCONHbits.EDGEN = HIGH; // start looking at external edges
	DLED2_SetHigh();

	while (!PIR3bits.CTMUIF) {
		if (++del > 1000) {
			DLED2_SetLow();
			return;
		}
	}
	DLED2_SetLow();

	// CTED (tx1) is high then CTED2 (rx2)went high
	PIR3bits.CTMUIF = LOW; // clear CTMU flag 
	ADC_StartConversion();
	CTMUCONHbits.CTMUEN = LOW;
	CTMUICON = 0x00; // current off
	PIE3bits.CTMUIE = LOW; // disable interrupt
	CTMUCONHbits.EDGEN = LOW;
	CTMUCONLbits.EDG1STAT = 0; // Set Edge status bits to zero
	CTMUCONLbits.EDG2STAT = 0;

	while (!ADC_IsConversionDone()) {

	}

	tdr_adc = ADC_GetConversionResult();

	DLED1_Toggle();

	printout = true;
}

/*
 * value of 1 for 3.6us, 10 for 15us, 100 = 126us, 1000 for 1256us
 */
void wdtdelay(uint32_t delay)
{
	static uint32_t dcount;

	for (dcount = 0; dcount <= delay; dcount++) { // delay a bit
		Nop();
		ClrWdt(); // reset the WDT timer
	};
}

/**
 End of File
 */