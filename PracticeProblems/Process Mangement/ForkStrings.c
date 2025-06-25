#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define MAX_STRINGS 5
#define MAX_LENGTH 50

int main() {
    char fruitsNames[MAX_STRINGS][MAX_LENGTH];
    
    // Assigning values to the string array
    strcpy(fruitsNames[0], "Mango");
    strcpy(fruitsNames[1], "Strawberry");
    strcpy(fruitsNames[2], "Banana");
    strcpy(fruitsNames[3], "Apple");
    strcpy(fruitsNames[4], "Grapes");
    
    int pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } 

	else if (pid > 0) {
        // Parent process
        for (int i = 0; i < MAX_STRINGS; i++) {
            printf("Parent Process: %s\n", fruitsNames[i]);
            sleep(1);  // Sleep for 10 seconds
        }
    }

	 else {
        // Fork failed
        perror("fork");
        return 1;
    }
    
    return 0;
}

