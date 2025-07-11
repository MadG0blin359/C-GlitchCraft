#include <stdio.h>   // For printf
#include <unistd.h>  // For sleep (though not used, often included with threads)
#include <pthread.h> // For pthread_t, pthread_mutex_t, pthread_create, pthread_join, pthread_mutex_lock/unlock
#include <string.h>  // For strcpy, strcat

// Shared resource (data to be read/written by threads)
char dataset[] = 
"A mutex is a mutual exclusion lock: \n"
"1. To block the access of variables by other threads \n"
"2. Enforces exclusive access by a thread to a shared resource. \n"
"3. Can protect a “critical” section of memory. \n"
"Mutexes can be applied to threads in a single process and do not work between processes\n";

pthread_mutex_t lock; // Mutex to protect the shared dataset

// Writer thread function
void* writer(void* arg) {
    char sharedData[1024], localData[1024]; // Local buffers
    printf("Writer trying to acquire lock\n");
    pthread_mutex_lock(&lock); // Acquire the mutex (enters critical section)

    printf("Writer acquired lock\n");

    strcpy(sharedData, dataset); // Reads the shared dataset (copying to local buffer)
    printf("Writer reads the original dataset:\n%s\n", sharedData);
    
    strcpy(localData, "\nModified by Writer!");
    strcat(dataset, localData); // Update the shared dataset (writing)
    printf("Writer updates the data in shared dataset\n");

    pthread_mutex_unlock(&lock); // Release the mutex (exits critical section)
    printf("Writer releases the lock\n");
    return NULL; // Thread exit
}

// Reader thread function
void* reader(void* arg) {
    printf("\nReader trying to acquire lock\n");
    pthread_mutex_lock(&lock); // Acquire the mutex (enters critical section)

    printf("Reader acquired lock\n");
    printf("Reader reads the shared dataset:\n%s\n", dataset); // Read shared dataset

    pthread_mutex_unlock(&lock); // Release the mutex (exits critical section)
    printf("Reader releases the lock\n");
    return NULL; // Thread exit
}

// Main function
int main() {
    pthread_t w_thread, r_thread; // Thread identifiers
    
    // Initialize the mutex (pthread_mutex_init is implicitly called if no parameters are specified, but explicit init is better practice)
    pthread_mutex_init(&lock, NULL); 

    // Create writer and reader threads
    pthread_create(&w_thread, NULL, writer, NULL);
    pthread_create(&r_thread, NULL, reader, NULL);
    
    // Wait for writer thread to complete
    pthread_join(w_thread, NULL); 
    // Wait for reader thread to complete
    pthread_join(r_thread, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    return 0; // Program exit
}