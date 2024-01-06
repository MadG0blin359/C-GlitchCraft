#include <stdio.h>

void copyString(char *str, char *copy) {
	
	while (*str != '\n') {
		*copy = *str;
		str++;		// Move to next character in str
		copy++;		// Move to next character in copy
	}
	
	*copy = '\0';		// Add null terminator at the end of copy string

}

int main() {
	int size = 50;
	char str[size];
	char copy[size];
	
	// Prompt the user to enter any string
	printf("Enter any string: ");
	fgets(str, sizeof(str), stdin);
	
	// Call the function to copy the string
	copyString(str, copy);
	
	// Display the copied string
	printf("\n--Source String: %s", str);
	printf("--Copied String: %s\n", copy);


	return 0;
}
