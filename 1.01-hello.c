#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	wprintf(L"hello, world\n");
	return 0;
}
