#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

// Shared variable and synchronization tools
int sharedNumber;
pthread_mutex_t lock;
pthread_cond_t cond;
bool isOddDone = false;

void* inputNumber() {
    pthread_mutex_lock(&lock);

    printf("Enter a number: ");
    scanf("%d", &sharedNumber);
    printf("Thread 1: Number entered: %d\n", sharedNumber);

    pthread_mutex_unlock(&lock);

}

void* checkOddEven() {
    pthread_mutex_lock(&lock);

    // Perform the odd/even check
    if (sharedNumber % 2 == 0) {
        printf("Thread 3: The number %d is even.\n", sharedNumber);
    } 
    else {
        printf("Thread 3: The number %d is odd.\n", sharedNumber);
    }

    isOddDone = true; // Update the flag to signal thread 2
    pthread_cond_broadcast(&cond); // Signal thread 2
    pthread_mutex_unlock(&lock);

}

void* calculateFactorial() {
    pthread_mutex_lock(&lock);

    while (!isOddDone) {
        pthread_cond_wait(&cond, &lock);
    }

    // Calculate factorial
    unsigned long long factorial = 1;
    for (int i = 1; i <= sharedNumber; i++) {
        factorial *= i;
    }
    printf("Thread 2: The factorial of %d is %llu.\n", sharedNumber, factorial);

    pthread_mutex_unlock(&lock);

}

int main() {
    pthread_t t1, t2, t3;

    //pthread_mutex_init(&lock, NULL);
    //pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, inputNumber, NULL);
    pthread_create(&t3, NULL, checkOddEven, NULL);
    pthread_create(&t2, NULL, calculateFactorial, NULL);

    pthread_join(t1, NULL);
    pthread_join(t3, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}
