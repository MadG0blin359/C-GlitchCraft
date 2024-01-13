#include <stdio.h>

int main() {
	int num;
	
	printf("\n\tPointers : Store and retrieve elements from an array :");
	printf("\n\t------------------------------------------------------\n");
	printf("\nInput the number of elements to store in the array : ");
	scanf("%d", &num);		// Read the number of elements to be stored in the array
	
	printf("\nInput %d number of elements in the array :\n", num);
	
	int arr[num];
	
	for (int i = 0; i < num; i++) {
		printf("--element - %d : ", i);
		scanf("%d", arr + i);		// Read and store 'n' elements in the array arr1 using pointer arithmetic
	}
	
	printf("\nThe elements you entered are :");
	
	for (int i = 0; i < num; i++) {
		printf("\n--element - %d : %d", i, *(arr+i));		// Display the elements stored in the array using pointers
	}

	printf("\n");

	return 0;
}
