#include<stdio.h>
#include<unistd.h>

int main() {
	int number = 0;
	int pid = fork();	// Create first parent process
	
	if (pid == 0) {
		printf("--Enter any number : ");
		scanf("%d", &number);
		printf("Number : %d", number);
	}
	
	return 0;
}
