#include <stdio.h>
#include <unistd.h>	// POSIX (UNIX/LINUX)
#include <sys/wait.h>	// wait()
#include <stdlib.h>	// exit()

int main() {		// Orphan Child
	int x = 5, status;
	pid_t pid = fork();

	if (pid == 0) {
		sleep(10);
		x++;
		printf("%d: I'm Child, my new Parent is %d, x:%d\n", getpid(), getppid(), x);
	}
	else if (pid > 0) {
		printf("%d: I'm Parent & my Child is %d, x:%d\n", getpid(), pid, x);
	}
	else {
		perror("Bad Fork!");
		exit(1);
	}
	
	if (pid > 0)
		printf("%d: Terminated!\n", getpid());
	
	return 0;
}
