#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <wctype.h>

// Count digits, whitespace, others

int main() {
	setlocale(LC_ALL, "");

	wint_t c;
	size_t i;

	size_t nspace, nother;
	size_t ndigit[10];

	nspace = nother = 0;
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}

	while ((c = getwchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			ndigit[c - '0']++;
		} else if (iswspace(c)) {
			nspace++;
		} else {
			nother++;
		}
	}

	wprintf(L"digits =");
	for (i = 0; i < 10; i++) {
		wprintf(L" %zu", ndigit[i]);
	}
	wprintf(L", white space = %zu, other = %zu\n", nspace, nother);

	return 0;
}
