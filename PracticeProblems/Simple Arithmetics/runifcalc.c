#include <stdio.h>
// Define a menu function to display available choices
int menu(){
	printf("Press 1 for \'Division\'\n");
	printf("Press 2 for \'Multiplication\'\n");
	printf("Press 3 for \'Addition\'\n");
	printf("Press 4 for \'Subtraction\'\n");
}

int main() {
	
	// Call the function to display the menu
	menu();
	
	// Declare the variable to store user input
	int choice;
	
	// Prompt the user to enter their choice
	printf("= ");
	scanf("%d", &choice);
	
	// Check if the choice is between 1 and 4
	if (choice>=1 && choice<=4) {
		
		int num1, num2;
	
		// Check the selected operation and prompt the user to enter two numbers
		if (choice==1) {
		
		printf("Enter first number = ");
		scanf("%d", &num1);
	
		printf("Enter second number = ");
		scanf("%d", &num2);
			
			// Check for division by zero
			if (num2==0) {
				printf("Division by zero is \'undefined\'\n");
			}
		
			else {
				printf("The Division of %d by %d is \'%d\'\n",num1, num2, num1/num2);
			}
		}
	
		// Check the selected operation and prompt the user to enter two numbers
		else if (choice==2) {
		
			printf("Enter first number = ");
			scanf("%d", &num1);
	
			printf("Enter second number = ");
			scanf("%d", &num2);
		
				printf("The Multiplication of %d into %d is \'%d\'\n", num1, num2, num1*num2);
			}
	
		// Check the selected operation and prompt the user to enter two numbers
		else if (choice==3) {
		
			printf("Enter first number = ");
			scanf("%d", &num1);
	
			printf("Enter second number = ");
			scanf("%d", &num2);
		
				printf("The Addition of %d & %d is \'%d\'\n",num1, num2, num1+num2);
			}
		
		// Check the selected operation and prompt the user to enter two numbers
		else if (choice==4) {
		
			printf("Enter first number = ");
			scanf("%d", &num1);
	
			printf("Enter second number = ");
			scanf("%d", &num2);
		
				printf("The Subtraction of %d from %d is \'%d\'\n", num2, num1, num1-num2);
			}
	
	}
	
	// Display invalid input if the choice is different from the given choices
	else {
		printf("Invalid input. Enter from the given choices\n");
	}

	return 0;
}
