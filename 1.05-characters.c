#include <stdio.h>
#include <wchar.h>
#include <locale.h>

// Copy input to output

int main() {
	setlocale(LC_ALL, "");

	wint_t c;
	c = getwchar();

	while (c != WEOF) {
		putwchar(c);
		c = getchar();
	}

	return 0;
}
