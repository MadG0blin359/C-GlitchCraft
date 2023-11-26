#include <stdio.h>

int main () {
	int sum = 0, odd = 1;
	
	for (int i = 1; i <= 100; i++) {
		
		sum += odd;	
		odd += 2;
		
		printf("%d ", sum);
	}


	return 0;
}
