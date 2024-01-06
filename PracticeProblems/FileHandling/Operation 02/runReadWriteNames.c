#include <stdio.h>

int main() {
	FILE *rptr;		// Declaring a file pointer for reading
	char content[100];	// Declaring an array to store content read from file
	
	rptr = fopen("names.txt", "r");		// Opening 'names.txt' file in read mode

	// Checking if the file failed to open
	if (rptr == NULL) {			
		printf("\nError: Cannot open file");
		printf("\n-----------------------\n\n");
		return 1;	// Return 1 to exit main function
	}
	
	// If the file opened successfully
	else {
	
		for (int i = 0; i < sizeof(content); i++) {
		
			content[i] = fgetc(rptr);
			
			// Checking for end of file
			if (content[i] == EOF) {
				printf("\n");
				break;
			}

		}

	}
	
	// Closing the file pointer after reading
	fclose(rptr);
	
	// Declaring a file pointer for writing
	FILE *wptr;
	
	// Creating 'name_subj.txt' file in write mode
	wptr = fopen("name_subj.txt", "w");
	
	int count_names = 1;
	
	// Writing the count of names to file
	fprintf(wptr, "%d ", count_names);
		
	for (int i = 0; i < sizeof(content); i++) {
		
		// Checking for characters other than end of file and newline
		if (content[i] != EOF && content[i] != '\n') {
			fprintf(wptr, "%c", content[i]);	// Writing characters to file
		}
		
		else if (content[i] == '\n') {
			fprintf(wptr, ", Programming Fundamentals, Calculus, English Composition\n");		// Writing subjects to file
			count_names++;				// Incrementing the count of names
			if (count_names != 14) {
				fprintf(wptr, "%d ", count_names);
			}
		}
		
		// If end of file is encountered
		else {
			break;
		}
			
	}
	
	// Closing the file pointer after writing
	fclose(wptr);
	
	// Returning 0 to indicate successful execution
	return 0;

}
