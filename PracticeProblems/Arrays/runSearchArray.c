#include <stdio.h>

int main() {
	int arr[10] = {1,2,3,4,4,5,6,7,8,4};	// Declare & initialize the array
	int size = 10;				// Declare & initialize size variable same as the array size for ease
	int num = 0;				// Declare the num variable to store the user input
	
	printf("Enter element to search in array\n");
	
	printf("[");
	
	// Loop to print the elements of the array
	for (int i = 0; i < size; i++) {
		
		printf("%d ", arr[i]);
	
	}
	
	// Remove extra space and add the closing bracket
	printf("\b]: ");
	
	// Read & store the element to search for
	scanf("%d", &num);

	int element_count = 0, same_element = 0;
	
	// Search for the element in the array
	for (int j = 0; j < size; j++) {

		if (num == arr[j]) {
			
			element_count++;
			same_element = j;
		
		}
	
	}
	
	// Display the element found
	if (element_count > 0) {
	
		printf("Element %d found %d time(s)\n", arr[same_element], element_count);

	}
	
	// Handle the foreign element
	else {
		
			printf("Element Not Found!\n");
		
	}

	return 0;
}
