#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int n, fd, fd1;
	char buff[50];	
	fd = open("test.txt", O_RDONLY);
	n = read(fd, buff, 10);
	printf("File Descriptor: %d\n", fd);

	fd1 = open("write.txt", O_WRONLY|O_CREAT, 0642);
	write(fd1, buff, n);	
	
	return 0;
}
