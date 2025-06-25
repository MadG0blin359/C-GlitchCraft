#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main() {
	int number = 0, statusValue;
	printf("%d: I am the parent!\n", getpid());
	printf("%d: number = %d\n", getpid(), number);
	printf("%d: forking!\n", getpid());

	int forkResult = fork();

	if (forkResult < 0) {
		perror("Fork Failed");
		exit(1);
	}

	else if (forkResult == 0) {
		printf("%d: I am the child\n", getpid());
		printf("%d: number = %d\n", getpid(), number);
		printf("%d: Enter a number : \n", getpid());
		scanf("%d", &number);
		printf("%d: number = %d\n", getpid(), number);
		printf("%d: exiting with value %d\n", getpid(), number);
		exit(number);
	}

	printf("%d: number = %d\n", getpid(), number);
	printf("%d: waiting for my child\n", getpid());
	wait(&statusValue);

	if (WIFEXITED(statusValue)) {
		printf("%d: My child exited with status %d\n", getpid(), WIFEXITED(statusValue));
	}

	else {
		printf("%d: My child was killed off.\n", getpid());
	}

	return 0;
}
