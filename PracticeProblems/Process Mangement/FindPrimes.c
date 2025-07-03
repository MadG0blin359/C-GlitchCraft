#include <stdio.h>    // For standard input/output functions (printf).
#include <stdlib.h>   // For general utilities (atoi, exit, perror).
#include <sys/types.h> // For system data types (not directly used here, but common for threading/process).
#include <pthread.h>  // For POSIX threads.

// Function to check if a number is prime.
int is_prime(int num) {
    // Numbers less than 2 are not prime.
    if (num < 2)
        return 0;
    // Check for divisibility from 2 up to the square root of num.
    for (int i = 2; i * i <= num; i++) {
        // If divisible, it's not prime.
        if (num % i == 0)
            return 0;
    }
    // If no divisors found, it's prime.
    return 1;
}

// Thread function to find primes within a given range.
void *find_primes(void *arg) {
    // Cast the void pointer argument back to an integer array for the range.
    int *range = (int *)arg;
    // Extract the start and end of the range.
    int start = range[0];
    int end = range[1];

    // Print the range this thread is checking.
    printf("Thread checking range: %d to %d\n", start, end);
    // Iterate through the numbers in the assigned range.
    for (int i = start; i <= end; i++) {
        // If the number is prime, print it.
        if (is_prime(i)) {
            printf("Prime: %d\n", i);
        }
    }

    // Exit the thread.
    pthread_exit(NULL);
}

// Main function: Parses arguments, divides range, creates and joins threads.
int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided.
    // Expected: program_name start_number end_number num_threads
    if (argc != 4) {
        printf("Usage: %s <start_number> <end_number> <num_threads>\n", argv[0]);
        return 1; // Indicate error
    }

    // Convert command-line arguments to integers.
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int num_threads = atoi(argv[3]);

    // Validate input ranges and thread count.
    if (start > end || start < 0 || num_threads <= 0) {
        printf("Invalid input! Please ensure start <= end, start >= 0, and num_threads > 0.\n");
        return 1; // Indicate error
    }

    // Declare an array to hold thread IDs.
    pthread_t threads[num_threads];
    // Declare a 2D array to hold start and end ranges for each thread.
    int ranges[num_threads][2];
    // Calculate the approximate size of each thread's range.
    int range_per_thread = (end - start + 1) / num_threads;

    // Loop to prepare ranges and create threads.
    for (int i = 0; i < num_threads; i++) {
        // Calculate the start of the current thread's range.
        ranges[i][0] = start + i * range_per_thread;

        // For the last thread, ensure it covers up to the 'end' number.
        if (i == num_threads - 1) {
            ranges[i][1] = end;
        } else {
            // Calculate the end of the current thread's range.
            ranges[i][1] = start + (i + 1) * range_per_thread - 1;
        }

        // Create a new thread.
        // Pass the address of the thread ID, default attributes, the thread function, and the range as argument.
        if (pthread_create(&threads[i], NULL, find_primes, (void *)ranges[i]) != 0) {
            // Print error if thread creation fails.
            perror("Error creating thread");
            return 1; // Indicate error
        }
    }

    // Loop to wait for all created threads to finish.
    for (int i = 0; i < num_threads; i++) {
        // Join the thread, waiting for it to terminate.
        pthread_join(threads[i], NULL);
    }

    // Print message indicating all threads have completed.
    printf("All threads finished!\n");
    return 0; // Indicate success.
}