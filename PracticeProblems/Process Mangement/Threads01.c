#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>

void *thread_creation(void *arg) {
    int thread_num = atoi(arg);
    printf("Hello, I am thread %d, my ID is %lu\n", thread_num, pthread_self());
    pthread_exit(NULL);
}

int main() {
    int number_threads;

    printf("Enter the number of threads to create: ");
    scanf("%d", &number_threads);

    pthread_t threads[number_threads];
    int thread_nums[number_threads];

    for (int i = 0; i < number_threads; i++) {
        thread_nums[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_creation, &thread_nums[i]);
    }

    for (int i = 0; i < number_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished execution.\n");
    return 0;
}
