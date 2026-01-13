// UDP Server: Receives a decimal integer, calculates sum of even-positioned digits, sends result
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int sum_even_position_digits(const char *numStr) {
    int sum = 0;
    int len = strlen(numStr);
    for (int i = 0; i < len; i++) {
        if ((i + 1) % 2 == 0 && numStr[i] >= '0' && numStr[i] <= '9') {
            sum += numStr[i] - '0';
        }
    }
    return sum;
}

int main() {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    socklen_t len = sizeof(cliaddr);

    while (1) {
        int n = recvfrom(sockfd, buffer, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0';

        if (strcmp(buffer, "exit") == 0) break;

        int result = sum_even_position_digits(buffer);
        sprintf(buffer, "Sum of even-positioned digits: %d", result);

        sendto(sockfd, buffer, strlen(buffer), 0, (const struct sockaddr *)&cliaddr, len);
    }

    close(sockfd);
    return 0;
}

