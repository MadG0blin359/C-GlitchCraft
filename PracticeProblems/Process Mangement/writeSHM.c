#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h

int main() {
    int shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
    char *shared_memory = (char*) shmat(shmid, NULL, 0);

    char *message = "Hello from Process 1!";
    strcpy(shared_memory, message);
    printf("Process 1: Wrote message to shared memory: %s\n", message);

    return 0;
}

