#ifndef TIMERS_H
#define TIMERS_H

#include <stdint.h>
#include <stdbool.h>
#include "mateQ84.X/mcc_generated_files/mcc.h"

//Software timers - use these to refer to timers rather than
//integers.  Add more as needed.
//NOTE: 32767 ms max delay

enum APP_TIMERS {
	TMR_INTERNAL = 0, //Used in timers.c - do not remove or use elsewhere
	TMR_MBMASTER,
	TMR_MBTEST,
	TMR_SPIN,
	TMR_DERE,
	//
	//(Add timers here as needed)
	//
	TMR_COUNT //number of timers - always keep at end of enum!
};

enum D_SW {
	D_SW_A = 0,
	D_SW_L,
	D_SW_COUNT // number is switches to check
};

extern uint8_t a_debounce[D_SW_COUNT];

#define debounce_time	200
#define SW_NO	0
#define SW_NC	1

void StartTimer(const uint8_t timer, const uint16_t count);
bool TimerDone(const uint8_t timer);
void WaitMs(const uint16_t numMilliseconds);
void timer_ms_tick(const uint32_t, const uintptr_t);

void delay_ms(const uint16_t);

#endif //TIMERS_H
