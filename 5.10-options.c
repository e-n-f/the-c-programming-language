#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

wint_t mbrtowcat(const char **s, const char *end, mbstate_t *mbs) {
	mbstate_t mbs2 = *mbs;
	wchar_t wc;

	size_t ret = mbrtowc(&wc, *s, end - *s, &mbs2);
	if (ret == 0) {
		return L'\0';
	}
	if (ret == (size_t) -1) {
		return WEOF; // encoding error
	}
	if (ret == (size_t) -2) {
		return WEOF; // incomplete character
	}
	*s += ret;
	return wc;
}

wint_t mbrtowcnext(const char **s, const char *end, mbstate_t *mbs) {
	mbstate_t mbs2 = *mbs;
	wchar_t wc;

	size_t ret = mbrtowc(&wc, *s, end - *s, &mbs2);
	if (ret == 0) {
		*s += 1;
		return L'\0';
	}
	if (ret == (size_t) -1) {
		*s += 1;
		return WEOF; // encoding error
	}
	if (ret == (size_t) -2) {
		*s += 1;
		return WEOF; // incomplete character
	}
	*s += ret;
	return wc;
}

int main(int argc, char **argv) {
	setlocale(LC_ALL, "");

	bool except = false;
	bool number = false;

	size_t i;
	for (i = 1; i < argc; i++) {
		printf("looking at %zu: %s\n", i, argv[i]);
		const char *s = argv[i];
		const char *end = argv[i] + strlen(argv[i]);
		mbstate_t mbs = { 0 };

		if (mbrtowcat(&s, end, &mbs) != L'-') {
			printf("found %lc\n", mbrtowcat(&s, end, &mbs));
			break;
		}

		// Skip past minus
		mbrtowcnext(&s, end, &mbs);

		for (; mbrtowcat(&s, end, &mbs) != L'\0'; mbrtowcnext(&s, end, &mbs)) {
			switch (mbrtowcat(&s, end, &mbs)) {
			case L'x':
				except = true;
				break;

			case L'n':
				number = true;
				break;

			default:
				fprintf(stderr, "find: unknown option %lc\n", mbrtowcat(&s, end, &mbs));
				return 1;
			}
		}
	}

	if (i >= argc) {
		fprintf(stderr, "Usage: find [-xn] pattern\n");
		return 1;
	}

	printf("%zu, %s\n", i, argv[i]);

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
