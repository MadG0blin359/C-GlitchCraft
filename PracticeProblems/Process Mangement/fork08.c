#include <stdio.h>
#include <unistd.h>		// fork()
#include <sys/wait.h>		// wait()
#include <sys/types.h>		// pid_t/size_t
#include <stdlib.h>		// exit()

int main() {
	printf("%d: I'm main.\n", getpid());
	
	pid_t pid = fork();
	
	if (pid < 0) {
		perror("Bad Fork!\n");
		exit(1);
	}
	
	else if (pid == 0) {
		printf("%d: I'm Child & my Parent is :%d\n", getpid(), getppid());
		printf("%d: Completed!\n", getpid());
		sleep(10);
		exit(0);
	}

	else if (pid > 0) {
		wait(NULL);
		printf("%d: Exit Status Collected by %d!\n", pid, getpid());
		printf("%d: I'm Parent.\n", getpid());
		sleep(10);
		
		pid = fork();
		if (pid > 0) {
			wait(NULL);
			printf("%d: I just want to sleep!\n", getpid());
		}
		
		else if (pid == 0) {
			printf("%d: New Process Created by %d!\n", getpid(), getppid());
			exit(0);		
		}
	}

	return 0;
}
