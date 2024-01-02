#include <stdio.h>

int main() {
	int r_size, c_size;
	r_size = 3;
	c_size = 3;
	int arr[r_size][c_size];	// Declaration of a 2D array to store user input
	int row_sum[3];

	// Loop for inputting values into the array
	for (int i = 0; i < 3; i++) {
		
		// Prompt for row input
		printf("\n\t***Row: %d***\n", i+1);
		
		for (int j = 0; j < 3; j++) {
			// Prompt for column input
			printf("--Column %d: ", j+1);
			scanf("%d", &arr[i][j]);
			
			row_sum[i] += arr[i][j];
			
		}
		
		// Display the sum of each row separately
		printf("\nSum of Row %d: %d\n", i+1, row_sum[i]);	
		
	}
	
	return 0;
	
}	
