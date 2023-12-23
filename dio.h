/*
 * File:   dio.h
 * Author: root
 *
 * Created on October 13, 2023, 9:29 AM
 */

#ifndef DIO_H
#define	DIO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "mateQ84.X/mcc_generated_files/pin_manager.h"
	/*
	 * MISC_IO header
	 * pin 3, CHARGER
	 * pin 2, MISC
	 * pin 1, RELAY
	 *
	 * DIGITAL header
	 *
	 * pin 2, DB1
	 * pin 1, DB0
	 */

#define DAY_RELAY_ON			RELAY_SetHigh()
#define DAY_RELAY_OFF			RELAY_SetLow()
#define NIGHT_RELAY_ON			MISC_SetHigh()
#define NIGHT_RELAY_OFF			MISC_SetLow()
#define CHARGER_RELAY_ON		CHARGER_SetHigh()
#define CHARGER_RELAY_OFF		CHARGER_SetLow()

	/*
	 * assign a physical pin for each switch
	 * ANALOG header
	 * A: pin 5
	 * L: pin 2
	 * M: pin 1
	 */
#define D_SW_A_PIN	A_SWITCH_GetValue()
#define D_SW_L_PIN	L_SWITCH_GetValue()
#define D_SW_M_PIN	M_SWITCH_GetValue()

#define debounce_time	200	// debounce counts, at least a few tens of milliseconds for a typical switch

#define SW_NO	0	// switch, normally open
#define SW_NC	1	// switch, normally closed

	/*
	 * switch inputs and flags, uses the IOC interrupt and the software 
	 * timing ISR for processing
	 */
	enum D_SW {
		D_SW_A = 0,	// alternate LCD display
		D_SW_L,		// history logging from FM80
		D_SW_M,
		D_SW_COUNT // one extra for number of switches to check
	};

	/*
	 * contact type per configured switch
	 * used to verify the de-bounced switch condition for setting the button flag
	 */
	const uint8_t sw_contact_types[D_SW_COUNT] = {
		SW_NO,
		SW_NO,
		SW_NC,
	};

	void init_all_switch(void); // setup data and interrupt functions for each switch
	void button_press_check(void); // for de-bounce timer ISR

	void all_relays_off(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DIO_H */

