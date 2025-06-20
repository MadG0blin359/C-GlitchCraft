#include<stdio.h>
#include<unistd.h>

int main() {
	int pid = fork();
	
	if (pid == 0) {
		printf("Child Process Created!\n");
		printf("PID = %d\n", pid);
	}

	else if (pid > 0) {
		printf("Parent Process Created!\n");
		printf("PID = %d\n", pid);
	}

	else {
		printf("Error Occured in Child Process Creation");
	}
	
	return 0;
}
