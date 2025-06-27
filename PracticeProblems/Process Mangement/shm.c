#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>

int main() {
	void* shm_ptr;
	char buffer[100];
	int shmid, i;

	shmid = shmget((Key_t)2345, 1024, 0666 | IPC_CREAT);
	shm_ptr = shmat(shmid, NULL, 0);

	read(0, buffer, 100);
	strcpy(shm_ptr, buffer);

	return 0;
}


