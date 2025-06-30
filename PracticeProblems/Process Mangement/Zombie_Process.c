#include <stdio.h>
#include <unistd.h>	// POSIX (UNIX/LINUX)
#include <sys/wait.h>	// wait()
#include <stdlib.h>	// exit()
#include <sys/types.h>	// pid_t/size_t

int main() {		// Zombie Process
	int x = 5, status;
	pid_t pid = fork();

	if (pid < 0) {
		perror("Bad Fork!\n");
		exit(1);
	}
	
	else if (pid == 0) {
		printf("%d: I'm Child & my Parent is :%d\n", getpid(), getppid());
		printf("%d: Completed!\n", getpid());
		exit(0);
	}
	
	else if (pid > 0) {
		printf("%d: I'm Parent & my Child is :%d\n", getpid(), pid);
		sleep(100);
		printf("%d: Terminated!\n", getpid());
	}
	
	return 0;
}
