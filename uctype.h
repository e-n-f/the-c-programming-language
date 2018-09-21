#include <uchar.h>
#include <wctype.h>
#include <ctype.h>

#define digitc32toint digittoint
#define isc32alnum iswalnum
#define isc32alpha iswalpha
#define isc32blank iswblank
#define isc32cntrl iswcntrl
#define isc32digit iswdigit
#define isc32graph iswgraph
#define isc32lower iswlower
#define isc32print iswprint
#define isc32punct iswpunct
#define isc32space iswspace
#define isc32upper iswupper
#define isc32xdigit iswxdigit

#define toc32lower towlower
#define toc32upper towupper

