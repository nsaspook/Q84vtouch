# 1 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/root/.mchp_packs/Microchip/PIC18F-Q_DFP/1.18.389/xc8/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2


# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/ctype.h" 1 3







# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/features.h" 1 3
# 9 "/opt/microchip/xc8/v2.41/pic/include/c99/ctype.h" 2 3

int isalnum(int);
int isalpha(int);
int isblank(int);
int iscntrl(int);
int isdigit(int);
int isgraph(int);
int islower(int);
int isprint(int);
int ispunct(int);
int isspace(int);
int isupper(int);
int isxdigit(int);
int tolower(int);
int toupper(int);
# 4 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/math.h" 1 3



# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/musl_xc8.h" 1 3
# 5 "/opt/microchip/xc8/v2.41/pic/include/c99/math.h" 2 3





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
# 11 "/opt/microchip/xc8/v2.41/pic/include/c99/math.h" 2 3




# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3
# 33 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef float float_t;




typedef double double_t;
# 16 "/opt/microchip/xc8/v2.41/pic/include/c99/math.h" 2 3
# 42 "/opt/microchip/xc8/v2.41/pic/include/c99/math.h" 3
int __fpclassifyf(float);







int __signbitf(float);
# 59 "/opt/microchip/xc8/v2.41/pic/include/c99/math.h" 3
double acos(double);
float acosf(float);
long double acosl(long double);



double acosh(double);
float acoshf(float);
long double acoshl(long double);



double asin(double);
float asinf(float);
long double asinl(long double);



double asinh(double);
float asinhf(float);
long double asinhl(long double);



double atan(double);
float atanf(float);
long double atanl(long double);



double atan2(double, double);
float atan2f(float, float);
long double atan2l(long double, long double);



double atanh(double);
float atanhf(float);
long double atanhl(long double);



double cbrt(double);
float cbrtf(float);
long double cbrtl(long double);



double ceil(double);
float ceilf(float);
long double ceill(long double);



double copysign(double, double);
float copysignf(float, float);
long double copysignl(long double, long double);



double cos(double);
float cosf(float);
long double cosl(long double);



double cosh(double);
float coshf(float);
long double coshl(long double);



double erf(double);
float erff(float);
long double erfl(long double);



double erfc(double);
float erfcf(float);
long double erfcl(long double);



double exp(double);
float expf(float);
long double expl(long double);



double exp2(double);
float exp2f(float);
long double exp2l(long double);



double expm1(double);
float expm1f(float);
long double expm1l(long double);



double fabs(double);
float fabsf(float);
long double fabsl(long double);



double fdim(double, double);
float fdimf(float, float);
long double fdiml(long double, long double);



double floor(double);
float floorf(float);
long double floorl(long double);



double fma(double, double, double);
float fmaf(float, float, float);
long double fmal(long double, long double, long double);



double fmax(double, double);
float fmaxf(float, float);
long double fmaxl(long double, long double);



double fmin(double, double);
float fminf(float, float);
long double fminl(long double, long double);



double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);



double frexp(double, int *);
float frexpf(float, int *);
long double frexpl(long double, int *);



double hypot(double, double);
float hypotf(float, float);
long double hypotl(long double, long double);



int ilogb(double);
int ilogbf(float);
int ilogbl(long double);



double ldexp(double, int);
float ldexpf(float, int);
long double ldexpl(long double, int);



double lgamma(double);
float lgammaf(float);
long double lgammal(long double);



long long llrint(double);
long long llrintf(float);
long long llrintl(long double);



long long llround(double);
long long llroundf(float);
long long llroundl(long double);



double log(double);
float logf(float);
long double logl(long double);



double log10(double);
float log10f(float);
long double log10l(long double);



double log1p(double);
float log1pf(float);
long double log1pl(long double);



double log2(double);
float log2f(float);
long double log2l(long double);



double logb(double);
float logbf(float);
long double logbl(long double);



long lrint(double);
long lrintf(float);
long lrintl(long double);



long lround(double);
long lroundf(float);
long lroundl(long double);



double modf(double, double *);
float modff(float, float *);
long double modfl(long double, long double *);



double nan(const char *);
float nanf(const char *);
long double nanl(const char *);



double nearbyint(double);
float nearbyintf(float);
long double nearbyintl(long double);



double nextafter(double, double);
float nextafterf(float, float);
long double nextafterl(long double, long double);



double nexttoward(double, long double);
float nexttowardf(float, long double);
long double nexttowardl(long double, long double);
# 323 "/opt/microchip/xc8/v2.41/pic/include/c99/math.h" 3
double pow(double, double);
__attribute__((nonreentrant)) float powf(float, float);
long double powl(long double, long double);



double remainder(double, double);
float remainderf(float, float);
long double remainderl(long double, long double);



double remquo(double, double, int *);
float remquof(float, float, int *);
long double remquol(long double, long double, int *);



double rint(double);
float rintf(float);
long double rintl(long double);



double round(double);
float roundf(float);
long double roundl(long double);



double scalbln(double, long);
float scalblnf(float, long);
long double scalblnl(long double, long);



