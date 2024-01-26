
#include "dio.h"
#include "gtimodbusQ84.X/mxcmd.h"

static uint8_t a_debounce[D_SW_COUNT] = {0};
static uint8_t get_d_switch(const uint8_t i);

static void aswitch(void);
static void lswitch(void);
static void mswitch(void);

void all_relays_off(void)
{
	DAY_RELAY_OFF;
	NIGHT_RELAY_OFF;
	CHARGER_RELAY_OFF;
}

/*
 * switch IOC handlers per PIN
 */
static void aswitch(void)
{
	B.a_trigger[D_SW_A] = true;
	a_debounce[D_SW_A] = 0;
}

static void lswitch(void)
{
	B.a_trigger[D_SW_L] = true;
	a_debounce[D_SW_L] = 0;
}

static void mswitch(void)
{
	B.a_trigger[D_SW_M] = true;
	a_debounce[D_SW_M] = 0;
}

void init_all_switch(void)
{
	for (uint8_t i = 0; i < D_SW_COUNT; i++) {
		B.a_type[i] = sw_contact_types[i];
		B.a_trigger[i] = false;
		B.a_switch[i] = false;
		a_debounce[i] = 0;
	}
	IOCAF5_SetInterruptHandler(aswitch);
	IOCAF2_SetInterruptHandler(lswitch);
	IOCAF1_SetInterruptHandler(mswitch);
}

/*
 * debounce button pin status parser
 */
static uint8_t get_d_switch(const uint8_t i)
{
	switch (i) {
	case D_SW_A:
		return D_SW_A_PIN;
		break;
	case D_SW_L:
		return D_SW_L_PIN;
		break;
	case D_SW_M:
		return D_SW_M_PIN;
		break;
	default:
		return D_SW_A_PIN;
		break;
	}
}

/*
 * button checking/de-bounce routine for 500us timing ISR , runs in software timer interrupt ISR timer #4
 */
void button_press_check(void)
{
#ifdef TRACE
	IO_RD7_SetHigh();
#endif
	/*
	 * check for button presses
	 */
	for (uint8_t i = 0; i < D_SW_COUNT; i++) {
		B.a_pin[i] = get_d_switch(i); // update the pin value at every interrupt
		if (B.a_trigger[i]) {
			if ((++a_debounce[i] > debounce_time) && (B.a_pin[i] == B.a_type[i])) {
				a_debounce[i] = 0;
				B.a_trigger[i] = false;
				B.a_switch[i] = true;
			}
		} else {
			a_debounce[i] = 0;
		}
	}
#ifdef TRACE
	IO_RD7_SetLow();
#endif
}