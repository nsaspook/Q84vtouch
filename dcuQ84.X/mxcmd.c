#include "mxcmd.h"

static volatile uint8_t data = 0x00, dcount = 0, dstart = 0, rdstart = 0;
static volatile uint16_t tbuf[FM_BUFFER + 1], rbuf[FM_BUFFER + 1];
static uint16_t *p_tbuf = (uint16_t*) tbuf, *p_rbuf = (uint16_t*) rbuf;
static volatile uint8_t pace = 0; // the charge controller doesn't like back to back bytes

/*
 * calls the timer.h software timers ISR
 */
void FM_io(void)
{
	INT_TRACE; // GPIO interrupt scope trace
	timer_ms_tick(0, 0); // software timers update
}

void onesec_io(void)
{
	INT_TRACE; // GPIO interrupt scope trace
	RLED_Toggle();
	MLED_SetLow();
	B.one_sec_flag = true;
}

void tensec_io(void)
{
	INT_TRACE; // GPIO interrupt scope trace
	DLED1_Toggle();
	DLED_Toggle();
	MLED_SetLow();
	B.ten_sec_flag = true;
}

/*
 * floating point low pass filter,
 * slow/fast select, use (-1) to zero buffer channel and return new
 */
float lp_filter(const float new, const uint8_t bn, const int8_t slow)
{
	static float smooth[LP_BUFFER_SIZE];
	float lp_speed;

	if (bn >= LP_BUFFER_SIZE) // buffer index check
		return new;

	if (slow == (-1)) { // reset smooth buffer and return original value
		smooth[bn] = 0.0f;
		return new;
	}

	if (slow) { // some random filter cutoffs beta values
		lp_speed = 0.0333f;
	} else {
		lp_speed = 0.1f;
	}
	// exponentially weighted moving average
	return smooth[bn] = smooth[bn] + ((new - smooth[bn]) * lp_speed);
}

uint16_t calc_checksum(uint8_t* data, const uint8_t len)
{
	uint16_t sum = 0;
	for (int i = 0; i < len; i++) {
		sum += data[i];
	}
	return sum;
}