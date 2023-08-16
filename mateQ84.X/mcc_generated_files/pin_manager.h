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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47Q84
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

// get/set channel_ANA0 aliases
#define channel_ANA0_TRIS                 TRISAbits.TRISA0
#define channel_ANA0_LAT                  LATAbits.LATA0
#define channel_ANA0_PORT                 PORTAbits.RA0
#define channel_ANA0_WPU                  WPUAbits.WPUA0
#define channel_ANA0_OD                   ODCONAbits.ODCA0
#define channel_ANA0_ANS                  ANSELAbits.ANSELA0
#define channel_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_ANA0_GetValue()           PORTAbits.RA0
#define channel_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_ANA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_ANA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_ANA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define channel_ANA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define channel_ANA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define channel_ANA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set channel_ANA1 aliases
#define channel_ANA1_TRIS                 TRISAbits.TRISA1
#define channel_ANA1_LAT                  LATAbits.LATA1
#define channel_ANA1_PORT                 PORTAbits.RA1
#define channel_ANA1_WPU                  WPUAbits.WPUA1
#define channel_ANA1_OD                   ODCONAbits.ODCA1
#define channel_ANA1_ANS                  ANSELAbits.ANSELA1
#define channel_ANA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_ANA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_ANA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_ANA1_GetValue()           PORTAbits.RA1
#define channel_ANA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_ANA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_ANA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define channel_ANA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define channel_ANA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define channel_ANA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define channel_ANA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define channel_ANA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set channel_ANA2 aliases
#define channel_ANA2_TRIS                 TRISAbits.TRISA2
#define channel_ANA2_LAT                  LATAbits.LATA2
#define channel_ANA2_PORT                 PORTAbits.RA2
#define channel_ANA2_WPU                  WPUAbits.WPUA2
#define channel_ANA2_OD                   ODCONAbits.ODCA2
#define channel_ANA2_ANS                  ANSELAbits.ANSELA2
#define channel_ANA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_ANA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_ANA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_ANA2_GetValue()           PORTAbits.RA2
#define channel_ANA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_ANA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_ANA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define channel_ANA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define channel_ANA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define channel_ANA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define channel_ANA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define channel_ANA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set channel_ANA4 aliases
#define channel_ANA4_TRIS                 TRISAbits.TRISA4
#define channel_ANA4_LAT                  LATAbits.LATA4
#define channel_ANA4_PORT                 PORTAbits.RA4
#define channel_ANA4_WPU                  WPUAbits.WPUA4
#define channel_ANA4_OD                   ODCONAbits.ODCA4
#define channel_ANA4_ANS                  ANSELAbits.ANSELA4
#define channel_ANA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define channel_ANA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define channel_ANA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define channel_ANA4_GetValue()           PORTAbits.RA4
#define channel_ANA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define channel_ANA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define channel_ANA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define channel_ANA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define channel_ANA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define channel_ANA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define channel_ANA4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define channel_ANA4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set channel_ANA5 aliases
#define channel_ANA5_TRIS                 TRISAbits.TRISA5
#define channel_ANA5_LAT                  LATAbits.LATA5
#define channel_ANA5_PORT                 PORTAbits.RA5
#define channel_ANA5_WPU                  WPUAbits.WPUA5
#define channel_ANA5_OD                   ODCONAbits.ODCA5
#define channel_ANA5_ANS                  ANSELAbits.ANSELA5
#define channel_ANA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define channel_ANA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define channel_ANA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define channel_ANA5_GetValue()           PORTAbits.RA5
#define channel_ANA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define channel_ANA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define channel_ANA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define channel_ANA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define channel_ANA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define channel_ANA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define channel_ANA5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define channel_ANA5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

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

