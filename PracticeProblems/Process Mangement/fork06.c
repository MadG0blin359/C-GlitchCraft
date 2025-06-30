#include <stdio.h>
#include <unistd.h>	// POSIX (UNIX/LINUX)
#include <sys/wait.h>	// wait()
#include <stdlib.h>	// exit()

int main() {
	int x = 5, status;
	pid_t pid = fork();

	if (pid == 0) {
		x++;
		printf("%d: I'm Child, my Parent %d, x:%d\n", getpid(), getppid(), x);
		exit(0);
	}
	else if (pid > 0) {
		printf("%d: I will wait.\n", getpid());
		wait(NULL);
		printf("%d: I'm Parent & my Child was %d, x:%d\n", getpid(), pid, x);
	}
	else {
		perror("Bad Fork!");
		exit(1);
	}

	return 0;
}
