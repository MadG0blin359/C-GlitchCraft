#include <stdio.h>
#include <math.h>	// using math library to use sqrt function

int myAbsolute(int num) {	// Define a function named myAbsolute that takes an integer (num) as input
	if(num>=0) {		    // Check if the input number is greater than or equal to 0
		return num;	        // If it's non-negative, return the number itself (no change)
	}
	
	else {		        // If it's negative, return the negation of the number (absolute value)

		return sqrt(num*num);
	}
}

int main() {
	int num;	
	
	printf("Enter an integer = ");	// Prompt the user to input an integer
	scanf("%d", &num);	// Read and store the user's input in the variable 'num'
	
	printf("The absolute value of %d is %d\n", num, myAbsolute(num));	    // Calculate the absolute value using the 'myAbsolute' function and display the result
	
	return 0;	// Return 0 to indicate to succesful program execution
}



