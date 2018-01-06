#include <stdio.h>
#include <wchar.h>
#include <locale.h>

// Print Fahrenheit-Celsius table
// for fahr = 0, 20, ..., 300

int main() {
	setlocale(LC_ALL, "");

	int fahr;
	for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
		wprintf(L"%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}

	return 0;
}
