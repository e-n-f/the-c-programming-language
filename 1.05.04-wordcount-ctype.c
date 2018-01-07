#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <wctype.h>

// Count words

int main() {
	setlocale(LC_ALL, "");

	bool within_word = false;
	wint_t c;
	size_t nl, nw, nc;

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

	wprintf(L"%zu %zu %zu\n", nl, nw, nc);
	return 0;
}
