#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO1 "pipe1"
#define FIFO2 "pipe2"

int main() {
	int fd;
	pid_t child1, child2;
	
	if (mkfifo(FIFO1, 0666) == -1 || mkfifo(FIFO2, 0666) == -1) {
		perror("mkfifo failed!");
		exit(1);
	}

	if ((child1 = fork()) == -1) {
		perror("First Child: Fork Failed!");
		exit(1);
	}

	else if (child1 == 0) {
		int n;
		char buffer[100];
		
		if ((fd = open(FIFO1, O_RDONLY)) == -1) {
			perror("First Child: Cannot open FIFO1 For Reading!");
			exit(1);
		}
		
		n = read(fd, buffer, sizeof(buffer));
		close(fd);

		int numbers[n], count = -1;
		
		// Convert char into int and square them
		printf("Squared numbers: ");
		for (int i = 0; i < n; i++) {
			if (buffer[i] != ' ') {
				count++;
				numbers[count] = buffer[i] - '0';
				numbers[count] *= numbers[count];
				printf("%d ", numbers[count]);
			}
		}
		printf("\n");
		
		if ((fd = open(FIFO2, O_WRONLY)) == -1) {
			perror("First Child: Cannot open FIFO2 For Writing!");
			exit(1);
		}
		
		write(fd, numbers, sizeof(int) * (count + 1));
		close(fd);
		
		exit(0);
	}
	
	if ((child2 = fork()) == -1) {
		perror("Second Child: Fork Failed!");
		exit(1);
	}

	else if (child2 == 0) {
		int numbers[10], count = 0, sum = 0;
		
		if ((fd = open(FIFO2, O_RDONLY)) == -1) {
			perror("Second Child: Cannot open FIFO2 For Reading!");
			exit(1);
		}
		
		count = read(fd, numbers, sizeof(numbers));
		close(fd);
		
		count /= sizeof(int); // Convert to size of numbers
		
		// Compute sum of squares
		for (int i = 0; i < count; i++) {
			sum += numbers[i];
		}
		
		if ((fd = open(FIFO2, O_WRONLY)) == -1) {
			perror("Second Child: Cannot open FIFO2 For Writing!");
			exit(1);
		}
		
		write(fd, &sum, sizeof(sum));
		close(fd);
        	
		exit(0);
	}
	
	int sum = 0;
	char input[] = "1 2 3 4 5";
	
	if ((fd = open(FIFO1, O_WRONLY)) == -1) {
            perror("Parent: Cannot open FIFO1 For Writing!");
            exit(1);
        }
	
	write(fd, input, sizeof(input) - 1);	// ignore '\0'
	close(fd);
	
	wait(NULL);		// wait for first child
	
	// Read sum result from FIFO2
	if ((fd = open(FIFO2, O_RDONLY)) == -1) {
		perror("Parent: Cannot open FIFO2 For Reading!");
		exit(1);
	}
	
	read(fd, &sum, sizeof(sum));
	close(fd);

	wait(NULL);		// wait for second child

	printf("Sum of squared numbers: %d\n", sum);

	// Cleanup
	unlink(FIFO1);
	unlink(FIFO2);
	
	return 0;
}
