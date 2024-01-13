#include <stdio.h>

long main() {
	int sum = 0;			// Variable to store sum of odd numbers
	
	// Loop to calculate sum of first 100 odd numbers 
	for (int odd = 1; odd <= 100; odd += 2) {
		sum += odd;
	}
	
	// Display the calculated sum
	printf("%d\n", sum);

	return 0;				// Return 0 to indicate successful program execution
}
