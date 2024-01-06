#include <stdio.h>	// Using standard library 

int main() {
	short num1, num2, num3;		// Declaring 3 short integer variables to store user inputs
	
	printf("Enter the first value = ");	// Prompt the user to input the first number
	scanf("%hi", &num1);	// Read and store the user value in num1
	
	printf("Enter the second value = ");	// Prompt the user to input the second numebr
	scanf("%hi", &num2);	// Read and store the user value in num2
	
	printf("Enter the third value = ");	// Prompt the user to input the third number
	scanf("%hi", &num3);	// Read and store the user value in num3
	
	if(num1>num2) {		// Checking if num1 is greater than num2
		if(num1>num3) {		// Checking if num1 is also greater than num3
			printf("\"%hi\" is greater than \"%hi\" & \"%hi\"\n", num1, num2, num3);
		} else { 	// num1 is less than num3
			if(num2>num3) {
				printf("\"%hi\" is greater than \"%hi\" but less than \"%hi\"\n", num1, num2, num3);
				printf("So \"%hi\" is greater than \"%hi\"\n", num2, num3);
			} else {	// num2 is less than num3
				printf("\"%hi\" is greater than \"%hi\" but less than \"%hi\"\n", num1, num2, num3);
				printf("So \"%hi\" is greater than both \"%hi\" & \"%hi\"\n", num3, num1, num2);
			}
		}
	} else {	// num2 is greater than num1
			if(num2>num3) {		// Checking if num2 is also greater than num3
				printf("\"%hi\" is greater than both \"%hi\" & \"%hi\"\n", num2, num1, num3);
			} else {	// num2 is less than num3
				printf("\"%hi\" is greater than \"%hi\" but less than \"%hi\"\n", num2, num1, num3);
			}
	}
	
	return 0;	// Return 0 to indicate succesfull program execution
}
