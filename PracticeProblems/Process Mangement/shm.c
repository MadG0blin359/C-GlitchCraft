#include <stdio.h>    // For printf, scanf, etc.
#include <unistd.h>   // For read()
#include <stdlib.h>   // For exit() (though not used)
#include <string.h>   // For strcpy()
#include <sys/shm.h>  // For shmget(), shmat()

int main() {
    void* shm_ptr;      // Pointer to shared memory
    char buffer[100];   // Buffer to hold input
    int shmid, i;       // shmid: shared memory ID, i: loop counter (unused)

    // Get a shared memory segment:
    // Key 2345, size 1024 bytes, 0666 permissions, create if not exists
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);

    // Attach shared memory segment to process's address space
    shm_ptr = shmat(shmid, NULL, 0);

    // Read up to 100 bytes from standard input (stdin, file descriptor 0) into buffer
    read(0, buffer, 100);

    // Copy content from buffer to shared memory
    strcpy(shm_ptr, buffer);

    return 0; // Program exit
}