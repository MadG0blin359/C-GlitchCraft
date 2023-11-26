#include <stdio.h>

// Function to display the pattern
int displayPattern(char symbol) {

	// Loops to display the pattern of the symbol
	for (int i = 5; i >= 1; i--) {
		
		for (int j = 5; j >= i; j--) {
			
			printf("%c", symbol);
		
		}
		
		printf("\n");
	
	}
	
	for (int i = 4; i >= 1; i--) {
		
		for (int j = 1; j <= i; j++) {
				
			printf("%c", symbol);
		
		}
		
		printf("\n");
	
	}

}

int main() {
	
	// Declare variable to store user input
	char symbol;
	
	// Prompt the user to enter the symbol
	printf("Enter symbol ");
	scanf(" %c", &symbol);

	printf("\n");
	
	// Call the function to display the pattern
	displayPattern(symbol);
	
	printf("\n");
	
	return 0;
}
