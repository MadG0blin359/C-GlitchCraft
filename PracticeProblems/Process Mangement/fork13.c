#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
	printf("%d: I'm main.\n", getpid());

	int status;
	pid_t pid = fork();

	if (pid < 0) {
		perror("Bad Fork!\n");
		exit(1);
	}
	
	else if (pid == 0) {
		printf("%d: I'm Child.\n", getpid());
		exit(1);
	}
	
	else {
		printf("%d: I'm Parent. My Child is %d\n", getpid(), pid);
		
		pid = fork();
		
		if (pid < 0) {
			perror("Bad Fork!\n");
			exit(1);
		}
		
		else if (pid == 0) {
			printf("%d: I'm another Child.\n", getpid());
			exit(0);
		}
		
		else {
			printf("%d: I created another child %d\n", getpid(), pid);
			
			sleep(5);
			
			for (int i = 1; i <= 2; i++) {
				pid = wait(&status);
				printf("%d: Child Terminated with Status %d!\n", pid, status);		
			}
		}
	
	}

	return 0;
}
