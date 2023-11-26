#include <stdio.h>

void main() {
	long choice, term, cube;
	
	for (;;) {
		
		printf("\n------------------------------------------------------");
		
		printf("\n\n\t-----Cube Cube Cube-----\n");
		printf("1. Calculate Cube of a Specific Number\n2. Calculate Cubes of Numbers Upto an Integer\n3. Press 0 to Exit the Program\n");
		printf("Press (0-2): ");
		scanf("%ld", &choice);
		
		printf("\n------------------------------------------------------");
		
		if (choice == 0) {
			printf("\n\n\'Program Ended\'\n\n");
			break;
		}
		
		if (choice < 0 || choice > 2) {
			printf("\n\nInvalid Input!\n");
		}
		
		else {
			switch (choice) {
			
			case 1:
				printf("\n\n\t-----Calculating Cube Of a Number-----\n");
				printf("Enter the number to calculate the cube: ");
				scanf("%ld", &term);
			
				cube = term*term*term;
				printf("The cube of \'%ld\' is \'%ld\'\n", term, cube);
				break;
			
			case 2:
				printf("\n\t-----Calculating Cubes Upto an Integer-----\n");
				printf("Enter the term to calculate the cube upto it: ");
				scanf("%ld", &term);
				
				if (term > 0) {
				
					for (int i = 1; i <= term; i++) {
						
						cube = i*i*i;
						printf("\nNumber is: %d\nCube of %d is: %ld\n", i, i, cube);
					}	
				}
				
				else {
					printf("Invalid Input!\n");
				}
				break;
			}
		}
	}
}
