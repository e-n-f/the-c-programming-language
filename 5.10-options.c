#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

int main(int argc, char **argv) {
	setlocale(LC_ALL, "");

	bool except = false;
	bool number = false;

	size_t i;
	for (i = 1; i < argc && argv[i][0] == '-'; i++) {
		size_t j;
		for (j = 1; argv[i][j] != '\0'; j++) {
			switch (argv[i][j]) {
			case 'x':
				except = true;
				break;

			case 'n':
				number = true;
				break;

			default:
				fwprintf(stderr, L"find: unknown option %c\n", argv[i][j]);
				return 1;
			}
		}
	}

	if (i >= argc) {
		fwprintf(stderr, L"Usage: find [-xn] pattern\n");
		return 1;
	}

	size_t space = strlen(argv[i]) + 1;
	wchar_t pattern[space];
	if (mbstowcs(pattern, argv[i], space) == (size_t) -1) {
		fwprintf(stderr, L"find: couldn't convert pattern %s\n", argv[i]);
		return 1;
	}

	wchar_t line[MAXLINE];
	bool found = false;
	size_t lineno = 0;

	while (fgetws(line, MAXLINE, stdin) > 0) {
		lineno++;

		if ((wcsstr(line, pattern) != NULL) != except) {
			if (number) {
				wprintf(L"%zu: ", lineno);
			}

			wprintf(L"%ls", line);
			found = true;
		}
	}

	return !found;
}
