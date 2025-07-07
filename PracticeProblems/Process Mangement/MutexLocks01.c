#include <stdio.h>    // For printf, scanf
#include <pthread.h>  // For pthread_t, pthread_mutex_t, pthread_cond_t, thread functions, mutex and condition variable operations
#include <stdbool.h>  // For bool type

// Shared variables and synchronization tools
int sharedNumber;       // Number shared between threads
pthread_mutex_t lock;   // Mutex to protect sharedNumber and isOddDone
pthread_cond_t cond;    // Condition variable to signal thread 2
bool isOddDone = false; // Flag to indicate if odd/even check is done

// Thread 1: Function to input a number
void* inputNumber(void* arg) {
    pthread_mutex_lock(&lock); // Acquire mutex before accessing sharedNumber

    printf("Enter a number: ");
    scanf("%d", &sharedNumber); // Read input into sharedNumber
    printf("Thread 1: Number entered: %d\n", sharedNumber);

    pthread_mutex_unlock(&lock); // Release mutex
    return NULL; // Thread exit
}

// Thread 3: Function to check if the number is odd or even
void* checkOddEven(void* arg) {
    pthread_mutex_lock(&lock); // Acquire mutex before accessing sharedNumber and isOddDone

    // Perform the odd/even check
    if (sharedNumber % 2 == 0) {
        printf("Thread 3: The number %d is even.\n", sharedNumber);
    } 
    else {
        printf("Thread 3: The number %d is odd.\n", sharedNumber);
    }

    isOddDone = true; // Set flag to true as check is complete
    pthread_cond_broadcast(&cond); // Signal all waiting threads (specifically thread 2)
    pthread_mutex_unlock(&lock); // Release mutex
    return NULL; // Thread exit
}

// Thread 2: Function to calculate factorial
void* calculateFactorial(void* arg) {
    pthread_mutex_lock(&lock); // Acquire mutex before accessing sharedNumber and isOddDone

    // Wait until Thread 3 has completed its odd/even check
    while (!isOddDone) {
        pthread_cond_wait(&cond, &lock); // Atomically release lock and wait for signal; re-acquires lock on return
    }

    // Calculate factorial
    unsigned long long factorial = 1; // Use unsigned long long for large factorials
    for (int i = 1; i <= sharedNumber; i++) {
        factorial *= i;
    }
    printf("Thread 2: The factorial of %d is %llu.\n", sharedNumber, factorial);

    pthread_mutex_unlock(&lock); // Release mutex
    return NULL; // Thread exit
}

// Main function
int main() {
    pthread_t t1, t2, t3; // Thread identifiers

    // Initialize mutex and condition variable (missing from original code, but necessary)
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    // Create threads: t1 (input), t3 (odd/even), t2 (factorial)
    // The order of creation matters less than the explicit synchronization
    pthread_create(&t1, NULL, inputNumber, NULL);
    pthread_create(&t3, NULL, checkOddEven, NULL);
    pthread_create(&t2, NULL, calculateFactorial, NULL);

    // Wait for all threads to complete
    pthread_join(t1, NULL);
    pthread_join(t3, NULL);
    pthread_join(t2, NULL);

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0; // Program exit
}