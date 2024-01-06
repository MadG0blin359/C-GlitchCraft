#include <stdio.h>

// Function prototype to find factorial of a number using pointers
void calculateFactorial(int, int*);

int main() {
	int num;	// Variable to store user input
	int fact;	// Variable to store factorial
	
	printf("\n\tPointer : Find the factorial of a given number :"); 
	printf("\n\t------------------------------------------------\n");
	
	// Prompt the user to enter any positve integer
	printf("Enter any positive integer : ");
	scanf("%d", &num);

	// Call the function to calculate factorial passing the address of 'fact'
	calculateFactorial(num, &fact);

	printf("The Factorial of %d is : %d\n", num, fact);
	
	return 0;
}

// Function definition to find factorial using pointers
void calculateFactorial(int num, int *fact) {

	*fact = 1; // Initialize the factorial to 1
	
	// Loop to calculate factorial of the given number
	for (int i = 1; i <= num; i++) {
		*fact = *fact * i;	// Calculate factorial by multiplying *f with i
	}

}
