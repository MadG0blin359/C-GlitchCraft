#include <stdio.h>   // For printf, fgets, perror
#include <unistd.h>  // For write, close
#include <string.h>  // For strcmp
#include <fcntl.h>   // For open, O_WRONLY

// Writing to a named pipe (FIFO)
int main() {
    char buffer[100]; // Buffer to store user input

    printf("Opening named pipe...\n");
    // Open the named pipe "chatFifo" for writing (blocking until a reader opens it)
    int fd = open("chatFifo", O_WRONLY);
    if (fd == -1) {
        perror("open failed"); // Print error if opening FIFO fails
        return 1;
    }

    // Loop indefinitely to write to the FIFO
    while (1) {
        printf("Enter Input: ");
        fgets(buffer, sizeof(buffer), stdin); // Read user input from stdin

        printf("\nWriting buffer to pipe...");
        // Write the content of the buffer to the FIFO
        int n = write(fd, buffer, strlen(buffer)); // Use strlen(buffer) to write only the actual input, not the whole buffer size
        if (n == -1) {
            perror("write failed"); // Print error if write fails
            break; // Exit loop on write error
        }
        printf("done\n");

        // Check if the input message is "exit\n" to terminate
        if (strcmp(buffer, "exit\n") == 0) {
            printf("Exiting\n");
            break; // Exit loop
        }
    }

    close(fd); // Close the FIFO file descriptor

    return 0; // Program exit
}