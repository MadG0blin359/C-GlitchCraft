#include <stdio.h>

float arithematicseries() {	// Function to calculate the sum of an arithmetic series
	float sum, a, n, d;	// Declare the variables to store the user input
	
	// Prompt the user to enter the first term of the series
	printf("Enter the first term of the series = ");
	scanf("%g", &a);
	
	// Prompt the user to enter the number of terms (n) or the nth term
	printf("Enter the number of term (n) or the nth term = ");	
	scanf("%g", &n);
	
	// Prompt the user to enter the common difference of the consecutive terms
	printf("Enter the common difference of the consecutive terms = ");	    
	scanf("%g", &d);	
	
	sum = (n/2)*(2*a + (n - 1)*d);	    // Calculate the sum of the arithmetic series
	
	return sum;	// Return the calculated sum
}

int main() {
	
	// Call the arithematicseries function to calculate the sum and display the result
	printf("The sum of the series is = %g\n", arithematicseries());

	return 0;	// Return 0 to indicate successful program execution 
}
