#include <stdio.h>

int main() {
	int students = 0, size = 32;			// Size for arrays
	char student_name[size], father_name[size];	// Arrays to store strings of names
	char temp[size];				// Store the input buffer
	
	// Prompt the user to enter the number of students
	printf("Enter number of students: ");
	scanf("%d", &students);
	
	// Consume the newline character left by scanf in input buffer
	fgets(temp, sizeof(temp), stdin);
	
	// Student Roll Number & class array
	int student_number[size], class[students];
	
	// Loop to prompt the user for data
	for (int i = 0; i < students; i++) {
	
		printf("Enter student number: ");
		scanf("%d", &student_number[i]);
		
		// Consume the newline character left by scanf in input buffer
		fgets(temp, sizeof(temp), stdin);
	
		printf("Enter name: ");	
		fgets(student_name, sizeof(student_name), stdin);
		
		printf("Enter father's name: ");
		fgets(father_name, sizeof(father_name), stdin);
		
		printf("Enter class: ");
		scanf("%d", &class[i]);
	
		printf("\n");
		
	}
	
	// Loop to remove the newline character at the end of the array stored by fgets
	for (int i = 0; student_name[i] != '\0'; i++) {
	
		if (student_name[i] == '\n') {
			student_name[i] = '\0';
			break;
		}
	}
	
	// Loop to remove the newline character at the end of the array stored by fgets
	for (int i = 0; father_name[i] != '\0'; i++) {
	
		if (father_name[i] == '\n') {
			father_name[i] = '\0';
			break;
		}
	}
	
	// Display student information
	printf("Student Information:\n");
	printf("Student Number | \tName\t | \tFather's Name\t | Class\n");
	printf("----------------------------------------------------------------\n");
	
	int j = 0;
	int k = 0;
	
	for (int i = 0; i < students; i++) {
		
		for (j; j <= i; j++) {
		
			if (student_number[j] == '\0') {
				break;
			}
			
			printf("\t\b\b%d\t\b| ", student_number[j]);
		}
		
		printf("%s | ", student_name);
		printf("%s | ", father_name);
		
		for (k; k <= i; k++) {
		
			if (class[k] == '\0') {
				break;
			}
			
			printf("\t%dth", class[k]);
		}
		
		printf("\n");
	}

	printf("\n");

	return 0;
}

