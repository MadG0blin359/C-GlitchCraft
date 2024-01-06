#include <stdio.h>

// Function to display the pattern
int displayPattern(char symbol) {

	// Loop to display upper half of the pattern of the user chosen symbol
	for (int i = 5; i >= 1; i--) {			// Number of columns
		
		for (int j = 5; j >= i; j--) {		// Number of symbols in each row
			
			printf("%c", symbol);
		
		}
		
		printf("\n");
	
	}
	
	// Loop to display lower half of the pattern of the user chosen symbol
	for (int i = 4; i >= 1; i--) {			// Number of columns
		
		for (int j = 1; j <= i; j++) {		// Number of symbols in each row
				
			printf("%c", symbol);
		
		}
		
		printf("\n");
	
	}

}

int main() {
	
	// Variable to store user input
	char symbol;
	
	// Prompt the user to enter any symbol
	printf("Enter symbol: ");
	scanf("%c", &symbol);

	printf("\n");
	
	// Call the function to display the pattern
	displayPattern(symbol);
	
	printf("\n");
	
	return 0;
}
