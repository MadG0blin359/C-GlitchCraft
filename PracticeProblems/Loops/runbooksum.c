#include <stdio.h>

// Function to calculate the sum of book numbers within a specified range
long sumOfBookNumbers(long firstbook, long endbook, long skipbooks) {
	long sum = 0;
	
	// Loop through the range of books
	for(sum; firstbook<=endbook; firstbook += skipbooks + 1) {
	
		// Add the current 'firstbook' to the sum
		sum += firstbook;
	}
	
	// Return the total sum
	return sum;
}

int main() {
	long firstbook, endbook, skipbooks;
	
	// Prompt the user to input the range (first book & last book) and skip value
	printf("First Book: ");
	scanf("%ld", &firstbook);
	
	printf("Last Book: ");
	scanf("%ld", &endbook);
	
	printf("Skip Books: ");
	scanf("%ld", &skipbooks);
	
	// Calculate the sum of book numbers using the function
	printf("Sum = %ld\n", sumOfBookNumbers(firstbook, endbook, skipbooks));

	// Return 0 to indicate successful program execution
	return 0;
}
