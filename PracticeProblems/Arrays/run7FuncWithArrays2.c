/*

Write a program to declare an array of size 10 and initialize the array with the user provided values.
Create function for each task and answer the following:
1. Find the minimum value in the array.
2. Find the maximum value in the array.
3. Find the average/mean value of the array.
4. Display the last element of array.
5. Display the value at index 2.
6. Count Even and Odd Elements in array.
7. Print numbers in reverse order.

*/

#include <stdio.h>

// Function to find the minimum value in the array
int findMinima(int num[10], int size) {
	int minima;
	minima = num[0];
	
	// Loop to compare each element to find the minimum
	for (int i = 1; i < size; i++) {
		
		if (num[i] < minima) {
		
			minima = num[i];
			
		}
	
	}
	
	return minima;

}

// Function to find the maximum value in the array
int findMaxima(int num[10], int size) {
	int maxima;
	maxima = num[0];

	// Loop to compare each element to find the maximum
	for (int i = 1; i < size; i++) {
	
		if (maxima < num[i]) {
		
			maxima = num[i];
		
		}
	
	}
	
	return maxima;

}

// Function to calculate the average value of the array
float calculateAverage(int num[10], int size) {
	int sum = 0;
	float avg = 0;
	
	// Loop to calculate the sum of all elements
	for (int i = 0; i < size; i++) {
	
		sum += num[i];
	
	}
	
	// Calculate the average
	avg = (float)sum/size;

	return avg;

}

// Function to return the value at index 2
int valueAtIndex2(int num[10], int size) {

	return num[2];

}

// Function to return the last element in the array
int lastElement(int num[10], int size) {

	return num[9];
	
}

// Function to count and print the number of even and odd elements
int countOddEven(int num[10], int size) {
	int odd_count = 0;
	
	// Loop to count odd elements
	for (int i = 0; i < size; i++) {
	
		if (num[i] %2 != 0) {
		
			odd_count++;
		
		}
	
	}
	
	printf("Odd Element Count %d\n", odd_count);
	
	int even_count = 0;
	
	// Loop to count even elements
	for (int i = 0; i < size; i++) {
	
		if (num[i] %2 == 0) {
		
			even_count++;
		
		}
	
	}
	
	printf("Even Element Count %d\n", even_count);
	
}

// Function to print the array in reverse order
int arrayInReverseOrder(int num[10], int size) {
	int reverse_arr[10];
	
	printf("Array in reverse order\n");
	
	// Loop to reverse and print the array
	for (int i = size - 1;;) {
	
		for (int j = 0; j < size; j++) {
		
			if (i >= 0) {
			
				reverse_arr[j] = num[i];
			
				printf("%d ", reverse_arr[j]);
				i--;
			
			}
		
		}
		
		break;
	
	}
	
	printf("\n");

}

int main() {
	int num[10];
	int size = 10;
	
	// Prompt the user to enter 10 integers
	printf("Enter 10 elements in array\n");
	
	// Loop to read & store all 10 values in an array
	for (int index = 0; index < size; index++) {

		scanf("%d", &num[index]);
		
	}
	
	// Function calls for various tasks
	printf("Minimum value in array is %d\n", findMinima(num, size));
	printf("Maximum value in array is %d\n", findMaxima(num, size));
	printf("Average of array is %f\n", calculateAverage(num, size));
	printf("Value at index 2 is %d\n", valueAtIndex2(num, size));
	printf("Last Element of array is %d\n", lastElement(num, size));
	
	countOddEven(num, size);
	arrayInReverseOrder(num, size);

	return 0;
}
