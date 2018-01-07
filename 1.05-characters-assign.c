#include <wchar.h>
#include <locale.h>

// Copy input to output

int main() {
	wint_t c;

	setlocale(LC_ALL, "");

	while ((c = getwchar()) != WEOF) {
		putwchar(c);
	}

	return 0;
}
