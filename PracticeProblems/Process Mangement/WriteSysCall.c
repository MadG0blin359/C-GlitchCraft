#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
	//int fd[2];
	//pid_t pid = fork();
	char buff[10];
	//read(0, buff, 5);
	//write(1, buff, 5);

	//ssize_t count = write(1, "hello\n", 6);
	//printf("Number: %ld\n", count);

	int nread = read(0, buff, 10);
	write(1, buff, nread);

	return 0;
}
