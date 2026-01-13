#include <stdio.h>          // Standard I/O functions
#include <stdlib.h>         // Standard library functions
#include <string.h>         // String manipulation functions
#include <unistd.h>         // POSIX API for close(), read(), etc.
#include <arpa/inet.h>      // Functions for IP address conversion

#define PORT 8080           // Port number to connect to
#define BUFFER_SIZE 1024    // Size of the buffer for receiving data

int main() {
    int sock = 0;                           // Socket file descriptor
    struct sockaddr_in serv_addr;          // Server address structure
    char buffer[BUFFER_SIZE] = {0};        // Buffer to store server response

    sock = socket(AF_INET, SOCK_STREAM, 0);    // Create a TCP socket

    serv_addr.sin_family = AF_INET;            // Set address family to IPv4
    serv_addr.sin_port = htons(PORT);          // Convert port to network byte order

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr); // Convert IP address to binary form

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)); // Connect to the server

	// Sending messages in sequence
        char message[50];
    for (int i = 0; i < 3; i++) {
        if (i == 0){
		strcpy(message, "Hello! This is Message 1 from Client");
	}
	if (i == 1){
		strcpy(message, "Hello! This is Message 2 from Client");
	}
	if (i == 2){
		strcpy(message, "Hello! This is Message 3 from Client");
	}

        send(sock, message, strlen(message), 0);

        // Clear buffer
        char buffer[BUFFER_SIZE] = {0};

        int valread = read(sock, buffer, BUFFER_SIZE - 1);
        buffer[valread] = '\0';
        printf("Server: %s\n", buffer);
    }

    close(sock);
    return 0;
}

