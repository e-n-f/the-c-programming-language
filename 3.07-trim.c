#include <wchar.h>
#include <wctype.h>
#include <locale.h>

size_t trim(wchar_t s[]) {
	size_t i;

	for (i = wcslen(s); i > 0; i--) {
		if (!iswspace(s[i - 1])) {
			break;
		}
	}

	s[i] = L'\0';
	return i;
}

// Test code, not given

int main() {
	setlocale(LC_ALL, "");

	wchar_t s[2000];
	while (fgetws(s, 2000, stdin)) {
		size_t lim = trim(s);
		wprintf(L"%zu: %ls\n", lim, s);
	}
}
