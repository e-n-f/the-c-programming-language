#include <uchar.h>
#include <locale.h>

// Copy input to output

int main() {
	c32int_t c;

	setlocale(LC_ALL, "");

	while ((c = getchar32()) != C32EOF) {
		putchar32(c);
	}

	return 0;
}
