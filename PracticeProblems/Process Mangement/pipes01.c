#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int buffer[5];
    int n, fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("Pipe Failed!\n");
        return 1;
    }

    if ((pid = fork()) < 0) {
        perror("Bad Fork!\n");
        exit(1);
    } else if (pid > 0) {
        close(fd[0]);

        printf("Enter 5 integers:\n");
        for (int i = 0; i < 5; i++) {
            scanf("%d", &buffer[i]);
        }

        write(1, buffer, n);
        write(fd[1], buffer, sizeof(buffer));
        close(fd[1]);

        wait(NULL);
        printf("%d: Parent Terminating!\n", getpid());
    } else {
        close(fd[1]);

        printf("%d: Child Process Recieving Data...\n", getpid());
        n = read(fd[0], buffer, sizeof(buffer));
        close(fd[0]);

        for (int i = 0; i < 5; i++) {
            buffer[i] *= 5;
        }

        write(1, buffer, n);
        printf("Total bytes recieved : %d\n", n);
        printf("Child Terminating!\n");
        exit(0);
    }

    return 0;
}