// tcp_server_poll.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    struct pollfd fds[MAX_CLIENTS + 1];
    char buffer[BUFFER_SIZE];

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind server socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    listen(server_fd, 5);
    printf("Server listening on port %d...\n", PORT);

    // Initialize pollfd array
    fds[0].fd = server_fd;
    fds[0].events = POLLIN;
    for (int i = 1; i <= MAX_CLIENTS; i++)
        fds[i].fd = -1;

    while (1) {
        int activity = poll(fds, MAX_CLIENTS + 1, -1);
        if (activity < 0) {
            perror("poll error");
            continue;
        }

        // New connection
        if (fds[0].revents & POLLIN) {
            client_fd = accept(server_fd, NULL, NULL);
            printf("New client connected\n");

            for (int i = 1; i <= MAX_CLIENTS; i++) {
                if (fds[i].fd == -1) {
                    fds[i].fd = client_fd;
                    fds[i].events = POLLIN;
                    break;
                }
            }
        }

        // Handle client messages
        for (int i = 1; i <= MAX_CLIENTS; i++) {
            if (fds[i].fd != -1 && fds[i].revents & POLLIN) {
                int bytes = read(fds[i].fd, buffer, BUFFER_SIZE);
                if (bytes == 0) {
                    close(fds[i].fd);
                    fds[i].fd = -1;
                    printf("Client disconnected\n");
                } else {
                    buffer[bytes] = '\0';
                    printf("Received: %s\n", buffer);
                    send(fds[i].fd, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}

