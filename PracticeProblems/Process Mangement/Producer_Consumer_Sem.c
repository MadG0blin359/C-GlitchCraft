#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 20

// Shared Resources
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

pthread_mutex_t mutex;
sem_t full;
sem_t empty;

void* produce_integer(void* arg) {
	int producer_id = *(int*)arg;
	
	while (1) {
		int item = rand() % 50;
		
		sem_wait(&empty);		// Sleep if no empty index until signaled by sem_post
		pthread_mutex_lock(&mutex);
		
		buffer[in] = item;
		printf("Producer %d Produced: %d\n", producer_id, buffer[in]);
		in = (in + 1) % BUFFER_SIZE;
		
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
		
		sleep(rand() % 3);
	}

}

void* consume_integer(void* arg) {
	int consumer_id = *(int*)arg;
	
	while (1) {
		sem_wait(&full);		// Sleep if no full index until signaled by sem_post
		pthread_mutex_lock(&mutex);
		
		int item = buffer[out];
		printf("Consumer %d Consumed: %d\n", consumer_id, item);
		out = (out + 1) % BUFFER_SIZE;
		
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	
		sleep(rand() % 3);
	}
}

int main(int argc, char* argv[]) {
	int producer_thread_count = atoi(argv[1]);
	int consumer_thread_count = atoi(argv[2]);
	pthread_t producer_id[producer_thread_count], consumer_id[consumer_thread_count];
	srand(time(NULL));
	
	printf("%d %d\n\n", producer_thread_count, consumer_thread_count);
	
	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	
	for (int i = 0; i < producer_thread_count; i++) {
		int *id = malloc(sizeof(int));
		*id = i;
		if (pthread_create(&producer_id[i], NULL, &produce_integer, id) != 0)
			perror("Failed to create producer thread!\n");
	}
	
	for (int j = 0; j < consumer_thread_count; j++) {
		int *id = malloc(sizeof(int));
		*id = j;
		if (pthread_create(&consumer_id[j], NULL, &consume_integer, id) != 0)
			perror("Failed to create consumer thread!\n");
	}
	
	for (int k = 0; k < producer_thread_count; k++) {
		if (pthread_join(producer_id[k], NULL) != 0)
			perror("Failed to join producer thread!\n");
	}
	
	for (int k = 0; k < consumer_thread_count; k++) {
		if (pthread_join(consumer_id[k], NULL) != 0)
			perror("Failed to join consumer thread!\n");
	}
	
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	
	return 0;
}
