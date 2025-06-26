#include<stdio.h>
#include<unistd.h>

int main() {
	int pid = fork();	// Create first parent process
	
	if (pid > 0) {
		printf("I am the left child, and my pid is : %d\n", getpid());
		pid = fork();
		if (pid > 0)
			printf("I am L1, and my pid is : %d\n", pid);
		if (pid == 0)
			printf("I am L2, and my pid is : %d\n", pid);
	}
	
	else if (pid == 0) {
		printf("I am the right child, and my pid is : %d\n", getpid());
		pid = fork();
		if (pid > 0)
			printf("I am L1, and my pid is : %d\n", pid);
		if (pid == 0)
			printf("I am L2, and my pid is : %d\n", pid);
	}

	return 0;
}