// get/set MLED aliases
#define MLED_TRIS                 TRISBbits.TRISB1
#define MLED_LAT                  LATBbits.LATB1
#define MLED_PORT                 PORTBbits.RB1
#define MLED_WPU                  WPUBbits.WPUB1
#define MLED_OD                   ODCONBbits.ODCB1
#define MLED_ANS                  ANSELBbits.ANSELB1
#define MLED_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define MLED_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define MLED_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define MLED_GetValue()           PORTBbits.RB1
#define MLED_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define MLED_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define MLED_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define MLED_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define MLED_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define MLED_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define MLED_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define MLED_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RLED aliases
#define RLED_TRIS                 TRISBbits.TRISB2
#define RLED_LAT                  LATBbits.LATB2
#define RLED_PORT                 PORTBbits.RB2
#define RLED_WPU                  WPUBbits.WPUB2
#define RLED_OD                   ODCONBbits.ODCB2
#define RLED_ANS                  ANSELBbits.ANSELB2
#define RLED_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RLED_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RLED_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RLED_GetValue()           PORTBbits.RB2
#define RLED_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RLED_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RLED_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define RLED_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define RLED_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define RLED_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define RLED_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RLED_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set DLED1 aliases
#define DLED1_TRIS                 TRISBbits.TRISB3
#define DLED1_LAT                  LATBbits.LATB3
#define DLED1_PORT                 PORTBbits.RB3
#define DLED1_WPU                  WPUBbits.WPUB3
#define DLED1_OD                   ODCONBbits.ODCB3
#define DLED1_ANS                  ANSELBbits.ANSELB3
#define DLED1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define DLED1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define DLED1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define DLED1_GetValue()           PORTBbits.RB3
#define DLED1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define DLED1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define DLED1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define DLED1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define DLED1_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define DLED1_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define DLED1_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define DLED1_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

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

// get/set IO_RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSELB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.ODCB6
#define IO_RB6_ANS                  ANSELBbits.ANSELB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSELB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set DERE aliases
#define DERE_TRIS                 TRISCbits.TRISC2
#define DERE_LAT                  LATCbits.LATC2
#define DERE_PORT                 PORTCbits.RC2
#define DERE_WPU                  WPUCbits.WPUC2
#define DERE_OD                   ODCONCbits.ODCC2
#define DERE_ANS                  ANSELCbits.ANSELC2
#define DERE_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define DERE_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define DERE_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define DERE_GetValue()           PORTCbits.RC2
#define DERE_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define DERE_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define DERE_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define DERE_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define DERE_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define DERE_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define DERE_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define DERE_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

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

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

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

// get/set DB0 aliases
#define DB0_TRIS                 TRISDbits.TRISD1
#define DB0_LAT                  LATDbits.LATD1
#define DB0_PORT                 PORTDbits.RD1
#define DB0_WPU                  WPUDbits.WPUD1
#define DB0_OD                   ODCONDbits.ODCD1
#define DB0_ANS                  ANSELDbits.ANSELD1
#define DB0_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define DB0_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define DB0_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define DB0_GetValue()           PORTDbits.RD1
#define DB0_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define DB0_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define DB0_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define DB0_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define DB0_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define DB0_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define DB0_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define DB0_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set DB1 aliases
#define DB1_TRIS                 TRISDbits.TRISD2
#define DB1_LAT                  LATDbits.LATD2
#define DB1_PORT                 PORTDbits.RD2
#define DB1_WPU                  WPUDbits.WPUD2
#define DB1_OD                   ODCONDbits.ODCD2
#define DB1_ANS                  ANSELDbits.ANSELD2
#define DB1_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define DB1_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define DB1_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define DB1_GetValue()           PORTDbits.RD2
#define DB1_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define DB1_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define DB1_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define DB1_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define DB1_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define DB1_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define DB1_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define DB1_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set CS aliases
#define CS_TRIS                 TRISDbits.TRISD3
#define CS_LAT                  LATDbits.LATD3
#define CS_PORT                 PORTDbits.RD3
#define CS_WPU                  WPUDbits.WPUD3
#define CS_OD                   ODCONDbits.ODCD3
#define CS_ANS                  ANSELDbits.ANSELD3
#define CS_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define CS_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define CS_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define CS_GetValue()           PORTDbits.RD3
#define CS_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define CS_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define CS_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set DLED aliases
#define DLED_TRIS                 TRISDbits.TRISD4
#define DLED_LAT                  LATDbits.LATD4
#define DLED_PORT                 PORTDbits.RD4
#define DLED_WPU                  WPUDbits.WPUD4
#define DLED_OD                   ODCONDbits.ODCD4
#define DLED_ANS                  ANSELDbits.ANSELD4
#define DLED_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define DLED_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define DLED_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define DLED_GetValue()           PORTDbits.RD4
#define DLED_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define DLED_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define DLED_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define DLED_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define DLED_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define DLED_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define DLED_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define DLED_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set IO_RD5 aliases
#define IO_RD5_TRIS                 TRISDbits.TRISD5
#define IO_RD5_LAT                  LATDbits.LATD5
#define IO_RD5_PORT                 PORTDbits.RD5
#define IO_RD5_WPU                  WPUDbits.WPUD5
#define IO_RD5_OD                   ODCONDbits.ODCD5
#define IO_RD5_ANS                  ANSELDbits.ANSELD5
#define IO_RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IO_RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IO_RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IO_RD5_GetValue()           PORTDbits.RD5
#define IO_RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IO_RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IO_RD5_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define IO_RD5_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define IO_RD5_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define IO_RD5_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define IO_RD5_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define IO_RD5_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

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

