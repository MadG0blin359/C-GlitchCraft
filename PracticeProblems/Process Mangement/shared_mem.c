#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() {
    int shmid;
    char *shm;

    shmid = shmget((key_t)2345, 1024, 0751 | IPC_CREAT);
    shm = shmat(shmid, NULL, 0);
    
    strcpy(shm, "Hello");
    printf("Process 1: Wrote 'Hello' and waiting...\n");
    sleep(2);
    
    strcpy(shm, " your name");
    printf("Process 2: Wrote 'your name'\n");

    strcpy(shm, " rollnumber");
    printf("Process 3: Wrote 'rollnumber'\n");

    printf("Final Shared Memory Content: %s\n", shm);

    return 0;
}

