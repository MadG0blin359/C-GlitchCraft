#include <stdio.h>   // For printf, scanf
#include <unistd.h>  // For sleep (though not used)
#include <pthread.h> // For pthread_t, pthread_mutex_t, pthread_create, pthread_join, pthread_mutex_lock/unlock
#include <string.h>  // For strcpy, strcat

// Shared resource (data to be read/written by threads)
char dataset[1024] = "";
pthread_mutex_t lock; // Mutex to protect the shared dataset

// Writer thread function
void* writer(void* arg) {
    char localData[1024] = ""; // Local buffer for input (initialize to empty string)
    char input[2]; // Buffer to read single characters + null terminator
    input[1] = '\0'; // Null terminate the input buffer
    
    printf("Writer trying to acquire lock\n");
    pthread_mutex_lock(&lock); // Acquire the mutex (enters critical section)

    printf("Writer acquired lock\n");
    
    printf("\nEnter data to shared variable:");
    // Read input character by character until newline or buffer is full
    for(int i = 0; i < 1024; i++) {
        scanf("%c", &input[0]); // Read one character
        strcat(localData, input); // Append character to localData
    
        if (input[0] == '\n') // Stop reading on newline
            break;
    }

    strcat(dataset, localData); // Append localData to the shared dataset
    printf("\nWriter writes the data in shared dataset\n");

    pthread_mutex_unlock(&lock); // Release the mutex (exits critical section)
    printf("Writer releases the lock\n==================================================================\n");
    return NULL; // Thread exit
}

// Reader thread function
void* reader(void* arg) {
    // Note: Reader is created before Writer in main(), but the timing depends on OS scheduler.
    printf("\nReader trying to acquire lock\n");
    pthread_mutex_lock(&lock); // Acquire the mutex (enters critical section)

    printf("Reader acquired lock\n");
    printf("\nReader reads the shared dataset:\n%s\n", dataset); // Read shared dataset

    pthread_mutex_unlock(&lock); // Release the mutex (exits critical section)
    printf("Reader releases the lock\n");
    return NULL; // Thread exit
}

// Main function
int main() {
    pthread_t w_thread, r_thread; // Thread identifiers
    
    // Initialize the mutex (necessary for thread safety)
    // pthread_mutex_init(&lock, NULL); 

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