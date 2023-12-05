#include<stdio.h>

int main() {
	char letter1 = 97;		// Lowercase Letter
	char letter2 = 'A';		// Uppercase Letter
	
	// Variable to store User Input
	int user = 0;
	
	printf("\n\t-----Change The Letters Using ASCII Values-----\n\n");
	//Display the lowercase letter with its ascii value
	printf("--Letter 1 is: %c\n--ASCII Value is: %d\n", letter1, letter1);
	
	// Loop to keep prompting the user until the input is valid
	do {
		// Prompt the user to enter an integer
		printf("\nAdd an integer to change it (1-25): ");
	    scanf("%d", &user);
        if (user < 1 || user > 25) {
            printf("-----Invalid Input!-----\n");
        }
	}
	
	while (user < 1 || user > 25);
	
	// Display the updated letter
	printf("--Letter 1 is: %c\n--ASCII Value is: %d\n\n", letter1 + user, letter1 + user);
	
	printf("\n");
	
	//Display the uppercase letter with its ascii value
	printf("--Letter 2 is: %c\n--ASCII Value is: %d\n", letter2, letter2);
	
	// Loop to keep prompting the user until the input is valid
	do {
		// Prompt the user to enter an integer
		printf("\nAdd an integer to change it (1-25): ");
	    scanf("%d", &user);
        if (user < 1 || user > 25) {
            printf("-----Invalid Input!-----\n");
        }
	}
	
	while (user < 1 || user > 25);
	
	// Display the updated letter
	printf("--Letter 1 is: %c\n--ASCII Value is: %d\n", letter2 + user, letter2 + user);
	
	return 0; 
    
}
