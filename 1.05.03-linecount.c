#include <stdio.h>
#include <wchar.h>
#include <locale.h>

// Count lines

int main() {
	setlocale(LC_ALL, "");

	wint_t c;
	size_t nl;

	nl = 0;
	while ((c = getwchar()) != WEOF) {
		if (c == L'\n') {
			nl++;
		}
	}

	wprintf(L"%zu\n", nl);
	return 0;
}
