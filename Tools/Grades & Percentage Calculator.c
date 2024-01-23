#include <stdio.h>

// Function to calculate total obtained marks
int calculateObtainedMarks(int maths, int english, int computer_science, int science, int urdu) {
	// Calculate and return the sum of obtained marks
	int obtained_marks;
	obtained_marks = maths+ english + computer_science + science + urdu;
	return obtained_marks;
}

// Function to calculate percentage
double calculatePercentage(int total_marks, int obtained_marks) {
	// Calculate the percentage and return it as a double
	double percentage = (double)obtained_marks/total_marks * 100;
	return percentage; 
}

// Function to calculate Grades
int calculateGrades(double percentage) {
	// Determine and return the grade based on the given percentage
	char grades;
	if (percentage >= 90 && percentage <= 100) {
		
		grades = 'A';
		return grades;
	}
	
	else if (percentage >= 80 && percentage <= 89) {
		
		grades = 'B';
		return grades;
	}

	else if (percentage >= 70 && percentage <= 79) {
			
		grades = 'C';
		return grades;
	}
		
	else if (percentage >= 60 && percentage <= 69) {
		
		grades = 'D';
		return grades;
	}
	
	else if (percentage < 60) {
		
		grades = 'F';
		return grades;
	}
}

int main() {
	// Declaration of varaibles
	int total_marks, obtained_marks, maths, english, computer_science, science, urdu;

	// Prompt the user to enter the total available marks
	printf("\nEnter the Total Marks Available = ");
	scanf("%d", &total_marks);
	
	// Prompt the user to enter the marks for maths
	printf("\nEnter the marks for Maths = ");
	scanf("%d", &maths);
	
	// Prompt the user to enter the marks for english
	printf("\nEnter the marks for English = ");
	scanf("%d", &english);
	
	// Prompt the user to enter the marks for computer science
	printf("\nEnter the marks for Computer Science = ");
	scanf("%d", &computer_science);
	
	// Prompt the user to enter the marks for science
	printf("\nEnter the marks for Science = ");
	scanf("%d", &science);
	
	// Prompt the user to enter the marks for urdu
	printf("\nEnter the marks for Urdu = ");
	scanf("%d", &urdu);
	
	if (obtained_marks <= total_marks && obtained_marks >= 0) {
	
	// Call the calculateObtainedMarks function to calculate the total obtained marks
	obtained_marks = calculateObtainedMarks(maths, english, computer_science, science, urdu);
	
	// Call the calculatePercentage function to calculate the percentage obtained
	double percentage = calculatePercentage(total_marks, obtained_marks);
	
	// Call the calculateGrades function to determine the grade
	char grades = calculateGrades(percentage);
	
	// Display the results
	printf("\n\t--Result--");
	printf("\n--Total Obtained Marks = %d\n", obtained_marks);
	printf("--Percentage = %.2lf\n", percentage);
	printf("--Grade = %c\n", grades);
	
	}
	
	else {
		printf("Unable to calculate. Invalid Data!\n");
	}
	
	// Return to indicate successfull program execution
	return 0;
}
