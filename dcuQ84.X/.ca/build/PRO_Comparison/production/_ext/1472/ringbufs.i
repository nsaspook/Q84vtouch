# 1 "../ringbufs.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/root/.mchp_packs/Microchip/PIC18F-Q_DFP/1.18.389/xc8/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "../ringbufs.c" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/string.h" 1 3



# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/musl_xc8.h" 1 3
# 5 "/opt/microchip/xc8/v2.41/pic/include/c99/string.h" 2 3





# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/features.h" 1 3
# 11 "/opt/microchip/xc8/v2.41/pic/include/c99/string.h" 2 3
# 25 "/opt/microchip/xc8/v2.41/pic/include/c99/string.h" 3
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3
# 122 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef unsigned size_t;
# 168 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef __int24 int24_t;
# 204 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 411 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef struct __locale_struct * locale_t;
# 26 "/opt/microchip/xc8/v2.41/pic/include/c99/string.h" 2 3

void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);

char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);

char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);

int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);

int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);

char *strchr (const char *, int);
char *strrchr (const char *, int);

size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);

size_t strlen (const char *);

char *strerror (int);




char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);




void *memccpy (void *restrict, const void *restrict, int, size_t);
# 2 "../ringbufs.c" 2
# 1 "../ringbufs.h" 1
# 14 "../ringbufs.h"
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stdlib.h" 1 3
# 21 "/opt/microchip/xc8/v2.41/pic/include/c99/stdlib.h" 3
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3
# 18 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef long int wchar_t;
# 22 "/opt/microchip/xc8/v2.41/pic/include/c99/stdlib.h" 2 3

int atoi (const char *);
long atol (const char *);
long long atoll (const char *);
double atof (const char *);

float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);
long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);

int rand (void);
void srand (unsigned);

void *malloc (size_t);
void *calloc (size_t, size_t);
void *realloc (void *, size_t);
void free (void *);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));







__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);
long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);

typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);
# 15 "../ringbufs.h" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stdint.h" 1 3
# 22 "/opt/microchip/xc8/v2.41/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3
# 127 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef long intptr_t;
# 158 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 173 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef long int32_t;





typedef long long int64_t;
# 188 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 209 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
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
# 16 "../ringbufs.h" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stdbool.h" 1 3
# 17 "../ringbufs.h" 2


 typedef struct ringBufS_t {
  uint8_t buf[32];
  uint8_t head;
  uint8_t tail;
  uint8_t count;
 } ringBufS_t;

 void *ringBufS_init(volatile ringBufS_t *_this);
 int8_t ringBufS_empty(ringBufS_t *_this);
 int8_t ringBufS_full(ringBufS_t *_this);
 uint8_t ringBufS_get(ringBufS_t *_this);
 void ringBufS_put(ringBufS_t *_this, const uint8_t c);
 void ringBufS_put_dma(ringBufS_t *_this, const uint8_t c);
 void ringBufS_put_dma_cpy(ringBufS_t *, const char *, const uint8_t);
 void *ringBufS_flush(ringBufS_t *_this, const _Bool clearBuffer);
# 3 "../ringbufs.c" 2




uint8_t modulo_inc(const uint8_t value, const uint8_t modulus)
{
 uint8_t my_value = value + 1;
 if (my_value >= modulus) {
  my_value = 0;
 }
 return my_value;
}

uint8_t modulo_dec(const uint8_t value, const uint8_t modulus)
{
 uint8_t my_value = (0 == value) ? (modulus - 1) : (value - 1);
 return my_value;
}

void *ringBufS_init(volatile ringBufS_t *_this)
{
# 32 "../ringbufs.c"
 return memset((void*) _this, 0, sizeof(*_this));
}

int8_t ringBufS_empty(ringBufS_t *_this)
{
 return(0 == _this->count);
}

int8_t ringBufS_full(ringBufS_t *_this)
{
 return(_this->count >= 32);
}

uint8_t ringBufS_get(ringBufS_t *_this)
{
 uint8_t c;
 if (_this->count > 0) {
  c = _this->buf[_this->tail];
  _this->tail = modulo_inc(_this->tail, 32);
  --_this->count;
 } else {
  c = 0;
 }
 return(c);
}

void ringBufS_put(ringBufS_t *_this, const uint8_t c)
{
 if (_this->count < 32) {
  _this->buf[_this->head] = c;
  _this->head = modulo_inc(_this->head, 32);
  ++_this->count;
 }
}

void ringBufS_put_dma(ringBufS_t *_this, const uint8_t c)
{
 if (_this->count < 32) {
  _this->buf[_this->head] = c;
  ++_this->head;
  ++_this->count;
 }
}

void ringBufS_put_dma_cpy(ringBufS_t *_this, const char *ptr, const uint8_t len)
{
 if (_this->count < 32) {
  memcpy(_this->buf, ptr, len);
  _this->head = len;
  _this->count = len;
 }
}

void *ringBufS_flush(ringBufS_t *_this, const _Bool clearBuffer)
{
 void *tmp = ((void*)0);

 _this->count = 0;
 _this->head = 0;
 _this->tail = 0;
 if (clearBuffer) {
  tmp = memset(_this->buf, 0, sizeof(_this->buf));
 }
 return tmp;
}
