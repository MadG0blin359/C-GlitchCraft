#include <stdio.h>

int main() {
	int r_size, c_size;
	r_size = 2;
	c_size = 2;
	int arr[r_size][c_size];	// Declaration of a 2D array to store user input

	// Loop for inputting values into the array
	for (int i = 0; i < 2; i++) {
		
		// Prompt for row input
		printf("\n\t***Row: %d***\n", i+1);
		
		for (int j = 0; j < 2; j++) {
			// Prompt for column input
			printf("--Column %d: ", j+1);
			scanf("%d", &arr[i][j]);	
		}
	}
	
	printf("\nTranspose of the Matrix is:");
	
	// Loop for converting 'rows' into 'columns' & 'columns' into 'rows'
	for (int j = 0; j < 2; j++) {
		
		printf("\n");
		
		for (int i = 0; i < 2; i++) {
			printf("%d ", arr[i][j]);
		}
	}
	
	printf("\n");
	
	return 0;
}
