#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

// Shared variable
char dataset[1024] = "";
pthread_mutex_t lock;

void* writer() {
	char localData[1024], input[2];
	input[1] = '\0';
	printf("Writer trying to acquire lock\n");
	pthread_mutex_lock(&lock);

	printf("Writer acquired lock\n");
	
	printf("\nEnter data to shared variable:");
	for(int i = 0; i < 1024; i++) {
		scanf("%c", &input[0]);
		strcat(localData, input);
	
		if (input[0] == '\n')
			break;
	}

	strcat(dataset, localData); // Update the shared dataset
	printf("\nWriter writes the data in shared dataset\n");

	pthread_mutex_unlock(&lock);
	printf("Writer releases the lock\n==================================================================\n");

}

void* reader() {
	printf("\nReader trying to acquire lock\n");
	pthread_mutex_lock(&lock);

	printf("Reader acquired lock\n");
	printf("\nReader reads the shared dataset:\n%s\n", dataset);

	pthread_mutex_unlock(&lock);
	printf("Reader releases the lock\n");
}

int main() {
	pthread_t w_thread, r_thread;
	
	pthread_create(&w_thread, NULL, writer, NULL);
	pthread_create(&r_thread, NULL, reader, NULL);
	

	pthread_join(w_thread, NULL);	
	pthread_join(r_thread, NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
