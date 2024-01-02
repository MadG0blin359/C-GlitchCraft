#include <stdio.h>

int main() {
	// Array size variables
	int r_size, c_size, size;
	r_size = 3;
	c_size = 3;
	size = 3;
	int arr[r_size][c_size];	// Declaration of a 2D array to store user input
	int row_sum[size];		// Declaration of a single dimension array to store sum of each row separately
	
	printf("The matrix is:\n");
	
	// Loop for inputting values into the array
	for (int i = 0; i < 3; i++) {
		
		for (int j = 0; j < 3; j++) {
			// Prompt for column input
			scanf("%d", &arr[i][j]);
			row_sum[i] += arr[i][j];
			
		}	
		
	}
	
	printf("\nThe sum of rows of the matrix is:\n");
	
	
	// Loop for printing the values
	for (int i = 0; i < 3; i++) {
		// Display the sum of each row separately
		printf("--Row %d: %d\n", i+1, row_sum[i]);
	}
	
	return 0;
	
}	
