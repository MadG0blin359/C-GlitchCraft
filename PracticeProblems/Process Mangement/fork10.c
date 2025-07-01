#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int pid, status;
	pid = fork();
	
	if (pid > 0) {
		printf("%d: I'm going to wait for %d\n", getpid(), pid);
		pid = wait(NULL);
		printf("%d: I'm Parent! My Child Died %d\n", getpid(), pid);
	}

	else if (pid == 0) {
		printf("%d: I'm Child! I'm going to sleep.\n", getpid());
		sleep(10);
		printf("%d: I'm Terminating!\n", getpid());
		exit(0);
	}

	return 0;
}
