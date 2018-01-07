#include <wchar.h>
#include <locale.h>

// Count characters

int main() {
	setlocale(LC_ALL, "");

	long long nc;
	nc = 0;

	for (nc = 0; getwchar() != WEOF; nc++) {
		;
	}

	wprintf(L"%lld\n", nc);
	return 0;
}