double scalbn(double, int);
float scalbnf(float, int);
long double scalbnl(long double, int);



double sin(double);
float sinf(float);
long double sinl(long double);



double sinh(double);
float sinhf(float);
long double sinhl(long double);



double sqrt(double);
float sqrtf(float);
long double sqrtl(long double);



double tan(double);
float tanf(float);
long double tanl(long double);



double tanh(double);
float tanhf(float);
long double tanhl(long double);



double tgamma(double);
float tgammaf(float);
long double tgammal(long double);



double trunc(double);
float truncf(float);
long double truncl(long double);
# 428 "/opt/microchip/xc8/v2.41/pic/include/c99/math.h" 3
extern int signgam;

double j0(double);
double j1(double);
double jn(int, double);

double y0(double);
double y1(double);
double yn(int, double);
# 5 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stdarg.h" 1 3







# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3





typedef void * va_list[1];
# 9 "/opt/microchip/xc8/v2.41/pic/include/c99/stdarg.h" 2 3

#pragma intrinsic(__va_start)
#pragma intrinsic(__va_arg)

extern void * __va_start(void);
extern void * __va_arg(void *, ...);
# 6 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stddef.h" 1 3
# 19 "/opt/microchip/xc8/v2.41/pic/include/c99/stddef.h" 3
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3
# 18 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef long int wchar_t;
# 122 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef unsigned size_t;
# 132 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef int ptrdiff_t;
# 20 "/opt/microchip/xc8/v2.41/pic/include/c99/stddef.h" 2 3
# 7 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2

# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stdio.h" 1 3
# 24 "/opt/microchip/xc8/v2.41/pic/include/c99/stdio.h" 3
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3
# 11 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef void * __isoc_va_list[1];
# 137 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef long ssize_t;
# 246 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef long long off_t;
# 399 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 25 "/opt/microchip/xc8/v2.41/pic/include/c99/stdio.h" 2 3
# 52 "/opt/microchip/xc8/v2.41/pic/include/c99/stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);
int getch(void);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);
void putch(char);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

__attribute__((__format__(__printf__, 1, 2)))
int printf(const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int fprintf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 2, 3)))
int sprintf(char *restrict, const char *restrict, ...);
__attribute__((__format__(__printf__, 3, 4)))
int snprintf(char *restrict, size_t, const char *restrict, ...);

__attribute__((__format__(__printf__, 1, 0)))
int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 2, 0)))
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__printf__, 3, 0)))
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

