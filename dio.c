
#include "dio.h"
#include "mateQ84.X/mxcmd.h"

void all_relays_off(void)
{
	DAY_RELAY_OFF;
	NIGHT_RELAY_OFF;
	CHARGER_RELAY_OFF;
}

/*
 * switch IOC handlers
 */
void aswitch(void)
{
	B.a_trigger[D_SW_A] = true;
}

void lswitch(void)
{
	B.a_trigger[D_SW_L] = true;
}