#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>

int is_prime(int num) {
    if (num < 2) 
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) 
            return 0;
    }
    return 1;
}

void *find_primes(void *arg) {
    int *range = (int *)arg;
    int start = range[0];
    int end = range[1];

    printf("Thread checking range: %d to %d\n", start, end);
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("Prime: %d\n", i);
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int num_threads = atoi(argv[3]);

    if (start > end || start < 0 || num_threads <= 0) {
        printf("Invalid input!\n");
        return 1;
    }

    pthread_t threads[num_threads];
    int ranges[num_threads][2];
    int range = (end - start + 1) / num_threads;

    for (int i = 0; i < num_threads; i++) {
        ranges[i][0] = start + i * range;

        if (i == num_threads - 1) {
            ranges[i][1] = end;
        } else {
            ranges[i][1] = start + (i + 1) * range - 1;
        }

        if (pthread_create(&threads[i], NULL, find_primes, (void *)ranges[i]) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads finished!\n");
    return 0;
}