__attribute__((__format__(__scanf__, 1, 2)))
int scanf(const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int fscanf(FILE *restrict, const char *restrict, ...);
__attribute__((__format__(__scanf__, 2, 3)))
int sscanf(const char *restrict, const char *restrict, ...);

__attribute__((__format__(__scanf__, 1, 0)))
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
__attribute__((__format__(__scanf__, 2, 0)))
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 9 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stdlib.h" 1 3
# 21 "/opt/microchip/xc8/v2.41/pic/include/c99/stdlib.h" 3
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3
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
# 10 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/string.h" 1 3
# 25 "/opt/microchip/xc8/v2.41/pic/include/c99/string.h" 3
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/bits/alltypes.h" 1 3
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
# 11 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/inline.h" 1 3
# 12 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2
# 1 "/opt/microchip/xc8/v2.41/pic/include/c99/stdbool.h" 1 3
# 13 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c" 2
# 90 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
typedef signed int vfpf_sint_t;
typedef unsigned int vfpf_uint_t;
# 118 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
static int prec, width;
static char flags;

union flui {
 long double f;



 int32_t u;

};
# 144 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
static char dbuf[32];







static void pad(FILE *fp, char *buf, int p)
{
    int i, w;



    if (flags & (1 << 0)) {
        fputs((const char *)buf, fp);
    }



    w = (p < 0) ? 0 : p;
    i = 0;
    while (i < w) {
        fputc(' ', fp);
        ++i;
    }



    if (!(flags & (1 << 0))) {

        fputs((const char *)buf, fp);

    }





}
# 433 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
static void ctoa(FILE *fp, char c)
{
    int l,w;


    w = width ? width - 1 : width;



    if (flags & (1 << 0)) {
        fputc(c, fp);
    }



    w = (w < 0) ? 0 : w;
    l = 0;
    while (l < w) {
        fputc(' ', fp);
        ++l;
    }


    if (!(flags & (1 << 0))) {

        fputc(c, fp);

    }





}



static void dtoa(FILE *fp, vfpf_sint_t d)
{
 char s;
    int i, p, w;


    s = d < 0 ? 1 : 0;
    if (s) {
        d = -d;
    }



    if (!(prec < 0)) {
        flags &= ~(1 << 1);
    }

    p = (0 <= prec) ? prec : 1;
    w = width;
    if (s



    ) {
        --w;
  s = s ? '-' : '+';
    }
# 505 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
    i = sizeof(dbuf) - 1;
    dbuf[i] = '\0';
    while (!(i < 1) && (d || (0 < p)

    || ((0 < w) && (flags & (1 << 1)))

    )) {
        --i;
        dbuf[i] = (char)((int)'0' + abs(d % 10));
        --p;
        --w;
        d = d / 10;
    }


    if (s != 0) {
        --i;
        dbuf[i] = s;
    }


    return (void) pad(fp, &dbuf[i], w);
}
# 862 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
static void stoa(FILE *fp, char *s)
{
    char *cp, nuls[] = "(null)";
    int i, l, p, w;


    cp = s;
    if (!cp) {
        cp = nuls;
    }


    l = (int)strlen(cp);
    p = prec;
    l = (!(p < 0) && (p < l)) ? p : l;
    p = l;
    w = width;



    if (!(flags & (1 << 0))) {

        while (l < w) {
            fputc(' ', fp);
            ++l;
        }

    }



    i = 0;
    while (i < p) {
        fputc(*cp, fp);
        ++cp;
        ++i;
    }



    if (flags & (1 << 0)) {
        while (l < w) {
            fputc(' ', fp);
            ++l;
        }
    }





}
# 952 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
static void xtoa(FILE *fp, vfpf_uint_t d, char x)





{
 char c;
    int i, p, w;






    if (!(prec < 0)) {
        flags &= ~(1 << 1);
    }

    p = (0 <= prec) ? prec : 1;
    w = width;
# 981 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
    i = sizeof(dbuf) - 1;
    dbuf[i] = '\0';
    while (!(i < 2) && (d || (0 < p)

    || ((0 < w) && (flags & (1 << 1)))

    )) {
        --i;
        c = d & 0x0f;

        c = (c < 10) ? (int)'0' + c : (int)'a' + (c - 10);

        if ((0 && isupper((int)x), ((unsigned)((int)x)-'A') < 26) && (0 && isalpha(c), (((unsigned)(c)|32)-'a') < 26)) {
            c = (char) toupper(c);
        }




        dbuf[i] = (char)c;
        --p;
        --w;
        d = d >> 4;
    }
# 1023 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
    return (void) pad(fp, &dbuf[i], w);
}



static int
read_prec_or_width (const char **fmt, va_list *ap) {
    int n = 0;
    if ((*fmt)[0] == '*') {
        ++*fmt;
        n = (*(int *)__va_arg(*(int **)*ap, (int)0));
    } else {
        unsigned char c;
        while ((c = ((unsigned)(*fmt)[0]) - '0') < 10) {
            n = n * 10 + c;
            ++*fmt;
        }
    }
    return n;
}




static void
vfpfcnvrt(FILE *fp, char *fmt[], va_list ap)
{
    char c, *cp;
    int done, i;
 union {

  vfpf_sint_t sint;
  vfpf_uint_t uint;

  void *vp;
  long double f;
 } convarg;


    if ((*fmt)[0] == '%') {
        ++*fmt;

        flags = width = 0;
        prec = -1;



        done = 0;
        while (!done) {
            switch ((*fmt)[0]) {







                case '0' :
                    flags |= (1 << 1);
                    ++*fmt;
                    break;
# 1103 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
                default:
                    done = 1;
                    break;
            }
        }
# 1117 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
  width = read_prec_or_width(fmt, ap);
  if (width < 0) {
   flags |= (1 << 0);
   width = -width;
  }
# 1134 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
        if (*fmt[0] == 'c') {
            ++*fmt;
            c = (unsigned char)(*(int *)__va_arg(*(int **)ap, (int)0));
            return (void) ctoa(fp, c);
        }




  cp = *fmt;
# 1213 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
  if (*cp == 'd' || *cp == 'i') {
# 1256 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
   convarg.sint = (vfpf_sint_t)(int)(*(int *)__va_arg(*(int **)ap, (int)0));

   *fmt = cp+1;
   return (void) dtoa(fp, convarg.sint);
  }




  if (0

    || *cp == 'x'


    || *cp == 'X'







    ) {
# 1321 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
   convarg.uint = (vfpf_uint_t)(unsigned int)(*(unsigned int *)__va_arg(*(unsigned int **)ap, (unsigned int)0));

   *fmt = cp+1;
   switch (*cp) {
# 1335 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
    case 'X':


    case 'x':

     return (void) xtoa(fp,convarg.uint,*cp);

   }
  }
# 1409 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
        if (*fmt[0] == 's' || !strncmp(*fmt, "lls", ((sizeof("lls")/sizeof("lls"[0]))-1))) {

   *fmt += *fmt[0] == 's' ? 1 : ((sizeof("lls")/sizeof("lls"[0]))-1);
            return (void) stoa(fp, (*(char * *)__va_arg(*(char * **)ap, (char *)0)));
        }
# 1535 "/opt/microchip/xc8/v2.41/pic/sources/c99/common/doprnt.c"
        ++*fmt;
        return (void) 0;
    }


    fputc((int)(*fmt)[0], fp);
    ++*fmt;
    return (void) 1;
}


int vfprintf(FILE *fp, const char *fmt, va_list ap)
{

    char *cfmt;

    cfmt = (char *)fmt;



    while (*cfmt) {



   vfpfcnvrt(fp, &cfmt, ap);
    }



 return 0;




}
