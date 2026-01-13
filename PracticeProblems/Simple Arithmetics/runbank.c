#include <stdio.h>
#include <math.h>

float calculateSimpleInterest(float principal) {	// Function to calculate simple interest
	float const rate = 5;	// Fixed interest rate
	
	float SI = (principal*rate)/100;	 // Calculate simple interest
	
	// Display the calculated simple interest and total amount
	printf("\n\nSimple interest on \'%g\' in 1 year is \'%g\'\nTotal = \'%g\'\n", principal, SI, SI+principal);
}

float calculateCompoundInterest(float principal) {	// Function to calculate compound interest
	float const rate = 12;	// Fixed interest rate
	
	float CI = principal*( 1 + (rate/100)) - principal;	// Calculate compound interest
	
	// Display the calculated compound interest and total amount
	printf("\nCompound Interest on \'%g\' in 1 year is \'%g\'\nTotal = \'%g\'\n", principal, CI, CI+principal);

}

float calculateCompoundInterestForSpecifiedYears(float principal, float rate, float time) {	// Function to calculate compound interest for specified years
	float RateBracket =  ( 1 + (rate/100));		
	float power = pow(RateBracket, time);		// Calculate power
	
	float CIY = principal*power - principal;	// Calculate compound interest for specified years
	
	// Display the calculated compound interest and total amount
	printf("\nCompound Interest on \'%g\' in \'%g\' year is \'%g\'\nTotal = \'%g\'\n", principal, time, CIY, CIY+principal);

}

int main() {
	float principal, rate, time;	// Declare the variables to store the user input
	
	printf("\nEnter the account balance = ");	// Prompt the user to input the value of the account balance
	scanf("%g", &principal);	// Read and store the value of the user input 
	
	printf("Compound Interest for specified years = ");	// Prompt the user to input the value for the specified years
	scanf("%g", &time);	// Read and store the value of the user input
	
	printf("Compound Interest for specified rate = ");	// Prompt the user to input the value for the specified rate
	scanf("%g", &rate);	// Read and store the value of the user input
	
	calculateSimpleInterest(principal);	// Call the function of simple interest
		
	calculateCompoundInterest(principal);	// Call the function of compound interest
		
	calculateCompoundInterestForSpecifiedYears(principal, rate, time);	// Call the function of compound interest for specified years
	
	return 0;	// Return 0 to indicate the successful program execution
}
