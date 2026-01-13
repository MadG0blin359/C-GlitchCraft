#include <stdio.h>

int main() {
	int num;
	
	printf("-----------------------------");
	printf("\n\tA Hectic Week\n");
	printf("-----------------------------");
	printf("\n1. Sunday\n");
	printf("2. Monday\n");
	printf("3. Tuesday\n");
	printf("4. Wednesday\n");
	printf("5. Thursday\n");
	printf("6. Friday\n");
	printf("7. Saturday\n");
	printf("\nEnter a number (1-7): ");
	scanf("%d", &num);

	switch(num) {
	
	case 1: 
		printf("--Weekend\n");
	break;
	
	case 2: 
		printf("--Weekday\n");
	break;
	
	case 3: 
		printf("--Weekday\n");
	break;
	
	case 4: 
		printf("--Weekday\n");
	break;
	
	case 5: 
		printf("--Weekday\n");
	break;
	
	case 6: 
		printf("--Weekday\n");
	break;
	
	case 7: 
		printf("--Weekend\n");
	break;
	
	default: 
		printf("Invalid Input!\n");
	}

	return 0;
}
