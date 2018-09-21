#include <uchar.h>
#include <locale.h>

int power(int base, size_t n);

int main() {
	size_t i;

	setlocale(LC_ALL, "");

	for (i = 0; i < 10; i++) {
		printf("%zu %d %d\n", i, power(2, i), power(-3, i));
	}

	return 0;
}

int power(int base, size_t n) {
	int p;
	size_t i;

	p = 1;
	for (i = 0; i < n; i++) {
		p = p * base;
	}

	return p;
}
