#include <wchar.h>
#include <locale.h>
#include <stdbool.h>

// Count words

int main() {
	setlocale(LC_ALL, "");

	bool within_word = false;
	wint_t c;
	long nl, nw, nc;

	nl = nw = nc = 0;
	while ((c = getwchar()) != WEOF) {
		nc++;

		if (c == L'\n') {
			nl++;
		}

		if (c == L' ' || c == L'\n' || c == L'\t') {
			within_word = false;
		} else if (!within_word) {
			within_word = true;
			nw++;
		}
	}

	wprintf(L"%ld %ld %ld\n", nl, nw, nc);
	return 0;
}
