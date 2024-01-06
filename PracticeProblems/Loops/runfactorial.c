#include <stdio.h>

// Function to calculate the factorial of a given number
long calculateFactorail(long num) {
	// Declare variables to perform calculations
	long factorial, i;
	// Initialize the factorial to 0
	factorial = 0;
	// Initialize the i to 2, to start multiplying with 2 rather from 1
	i = 2; 
	
	factorial += num * i;
	i++;
	
	// Loop from 2 to num
	for(num; i < num; i++) {
		
		// Calculate the factorial
		factorial = factorial * i;
		
	}
	
	// Return calculated factorial
	return factorial;
}

int main() {
	long num;
	
	// Prompt the user to enter an integer for factorial calculation
	printf("Enter any integer to calculate its factorial: ");
	scanf("%ld", &num);

	// Declare a new factorial variable to store the value returning from the function calculateFactorail
	long factorial = calculateFactorail(num);
	// Display the calculated factorial
	printf("%ld\n", factorial);

	// Return 0 to indicate successful program execution
	return 0;
}
