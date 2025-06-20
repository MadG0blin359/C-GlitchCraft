#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
	int fd1, n;
	char buffer[100];

	fd1 = open("fifo1", O_RDONLY);
	n = read(fd1, buffer, 100);
	printf("Reader Process %d has started.\n", getpid());
	printf("Data received by receiver %d is: %s\n", getpid(), buffer);
	return 0;
}
