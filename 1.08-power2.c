#include <wchar.h>
#include <locale.h>

int power(int base, size_t n);

int main() {
	size_t i;

	setlocale(LC_ALL, "");

	for (i = 0; i < 10; i++) {
		wprintf(L"%zu %d %d\n", i, power(2, i), power(-3, i));
	}

	return 0;
}

int power(int base, size_t n) {
	int p;

	p = 1;
	for (; n > 0; n--) {
		p = p * base;
	}

	return p;
}
