#include<stdio.h>   // For standard input/output functions like printf and scanf.
#include<unistd.h>  // For POSIX operating system API functions like fork, getpid, getppid, sleep.
#include<sys/wait.h> // For functions related to waiting for child processes, like wait.
#include<stdlib.h>  // For general utilities like exit.

int main() {
    int number; // Declare an integer variable to store the user's input number.

    // Prompt the user to enter a number.
    printf("\n--Enter a number : ");
    // Read the integer input from the user and store it in 'number'.
    scanf("%d", &number);
    // Print the parent process ID (PID) and the initial value of 'number'.
    printf("\n%d: I am the parent... Number is : %d", getpid(), number);

    // Create a new child process using fork().
    // The 'pid' variable will hold 0 in the child process and the child's PID in the parent process.
    // If fork fails, 'pid' will be -1.
    int pid = fork();

    // Check if fork() failed.
    if (pid < 0) {
        // Print an error message to stderr.
        perror("Fork Failed");
        // Exit the program with an error status.
        exit(1);
    }

    // This block executes only in the child process.
    else if (pid == 0) {
        // Print the child process ID and its parent's process ID.
        printf("\n%d: I am the child & my parent is : %d...", getpid(), getppid());
        // Print the current value of 'number' within the child process.
        printf("\nCurrent number is : %d", number);
        // Increment the 'number' variable (this change is local to the child process).
        ++number;
        // Print a message indicating the child is exiting.
        printf("\nExiting child...\n");
        // Pause the child process for 1 second.
        sleep(1);
    }

    // This line is executed by the parent process.
    // The parent waits for any of its child processes to terminate.
    // 'NULL' means no status information about the child's termination is retrieved.
    wait(NULL);
    // After the child has terminated, the parent continues execution.
    // Print the parent process ID and the (unchanged) value of 'number' in the parent.
    printf("\n%d: I am the parent... Updated number is : %d\n", getpid(), number);

    // Return 0 to indicate successful program execution.
    return 0;
}