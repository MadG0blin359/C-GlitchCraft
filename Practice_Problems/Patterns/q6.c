#include <stdio.h>

// Function to display a pattern of numbers according to the rows
int displayPattern(int rows) {

	// Loop to print the upper part of the pattern
	for(int i = 0; i <= rows; i++) {
	
		// Loop to print leading spaces
		for(int j = rows; j > i; j--) {
		
			printf(" ");
		
		}
	
		// Loop to print numbers
		for(int k = 0; k <= i; k++) {
		
			printf("%d ", i);
		
		}
		// Move to the next line after completing the row
		printf("\n");
	
	}
	
	// Initialize a variable to manage spaces for the lower part
	int lower_space = 1;
	
	// Loop to print the lower part of the pattern
	for(int i = rows - 1; i >= 0; i--) {
		
		// Loop to print leading spaces
		for(int j = 1; j <= lower_space; j++) {
		
			printf(" ");
		
		}
		
		// Increase the number of spaces for the next row
		lower_space++;
		
		// Loop to print numbers
		for(int k = 0; k <= i; k++) {
		
			printf("%d ", i);
			
		
		}
		
		// Move to the next line after completing the row
		printf("\n");
	
	}

}

int main() {

	int rows;
	
	// Prompt the user to enter the number of rows (limited to 1-9)
	printf("Enter the number of rows (1-9): ");
	scanf("%d", &rows);

	printf("\n");
	
	// If the input is within the valid range, call the displayPattern function
	if (rows > 0 && rows < 10) {
	
		displayPattern(rows);
	
	}
	
	else {
		// Handle invalid input
		printf("Invalid Input!");
	
	}
	
	printf("\n");

	return 0;
}
