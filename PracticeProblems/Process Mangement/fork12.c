#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t whichone, first, second;
    int howmany, status;

    if ((first = fork()) == 0) {  // Parent creates 1st child
        printf("Hi, I am the first child and my ID is %d\n", getpid());
        sleep(10);
        exit(0);
    } else if (first == -1) {
        perror("1st fork: something went wrong\n");
        exit(1);
    }

    if ((second = fork()) == 0) {  // Parent creates 2nd child
        printf("Hi, I am the second child, and my ID is %d\n", getpid());
        sleep(15);
        exit(0);
    } else if (second == -1) {
        perror("2nd fork: something went wrong\n");
        exit(1);
    }

    printf("This is the parent\n");

    howmany = 0;
    while (howmany < 2) {
        whichone = wait(&status);  // Wait for a child to exit
        howmany++;

        if (whichone == first) {
            printf("First child %d exited\n", whichone);
        } else if (whichone == second) {
            printf("Second child %d exited\n", whichone);
        }

        if (WIFEXITED(status)) {  // Check if child exited normally
            printf("Correctly! %d Exit Status %d\n",whichone, status);
        } else {
            printf("Uncorrectly\n");
        }
    }

    return 0;
}
