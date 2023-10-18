#include "timers.h"
#include "mateQ84.X/mxcmd.h"

#pragma warning disable 520
#pragma warning disable 1498
#pragma warning disable 1090

extern volatile uint16_t tickCount[TMR_COUNT];
static uint8_t get_d_switch(uint8_t i);
uint8_t a_debounce[D_SW_COUNT] = {0, 0};

//**********************************************************************************************************************
// Start one of the software timers

void StartTimer(const uint8_t timer, const uint16_t count)
{
	tickCount[timer] = count << 1; //Interrupt is every 500us but StartTimer() takes multiple of 1ms so multiply by 2
}

//**********************************************************************************************************************
// Check if one of the software software timers has timed out

bool TimerDone(const uint8_t timer)
{
	if (tickCount[timer] == 0) { //Check if counted down to zero
		return true; //then return true
	}
	return false; //else return false
}

//**********************************************************************************************************************
// Simple delay for n milliseconds (blocking)

void WaitMs(const uint16_t numMilliseconds)
{
	StartTimer(TMR_INTERNAL, numMilliseconds); //Start software timer and wait for it to count down
	while (!TimerDone(TMR_INTERNAL)) {
	} //Enter idle mode to reduce power while waiting
} //(timer interrupt will wake part from idle)

/*
 * debounce button status parser
 */
static uint8_t get_d_switch(uint8_t i)
{
	switch (i) {
	case D_SW_A:
		return A_SWITCH_GetValue();
		break;
	case D_SW_L:
		return L_SWITCH_GetValue();
		break;
	default:
		return A_SWITCH_GetValue();
		break;
	}
}

/*
 * runs in timer #4 interrupt from FM_io(void)
 */
void timer_ms_tick(const uint32_t status, const uintptr_t context)
{

	//Decrement each software timer
	for (uint16_t i = 0; i < TMR_COUNT; i++) {
		if (tickCount[i] != 0) {
			tickCount[i]--;
		}
	}
	/*
	 * check for button presses
	 */
	for (uint8_t i = 0; i < D_SW_COUNT; i++) {
		if (B.a_trigger[i]) {
			if ((++a_debounce[i] > debounce_time) && (get_d_switch(i) == SW_NC)) {
				a_debounce[i] = 0;
				B.a_trigger[i] = false;
				B.a_switch[i] = true;
			}
		} else {
			a_debounce[i] = 0;
		}
	}
}

/*
 * microsecond busy wait delay, 90 seconds MAX
 * Careful, uses core timer
 */
void delay_us(uint32_t us)
{
}

void delay_ms(const uint16_t ms)
{
	WaitMs(ms);
}