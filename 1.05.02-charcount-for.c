#include <uchar.h>
#include <locale.h>

// Count characters

int main() {
	long long nc;

	setlocale(LC_ALL, "");

	nc = 0;
	for (nc = 0; getchar32() != C32EOF; nc++) {
		;
	}

	printf("%lld\n", nc);
	return 0;
}
