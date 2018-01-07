#include <wchar.h>
#include <locale.h>

// Count characters

int main() {
	long nc;

	setlocale(LC_ALL, "");

	nc = 0;
	while (getwchar() != WEOF) {
		nc++;
	}

	wprintf(L"%ld\n", nc);
	return 0;
}
