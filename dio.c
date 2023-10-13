
#include "dio.h"

void all_relays_off(void)
{
	DAY_RELAY_OFF;
	NIGHT_RELAY_OFF;
	CHARGER_RELAY_OFF;
}