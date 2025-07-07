#include <stdio.h>   // For printf, perror
#include <unistd.h>  // For read, close
#include <string.h>  // For strcmp
#include <sys/stat.h> // For mkfifo
#include <fcntl.h>   // For open, O_RDONLY

// Reading from a named pipe (FIFO)
int main() {
    char buffer[100]; // Buffer to store data read from FIFO

    printf("Creating named pipe...\n");
    // Create a named pipe named "chatFifo" with read/write permissions for all
    if (mkfifo("chatFifo", 0666) == -1) {
        perror("mkfifo failed!\n"); // Print error if FIFO creation fails
        return 1;
    }

    printf("Waiting for input...\n");
    // Open the named pipe for reading (blocking until a writer opens it)
    int fd = open("chatFifo", O_RDONLY);
    if (fd == -1) {
        perror("open failed"); // Print error if opening FIFO fails
        return 1;
    }

    // Loop indefinitely to read from the FIFO
    while (1) {
        int n = read(fd, buffer, sizeof(buffer)); // Read data from FIFO into buffer
        if (n == -1) {
            perror("read failed!\n"); // Print error if read fails
            break; // Exit loop on read error
        }
        buffer[n] = '\0'; // Null-terminate the string read from FIFO

        printf("Received: %s\n", buffer); // Print the received data

        // Check if the received message is "exit\n" to terminate
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Exiting...\n");
            break; // Exit loop
        }
    }

    close(fd); // Close the FIFO file descriptor
    unlink("chatFifo"); // Delete the named pipe from the filesystem

    return 0; // Program exit
}