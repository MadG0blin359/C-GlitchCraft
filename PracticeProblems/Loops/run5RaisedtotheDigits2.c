#include <stdio.h>

// Function to find the number of digits in user input
int countDigits(int num) {

	int count = 0;		// Count the number of digits

	// Keep dividing the number by 10 until it becomes 0, counting each iteration
	while (num != 0) {
		num = num / 10;
		count++;
	}

	return count;

}

// Function to perform the multiplication
int multiply(int num, int digits, int constant) {
	int total = 0;

	if (digits > 1) {
		total += constant * constant;

	for (int i = 3; i <= digits; i++) {
		total = total * constant;
	}

	printf("\n%d multiply by %d raised to the power %d : %d\n", num, constant, digits, num*total);

	}

	else if (digits <= 1) {
		total = constant;
		digits = 1;

		printf("\n%d multiply by %d raised to the power %d : %d\n", num, constant, digits, num*total);

	}

}

int main() {
	int constant = 5;	// Constant 5
	int num = 0;		// Store user input

	// Prompt the user to enter any integer
	printf("\n--Enter any number : ");
	scanf("%d", &num);

	// Call the functino to count the number of digits
	int digits = countDigits(num);

	printf("--The number of digits in %d are : %d\n", num, digits);

	// Call the function to perform multiplication
	multiply(num, digits, constant);

	return 0;

}