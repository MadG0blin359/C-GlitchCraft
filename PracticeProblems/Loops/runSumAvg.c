#include <stdio.h>

long main(void) {
	double num, sum = 0;
	long range = 0;

	printf("\t\t\t------Calculate Sum & Average------\n");
	printf("Enter the number of terms you want to insert in order to calculate their sum & average: ");
	scanf("%ld", &range);
	
	if (range >= 1) {
	
		for (int i = 1; i <= range; i++) {

			printf("Enter number - %d: ",i);
			scanf("%lg", &num);

			sum += num;
		}
		
		printf("The sum is \'%lg\'\n", sum);
		
		double avg;
		avg = sum/range;
		
		printf("The Average is \'%lg\'\n", avg);

	}

	else {
		printf("Invalid Input!\n");
	}
}
