#include <stdio.h>

int main() {
	long num, sum = 0, natural = 1;
	
	printf("Enter any nth term of natural numbers to display their sum: ");
	scanf("%ld", &num);
	
	if (num > 0) {
		
		printf("The first %ld natural numbers are:\n", num);
		
		for (short i = 1; i <= num; i++) {
			sum += natural;	
			natural += 1;
			
			printf("%hi ", i);
			
		}
		
		printf("\nThe sum of natural numbers upto \'%ld\' terms is \'%ld\'\n", num, sum);
	}
	
	else {
		printf("Invalid Input!\n");
	}
	
	
	return 0;
}
