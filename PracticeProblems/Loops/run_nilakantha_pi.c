#include <stdio.h>

// Function to calculate Pi
long double calculatePi(int terms) {
	long double pi = 0;
	int j = 2;
	
	// Loop to iterate according to the number of terms
	for (int i = 1; i <= terms; i++) {
		
		if (i == 1) {
			// Add first term of Nilakantha Series
			pi += 3;
		}
		
		else {
			// Subtraction according to the number of term (-Odd)
			if (i %2 != 0) {
				pi -= (long double)4/(j*(j+1)*(j+2));
			}
			
			// Addition according to the number of term (+Even)
			else {
				pi += (long double)4/(j*(j+1)*(j+2));
			}
			
			j += 2; // Increment j to move to the next denominator

		}
		
	}
	
	return pi;

}

int main() {
	int terms = 0;
	long double pi = 0;
	
	printf("\n\t\t*********Nilakantha Series*********\n\t\t     Calculate the Value of Pi\n");
	
	do {	
		// Prompt the user to enter the number of terms
		printf("\nEnter the number of terms: ");
		scanf("%d", &terms);
		
		if (terms < 0) {
			printf("\nInvlaid Input!\nEnter a Positive Integer.\n");
		}
		
		else {
			// Call and store the value in variable pi
			pi = calculatePi(terms);
		}
		
	}
	
	while (terms < 0);
	
	// Display the calculated result
	printf("\nThe approximate value of Pi = %.8Lf\n", pi);
	
	return 0;
}
