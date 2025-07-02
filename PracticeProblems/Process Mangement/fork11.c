#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, returnPID;
    int status;

    pid1 = fork();

    if (pid1 < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } 
    
    else if (pid1 == 0) {
        // First child process
        printf("First child (PID: %d) going to sleep for 5 seconds\n", getpid());
        sleep(50);
        printf("First child (PID: %d) woke up and exiting\n", getpid());
        exit(0);
    } 
    
    else {
        // Parent process creates second child
        pid2 = fork();

        if (pid2 < 0) {
            // Fork failed
            fprintf(stderr, "Fork failed\n");
            return 1;
        } 
        
        else if (pid2 == 0) {
            // Second child process
            printf("Second child (PID: %d) doing some work and exiting\n", getpid());
            exit(0);
        } 
        
        else {
            // Parent process waits for both children
            printf("Parent process (PID: %d) waiting for children to terminate\n", getpid());

            // Wait for any child to terminate
            returnPID = wait(&status);
            printf("Parent process: A child (%d) has terminated\n", returnPID);

            // Wait for the second child to terminate if the first one has already terminated
            wait(&status);
            printf("Parent process: Another child has terminated\n");

            printf("I am Parent Process with PID: %d\n", getpid());
        }
    }

    return 0;
}
