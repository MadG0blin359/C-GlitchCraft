#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main() {
	int pid;
	int status;
	printf("Hello World!\n");
	
	pid = fork();

	if (pid == -1) {
		perror("Bad Fork");
		exit(1);
	}

	if (pid == 0) {
		printf("I am the Child Process.\n");
	}

	else {
		wait(&status);
		printf("I am the Parent Process.\n");
	}

	return 0;
}
