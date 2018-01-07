#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <wctype.h>

// Count words

int main() {
	bool within_word;
	wint_t c;
	long nl, nw, nc;

	setlocale(LC_ALL, "");

	within_word = false;
	nl = nw = nc = 0;

	while ((c = getwchar()) != WEOF) {
		nc++;

		if (c == L'\n') {
			nl++;
		}

		if (iswspace(c)) {
			within_word = false;
		} else if (!within_word) {
			within_word = true;
			nw++;
		}
	}

	wprintf(L"%ld %ld %ld\n", nl, nw, nc);
	return 0;
}
