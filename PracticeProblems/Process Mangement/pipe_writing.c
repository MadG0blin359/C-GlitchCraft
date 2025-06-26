#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

// Writing file
int main() {
    char buffer[100];

    printf("Opening named pipe...\n");
    int fd = open("chatFifo", O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    while (1) {
        printf("Enter Input: ");
        fgets(buffer, sizeof(buffer), stdin);

        printf("\nWriting buffer to pipe...");
        int n = write(fd, buffer, sizeof(buffer));
        if (n == -1) {
            perror("write failed");
            break;
        }
        printf("done\n");

        if (strcmp(buffer, "exit\n") == 0) {
            printf("Exiting\n");
            break;
        }
    }

    close(fd);

    return 0;
}


