#include <wchar.h>
#include <locale.h>

// Count characters

int main() {
	setlocale(LC_ALL, "");

	long nc;
	nc = 0;

	while (getwchar() != WEOF) {
		nc++;
	}

	wprintf(L"%ld\n", nc);
	return 0;
}
