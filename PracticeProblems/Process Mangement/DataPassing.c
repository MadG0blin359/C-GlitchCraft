#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2], pipe3[2];
    pid_t child1, child2, child3;

    if (pipe(pipe1) == -1 || pipe(pipe2) == -1 || pipe(pipe3) == -1) {
        perror("Pipe failed!\n");
        exit(1);
    }

    child1 = fork();
    if (child1 == 0) {
        // First child process
        close(pipe1[1]); 
        close(pipe2[0]);

        int num;
        
        read(pipe1[0], &num, sizeof(num)); // Read data from parent
        close(pipe1[0]);

        int result1 = num * 10; // Multiplication
        
        int result2 = num / 10; // Division

        write(pipe2[1], &result1, sizeof(result1)); // Send result1 to second child
      write(pipe2[1], &result2, sizeof(result2)); // Send result2 to second child
        
        close(pipe2[1]);

        child3 = fork();
        if (child3 == 0) {
            // Third child process (C3)
            close(pipe3[1]);

            int final_result1, final_result2;
            
            read(pipe3[0], &final_result1, sizeof(final_result1));
            	read(pipe3[0], &final_result2, sizeof(final_result2));
            close(pipe3[0]);

            printf("C3 process: Addition result = %d\n", final_result1);
            
            printf("C3 process: Subtraction result = %d\n", final_result2);
            exit(0);
        } else {
            wait(NULL); // Wait for C3 to finish
            exit(0);
        }
    }

    child2 = fork();
    if (child2 == 0) {
        // Second child process
        close(pipe2[1]);
        close(pipe3[0]); 

        int result1, result2;
        read(pipe2[0], &result1, sizeof(result1)); 
        
        read(pipe2[0], &result2, sizeof(result2)); 
        
        close(pipe2[0]);

        int new_num;
        printf("Second child process: enter a number: ");
        scanf("%d", &new_num);

        int final_result1 = result1 + new_num; // Addition
int final_result2 = result2 - new_num; // Subtraction

        write(pipe3[1], &final_result1, sizeof(final_result1)); // Send results to C3
        
        write(pipe3[1], &final_result2, sizeof(final_result2));
        
        close(pipe3[1]);

        exit(0);
    }

    // Parent process
    close(pipe1[0]); 

    int num;
    printf("Parent process: enter a number: ");
    scanf("%d", &num);
    
    write(pipe1[1], &num, sizeof(num)); // Send data to first child
    close(pipe1[1]); 

    // Wait for all child processes to complete
    wait(NULL); 
    wait(NULL); 

    printf("Parent process terminating after All children have completed.\n");
    return 0;
}

