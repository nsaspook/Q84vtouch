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
 * MISC_IO
 * pin 3, RE2
 * pin 2, MISC
 * pin 1, RELAY
 * 
 * DIGITAL
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
	
void all_relays_off(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DIO_H */

