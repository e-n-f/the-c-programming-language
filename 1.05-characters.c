#include <wchar.h>
#include <locale.h>

// Copy input to output

int main() {
	wint_t c;

	setlocale(LC_ALL, "");

	c = getwchar();
	while (c != WEOF) {
		putwchar(c);
		c = getchar();
	}

	return 0;
}
