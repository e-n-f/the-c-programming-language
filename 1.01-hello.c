#include <uchar.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	printf("hello, world\n");
	return 0;
}
