#include <stdio.h>

// Function to write each digit into a newline
int convertToNewLine(short num) {
	
	printf("hundred %hi\n", num/100);	// dividing by 100 to get the 1st digit in a separate line
	printf("ten %hi\n", (num/10)%10);	// dividing by 10 for quotinent and then again dividing by 10 for remainder to get the 2nd digit in a separate line
	printf("unit %hi\n", num%10);		// dividing by 10 for remainder to get the last digit in a separate line
}

int main() {
	short num;	// Variable 'num' to store the user input
	
	// Prompt the user to enter any 3-digit number
	printf("Enter 3 digit = ");
	scanf("%hi", &num);
	
	// Verify if the number is 3-digit
	if(num>99 && num<=999) {
		// Call the function
		convertToNewLine(num);
	}
	
	// Display invalid number if the number is not a 3-digit number
	else {
		printf("You have entered an invalid number\n");
	}

	return 0;
}
