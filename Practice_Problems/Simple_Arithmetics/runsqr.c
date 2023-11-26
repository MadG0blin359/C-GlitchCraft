#include <stdio.h>
#include <math.h> // Include math.h library to calculate power

int calculateSquare(int num) {		// Function to calculate square of a number
	return pow(num, 2);
}

int calculateCube(int num) {		// Function to calculate cube of a number
	return pow(num, 3);
}

int main() {
	int num;	// Declare the num variable to store the user input
	
	printf("Enter an integer = ");		// Prompt the user to input an integer
	scanf("%d", &num);	// Read and store the user input in num
	
	if(num<0) {
		printf("The integer is negative & the square of the integer is = %d\n", calculateSquare(num));	// Call the function and display the calculated result
	}
	
	else {
		printf("The integer is positive & the cube of the integer is = %d\n", calculateCube(num));	// Call the function and display the calculated result
	}
	
	return 0;	// Return 0 to indicate successful program execution
}
	
