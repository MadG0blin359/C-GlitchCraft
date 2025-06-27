#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	char buff[20];	// store data
	int fd[2], n;	// file descriptors
	pid_t pid;
	pipe(fd);	// make pipe

	if ((pid = fork()) == -1) {
		perror("Bad Fork!\n");
		return 1;
	} else if (pid > 0) {
		close(fd[0]);		// Close reading file descriptior
		n = read(0, buff, sizeof(buff));	// Read input from user in buffer
		write(fd[1], buff, n);		// Send data to child
		close(fd[1]);		// Close writing side after writing
		printf("Greetings sent by parent!\n");
	} else {
		close(fd[1]);		// Close writing file descriptor
		n = read(fd[0], buff, sizeof(buff));	// Read greeting from parent
		printf("\nGreetings recieved by child!\n");
		write(1, buff, n);	// Write greeting to screen
		close(fd[0]);		// Close reading file descriptor after reading the data sent by parent
	}

	return 0;
}
