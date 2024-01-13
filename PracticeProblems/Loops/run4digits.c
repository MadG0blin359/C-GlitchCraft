#include <stdio.h>

// Function to convert a 4-digit number into each on a new line
int convertToNewLine(short num) {
	
	printf("--Thousand: %hi\n", num/1000);
	printf("--hundred:  %hi\n", (num/100)%10);
	printf("--ten:      %hi\n", (num/10)%10);
	printf("--unit:     %hi\n", num%10);
}

int main() {
	short num;
	
	printf("\n-----------------------------------------------------------");
	printf("\n\tCalculate Units, Tens, Hundreds, & Thousands\n");
	printf("-----------------------------------------------------------\n");
	
	for (;;) {
		
		// Prompt the user to enter a 4-digit integer
		printf("\nEnter any 4-digit integer: ");
		scanf("%hi", &num);
		
	        // Check if the number is a valid 4-digit number or its negative counterpart
		if((num > 999 && num <= 9999) || (num < -999 && num >= -9999)) {
			
			if (num < 0) {
				// Convert negative numbers to positive		
				num = num/-1;
			}
			
			// Call the function to display each digit on a new line
			convertToNewLine(num);
		}
		
		// Display an error message if the input is not a 4-digit integer
		else {
			printf("\nYou have entered an invalid number\n");
		}
		
		char choice;
		
		for (;;) {
		
			printf("\nDo you want to continue? (y/n): ");
			scanf(" %c", &choice);
			
			if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
				break;
			}
			
			else {
				printf("Invalid Input!\n");
			}
		}
		
		// Exit the program if the user selects the letter 'n' or 'N'
		if (choice == 'n' || choice == 'N') {
			printf("Program Terminated!\n");
			break;
		}
		
	}
	
	return 0;
}
