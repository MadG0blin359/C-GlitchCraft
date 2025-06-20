#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int ret_id, fd;

	if ((ret_id = mkfifo("fifo1", 0666)) < 0) {
		printf("Named Pipe Failed!\n");		
		return 1;
	}
	
	printf("Named Pipe Created!\n");

	return 0;
}
