#include <stdio.h>

// Display the final results
void displayResults(int odd_count, int odd_sum, int even_count, int even_sum, int zero_count) {
    printf("\nThe number of Odd integers : %d", odd_count);
    printf("\nThe sum of Odd integers : %d", odd_sum);
    printf("\nThe number of Even integers : %d", even_count);
    printf("\nThe sum of Even integers : %d", even_sum);
    printf("\nThe number of zeros : %d", zero_count);
}

// Function to input n integers and calculate statistics
void identifyIntegers(int n) {
    int odd_count = 0, odd_sum = 0, even_count = 0, even_sum = 0, zero_count = 0;

    for (int i = 0; i < n; i++) {
        int num;
        printf("Enter integer %d: ", i +1);
        scanf("%d", &num);

        if (num %2 == 0) {
            odd_count++;
            odd_sum += num;
        }

        if (num == 0) {
            zero_count++;
            continue;
        }
    
        even_count++;
        even_sum += num;
        
    }

    // Calling the function to display the results
    displayResults(odd_count, odd_sum, even_count, even_sum, zero_count);
}

int main() {
    int n;

    // take input the number of integers
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Call the function to find integers
    identifyIntegers(n);

    return 0;
}
