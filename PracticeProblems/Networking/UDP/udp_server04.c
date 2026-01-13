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
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Receive encryption key
    char key;
    recvfrom(sockfd, &key, sizeof(key), 0, (struct sockaddr *)&cliaddr, &len);
    printf("Received key: %d\n", key);

    FILE *fp = fopen("decrypted_output.txt", "w");
    if (!fp) {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);
        if (n <= 0) break;

        for (int i = 0; i < n; i++) {
            buffer[i] ^= key; // Decrypt
        }

        fwrite(buffer, sizeof(char), n, fp);

        if (n < MAXLINE) break; // Last chunk
    }

    fclose(fp);
    printf("Decryption complete. Saved to 'decrypted_output.txt'\n");
    close(sockfd);
    return 0;
}

