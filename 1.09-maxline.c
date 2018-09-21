#include <uchar.h>
#include <locale.h>
#include <stdbool.h>

#define MAXLINE 1000

size_t readline(char32_t out[], size_t limit);
void copy(char32_t to[], char32_t from[]);

int main() {
	size_t max;
	char32_t line[MAXLINE];
	char32_t longest[MAXLINE];
	size_t len;

	setlocale(LC_ALL, "");

	max = 0;

	while ((len = readline(line, MAXLINE)) > 0) {
		if (len > max) {
			copy(longest, line);
			max = len;
		}
	}

	if (max > 0) { // there was a line
		printf("%ls", longest);
	}

	return 0;
}

size_t readline(char32_t out[], size_t limit) {
	size_t i;
	bool done;
	c32int_t c;

	i = 0;
	done = false;

	while (!done) {
		if (i + 1 >= limit) {
			done = true;
		} else {
			c = getchar32();
			if (c == EOF) {
				done = true;
			} else {
				out[i] = c;
				i++;

				if (c == '\n') {
					done = true;
				}
			}
		}
	}

	out[i] = L'\0';
	return i;
}

void copy(char32_t to[], char32_t from[]) {
	size_t i;

	i = 0;
	while ((to[i] = from[i]) != U'\0') {
		i++;
	}
}
