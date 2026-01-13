#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

void handle_client(int client_socket) {
    char buffer[1024];
    ssize_t bytes_received;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

        if (bytes_received <= 0) {
            printf("Client %d disconnected or error occurred.\n", client_socket);
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Received from client %d: %s\n", client_socket, buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Client %d requested to exit.\n", client_socket);
            break;
        }

        send(client_socket, "Your request was serviced\n", strlen("Your request was serviced\n"), 0);
        printf("Request serviced for client: %d by child %d\n", client_socket, getpid());
    }

    close(client_socket);
    exit(0);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pid_t pid;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket error");
        exit(1);
    }
    printf("Socket created for server.\n");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    if (listen(server_socket, 8) == 0) {
        printf("Listening...\n");
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        pid = fork();
        if (pid == 0) {
            close(server_socket);
            printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            handle_client(client_socket);
        } else if (pid > 0) {
            close(client_socket);
        } else {
            perror("Fork failed");
        }
    }

    close(server_socket);
    return 0;
}
