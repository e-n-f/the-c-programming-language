#include <wchar.h>
#include <locale.h>

// The alloc part

#define ALLOCSIZE 100000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

void *alloc(size_t n) {
	if ((allocp - allocbuf) + n <= ALLOCSIZE) {
		// It fits
		void *ret = allocp;
		allocp += n;
		return ret;
	} else {
		// Not enough room
		return NULL;
	}
}

void afree(void *v) {
	char *p = v;

	if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
		allocp = p;
	} else {
		wprintf(L"error: afree called with invalid pointer\n");
	}
}

// The sort part

void swap(wchar_t *lines[], size_t i, size_t j) {
	wchar_t *tmp = lines[i];
	lines[i] = lines[j];
	lines[j] = tmp;
}

void sort(wchar_t *lines[], size_t left, size_t right) {
	if (left < right) {
		swap(lines, left, (left + right) / 2);

		size_t last = left;
		for (size_t i = left + 1; i < right; i++) {
			if (wcscmp(lines[i], lines[left]) < 0) {
				last++;
				swap(lines, last, i);
			}
		}

		swap(lines, left, last);

		sort(lines, left, last);
		sort(lines, last + 1, right);
	}
}

// The I/O part

#define MAXLINES 5000
#define MAXLEN 1000

wchar_t *lineptr[MAXLINES];

ssize_t readlines(wchar_t *lineptr[], size_t maxlines);
void writelines(wchar_t *lineptr[], size_t nlines);
size_t readline(wchar_t out[], size_t limit);

int main() {
	ssize_t nlines = readlines(lineptr, MAXLINES);

	if (nlines >= 0) {
		sort(lineptr, 0, nlines);
		writelines(lineptr, nlines);
		return 0;
	} else {
		wprintf(L"error: too big to sort\n");
		return 1;
	}
}

ssize_t readlines(wchar_t *lineptr[], size_t maxlines) {
	size_t nlines = 0;
	size_t len;
	wchar_t line[MAXLEN];

	while ((len = readline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines) {
			return -1;
		}

		wchar_t *p = alloc(len * sizeof(wchar_t));
		if (p == NULL) {
			return -1;
		}

		line[len - 1] = L'\0'; // replace \n with \0
		wcscpy(p, line);
		lineptr[nlines++] = p;
	}

	return nlines;
}

// as before
size_t readline(wchar_t out[], size_t limit) {
	size_t i;
	wint_t c;

	i = 0;
	while (i + 1 < limit) {
		c = getwchar();

		if (c == WEOF) {
			break;
		}

		out[i] = c;
		i++;

		if (c == L'\n') {
			break;
		}
	}

	out[i] = L'\0';
	return i;
}

void writelines(wchar_t *lines[], size_t nlines) {
	for (size_t i = 0; i < nlines; i++) {
		wprintf(L"%ls\n", lines[i]);
	}
}
