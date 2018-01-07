#include <stdio.h>
#include <wchar.h>
#include <locale.h>

// Count characters

int main() {
	setlocale(LC_ALL, "");

	size_t nc;
	nc = 0;

	for (nc = 0; getwchar() != WEOF; nc++) {
		;
	}

	wprintf(L"%zu\n", nc);
	return 0;
}
