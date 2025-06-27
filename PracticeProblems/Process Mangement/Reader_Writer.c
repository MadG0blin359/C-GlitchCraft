#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

char dataset[] = 
"A mutex is a mutual exclusion lock: \n"
"1. To block the access of variables by other threads \n"
"2. Enforces exclusive access by a thread to a shared resource. \n"
"3. Can protect a “critical” section of memory. \n"
"Mutexes can be applied to threads in a single process and do not work between processes\n";

pthread_mutex_t lock;

void* writer() {
	char sharedData[1024], localData[1024];
	printf("Writer trying to acquire lock\n");
	pthread_mutex_lock(&lock);

	printf("Writer acquired lock\n");

	strcpy(sharedData, dataset); // Reads the shared dataset
	printf("Writer reads the original dataset:\n%s\n", sharedData);
	
	strcpy(localData, "\nModified by Writer!");
	strcat(dataset, localData); // Update the shared dataset
	printf("Writer updates the data in shared dataset\n");

	pthread_mutex_unlock(&lock);
	printf("Writer releases the lock\n");

}

void* reader() {
	printf("\nReader trying to acquire lock\n");
	pthread_mutex_lock(&lock);

	printf("Reader acquired lock\n");
	printf("Reader reads the shared dataset:\n%s\n", dataset);

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
