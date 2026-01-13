#include <stdio.h>

float calculateSumOfMarks1(float maths1, float science1, float english1) {	// Function to calculate the sum of marks for first student
	float sum1;
	return sum1 = maths1 + science1 + english1;
}

float calculatePercentage1(float sum1) {	// Function to calculate the percentage based on the total sum
	float per1;
	return per1 = (sum1/300)*100;
}

float calculateSumOfMarks2(float maths2, float science2, float english2) {	// Function to calculate the sum of marks for second student
	float sum2;
	return sum2 = maths2 + science2 + english2;
}

float calculatePercentage2(float sum2) {	// Function to calculate the percentage based on the total sum
	float per2;
	return per2 = (sum2/300)*100;
}

float calculateSumOfMarks3(float maths3, float science3, float english3) {	// Function to calculate the sum of marks for third student
	float sum3;
	return sum3 = maths3 + science3 + english3;
}

float calculatePercentage3(float sum3) {	// Function to calculate the percentage based on the total sum
	float per3;
	return per3 = (sum3/300)*100;
}

void main() {
	int s1, s2, s3;	// Student IDs
	float maths1, science1, english1, maths2, science2, english2, maths3, science3, english3;	// Marks for the student
	float sum1, sum2, sum3;		// Total marks for each student
	
	printf("Enter the ID of the first student = ");
	scanf("%d", &s1);
	
	// Frist prompt the user to enter the marks then read and store the user inputs in the varaiables according to the student
		printf("Marks gained in Mathematics = ");
		scanf("%g", &maths1);
	
		printf("Marks gained in Science = ");
		scanf("%g", &science1);
	
		printf("Marks gained in English = ");
		scanf("%g", &english1);
		
	sum1 = calculateSumOfMarks1(maths1, science1, english1);	    // Calculate the total marks for the first student
		
printf("\n\n\t\tFirst Student ID = \'%d\'\n\n--Mathematics Marks = \'%g\'\n--Science Marks = \'%g\'\n--English Marks = \'%g\'\n\nTotal Marks = \'%g\'\t\tTotal Percentage = \'%g\'\n\n", s1, maths1, science1, english1, sum1, calculatePercentage1(sum1));	    // Display the details for the first student
	
	printf("Enter the ID of the second student = ");
	scanf("%d", &s2);
	
	// Frist prompt the user to enter the marks then read and store the user inputs in the varaiables according to the student
		printf("Marks gained in Mathematics = ");
		scanf("%g", &maths2);
	
		printf("Marks gained in Science = ");
		scanf("%g", &science2);
	
		printf("Marks gained in English = ");
		scanf("%g", &english2);
		
	sum2 = calculateSumOfMarks2(maths2, science2, english2);	    // Calculate the total marks for the second student
		
printf("\n\n\t\tSecond Student ID = \'%d\'\n\n--Mathematics Marks = \'%g\'\n--Science Marks = \'%g\'\n--English Marks = \'%g\'\n\nTotal Marks = \'%g\'\t\tTotal Percentage = \'%g\'\n\n", s2, maths2, science2, english2, sum2, calculatePercentage2(sum2));	    // Display the details for the second student
	
	printf("Enter the ID of the third student = ");
	scanf("%d", &s3);
	
	// Frist prompt the user to enter the marks then read and store the user inputs in the varaiables according to the student
		printf("Marks gained in Mathematics = ");
		scanf("%g", &maths3);
	
		printf("Marks gained in Science = ");
		scanf("%g", &science3);
	
		printf("Marks gained in English = ");
		scanf("%g", &english3);

	sum3 = calculateSumOfMarks3(maths3, science3, english3);	    // Calculate the total marks for the third student

printf("\n\n\t\tThird Student ID = \'%d\'\n\n--Mathematics Marks = \'%g\'\n--Science Marks = \'%g\'\n--English Marks = \'%g\'\n\nTotal Marks = \'%g\'\t\tTotal Percentage = \'%g\'\n\n", s3, maths3, science3, english3, sum3, calculatePercentage3(sum3));	    // Display the details for the third student
		
}
