#include <stdio.h>

int main() {
	
	// Declaration of a variable & an array
	char str[64];
	int length = 0;
	
	printf("\n\nFind the length of a string:\n");
	printf("----------------------------\n"); 
	
	// Prompt the user to enter any string
	printf("Enter any string: ");
	scanf("%s", str);
	
	// Count the string characters until \0, except the new line character that comes before null character. Scanf doesn't read new line character
	while (str[length] != '\0') {
		length++;
	}
	
	// Display the total character count
	printf("%d\n", length);

	return 0;
}
