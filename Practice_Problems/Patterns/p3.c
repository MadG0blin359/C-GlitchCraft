#include <stdio.h>

// Function to display a pattern of symbols according to the rows
int DisplayPattern(int rows, char symbol) {
	
	// Loop to perform iterations for the rows
	for(int i = 1; i <= rows; i++) {
		
		// Loop to print leading spaces
		for(int j = rows - 1; j >= i; j--) {
			
			printf(" ");
		
		}
		
		// Loop to print the symbol
		for(int k = 1; k <= i; k++) {
		
			printf("%c", symbol);
		
		}
		
		// Loop to print the symbol again (doubling the symbol)
		for(int k2 = 2; k2 <= i; k2++) {
		
			printf("%c", symbol);
		
		}
		
		// Move to the next line after completing the row
		printf("\n");
		
	}
		
}

int main() {
	
	int rows;
	char symbol;
	
	// Prompt the user to enter the number of rows for the pattern
	printf("Enter the number of rows: ");
	scanf("%d", &rows);
	
	// Prompt the user to enter the symbol for the pattern
	printf("Enter symbol: ");
	scanf(" %c", &symbol);
	
	printf("\n");
	
	// Call the DisplayPattern function to generate and display the pattern
	DisplayPattern(rows, symbol);

	printf("\n");

	return 0;
}
