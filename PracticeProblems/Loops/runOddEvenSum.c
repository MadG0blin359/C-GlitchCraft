#include <stdio.h>

// Display the final results
void displayResults(int odd_count, int odd_sum, int even_count, int even_sum, int zero_count) {
    printf("\nThe number of Odd integers : %d", odd_count);
    printf("\nThe sum of Odd integers : %d", odd_sum);
    printf("\nThe number of Even integers : %d", even_count);
    printf("\nThe sum of Even integers : %d", even_sum);
}

void identifyIntegers(int arr[], int size) {

    int odd_count = 0, odd_sum = 0, even_count = 0, even_sum = 0, zero_count = 0;

    for (int i = 0; i < size; i++) {
        // Condition to check for even numbers
        if (arr[i] %2 == 0) {
            even_count++;
            even_sum += arr[i];
            continue;
        }

        else {
            // Sum and count of odd numbers 
            odd_count++;
            odd_sum += arr[i];
        }

        // Check for zeros
        if (arr[i] == 0) {
            zero_count++;
            continue;
        }
        
    }

    // Calling the function to display the results
    displayResults(odd_count, odd_sum, even_count, even_sum, zero_count);
}

int main() {

    int size;

    printf("\nEnter number of Integers : ");
    scanf("%d", &size);

    int arr[size];
    
    // Loop to take n number of integers
    for (int i = 0; i < size; i++) {
        printf("\n---Integer : %d---", i+1);
        printf("\nEnter : ");
        scanf ("%d", &arr[i]);
        // printf("\n");
    }

    // Call the function to identify the integers
    identifyIntegers(arr, size);

    return 0;
}