#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int main(int argc, char **argv) {
	setlocale(LC_ALL, "");

	if (argc != 2) {
		fwprintf(stderr, L"Usage: find pattern\n");
		return 1;
	}

	size_t space = strlen(argv[1]) + 1;
	wchar_t pattern[space];
	if (mbstowcs(pattern, argv[1], space) == (size_t) -1) {
		fwprintf(stderr, L"find: couldn't convert pattern %s\n", argv[1]);
		return 1;
	}

	wchar_t line[MAXLINE];
	bool found = false;

	while (fgetws(line, MAXLINE, stdin) > 0) {
		if (wcsstr(line, pattern) != NULL) {
			wprintf(L"%ls", line);
			found = true;
		}
	}

	return !found;
}
