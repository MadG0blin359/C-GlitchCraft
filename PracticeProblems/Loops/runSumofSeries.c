#include <stdio.h>

int main() {
	int denominator = 4;	// Variable to be used as denominator
	float sum = 1;			// Variable to store sum of the series

	// Sum of the series 1 + 1/4 + 1/8 + 1/12 + ...1/100 
	do {
		sum += (float)1/denominator; 
		denominator += 4;
	}
	
	// Iterate until the denometer is equal to 100 
	while (denominator <= 100);
	
	// Display the calculated sum
	printf("Sum of the series is : %lg\n", sum);

	return 0;
}
