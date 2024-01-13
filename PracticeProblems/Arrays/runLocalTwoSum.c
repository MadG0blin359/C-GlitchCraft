#include <stdio.h>

int main() {
	int size = 4;			// Size of the array
	int arr[size];			// Declare an array
	int target = 0;			// Store user input
	int sum = 0;			// Store the indices of two indexes

	printf("\n----- Enter 4 integers in the array -----\n");

	for (int i = 0; i < 4; i++) {
		// Prompt the user to input the element of the array
		printf("Enter element number %d in the array : ", i+1);
		scanf("%d", &arr[i]);
	}

	// Prompt the user to enter a target
	printf("\nTarget : ");
	scanf("%d", &target);

	// Loop to find the indices
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum = arr[i] + arr[j];
			if (sum == target) {
				printf("Target found : [%d,%d]\n", i, j);
				break;
			}
		}

		if (sum == target) {
			break;
		}
	}

	// Display target not found if there are no indices
	if (sum != target) {
		printf("\nTarget not found!\n");
	}
	return 0;
}