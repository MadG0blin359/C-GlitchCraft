#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 4444
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Connected to calculator server.\n");

    while (1) {
        printf("Enter expression (e.g., 3 + 5), or type 'exit': ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, "exit") == 0)
            break;

        send(client_socket, buffer, strlen(buffer), 0);

        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        buffer[bytes_received] = '\0';
        printf("Server: %s\n", buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    close(client_socket);
    return 0;
}
