#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

// Shared resources
int counter = 0;
int turn = -1;
bool flag[2] = {false, false};

void* thread0() {
	int local = 0;
	do {
		// Entry Section
		flag[0] = true;
		turn = 1;
		while (flag[1] && turn == 1);
		
		// Critical Section
		counter++;
		
		// Exit Section
		local++;
		flag[0] = false;
		
		// Remainder Section
		if (local == 10)
			break;
	
	} while (true);
}

void* thread1() {
	int local = 0;
	do {
		// Entry Section
		flag[1] = true;
		turn = 0;
		while (flag[0] && turn == 0);
		
		// Critical Section
		counter++;
		
		// Exit Section
		local++;
		flag[1] = false;
		
		// Remainder Section
		if (local == 10)
			break;
	
	} while (true);
}

int main() {
	pthread_t tid0, tid1;
	
	pthread_create(&tid0, NULL, thread0, NULL);
	pthread_create(&tid1, NULL, thread1, NULL);

	pthread_join(tid0, NULL);
	pthread_join(tid1, NULL);
	
	printf("Updated Counter: %d\n", counter);

	return 0;
}
