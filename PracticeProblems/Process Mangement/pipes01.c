#include <stdio.h>    // For printf, scanf, perror
#include <unistd.h>   // For pipe, fork, read, write, close, getpid
#include <stdlib.h>   // For exit
#include <sys/types.h> // For pid_t
#include <sys/wait.h> // For wait

int main() {
    int buffer[5];    // Buffer to hold 5 integers
    int n, fd[2];     // n: bytes read/written, fd: pipe file descriptors
    pid_t pid;        // Process ID

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("Pipe Failed!\n");
        return 1;
    }

    // Create child process
    if ((pid = fork()) < 0) {
        perror("Bad Fork!\n");
        exit(1);
    } else if (pid > 0) { // Parent process
        close(fd[0]); // Close read end of pipe in parent

        printf("Enter 5 integers:\n");
        // Read 5 integers from stdin into buffer
        for (int i = 0; i < 5; i++) {
            scanf("%d", &buffer[i]);
        }

        // This line is potentially incorrect; 'n' is uninitialized here.
        // If the intention was to print the input, it should use sizeof(buffer).
        write(1, buffer, n); // Write buffer content to stdout (might be garbage as 'n' is undefined)

        write(fd[1], buffer, sizeof(buffer)); // Write buffer (5 integers) to pipe
        close(fd[1]); // Close write end of pipe in parent

        wait(NULL); // Wait for child to terminate
        printf("%d: Parent Terminating!\n", getpid());
    } else { // Child process
        close(fd[1]); // Close write end of pipe in child

        printf("%d: Child Process Recieving Data...\n", getpid());
        // Read integers from pipe into buffer
        n = read(fd[0], buffer, sizeof(buffer)); 
        close(fd[0]); // Close read end of pipe in child

        // Multiply each integer in the buffer by 5
        for (int i = 0; i < 5; i++) {
            buffer[i] *= 5;
        }

        write(1, buffer, n); // Write updated buffer content to stdout
        printf("Total bytes recieved : %d\n", n);
        printf("Child Terminating!\n");
        exit(0); // Child exits
    }

    return 0; // Parent exits
}