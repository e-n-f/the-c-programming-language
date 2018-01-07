#include <wchar.h>
#include <locale.h>

// Count characters

int main() {
	long long nc;

	setlocale(LC_ALL, "");

	nc = 0;
	for (nc = 0; getwchar() != WEOF; nc++) {
		;
	}

	wprintf(L"%lld\n", nc);
	return 0;
}
