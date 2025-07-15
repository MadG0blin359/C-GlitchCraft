#include <stdio.h>   // For printf
#include <unistd.h>  // For IPC_RMID (though not explicitly used here, it's a common IPC header)
#include <stdlib.h>  // For exit() (though not used)
#include <string.h>  // For string manipulation (though not used here)
#include <sys/shm.h> // For shmget(), shmat(), shmctl()

int main() {
    void* shm_ptr;     // Pointer to shared memory segment
    char buffer[100];  // Buffer for data (unused in this reading example)
    int shmid, i;      // shmid: shared memory ID, i: loop counter (unused)

    // Get (or create if not existing) a shared memory segment with key 2345, size 1024 bytes, and 0666 permissions.
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);

    // Attach the shared memory segment to the process's address space.
    // NULL for the second argument lets the system choose the attach address.
    // 0 for the third argument means read/write permissions.
    shm_ptr = shmat(shmid, NULL, 0);

    // Print the data read from the shared memory segment, casting shm_ptr to char* for string interpretation.
    printf("Data read from shared memory: %s\n", (char*)shm_ptr);

    // Note: In a complete example, you'd typically detach the shared memory (shmdt(shm_ptr))
    // and potentially mark it for deletion (shmctl(shmid, IPC_RMID, NULL)) when no longer needed.

    return 0; // Program exits
}