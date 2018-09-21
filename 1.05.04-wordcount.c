#include <uchar.h>
#include <locale.h>
#include <stdbool.h>

// Count words

int main() {
	bool within_word;
	c32int_t c;
	long nl, nw, nc;

	setlocale(LC_ALL, "");

	within_word = false;
	nl = nw = nc = 0;

	while ((c = getchar32()) != C32EOF) {
		nc++;

		if (c == U'\n') {
			nl++;
		}

		if (c == U' ' || c == U'\n' || c == U'\t') {
			within_word = false;
		} else if (!within_word) {
			within_word = true;
			nw++;
		}
	}

	printf("%ld %ld %ld\n", nl, nw, nc);
	return 0;
}
