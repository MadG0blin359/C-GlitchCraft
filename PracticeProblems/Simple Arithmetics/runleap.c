#include <stdio.h>

int main() {
	int year;
	
	// Prompt the user to enter the any year
	printf("Enter the year = ");
	scanf("%d", &year); 
	
	// Check if the year is divisible by 400
	if ((year%400) == 0) {
		printf("The given year %d is a leap year\n", year);
	}
	
	// Check if the year is divisible by 100
	else if ((year%100) == 0) {
		printf("The given year %d is not a leap year\n", year);
	}
	
	// Check if the year is divisible by 4
	else if ((year%4) == 0) {
		printf("The given year %d is a leap year\n", year);
	}
	
	else {
		printf("The given year %d is not a leap year\n", year);
	}
	
	// Return 0 to indicate successful program execution
	return 0;	
}