// get/set IO_RD7 aliases
#define IO_RD7_TRIS                 TRISDbits.TRISD7
#define IO_RD7_LAT                  LATDbits.LATD7
#define IO_RD7_PORT                 PORTDbits.RD7
#define IO_RD7_WPU                  WPUDbits.WPUD7
#define IO_RD7_OD                   ODCONDbits.ODCD7
#define IO_RD7_ANS                  ANSELDbits.ANSELD7
#define IO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_GetValue()           PORTDbits.RD7
#define IO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define IO_RD7_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define IO_RD7_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define IO_RD7_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define IO_RD7_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set RELAY aliases
#define RELAY_TRIS                 TRISEbits.TRISE0
#define RELAY_LAT                  LATEbits.LATE0
#define RELAY_PORT                 PORTEbits.RE0
#define RELAY_WPU                  WPUEbits.WPUE0
#define RELAY_OD                   ODCONEbits.ODCE0
#define RELAY_ANS                  ANSELEbits.ANSELE0
#define RELAY_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define RELAY_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define RELAY_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define RELAY_GetValue()           PORTEbits.RE0
#define RELAY_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define RELAY_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define RELAY_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define RELAY_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define RELAY_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define RELAY_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define RELAY_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define RELAY_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set MISC aliases
#define MISC_TRIS                 TRISEbits.TRISE1
#define MISC_LAT                  LATEbits.LATE1
#define MISC_PORT                 PORTEbits.RE1
#define MISC_WPU                  WPUEbits.WPUE1
#define MISC_OD                   ODCONEbits.ODCE1
#define MISC_ANS                  ANSELEbits.ANSELE1
#define MISC_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define MISC_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define MISC_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define MISC_GetValue()           PORTEbits.RE1
#define MISC_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define MISC_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define MISC_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define MISC_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define MISC_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define MISC_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define MISC_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define MISC_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set IO_RE2 aliases
#define IO_RE2_TRIS                 TRISEbits.TRISE2
#define IO_RE2_LAT                  LATEbits.LATE2
#define IO_RE2_PORT                 PORTEbits.RE2
#define IO_RE2_WPU                  WPUEbits.WPUE2
#define IO_RE2_OD                   ODCONEbits.ODCE2
#define IO_RE2_ANS                  ANSELEbits.ANSELE2
#define IO_RE2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define IO_RE2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define IO_RE2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define IO_RE2_GetValue()           PORTEbits.RE2
#define IO_RE2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define IO_RE2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define IO_RE2_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define IO_RE2_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define IO_RE2_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define IO_RE2_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define IO_RE2_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define IO_RE2_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

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