#include <stdio.h>

int main() {
	FILE *fptr;			// Declare a file pointer for reading
	char content[100];
	
	// Open 'firstfile.txt' in read mode
	fptr = fopen("firstfile.txt", "r");
	
	// Check if the file failed to open
	if (fptr == NULL) {
		printf("\nError: Cannot open file");
		printf("\n-----------------------\n\n");
		return 1;	// Return 1 to exit main function
	}
	
	// If the file was opened successfully
	else {
		// Loop to read file content
		for (int i = 0; i < sizeof(content); i++) {
			content[i] = fgetc(fptr);		// Read characters from the file
			
			// Check if the character is not the end of file marker			
			if (content[i] != EOF) {
				printf("%c", content[i]);
			}
		}
	}
	
	// Close the file
	fclose(fptr);
	
	return 0;
}
