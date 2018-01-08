#include <wchar.h>
#include <locale.h>
#include <stdbool.h>

#define MAXLINE 1000

size_t readline(wchar_t out[], size_t limit);
ssize_t strindex(wchar_t haystack[], wchar_t needle[]);

wchar_t pattern[] = L"ould";

int main() {
	wchar_t line[MAXLINE];
	size_t found;

	setlocale(LC_ALL, "");

	found = 0;
	while (readline(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0) {
			wprintf(L"%ls", line);
			found++;
		}
	}

	return found;
}

size_t readline(wchar_t out[], size_t limit) {
	size_t i;
	wint_t c;

	i = 0;
	while (i + 1 < limit) {
		c = getwchar();

		if (c == WEOF) {
			break;
		}

		out[i] = c;
		i++;

		if (c == L'\n') {
			break;
		}
	}

	out[i] = L'\0';
	return i;
}

ssize_t strindex(wchar_t haystack[], wchar_t needle[]) {
	size_t i, j;

	for (i = 0; haystack[i] != L'\0'; i++) {
		for (j = 0; needle[j] != L'\0'; j++) {
			if (haystack[i + j] != needle[j]) {
				break;
			}
		}

		if (needle[j] == L'\0') {
			// reached the end without finding a mismatch
			return i;
		}
	}

	return -1;
}
