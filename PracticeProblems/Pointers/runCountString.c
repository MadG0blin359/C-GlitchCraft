#include <stdio.h>

// Function to calculate length of string using pointers
int stringLength(char *str) {

	int length = 0;	
	
	while (*str != '\n') {
		length++; 	// Count each character
		str++;		// Move the pointer to the next character
	}

	// Return total length
	return length;
}

int main() {
	char str[100];
	
	// Prompt the user to enter any string with/without spaces
	printf("Enter a string: ");
	fgets(str, sizeof(str), stdin);
	
	// Call the function and store the value in length
	int length = stringLength(str);
	
	// Display the final result
	printf("Length of the string is %d\n", length);

	return 0;
}

