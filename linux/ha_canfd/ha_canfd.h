
#ifndef HA_CANFD_H
#define HA_CANFD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <errno.h>
#include <getopt.h>
#include <libgen.h>
#include <limits.h>
#include <sched.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <syslog.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <cjson/cJSON.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#define LOG_TO_FILE         "/store/logs/canfd.log"
#define CAN_MSG_ID_PING  0x80000002
#define CAN_MSG_ID_PING_X 0x80000003
#define EMON_SL   0x80000002 // config reporting
#define EMON_SU   0x80000003 // config reporting
#define EMON_SH   0x80000004 // config reporting
#define EMON_DM   0x8000000E // set display to mode 1
#define EMON_ER   0x8000000F // error reporting
#define EMON_CO   0x8000000C // config reporting
#define EMON_DA   0x8000000D // blob reporting
#define EMON_TM   0x8000000A // send time to mateQ84
#define CAN_MSG_ID_PONG  0x3
#define CAN_MSG_LEN 64
#define CAN_FULL_BUFFER CAN_MSG_LEN+CAN_MSG_LEN+CAN_MSG_LEN+1
#define CAN_MSG_COUNT 1
#define CAN_MSG_WAIT 27
#define CAN_TM_TIME 30
#define HR_SEC  3600
#define DAY_SEC  HR_SEC*24

#define LOG_VERSION     "v1.17"
#define MQTT_VERSION    "V3.11"
#ifdef __amd64
#define ADDRESS         "tcp://10.1.1.172:1883"
#else
#define ADDRESS         "tcp://10.1.1.172:1883"
#endif
#define CLIENTID        "MateQ84_Mqtt"
#define TOPIC_P         "mateq84/data/solar"
#define TOPIC_S         "mateq84/data/solar/sub"
#define PGE_ZERO

	static const uint32_t QOS = 2;
	static const uint32_t TIMEOUT = 10000L;
	static const uint32_t SPACING_USEC = 500 * 1000;
	static const uint32_t MQTT_TIMEOUT = 150;

	static const double E_MONTH = 2266.0f; // Kwh
	static const double G_MONTH = 1000.0f; // kWh
	static const double E_DAYS = 31.0f;
	static const double E_PER_DAY = E_MONTH / E_DAYS;
	static const double E_PER_HOUR = E_PER_DAY / 24.0f;
	static const double G_PER_DAY = G_MONTH / E_DAYS;
	static const double G_PER_HOUR = G_PER_DAY / 24.0f;

#ifdef __cplusplus
}
#endif

#endif /* HA_CANFD_H */

