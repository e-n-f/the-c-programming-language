#include <wchar.h>
#include <locale.h>

// Copy input to output

int main() {
	setlocale(LC_ALL, "");

	wint_t c;
	while ((c = getwchar()) != WEOF) {
		putwchar(c);
	}

	return 0;
}
