# 1 "../timers.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/root/.mchp_packs/Microchip/PIC18F-Q_DFP/1.18.389/xc8/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "../timers.c" 2
# 1 "../timers.h" 1



# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stdint.h" 1 3



# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/musl_xc8.h" 1 3
# 5 "/opt/microchip/xc8/v2.41/pic/include/c99/stdint.h" 2 3
# 22 "/opt/microchip/xc8/v2.41/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3
# 127 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef long intptr_t;
# 158 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 23 "/opt/microchip/xc8/v2.41/pic/include/c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "/opt/microchip/xc8/v2.41/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 145 "/opt/microchip/xc8/v2.41/pic/include/c99/stdint.h" 2 3
# 5 "../timers.h" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stdbool.h" 1 3
# 6 "../timers.h" 2





enum APP_TIMERS {
 TMR_INTERNAL = 0,
 TMR_MBMASTER,
 TMR_MBTEST,
 TMR_SPIN,



 TMR_COUNT
};

void StartTimer(const uint8_t timer, const uint16_t count);
_Bool TimerDone(const uint8_t timer);
void WaitMs(const uint16_t numMilliseconds);
void timer_ms_tick(uint32_t, uintptr_t);

void delay_ms(uint16_t);
# 2 "../timers.c" 2

extern volatile uint16_t tickCount[TMR_COUNT];




void StartTimer(const uint8_t timer, const uint16_t count)
{
 tickCount[timer] = count << 1;
}




_Bool TimerDone(const uint8_t timer)
{
 if (tickCount[timer] == 0) {
  return 1;
 }
 return 0;
}




void WaitMs(const uint16_t numMilliseconds)
{
 StartTimer(TMR_INTERNAL, numMilliseconds);
 while (!TimerDone(TMR_INTERNAL)) {
 }
}




void timer_ms_tick(uint32_t status, uintptr_t context)
{

 for (uint16_t i = 0; i < TMR_COUNT; i++) {
  if (tickCount[i] != 0) {
   tickCount[i]--;
  }
 }
}





void delay_us(uint32_t us)
{
}

void delay_ms(uint16_t ms)
{
 WaitMs(ms);
}
