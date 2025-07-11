#include <stdio.h>    // For printf, perror
#include <stdlib.h>   // For malloc, atoi, rand, srand
#include <unistd.h>   // For sleep
#include <pthread.h>  // For pthread_t, pthread_mutex_t, pthread_create, pthread_join, pthread_mutex_init, pthread_mutex_destroy
#include <semaphore.h> // For sem_t, sem_init, sem_wait, sem_post, sem_destroy
#include <time.h>     // For time (to seed rand)

#define BUFFER_SIZE 20 // Size of the shared buffer

// Shared Resources
int buffer[BUFFER_SIZE]; // The circular buffer
int in = 0, out = 0;     // Pointers for producer (in) and consumer (out)

pthread_mutex_t mutex; // Mutex for critical section (access to buffer)
sem_t full;            // Semaphore counting occupied slots (initially 0)
sem_t empty;           // Semaphore counting empty slots (initially BUFFER_SIZE)

// Producer thread function
void* produce_integer(void* arg) {
    int producer_id = *(int*)arg; // Get producer ID
    
    while (1) { // Loop indefinitely
        int item = rand() % 50; // Generate random item
        
        sem_wait(&empty); // Wait if buffer is full (decrement empty count)
        pthread_mutex_lock(&mutex); // Acquire mutex for critical section
        
        buffer[in] = item; // Add item to buffer
        printf("Producer %d Produced: %d\n", producer_id, buffer[in]);
        in = (in + 1) % BUFFER_SIZE; // Move 'in' pointer circularly
        
        pthread_mutex_unlock(&mutex); // Release mutex
        sem_post(&full); // Signal buffer is no longer empty (increment full count)
        
        sleep(rand() % 3); // Simulate work
    }
    // Note: The producer thread has an infinite loop and won't naturally exit.
}

// Consumer thread function
void* consume_integer(void* arg) {
    int consumer_id = *(int*)arg; // Get consumer ID
    
    while (1) { // Loop indefinitely
        sem_wait(&full); // Wait if buffer is empty (decrement full count)
        pthread_mutex_lock(&mutex); // Acquire mutex for critical section
        
        int item = buffer[out]; // Consume item from buffer
        printf("Consumer %d Consumed: %d\n", consumer_id, item);
        out = (out + 1) % BUFFER_SIZE; // Move 'out' pointer circularly
        
        pthread_mutex_unlock(&mutex); // Release mutex
        sem_post(&empty); // Signal buffer has free space (increment empty count)
    
        sleep(rand() % 3); // Simulate work
    }
    // Note: The consumer thread has an infinite loop and won't naturally exit.
}

// Main function
int main(int argc, char* argv[]) {
    // Get number of producers and consumers from command-line arguments
    int producer_thread_count = atoi(argv[1]);
    int consumer_thread_count = atoi(argv[2]);
    
    // Arrays for thread IDs
    pthread_t producer_id[producer_thread_count];
    pthread_t consumer_id[consumer_thread_count];
    srand(time(NULL)); // Seed random number generator
    
    printf("%d %d\n\n", producer_thread_count, consumer_thread_count);
    
    // Initialize mutex and semaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE); // Empty slots = BUFFER_SIZE
    sem_init(&full, 0, 0);            // Full slots = 0
    
    // Create producer threads
    for (int i = 0; i < producer_thread_count; i++) {
        // Allocate memory for thread ID and pass pointer to producer function
        int *id = malloc(sizeof(int)); 
        *id = i;
        if (pthread_create(&producer_id[i], NULL, produce_integer, id) != 0)
            perror("Failed to create producer thread!\n");
    }
    
    // Create consumer threads
    for (int j = 0; j < consumer_thread_count; j++) {
        // Allocate memory for thread ID and pass pointer to consumer function
        int *id = malloc(sizeof(int));
        *id = j;
        // Check if thread creation failed (pthread_create returns 0 on success)
        if (pthread_create(&consumer_id[j], NULL, consume_integer, id) != 0) 
            perror("Failed to create consumer thread!\n");
    }
    
    // Join producer threads (will block indefinitely as they loop infinitely)
    for (int k = 0; k < producer_thread_count; k++) {
        if (pthread_join(producer_id[k], NULL) != 0)
            perror("Failed to join producer thread!\n");
    }
    
    // Join consumer threads (will block indefinitely as they loop infinitely)
    for (int k = 0; k < consumer_thread_count; k++) {
        if (pthread_join(consumer_id[k], NULL) != 0)
            perror("Failed to join consumer thread!\n");
    }
    
    // Destroy synchronization primitives (unreachable due to infinite loops)
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0; // Program exit (unreachable)
}