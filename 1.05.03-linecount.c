#include <uchar.h>
#include <locale.h>

// Count lines

int main() {
	c32int_t c;
	long nl;

	setlocale(LC_ALL, "");

	nl = 0;
	while ((c = getchar32()) != WEOF) {
		if (c == U'\n') {
			nl++;
		}
	}

	printf("%ld\n", nl);
	return 0;
}
