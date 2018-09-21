#include <uchar.h>
#include <locale.h>

// Copy input to output

int main() {
	c32int_t c;

	setlocale(LC_ALL, "");

	c = getchar32();
	while (c != WEOF) {
		putchar32(c);
		c = getchar32();
	}

	return 0;
}
