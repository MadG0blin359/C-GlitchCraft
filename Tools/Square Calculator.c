#include <stdio.h>

// Function to calculate square of natural numbers
int calculateSquare(int terms) {
    
    int num = 1, sum = 0, square = 0;
    
    printf("The square natural upto %d terms are : ", terms);

    // Loop to perform simultaneous calculations multiple times
    for (int i = 1; i <= terms; i++) {
        square = num * num;
        num++;
        sum += square;
        printf("%d ", square);
    }

    return sum;
}

int main() {

    int terms = 0;

    printf("\nEnter the number of terms : ");       // Prompt the user to enter the number of terms
    scanf("%d", &terms);

    int sum = calculateSquare(terms);       // Call the function to perform the task

    printf("\nThe Sum of Square Natural Number upto 5 terms = %d", sum);        // Display calculated data

    return 0;
}