#include <stdio.h>

int main() {
	FILE *fptr;			// Declare a file pointer for writing
	
	fptr = fopen("firstfile.txt", "w");		// Creating and opening 'firstfile.txt' in write mode
	
	char name[30];
	char roll[10];
	float cgpa;
	
	printf("\nStudent Info");
	printf("\n------------\n");
	
	// Prompt for entering name
	printf("--Name : ");
	
	// Loop to input the name
	for (int i = 0; i < sizeof(name); i++) {
		scanf("%c", &name[i]);		// Read characters for the name
		
		if (name[i] == '\n') {		// Check for newline to exit the loop
			break;
		}
	}
	
	fprintf(fptr, "--Name : %s", name);	// Write the name to the file

	int roll_length;

	do {	
		roll_length = 0;
		
		printf("--Roll Number (XXX-XXXX) : ");		// Prompt for roll number
		
		// Loop to input the roll number
		for (int i = 0; i < sizeof(roll); i++) {
			scanf("%c", &roll[i]);			// Read characters for the roll number
				
			if (roll[i] == '\n') {
				break;
			}
			
			roll_length++;
			
		}
		
		// Repeat until valid roll number format is entered
		if (roll[3] != '-' || roll_length < 8) {
			printf("\n----- Invalid Format! -----\n\n");
		}
		
	}
	
	while (roll[3] != '-' || roll_length < 8);
	
	// Write the roll number to the file
	fprintf(fptr, "--Roll Number : %s", roll);
	
	do {
		// Prompt for CGPA input
		printf("--CGPA : ");
		// Read the CGPA
		scanf("%g", &cgpa);
		
		// Check for valid CGPA range
		if (cgpa < 0 || cgpa > 4) {
			printf("\n----- Invalid Input! -----\n\n");
		}
	
	}
	
	while (cgpa <= 0 || cgpa > 4);
	
	// Write the CGPA to the file
	fprintf(fptr, "--CGPA : %g\n", cgpa);
	
	// Close the file
	fclose(fptr);

	return 0;
}
