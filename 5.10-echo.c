#include <stdio.h>

int main(int argc, char *argv[]) {
	for (size_t i = 1; i < argc; i++) {
		printf("%s%s", argv[i], (i + 1 < argc) ? " " : "");
	}
	printf("\n");
	return 0;
}
