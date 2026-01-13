#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

int main() {
	int sock, optval;
	socklen_t optlen = sizeof(optval);

	sock = socket(AF_INET, SOCK_STREAM, 0);

	printf("Receive Buffer:\n");
	getsockopt(sock, SOL_SOCKET, SO_RCVBUF, &optval, &optlen);
	printf("Default receive buffer: %d\n", optval);
 
	// Larger buffers can improve throughput for high-bandwidth or high-latency connections.
	optval = 65536;	// 64 kilo bytes - For receive buffer only, kernel internally doubles this size because of overhead

	setsockopt(sock, SOL_SOCKET, SO_RCVBUF, &optval, sizeof(optval));

	getsockopt(sock, SOL_SOCKET, SO_RCVBUF, &optval, &optlen);
	printf("Updated receive buffer: %d\n", optval);

	printf("Send Buffer:\n");
	
	getsockopt(sock, SOL_SOCKET, SO_SNDBUF, &optval, &optlen);
	printf("Default send buffer: %d\n", optval);

	optval = 65536;	// 64 kilo bytes

	setsockopt(sock, SOL_SOCKET, SO_SNDBUF, &optval, sizeof(optval));
	printf("Updated send buffer: %d\n", optval);

	return 0;
}


