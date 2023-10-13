/* 
 * File:   trace.h
 * Author: root
 *
 * Created on October 11, 2023, 5:33 PM
 * 
 * enable/disable various GPIO pins for program timing and debugging with logic analyzers
 * and o-scopes
 * 
 * adds small program delay and latencies when defined
 */

#ifndef TRACE_H
#define	TRACE_H

#ifdef	__cplusplus
extern "C" {
#endif

#define TRACE
// EXT_IO pin 4, MISC_IO pin 6, SPI DMA driver toggles to RB5
// EXT_IO PIN 5, interrupt toggles to RB6 PGC
// EXT_IO pin 6, composite I/O from CLC7 to RB7 PGD
// EXT_IO pin 2, MISC_IO pin 5, main program trace high to RD5
// EXT_IO pin 3, MISC_IO pin 7, RD7


#ifdef	__cplusplus
}
#endif

#endif	/* TRACE_H */

