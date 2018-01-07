#include <wchar.h>
#include <locale.h>

int power(int base, size_t n);

int main() {
	setlocale(LC_ALL, "");

	size_t i;
	for (i = 0; i < 10; i++) {
		wprintf(L"%zu %d %d\n", i, power(2, i), power(-3, i));
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
