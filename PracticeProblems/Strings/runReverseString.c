#include <stdio.h>

int main() {
	char str[32];
	int length = 0;
	
	// Prompt the user to enter any string
	printf("\nPrint Reverse of a string:\n");
	printf("--------------------------\n");
	printf("\nEnter any string: ");
	fgets(str, sizeof(str), stdin);
	
	while (str[length] != '\n') {
		// Count characters, counting zeroth index character as 1
		length++;
	}
	
	length--;	// length--, due to the extra character count, extra space will be printed because that index will be empty
	printf("\nThe characters of the string in reverse are: \n");
	
	// Loop to print the string in reverse
	do {
		printf("%c ", str[length]);
		length--;
	}
	
	// Continue the loop until the character count reaches zero
	while (length >= 0);
	
	printf("\n");
	
	return 0;
}
