#include <stdio.h>

int main () {
	int sum = 0; 		// Variable to store sum of odd numbers
	int odd = 1;		// Variable to iterate through odd numbers
	
	// Loop to calculate sum of first 100 odd numbers 
	for (int i = 1; i <= 100; i++) {
		
		sum += odd;	
		odd += 2;
		
		// Display the calculated sum at each iteration
		printf("%d ", sum);
		
	}

	return 0;		// Return 0 to indicate successful program execution
}
