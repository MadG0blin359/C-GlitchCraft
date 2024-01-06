#include<stdio.h>	// Include this library to for printf and scanf functions.

int main() {
	float hours;	// Declare a variable to store hours as a floating-point number.
	int seconds;	// Declare a variable to store seconds as an integer number.
	
	// Prompt the user to input the number of hours.
	printf("Enter the hours = ");	
	
	// Read the input value (hours) from the user and store it in the 'hours' variable.
	scanf("%g", &hours);
	
	// Convert the hours into seconds by multiplying with 3600 (1 hour = 3600 seconds).
	seconds=hours*3600;
	
	// Display the result by printing the original hours and the converted seconds.
	printf("%g hours in seconds are %d \n", hours,seconds);
	return 0; }
