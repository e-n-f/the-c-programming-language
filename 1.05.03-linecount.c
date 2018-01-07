#include <wchar.h>
#include <locale.h>

// Count lines

int main() {
	wint_t c;
	long nl;

	setlocale(LC_ALL, "");

	nl = 0;
	while ((c = getwchar()) != WEOF) {
		if (c == L'\n') {
			nl++;
		}
	}

	wprintf(L"%ld\n", nl);
	return 0;
}
