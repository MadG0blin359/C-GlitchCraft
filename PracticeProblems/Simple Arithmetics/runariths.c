#include <stdio.h>
float arithematicseries(float a, float n, float d);		// Declaring function prototype with parameters and return type float to calculate the sum of the series

int main() {
	// declaring variables to store user input
	float a, n, d;
	
	// Prompt the user to enter first term of the seires
	printf("Enter the first term of the series = ");
	scanf("%g", &a);
	
	// Prompt the user to enter the number of seires
	printf("Enter the number of term (n) or the nth term = ");
	scanf("%g", &n);
	
	// Prompt the user to enter the common difference
	printf("Enter the common difference of the consecutive terms = ");
	scanf("%g", &d);
	
	// Display the final result by calling the function
	printf("The sum of the series is = %g\n", arithematicseries(a, n, d));

	return 0;
}

// Function to calculate the sum of seires
float arithematicseries(float a, float n, float d) {
	float sum;
	
	// Formula of the sum of series 
	sum = (n/2)*(2*a + (n - 1)*d);
	
	// Return calculated sum
	return sum;
}
