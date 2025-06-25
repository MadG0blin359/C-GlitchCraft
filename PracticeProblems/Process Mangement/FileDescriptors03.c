#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int n, fd, fd1;
	char buff[200];	
	fd = open("file.txt", O_RDONLY);
	n = read(fd, buff, 200);
	printf("File Descriptor: %d\n", fd);
	printf("Total Characters read: %d\n", n);

	fd1 = open("oldfile.txt", O_WRONLY|O_APPEND, 0642);
	write(fd1, buff, n);	
	
	return 0;
}
