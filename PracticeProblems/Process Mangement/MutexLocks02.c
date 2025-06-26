#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int num_THREADS = 4; // Number of threads
int inc = 1000; // Number of increments per thread
int counter = 0;
pthread_mutex_t lock;

void* incrementCounter() {
    for (int i = 0; i < inc; i++) {
        pthread_mutex_lock(&lock); // Lock the mutex
        counter++;
        pthread_mutex_unlock(&lock); // Unlock the mutex
    }
}

int main() {
    pthread_t threads[num_THREADS];

    // Create threads
    for (int i = 0; i < num_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, incrementCounter, NULL) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < num_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Output the final value of the counter
    printf("Final value of the counter: %d\n", counter);
    pthread_mutex_destroy(&lock);

    return 0;
}
