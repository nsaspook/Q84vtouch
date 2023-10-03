/* 
 * File:   tdr.h
 * Author: root
 *
 * Created on October 2, 2023, 9:46 AM
 */

#ifndef TDR_H
#define	TDR_H

#ifdef	__cplusplus
extern "C" {
#endif
	
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stddef.h> 
#include <stdio.h>
#include <string.h>


#define DLED1		LATCbits.LATC1
#define DLED2		LATCbits.LATC2
#define DLED3		LATCbits.LATC3

// CTMU ADC results for cables
#define offset_meter	2752.0f
#define	one_meter	2752.0f
#define five_meter	3264.0f


#ifdef	__cplusplus
}
#endif

#endif	/* TDR_H */

