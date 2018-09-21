#include <uchar.h>
#include <locale.h>

// Count characters

int main() {
	long nc;

	setlocale(LC_ALL, "");

	nc = 0;
	while (getchar32() != C32EOF) {
		nc++;
	}

	printf("%ld\n", nc);
	return 0;
}
