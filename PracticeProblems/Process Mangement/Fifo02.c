#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd1;

	fd1 = open("fifo1", O_WRONLY);
	write(fd1, "Hello World!\n", 13);
	printf("Sender Process %d has sent the data.\n", getpid());
	return 0;
}
