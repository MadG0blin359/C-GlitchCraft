#include<stdio.h>
#include<unistd.h>

int main() {
	printf("Before\n");	
	int pid = fork();
	printf("After\n");
	fork();
	printf("After 2\n");
	printf("After 3\n");	
	
	return 0;
}
