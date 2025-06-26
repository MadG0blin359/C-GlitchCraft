#include<stdio.h>
#include<unistd.h>

int main() {
	int pid = fork();	// Create first parent process
	
	if (pid > 0) {
		printf("I am a child, my PID is %d, my parent PID is %d.\n",pid ,getpid());
		pid = fork();
		
		if (pid > 0) {
			printf("I am a child, my PID is %d, my parent PID is %d.\n",pid ,getpid());
		
		}
	}
	
	return 0;
}
