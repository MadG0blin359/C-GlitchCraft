#include <stdio.h>

int main() {
	// Declaration of variables
	int choice, coffee, tea, coke, orange_juice;
	choice = 0;		// Store user input
	coffee = 0;		// Store Coffee votes
	tea = 0;		// Store Tea votes
	coke = 0;		// Store Coke votes
	orange_juice = 0;	// Store Juice votes
	
	// Display menu
	printf("\nChoose your favorite beverage from the following list:\n");
	printf("1. Coffee   2. Tea   3. Coke   4. Orange Juice\n\n");
	
	int i = 1;		// Variable to count persons
	do {
		// Prompt the user to choose favorite beverage
		printf("Please input the favorite beverage of person# %d | ", i);
		printf("Choose 1,2,3 or 4 from the above menu or -1 to exit the program\n");
		scanf("%d", &choice);
		
		i++;	// Count persons
		
		// Count votes to the favorite beverage
		switch (choice) {
		
			case 1:
				coffee++;
			break;
			
			case 2:
				tea++;
			break;
			
			case 3:
				coke++;
			break;
			
			case 4:
				orange_juice++;
			break;
			
			default:
				// Display invalid input
				if (choice != -1) {
					printf("\nInvalid Input!\n");
					i--;
				}
			break;
		
		}
	
	}
	
	while (choice != -1);
	
	// Display final result
	printf("\nBeverage\tNumber of Votes\n");
	printf("********************************\n");
	printf("Coffee\t\t\t%d\n", coffee);
	printf("Tea\t\t\t%d\n", tea);
	printf("Coke\t\t\t%d\n", coke);
	printf("Juice\t\t\t%d\n", orange_juice);

	return 0;
}
