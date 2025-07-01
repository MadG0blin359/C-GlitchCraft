#include <stdio.h>
#include <unistd.h>		// fork()
#include <sys/wait.h>		// wait()
#include <sys/types.h>		// pid_t/size_t
#include <stdlib.h>		// exit()

int main() {
	pid_t pid = fork();
	
	if (pid < 0) {
		perror("Bad Fork!\n");
		exit(1);
	}
	
	else if (pid == 0) {
		int x = 10;
		
		if (pid > 0) {
			printf("%d: New New Child!\n", getpid());
		}
		
		else if (pid == 0) {
			printf("%d: I am main child my parent is %d\n", getpid(), getppid());
		}
	}
	
	else {
		pid = fork();
		
		if (pid > 0)
			printf("%d: I'm Parent, my Child is %d\n", getpid(), pid);
			
		else if (pid == 0)
			printf("%d: I'm new Child, my Parent is %d\n", getpid(), getppid());
	}

	return 0;
}
