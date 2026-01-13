// Server side implementation of UDP client-server model
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

int main() {
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "Hello from server";
	struct sockaddr_in servaddr, cliaddr;

	// Creating socket file descriptor

	//PARAMETERS FOR CREATING A SOCKET
	/*AF_INET: FamilY address which specifies the use of ipv4
	SOCK_DGRAM: UDP connection
	0: default protocols
	*/

	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		perror("Socket Creation Failed!\n");
		exit(EXIT_FAILURE);
	}

	/* servaddr.sin_family = 0;
	servaddr.sin_port = 0;
	servaddr.sin_addr.s_addr = 0;
	memset(servaddr.sin_zero, 0, sizeof(servaddr.sin_zero)); */
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));

	// Filling server info:
	servaddr.sin_family = AF_INET; // Assigning the IPV4 to the Family Address
	servaddr.sin_addr.s_addr = INADDR_ANY; // Assigning IP address from any available network interface on server to the address structure
	servaddr.sin_port = htons(PORT); // Assigning fixed and specific port number to the address structure

	// Bind the socket with server address
	if(bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
		perror("bind failed :(");
		exit(EXIT_FAILURE);
	}

	socklen_t len; // Datatype to represent the length of a socket address
	int clientSize; // var to store the size of clientaddress

	len = sizeof(cliaddr);

	/* Parameters for recvfrom();
	sockfd: file descriptor in which data is recieved
	buffer: A pointer to buffer where data will be stored
	MAXLINE: Maximum number of bytes to recieve in buff
	MSG_WAITALL: Flag to wait until the specified numbers of bytes(MAXLINE) have been recieved
	sockaddr: a pointer to a struct sockaddr that will be filled with the address of sending socket (clientaddr).
	len: pointer to socklen_t variable, having the size of clientaddr.
	*/

	//recieving the message from client

	for (;;) {
		clientSize = recvfrom(sockfd, (char*)buffer, MAXLINE, 0, (struct sockaddr *)&cliaddr, &len);

		// Terminating the string with \0
		buffer[clientSize] = '\0';
		printf("Client: %s\n",buffer);

		if (strcmp(buffer, "exit") == 0) {
    			break;
		}
		fgets(buffer, MAXLINE, stdin);
		sendto(sockfd, (const char* )buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr*)&cliaddr, sizeof(cliaddr));

		
	}
	return 0;
}

