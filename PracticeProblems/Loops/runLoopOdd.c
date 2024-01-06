#include <stdio.h>

long main() {
	int sum = 0;
	
	for (int odd = 1; odd <= 100; odd += 2) {
		sum += odd;
	}
	
	printf("%d\n", sum);

	return 0;
}
