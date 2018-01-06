#include <stdio.h>
#include <wchar.h>
#include <locale.h>

// Print Fahrenheit-Celsius table
// for fahr = 0, 20, ..., 300

#define LOWER 0		// lower limit of table
#define UPPER 300	// upper limit of table
#define STEP 20		// step size

int main() {
	setlocale(LC_ALL, "");

	int fahr;
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
		wprintf(L"%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}

	return 0;
}
