// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
// #define BUFFER_SIZE 1024  // Small buffer
#define BUFFER_SIZE 131072 // Large buffer

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // dd if=/dev/urandom of=large_file.bin bs=1M count=50
    FILE *fp = fopen("large_file.bin", "rb");

    sock = socket(AF_INET, SOCK_STREAM, 0);

    // Uncomment this to test with 128 KB buffer
    int bufsize = 131072;
    setsockopt(sock, SOL_SOCKET, SO_SNDBUF, &bufsize, sizeof(bufsize));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Connected to server. Sending file...\n");

    clock_t start = clock();

    int bytes;
    while ((bytes = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        send(sock, buffer, bytes, 0);
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("File sent in %.2f seconds\n", time_taken);

    fclose(fp);
    close(sock);
    return 0;
}

