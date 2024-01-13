#include <stdio.h>

int main() {
	int num1 = 0, num2 = 0;

	// Prompt the user to enter a number
	printf("Enter first nunmber : ");
	scanf("%d", &num1);
	
	// Prompt the user to enter a second number
	printf("Enter second nunmber : ");
	scanf("%d", &num2);
	
	int sum1 = 1 + num1;
	
	// Loop to check for divisors for the first number
	for (int i = 2; i <= num1/2; i++) {
		
		if (num1 %i == 0) {
			sum1 += i;
		}
	
	}

	int sum2 = 1 + num2;

	// Loop to check for divisors for the second number
	for (int i = 2; i <= num2/2; i++) {
		
		if (num2 %i == 0) {
			sum2 += i;
		}
	
	}
	
	// Check if the sum of divisors of both numbers are equal
	if (sum1/num1 == sum2/num2) {
		// Display the result
		printf("%d & %d are a friendly pair\n", num1, num2);
	}
	
	else {
		// Display a message
		printf("%d & %d are NOT a friendly pair\n", num1, num2);
	}

	return 0;
}
