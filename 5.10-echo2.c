#include <stdio.h>

int main(int argc, char *argv[]) {
	argv++;
	argc--;

	while (argc > 0) {
		printf("%s%s", *argv, (argc - 1 > 0) ? " " : "");

		argv++;
		argc--;
	}

	printf("\n");
	return 0;
}
