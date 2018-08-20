#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");

	for (size_t i = 1; i < argc; i++) {
		size_t space = strlen(argv[i]) + 1;
		wchar_t pattern[space];

		if (mbstowcs(pattern, argv[i], space) == (size_t) -1) {
			fwprintf(stderr, L"find: couldn't convert pattern %s\n", argv[i]);
			return 1;
		}

		if (i + 1 < argc) {
			wprintf(L"%ls ", pattern);
		} else {
			wprintf(L"%ls", pattern);
		}
	}

	wprintf(L"\n");
	return 0;
}
