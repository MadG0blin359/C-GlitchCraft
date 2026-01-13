#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;
    socklen_t len = sizeof(servaddr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Define encryption key
    char key = 0x5A; // Example key
    sendto(sockfd, &key, sizeof(key), 0, (const struct sockaddr *)&servaddr, len);

    FILE *fp = fopen("sentences.txt", "r");
    if (!fp) {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    while (!feof(fp)) {
        int n = fread(buffer, sizeof(char), MAXLINE, fp);
        for (int i = 0; i < n; i++) {
            buffer[i] ^= key; // Encrypt
        }

        sendto(sockfd, buffer, n, 0, (const struct sockaddr *)&servaddr, len);
    }

    fclose(fp);
    printf("File encrypted and sent to server.\n");
    close(sockfd);
    return 0;
}

