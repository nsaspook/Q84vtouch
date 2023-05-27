/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F47Q84
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISBbits.TRISB1
#define LED1_LAT                  LATBbits.LATB1
#define LED1_PORT                 PORTBbits.RB1
#define LED1_WPU                  WPUBbits.WPUB1
#define LED1_OD                   ODCONBbits.ODCB1
#define LED1_ANS                  ANSELBbits.ANSELB1
#define LED1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LED1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define LED1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define LED1_GetValue()           PORTBbits.RB1
#define LED1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define LED1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISBbits.TRISB2
#define LED2_LAT                  LATBbits.LATB2
#define LED2_PORT                 PORTBbits.RB2
#define LED2_WPU                  WPUBbits.WPUB2
#define LED2_OD                   ODCONBbits.ODCB2
#define LED2_ANS                  ANSELBbits.ANSELB2
#define LED2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define LED2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define LED2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define LED2_GetValue()           PORTBbits.RB2
#define LED2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define LED2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISBbits.TRISB3
#define LED3_LAT                  LATBbits.LATB3
#define LED3_PORT                 PORTBbits.RB3
#define LED3_WPU                  WPUBbits.WPUB3
#define LED3_OD                   ODCONBbits.ODCB3
#define LED3_ANS                  ANSELBbits.ANSELB3
#define LED3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define LED3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define LED3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define LED3_GetValue()           PORTBbits.RB3
#define LED3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define LED3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()              PORTDbits.RD0
#define RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetPullup()             do { WPUDbits.WPUD0 = 1; } while(0)
#define RD0_ResetPullup()           do { WPUDbits.WPUD0 = 0; } while(0)
#define RD0_SetAnalogMode()         do { ANSELDbits.ANSELD0 = 1; } while(0)
#define RD0_SetDigitalMode()        do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set RD6 procedures
#define RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define RD6_GetValue()              PORTDbits.RD6
#define RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define RD6_SetPullup()             do { WPUDbits.WPUD6 = 1; } while(0)
#define RD6_ResetPullup()           do { WPUDbits.WPUD6 = 0; } while(0)
#define RD6_SetAnalogMode()         do { ANSELDbits.ANSELD6 = 1; } while(0)
#define RD6_SetDigitalMode()        do { ANSELDbits.ANSELD6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);




#endif // PIN_MANAGER_H
/**
 End of File
*/