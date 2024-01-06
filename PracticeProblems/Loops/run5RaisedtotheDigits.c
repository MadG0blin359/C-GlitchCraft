#include <stdio.h>

int countDigits(int num) {
	int count = 0;

	if (num == 0) {
		count++;
	}

	else {
		// Keep dividing the number by 10 until it becomes 0, counting each iteration
		while (num != 0) {
			num = num / 10;
			count++;
		}
	}

	// Return the number of digits
	return count;

}

int numMultiplication(int num, int digits, int constant) {
	
	int total = 0;
	if (digits == 1) {
		total = constant;
	}

	else {
		total += constant * constant;

		for (int i = 3; i <= digits; i++) {
			total = total * constant;
		}
	}
	
	// Display the final result
	printf("\n--%d raised to the power %d : %d\n", constant, digits, total);
}

int main() {
	int constant = 5;
	int num = 0;
	
	// Prompt the user to enter any number
	printf("\n--Enter any number : ");
	scanf("%d", &num);

	// Call the function to count the number of digits in the user input
	int digits = countDigits(num);

	// Display a message with the number of digits in the user input
	printf("--Number of digits in %d : %d\n", num, digits);
	
	// Call the function to perform the calculation based on the number of digits
	numMultiplication(num, digits, constant);

	return 0;
}
