#include <stdio.h>    // For printf, perror
#include <unistd.h>   // For pipe, fork, read, write, close, getpid
#include <stdlib.h>   // For exit, atoi
#include <sys/types.h> // For pid_t
#include <sys/wait.h> // For wait

int main() {
    char buffer[5];   // Buffer to hold 5 characters
    int n, fd[2];     // n: bytes read/written, fd: pipe file descriptors
    pid_t pid;        // Process ID

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("Pipe Failed!\n");
        return 1;
    }

    pid = fork(); // Create child process

    if (pid < 0) {
        perror("Bad Fork!\n"); // Error if fork fails
        exit(1);
    } else if (pid > 0) { // Parent process
        printf("Enter 5 integers:\n");
        n = read(0, buffer, sizeof(buffer)); // Read 5 characters from stdin
        close(fd[0]); // Close read end of pipe in parent

        write(fd[1], buffer, n); // Write characters to pipe
        close(fd[1]); // Close write end of pipe in parent

        wait(NULL); // Wait for child to terminate
        printf("%d: Parent Terminating!\n", getpid());
    } else { // Child process
        close(fd[1]); // Close write end of pipe in child

        n = read(fd[0], buffer, sizeof(buffer)); // Read characters from pipe
        printf("%d: Child Process Recieving Data...\n", getpid());
        printf("Total bytes recieved : %d\n", n);
        close(fd[0]); // Close read end of pipe in child
        
        int values[n]; // Array to store integer values
        printf("Type Casting to (int)...\n");
        printf("Updated Numbers:\n");
        for (int i = 0; i < 5; i++) {
            values[i] = buffer[i] - '0'; // Convert char digit to int
            values[i] *= 5;              // Multiply by 5
            printf("-> %d\n", values[i]);
        }

        printf("Child Terminating!\n");
        exit(0); // Child exits
    }

    return 0; // Parent exits
}