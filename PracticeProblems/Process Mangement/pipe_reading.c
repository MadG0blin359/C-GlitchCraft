#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

// Reading file
int main() {
    char buffer[100];

    printf("Creating named pipe...\n");
    if (mkfifo("chatFifo", 0666) == -1) {
        perror("mkfifo failed!\n");
        return 1;
    }

    printf("Waiting for input...\n");
    int fd = open("chatFifo", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    while (1) {
        int n = read(fd, buffer, sizeof(buffer));
        if (n == -1) {
            perror("read failed!\n");
            break;
        }

        printf("Waiting for input... %s\n", buffer);

        if (strcmp(buffer, "exit\n") == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    close(fd);
    unlink("chatFifo");

    return 0;
}

