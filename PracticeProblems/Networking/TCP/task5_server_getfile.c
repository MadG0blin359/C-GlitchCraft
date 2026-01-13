// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024  // Small buffer
// #define BUFFER_SIZE 131072 // Large buffer

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    FILE *fp = fopen("received_file.bin", "wb");

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 1);
    printf("Server listening...\n");

    client_fd = accept(server_fd, NULL, NULL);
    printf("Client connected. Receiving file...\n");

    clock_t start = clock();

    int bytes;
    while ((bytes = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes, fp);
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("File received in %.2f seconds\n", time_taken);

    fclose(fp);
    close(client_fd);
    close(server_fd);
    return 0;
}

