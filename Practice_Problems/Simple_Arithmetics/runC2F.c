#include <stdio.h>

int main() {
	// Variables to store the performend calculations for converting Celsius to Fahrenheit
	float C, F;
	
	printf("\n\t-----Celsius to Fahrenheit Converter-----\n");

	// Prompt the user to input celsius
	printf("\nTemperature in celsius = ");
	scanf("%f", &C);
	
	// Formula to perform the conversion
	F = (9.0/5.0)*C+32;
	
	printf("Temperature in Fahrenheit = %g\n", F);
	return 0;
}
