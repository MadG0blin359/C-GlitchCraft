#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int n, fd;
	char buff[50];	
	fd = open("test.txt", O_RDONLY);
	printf("File Descriptor: %d\n", fd);

	n = read(fd, buff, 50);	
	write(1, buff, n);
	return 0;
}
