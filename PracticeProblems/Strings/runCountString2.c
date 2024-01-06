#include <stdio.h>

int main() {
	
	// Declaration of a variable & an array
	char str[64];
	int length = 0;

	printf("\n\nFind the length of a string:\n");
	printf("----------------------------\n");

	// Prompt the user to enter any string
	printf("Enter any string: ");
	fgets(str, sizeof str, stdin);
	
	// fgets reads and stores the new line character just before the null character.
	while (str[length] != '\n') {
		length++;
	}

	// Display the total character count
	printf("%d\n", length);
	
	return 0;
}
