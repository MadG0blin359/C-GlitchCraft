#include<stdio.h>
#include<unistd.h>

int main() {
	
	int pid = fork();	// Create first parent process
	
	// Create process in skewed manner
	if (pid > 0) {
		for (int i = 1; i <= 3; i++) {
			if (pid > 0  && getpid() != 0) {
				printf("I am a process %d.\n", pid);
			}
			pid = fork();	// Create child processes
		}
	}
	
	return 0;
}
