// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

int main(){
	int sockfd;
	char buffer[MAXLINE];
	//char *hello = "Hello from Client";
	struct sockaddr_in servaddr;

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("Socket Creation Failed!\n");
		exit(EXIT_FAILURE);
	}

	// Setting all sturcture properties equal to zero
	memset(&servaddr, 0, sizeof(servaddr));

	// Filling server info:
	servaddr.sin_family = AF_INET; // Assigning the IPV4 to the Family Address
	servaddr.sin_port = htons(PORT); // Assigning the port number to the address structure
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	int serverSize;
	socklen_t len;

	for (;;) {
		fgets(buffer, MAXLINE, stdin);
		sendto(sockfd, (const char* )buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr*)&servaddr, sizeof(servaddr));

		printf("Message Sent\n");

		len = sizeof(servaddr);
		serverSize = recvfrom(sockfd, (char *)buffer, MAXLINE, 0, (struct sockaddr *)&servaddr, &len);

		buffer[serverSize] = '\0';
		printf("Server: %s\n", buffer);

		if (strcmp(buffer, "exit") == 0) {
    			break;
		}
		
		

	}
	close(sockfd);
	return 0;

}
