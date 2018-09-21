#include <uchar.h>
#include <locale.h>
#include <stdbool.h>
#include <uctype.h>

// Count words

int main() {
	bool within_word;
	c32int_t c;
	long nl, nw, nc;

	setlocale(LC_ALL, "");

	within_word = false;
	nl = nw = nc = 0;

	while ((c = getchar32()) != WEOF) {
		nc++;

		if (c == L'\n') {
			nl++;
		}

		if (isc32space(c)) {
			within_word = false;
		} else if (!within_word) {
			within_word = true;
			nw++;
		}
	}

	printf("%ld %ld %ld\n", nl, nw, nc);
	return 0;
}
