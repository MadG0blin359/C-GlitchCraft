#include <stdio.h>

int main() {
	double arr[50];		// Store the square of first 25 index numbers & Cube of last 25 index numbers
	int new_line = 0;	// Print a new line after every 10 elements
	
	printf("\n\'Square of first 25 index numbers\' & \'Cube of last 25 index numbers\'\n\n");
	
	// Loop to perform calculations
	for (int i = 0; i < 50; i++) {
		
		// Condition to calculate squares
		if (i < 25) {
			arr[i] = i*i;
				
			printf("%lg ", arr[i]);
			new_line++;
			
		}
		
		// Condition to calculate cubes
		if (i >= 25 && i < 50) {
			arr[i] = i*i*i;
			
			printf("%lg ", arr[i]);
			new_line++;
			
		}
		
		// Condition to move to new line after every 10 elements
		if (new_line == 10) {
			printf("\n");
			new_line = 0;
		}
		
	}
	
	return 0;
} 
