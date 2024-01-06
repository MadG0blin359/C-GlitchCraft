#include <stdio.h>


int main() {
	// Declaring the age variable to store the user input
	int age;
	
	// Prompt the user to enter his/her age
	printf("Enter your age = ");
	// Read & Store the user input in the age variable
	scanf("%d", &age);
	
	// Calculate the if the age is 18 or greater
	int eligible_age = age-18;
	
	switch (eligible_age) {
	
	case 0 ... 200:
		// Display the statement
		printf("You are Eligible to Vote\n");
	break;
	
	default:
		// Display the sad statement
		printf("Unfortunately, You are Not Eligible For Voting\n");
	break;
	
	}
	
	// Return 0 to indicate successful program execution
	return 0;
}

