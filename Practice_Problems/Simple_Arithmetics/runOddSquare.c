#include <stdio.h>

int main() {
	int count;
	
	printf("Enter any integer to calculate sqare of all Odd integers till that = ");
	scanf("%d", &count);
	
	for (int i=1; i<=count; i++) {
		
		if (i %2!=0) {
			printf("\nSqaure of Odd integer %d is \'%d\'\n", i, i*i);
		}
	}

	return 0;
}
