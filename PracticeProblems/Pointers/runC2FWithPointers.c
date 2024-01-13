#include <stdio.h>

void convertF2C(float *fahrenheit, float *celsius) {
	
	 *celsius = ((*fahrenheit - 32) * 5) / 9; // Conversion formula from Fahrenheit to Celsius

}

int main() {
	float fahrenheit, celsius;
	
	// Prompt the user to enter temperature in fahrenheit
	printf("\nEnter Temperature in Fahrenheit: ");
	scanf("%f", &fahrenheit);
	
	// Call the function to perform calculations
	convertF2C(&fahrenheit, &celsius);
	
	// Display the final result
	printf("--Temperature in Celsius: %g degrees\n\n", celsius);

	return 0;
}
