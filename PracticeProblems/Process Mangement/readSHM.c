#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid = shmget((key_t)1234, 1024, 0666);
    char *shared_memory = (char *) shmat(shmid, NULL, 0);
    
    printf("Process 2: Read message from shared memory: %s\n", shared_memory);

    return 0;
}

