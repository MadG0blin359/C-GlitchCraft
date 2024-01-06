#include <stdio.h>

// Function prototype declaration
int findSmallest();

int main() {
	int arr[4][3];	// Declaration of a 2D array to store user input
	int smallest;	// // Variable to store the smallest value

	// Loop for inputting values into the array
	for (int i = 0; i < 4; i++) {
		
		// Prompt for row input
		printf("\n\t***Row: %d***\n", i+1);
		
		for (int j = 0; j < 3; j++) {
			// Prompt for column input
			printf("--Column %d: ", j+1);
			scanf("%d", &arr[i][j]);	
		}
	}
	
	// Calling the function to find the smallest value in the array
	smallest = findSmallest(arr);
	
	// Displaying the smallest value
	printf("\nThe smallest value in the array is: %d\n", smallest);

	return 0;
}

// Function definition to find the smallest value in the array
int findSmallest(int arr[4][3]) {
	int smallest;
	smallest = arr[0][0];
	
	// Loop to compare elements and find the smallest value
	for (int i = 0; i < 4; i++) {	
	
		for (int j = 0; j < 3; j++) {
			// Updating smallest if a smaller value is found
			if (smallest > arr[i][j]) {
				smallest = arr[i][j];
			}	
		}
	}

	// Returning the smallest value found
	return smallest;
	
}
