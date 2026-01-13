#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server listening on port %d...\n", PORT);

	

    new_socket = accept(server_fd, (struct sockaddr *)&address,
                        (socklen_t*)&addrlen);

// send the welcome message immediately after client connection 
        char reply[50];
        sprintf(reply, "Welcome from Server");
        send(new_socket, reply, strlen(reply), 0);

    for (int i = 0; i < 3; i++) {
        // Clear buffer
        char buffer[BUFFER_SIZE] = {0};

	int clientMsg =  read(new_socket, buffer, BUFFER_SIZE-1);
	printf("Client: %s \n", buffer);

        // send the response string 
        sprintf(reply, "Message %d received", i + 1);
        send(new_socket, reply, strlen(reply), 0);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}

