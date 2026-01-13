#include <stdio.h>

// Declare function prototypes (forward declarations)
int swap1();
int swap2();

int main() {
	int n1, n2;	// Declare two integer variables to store user inputs
	
	// Prompt the user to enter the first number
	printf("Enter number 1 = ");	
	scanf("%d", &n1);	// Read and store the first number in the variable n1
	
	// Prompt the user to enter the second number
	printf("Enter number 2 = ");	
	scanf("%d", &n2);	// Read and store the second number in the variable n2
	
	// Display the values of n1 and n2 before swaping
	printf("Before swapping num1 = %d & num2 = %d\n", n1, n2);
	
	// Call the swap1 and swap2 functions to swap the numbers and display the result
	printf("After swapping num1 = %d & num2 = %d\n", swap1(n2,0), swap2(0,n1));
	
	return 0;	// Return 0 to indicate successful program execution
}
	
int swap1(int n1, int n2) {	// Define the swap1 function to swap the n1 value with n2
	return n1;
}
	
int swap2(int n1, int n2) {	// Define the swap2 function to swap the n2 value with n1
	return n2; 
}
