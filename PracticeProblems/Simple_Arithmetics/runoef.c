#include <stdio.h>
int checkOddEven();	// Declare the prototype for checking if the number is Even or Odd

int main() {
	int num;	// Declare the variable to store the user input
	
	printf("Enter any number = ");		// Prompt the user to input the value
	scanf("%d", &num);	// Read and Store the user input in variable num
	
	checkOddEven(num);	// Call the function to display the result
	
	return 0; 	// Return 0 to indicate succesful program execution 
}

int checkOddEven(int num) {	// Define the function to check if the user input is Odd or Even
	
	if (num %2== 0)		// Divide the num with 2, if the remainder is zero then its Even
		{
		printf("The entered number is Even\n");		// Display the result is Even
		}
	else	// Else its Odd
		{
		printf("The entered number is Odd\n");		// Display the result is Odd
		}
	return 0;	// Return 0 to indicate successful execution of the function
}
