#include <stdio.h>

// Function to check if the user input is a prime number or not
long checkPrime(long num) {
	// Declare variables to perform calculations
	long i, factor;
	// Initialize factor variable as 0 to avoid garbage values
	factor = 0;
	// Loop to go through numbers from 1 to num, to divide num by i
	for (i = 1; i <= num; i++) {
		// Check if the remainder is 0 by dividing num with i
		if (num %i == 0) {
			// If the remainder is zero, increment 1 in factor variable
			factor++;
		}
	}
	// Return factor
	return factor;
}

int main() {
	long num;
	
	// Prompt the user to enter any integer
	printf("\n\t\t****Welcome to Prime Machine!****\n");
	printf("--Enter any integer to check whether its a prime number or not: ");
	scanf("%ld", &num);
	
	// Call the function and store its value in new factor variable
	long factor = checkPrime(num);
	
	// Display the final result
	if (factor == 2) {
		printf("\'%ld\' is a Prime Number\n", num);
	}
	
	else {
		printf("\'%ld\' is not a Prime Number\n", num);
	}
	
	// Return 0 to indicate successful program execution
	return 0;
}
