#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 4444
#define BUFFER_SIZE 1024

int main() {
    int Clisock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    Clisock = socket(AF_INET, SOCK_STREAM, 0);
    if (Clisock < 0) {
        perror("Socket creation failed");
        return -1;
    }
    printf("Client socket created\n");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(Clisock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }
    printf("Connected to the server\n");

    while (1) {
        printf("Enter message (type 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline

        send(Clisock, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }

        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(Clisock, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("Server: %s\n", buffer);
        } else {
            printf("Server disconnected\n");
            break;
        }
    }

    close(Clisock);
    return 0;
}
