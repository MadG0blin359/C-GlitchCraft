#include <stdio.h>
int increment();	// Declare the function for incrementing
int multiply();		// Declare the function for multiplying

int main() {
	int count = 5;		// Initialize the variable count with value 5
	
	// Display the incremented value of variable count
	printf("The incremented value of %d is %d \n", count, increment(count));
	
	// Display the multiplication of count with 2
	printf("The multiplication of %d & 2 is %d \n", count, multiply(count));
	
	return 0;	// Return 0 for successful program execution
}

int increment(int count) {	// Define the function to increment the count value 
	return ++count;		// Return the pre-incremented value to main 
}

int multiply(int count) {	// Define the function to multiply the count value by 2
	return count*2;		// Return the multiplyed value to main
}
