#include <stdio.h>

int main() {
	FILE *fptr;
	char content[150];
	
	fptr = fopen("read.txt", "r");
		
	if (fptr == NULL) {
		printf("\nError: Cannot open file");
		printf("\n-----------------------\n\n");
		return 1;	// Return 1 to exit main function
	}
		
	else {
		for (int i = 0; i < sizeof(content); i++) {
			content[i] = fgetc(fptr);
				
			if (content[i] != EOF) {
				printf("%c", content[i]);
			}
		}
	}
		
	fclose(fptr);

	return 0;
}
