#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	char buff[5];
	int n, fd[2], status;
	pid_t pid;

	if (pipe(fd) == -1) {
		return 1;
	}

	pid = fork();

	if (pid < 0) {
		return 1;
	} else if (pid == 0) {
		close(fd[1]);
		//n = read(fd[0], buff, 5);
		close(fd[0]);
		//write(1, buff, n);
	} else {
		//close(fd[0]);
		
		// write(1, "\nEnter any 5 integers: ", 23);
		printf("\nEnter any 5 integers: ");
		//read(0, buff, 5);
		
		//write(fd[1], buff, 5);
		close(fd[1]);
		wait(&status);

		printf("Parent process is terminating!\n");
	}

	return 0;
}
