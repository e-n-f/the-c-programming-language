#include <uchar.h>
#include <locale.h>

// Print Fahrenheit-Celsius table
// for fahr = 0, 20, ..., 300

#define LOWER 0		// lower limit of table
#define UPPER 300	// upper limit of table
#define STEP 20		// step size

int main() {
	int fahr;

	setlocale(LC_ALL, "");

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}

	return 0;
}
