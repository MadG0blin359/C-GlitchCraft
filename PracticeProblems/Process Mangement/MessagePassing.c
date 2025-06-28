#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char buffer[5];
    int n, fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("Pipe Failed!\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Bad Fork!\n");
        exit(1);
    } else if (pid > 0) {
        printf("Enter 5 integers:\n");
    	  n = read(0, buffer, sizeof(buffer));
        close(fd[0]);

        write(fd[1], buffer, n);
        close(fd[1]);

        wait(NULL);
        printf("%d: Parent Terminating!\n", getpid());
    } else {
        close(fd[1]);

        n = read(fd[0], buffer, sizeof(buffer));
        printf("%d: Child Process Recieving Data...\n", getpid());
        printf("Total bytes recieved : %d\n", n);
        close(fd[0]);
        
        int values[n];
        printf("Type Casting to (int)...\n");
	  printf("Updated Numbers:\n");
        for (int i = 0; i < 5; i++) {
        	values[i] = buffer[i] - '0';		// Converting char to int
            values[i] *= 5;			// Multiplying by 5
            printf("-> %d\n", values[i]);
        }

        printf("Child Terminating!\n");
        exit(0);
    }

    return 0;
}
