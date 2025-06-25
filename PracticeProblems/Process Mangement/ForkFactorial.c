#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int factorial(int num) {
    if (num == 0) return 1;
    return num * factorial(num - 1);
}

int main() {
    int number;
    int pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        printf("Enter a number: ");
        scanf("%d", &number);

        sleep(2); // Child process sleeps for 2 seconds

        int result = factorial(number);
        printf("Factorial of %d is %d\n", number, result);
        printf("Child process: I am now an orphan. My parent's PID is now %d.\n", getppid());
        printf("Child process terminated.\n");
        exit(0);
    } else {
        wait(NULL);
        printf("Parent process: My PID is %d.\n", getpid());
        printf("Parent process terminated.\n");
    }

    return 0;
}

