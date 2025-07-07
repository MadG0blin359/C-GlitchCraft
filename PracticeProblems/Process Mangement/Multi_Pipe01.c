#include <stdio.h>   // For printf, perror
#include <stdlib.h>  // For exit
#include <unistd.h>  // For fork, read, write, close, unlink
#include <sys/types.h> // For pid_t
#include <sys/wait.h>  // For wait
#include <sys/stat.h>  // For mkfifo
#include <fcntl.h>   // For open flags (O_RDONLY, O_WRONLY)

#define FIFO1 "pipe1" // Name for the first named pipe
#define FIFO2 "pipe2" // Name for the second named pipe

int main() {
    int fd;             // File descriptor
    pid_t child1, child2; // Process IDs for two child processes

    // Create two named pipes (FIFOs)
    if (mkfifo(FIFO1, 0666) == -1 || mkfifo(FIFO2, 0666) == -1) {
        perror("mkfifo failed!"); // Error if FIFO creation fails
        exit(1);
    }

    // Fork the first child process
    if ((child1 = fork()) == -1) {
        perror("First Child: Fork Failed!");
        exit(1);
    } else if (child1 == 0) { // Code for the first child process
        int n;
        char buffer[100]; // Buffer to read input from parent
        
        // Open FIFO1 for reading
        if ((fd = open(FIFO1, O_RDONLY)) == -1) {
            perror("First Child: Cannot open FIFO1 For Reading!");
            exit(1);
        }
        
        n = read(fd, buffer, sizeof(buffer)); // Read data from FIFO1
        close(fd); // Close FIFO1 read end

        int numbers[n], count = -1; // Array to store converted numbers, count of numbers
        
        // Convert char digits to int and square them
        printf("Squared numbers: ");
        for (int i = 0; i < n; i++) {
            if (buffer[i] != ' ') { // Skip spaces
                count++;
                numbers[count] = buffer[i] - '0'; // Convert char to int
                numbers[count] *= numbers[count]; // Square the number
                printf("%d ", numbers[count]); // Print squared number
            }
        }
        printf("\n");
        
        // Open FIFO2 for writing
        if ((fd = open(FIFO2, O_WRONLY)) == -1) {
            perror("First Child: Cannot open FIFO2 For Writing!");
            exit(1);
        }
        
        // Write squared numbers to FIFO2
        write(fd, numbers, sizeof(int) * (count + 1));
        close(fd); // Close FIFO2 write end
        
        exit(0); // First child exits
    }
    
    // Fork the second child process
    if ((child2 = fork()) == -1) {
        perror("Second Child: Fork Failed!");
        exit(1);
    } else if (child2 == 0) { // Code for the second child process
        int numbers[10], count = 0, sum = 0; // Array for numbers, count, sum
        
        // Open FIFO2 for reading
        if ((fd = open(FIFO2, O_RDONLY)) == -1) {
            perror("Second Child: Cannot open FIFO2 For Reading!");
            exit(1);
        }
        
        count = read(fd, numbers, sizeof(numbers)); // Read squared numbers from FIFO2
        close(fd); // Close FIFO2 read end
        
        count /= sizeof(int); // Calculate actual count of integers
        
        // Compute sum of squared numbers
        for (int i = 0; i < count; i++) {
            sum += numbers[i];
        }
        
        // Open FIFO2 for writing (re-open for writing the sum back to parent)
        if ((fd = open(FIFO2, O_WRONLY)) == -1) {
            perror("Second Child: Cannot open FIFO2 For Writing!");
            exit(1);
        }
        
        write(fd, &sum, sizeof(sum)); // Write the sum to FIFO2
        close(fd); // Close FIFO2 write end
            
        exit(0); // Second child exits
    }
    
    // Code for the parent process
    int sum = 0;
    char input[] = "1 2 3 4 5"; // Input string for children
    
    // Open FIFO1 for writing
    if ((fd = open(FIFO1, O_WRONLY)) == -1) {
        perror("Parent: Cannot open FIFO1 For Writing!");
        exit(1);
    }
    
    write(fd, input, sizeof(input) - 1); // Write input to FIFO1 (ignore null terminator)
    close(fd); // Close FIFO1 write end
    
    wait(NULL); // Wait for the first child to terminate
    
    // Open FIFO2 for reading to get the final sum
    if ((fd = open(FIFO2, O_RDONLY)) == -1) {
        perror("Parent: Cannot open FIFO2 For Reading!");
        exit(1);
    }
    
    read(fd, &sum, sizeof(sum)); // Read the sum from FIFO2
    close(fd); // Close FIFO2 read end

    wait(NULL); // Wait for the second child to terminate

    printf("Sum of squared numbers: %d\n", sum); // Print the final sum

    // Clean up: remove the named pipes
    unlink(FIFO1);
    unlink(FIFO2);
    
    return 0; // Parent exits
}