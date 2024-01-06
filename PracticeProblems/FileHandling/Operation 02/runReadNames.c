#include <stdio.h>

void printNames(int);

int main() {
	FILE *fptr;
	char content[100];
	
	fptr = fopen("names.txt", "r");

	if (fptr == NULL) {
		printf("\nError: Cannot open file");
		printf("\n-----------------------\n\n");
		return 1;	// Return 1 to exit main function
	}

	else {
		
		printf("\nOriginal Content in the file : \n\n");
		
		int total_length = 0;
		
		for (int i = 0; i < sizeof(content); i++) {
			//fscanf(fptr, "%c", &content[i]);
			
			content[i] = fgetc(fptr);
			
			// Avoid counting the newline character
			if (content[i] != '\n' && content[i] != EOF) {
				printf("%c", content[i]);
				total_length++;
			}
			
			else {
				printf("\n");
			}
			
			if (content[i] == EOF) {
				break;
			}
		}
	
		printf("--Total length : %d\n", total_length);
	
	}
	
	fclose(fptr);
	
	int length = 0;
	
	printf("\nEnter number of characters a name should have : ");
	scanf("%d", &length);
	
	printNames(length);

	return 0;
}

void printNames(int length) {
	FILE *fptr;
	char names[100];
	int name_length = 0;
	
	fptr = fopen("names.txt", "r");

	if (fptr == NULL) {
		printf("\nError: Cannot open file");
		printf("\n-----------------------\n\n");
		//return 1;	// Return 1 to exit main function
	}
	
	else {
		rewind(fptr);
		
		for (int i = 0; i < sizeof(names); i++) {
				
			names[i] = fgetc(fptr);
		
			if (names[i] != '\n' && names[i] != EOF) {
				name_length++;
			}
			
			if (names[i] == '\n' && names[i] != EOF) {
				
				if (name_length == length) {
					names[i+1] = '\0';	// Stop the array so if the previous name length was longer and it was not completely replaced by the second name.
					printf("%s", names);
					i = 0 - 1;		// (i) will become 0 when the next iteration starts
					name_length = 0;
				}
				
				else {
					i = 0 - 1;		// (i) will become 0 when the next iteration starts
					name_length = 0;
				}
			}
			
			else if (names[i] == EOF) {
				break;
			}
		}
	}
}
