#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main() {
	int number;
	
	printf("\n--Enter a number : ");
    	scanf("%d", &number);
    	printf("\n%d: I am the parent... Number is : %d", getpid(), number);

	int pid = fork();
	
	if (pid < 0) {
		perror("Fork Failed");
		exit(1);
	}

	else if (pid == 0) {
		printf("\n%d: I am the child & my parent is : %d...", getpid(), getppid());
		printf("\nCurrent number is : %d", number);
		++number;
		printf("\nExiting child...\n");		
		sleep(1);
	}

	wait(NULL);
	printf("\n%d: I am the parent... Updated number is : %d\n", getpid(), number);

	return 0;
}
