#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main() {
	int forkResult;
	printf("%d: I am the Parent Process. Remeber my number.\n", getpid());
	
	forkResult = fork();

	if (forkResult < 0) {
		perror("Fork Failed");
		exit(1);
	}

	if (forkResult > 0) {
		printf("%d: My Child's pid is : %d\n", getpid(), forkResult);
		wait(NULL);
	}

	else {
		printf("%d: Hi! I am the Child Process.\n", getpid());
	}

	printf("%d: Like father like son.\n", getpid());

	return 0;
}
