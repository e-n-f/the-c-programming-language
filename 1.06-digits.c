#include <uchar.h>
#include <locale.h>
#include <stdbool.h>
#include <uctype.h>

// Count digits, whitespace, others

int main() {
	c32int_t c;
	size_t i;

	size_t nspace, nother;
	size_t ndigit[10];

	setlocale(LC_ALL, "");

	nspace = nother = 0;
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}

	while ((c = getchar32()) != EOF) {
		if (c >= '0' && c <= '9') {
			ndigit[digitc32toint(c)]++;
		} else if (isc32space(c)) {
			nspace++;
		} else {
			nother++;
		}
	}

	printf("digits =");
	for (i = 0; i < 10; i++) {
		printf(" %zu", ndigit[i]);
	}
	printf(", white space = %zu, other = %zu\n", nspace, nother);

	return 0;
}
