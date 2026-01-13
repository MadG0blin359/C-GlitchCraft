#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
	int server_fd, optval;
	struct sockaddr_in server_address;
	int server_addrlen = sizeof(server_address);
	char buffer[BUFFER_SIZE];

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == 0) {
		perror("Socket Failed!");
		exit(EXIT_FAILURE);	
	}

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(PORT);
	
	optval = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == 0) {
		printf("Bind Successfull!\n");
	} else {
		perror("Bind Failed!\n");
		exit(EXIT_FAILURE);	
	}

	while(1) {
		sleep(1);
	}

	
	close(server_fd);

	return 0;
}


