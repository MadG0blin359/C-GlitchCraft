#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define SIZE 10

int main() {
	int fd[2];
	pid_t pid;
	
	if (pipe(fd) == -1) {
		perror("Pipe Failed!\n");
		return 1;
	}
	
	if ((pid = fork()) < 0) {
		perror("Bad Fork!\n");
		exit(1);
	} else if (pid > 0) {
		close(fd[0]);
		
		int randomNumbers[SIZE];
		srand(time(NULL));
		
		for (int i = 0; i < SIZE; i++) {
			randomNumbers[i] = rand() % 50;
		}
		
		ssize_t written = write(fd[1], randomNumbers, sizeof(randomNumbers));
		if (written != sizeof(randomNumbers)) {
			perror("Partial write error!\n");
			return 1;		
		}
		close(fd[1]);
		
		wait(NULL);
		
		printf("Original array: ");
		for (int i = 0; i < SIZE; i++) {
			printf("%d ", randomNumbers[i]);
		}
		printf("\nParent Process Terminated!\n");
	} else {
		close(fd[1]);
		
		int data[SIZE];
		
		if (read(fd[0], data, sizeof(data)) == -1) {
			perror("Partial read error!\n");
			return 1;
		}
		close(fd[0]);
		
		printf("Updated array: ");
		for (int i = 0; i < SIZE; i++) {
			data[i] *= i;
			printf("%d ", data[i]);
		}
		printf("\nChild Process Terminated!\n");
		
		exit(0);
	}
	
	return 0;
}
