#include <stdio.h>    // Standard input/output library. Provides functions like printf.
#include <unistd.h>   // POSIX operating system API. Provides functions like read, write, and close.
#include <stdlib.h>   // Standard library. Provides general utilities (not directly used in this snippet but often included).
#include <sys/wait.h> // System calls for waiting for process termination (not used in this specific snippet).
#include <sys/types.h> // System data types (e.g., pid_t, off_t). Necessary for some system calls.
#include <sys/stat.h> // File status and mode information. Used for functions like 'stat' and 'fstat' (not directly used here but related to file operations).
#include <fcntl.h>    // File control options. Provides flags for open() like O_RDONLY, O_WRONLY, O_CREAT, etc.

int main() {
    int n;    // Declare an integer variable 'n' to store the number of bytes read.
    int fd;   // Declare an integer variable 'fd' to store the file descriptor.
    char buff[50]; // Declare a character array (buffer) of size 50 to store data read from the file.

    // Open the file "test.txt" in read-only mode (O_RDONLY).
    // If the file does not exist or cannot be opened, 'open' will return -1.
    fd = open("test.txt", O_RDONLY);
    // Print the file descriptor returned by the open() call.
    // A positive integer indicates a successful open; -1 indicates an error.
    printf("File Descriptor: %d\n", fd);

    // Read up to 50 bytes from the file descriptor 'fd' into the 'buff' buffer.
    // The number of bytes actually read is stored in 'n'.
    // If 'n' is 0, end of file is reached. If 'n' is -1, an error occurred.
    n = read(fd, buff, 50);
    // Write 'n' bytes from the 'buff' buffer to file descriptor 1 (stdout - standard output, typically the console).
    // This will print the content read from "test.txt" to the screen.
    write(1, buff, n);
    // Return 0 to indicate successful program execution.
    return 0;
}