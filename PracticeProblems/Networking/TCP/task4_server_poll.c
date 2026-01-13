// server_poll.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Listen for connections
    listen(server_fd, 5);
    printf("Server listening on port %d...\n", PORT);

    struct pollfd fds[2];
    fds[0].fd = server_fd;
    fds[0].events = POLLIN;
    fds[1].fd = STDIN_FILENO;
    fds[1].events = POLLIN;

    while (1) {
        int activity = poll(fds, 2, -1);
        if (activity < 0) {
            perror("poll error");
            continue;
        }

        // Check for new connection
        if (fds[0].revents & POLLIN) {
            client_fd = accept(server_fd, NULL, NULL);
            printf("New client connected\n");
        }

        // Check for input from stdin
        if (fds[1].revents & POLLIN) {
            fgets(buffer, BUFFER_SIZE, stdin);
            printf("You typed: %s", buffer);
        }
    }

    close(server_fd);
    return 0;
}

