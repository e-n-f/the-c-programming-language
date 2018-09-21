#include <wchar.h>

typedef wchar_t char32_t;
typedef wint_t c32int_t;

#define C32EOF WEOF

#define putchar32 putwchar
#define getchar32 getwchar
