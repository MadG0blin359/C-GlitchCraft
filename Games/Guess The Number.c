#include <stdio.h>	// Including Standard Input/Output Library
#include <time.h>	// Including Time Manipulation Library
#include <stdlib.h>	// Including Standard Library for General Utilities
#include <unistd.h>	// Including Standard Library for POSIX Operating System API

// Function to generate a random number between 1 and 100
int randomNumber() {
	
	// Seeds the random number generator with the current time	
	srand(time(NULL));
	return rand()%100+1;

}

int main() {
	int user_guess, choices, num;
	user_guess = 0; 
	choices = 100;
	num = 0;
	
	// Calling the functions and storing the random number in num variable
	num = randomNumber();
	
	printf("\n\t********Guess The Number********");

	printf("\n\nNumber of choices: %d\n", choices);
	
	do {
     		
     		// Prompting the user to enter a number
		printf("\nTake a Guess (1-100): ");
		scanf("%d",&user_guess);
     		
     		// If guesses are remaining
		if (choices > 0) {
	     		
	     		// Checking for input validity
	     		if (user_guess < 1 || user_guess > 100) {
	     			printf("\nInvalid Input!");
	     		}
	     
			else if (user_guess < num) {
				printf("\n--Your guess is \'Less\' than the random number\n");
				--choices;
				printf("--You are left with %d guesses\n", choices);
			}
		     
		     	else if (user_guess > num) {
				printf("\n--Your guess is \'Greater\' than the random number\n");
		    	 	--choices;
				printf("--You are left with %d guesses\n", choices);
		     }
	     
	     }
     		
     		// If no more guesses are available
		else {
			printf("\nBetter Luck Next Time!\n");
			break;
		}
	}
     	
     	// Loop continues until the user guesses the correct number
	while (user_guess != num);
	
	// If the user guessed the number within the available guesses
	if (choices != 0) {
		printf("\nCongratulations! You Guessed the Random Number \'%d\'\n", num);
	}
	
	return 0;
	
}
