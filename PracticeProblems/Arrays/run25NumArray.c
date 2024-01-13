#include <stdio.h>

int main() {
	int arr[25];		// Declare an array to store unique integers
	int size = 25;		// Initialize array size
	int num = 0;		// Variable to store user input
	int display = 1;	// Variable to display a statement once in a complete loop iterations
	
	// Prompt the user to enter 25 integers in the specified range
	printf("Enter 25 integers (10-100) to store in array:\n");
	
	for (int i = 0; i < size; i++) {
		
		// Read & store an integer from the user
		scanf("%d", &num);
		
		// Validate the entered number
		if (num >= 10 && num <= 100) {
			
			if (display == 1) {
				printf("\nUnique values stored in the array are\n");
				display++;
			}
			
			// Check for duplicates in the array
			int duplicate = 0;
			
			for (int j = 0; j <= i; j++) {
				
				if (num == arr[j]) {
					duplicate = 1;
					break;
				}
			}
			
			// If the number is not a duplicate, store it in the array
			if (duplicate != 1) {
				arr[i] = num;
				// Display unique values
				printf("%d ", arr[i]);
			}
		}
		
		else {
			// Display Invalid Input if the number is out of the provided range
			printf("Invalid Input! Please enter a number between 10 and 100.\n");
			// Decrement i to re-enter the number in the current position in the loop
			i--;
        	}
	}
	
	// Print a newline after the loop
	printf("\n");

	return 0;
}
