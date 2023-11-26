#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// Function to generate a random number between 1 and 6
int randomNumber() {

	sleep(1);
	srand(time(NULL));
	return rand()%6+1;

}

int main() {
	char name1[15], name2[15];
	
	printf("\n\tWelcome to the Dice Game!\n\n");
	
	printf("Player 1: Please Enter Your Name: ");
	scanf("%s", name1);
	
	printf("Player 2: Please Enter Your Name: ");
	scanf("%s", name2);
	
	int randNum[6];
	int dice = 0, sum1 = 0, sum2 = 0;
	for (int i = 0; i < 6; i++) {
		
		if (i == 0)
			printf("\nRolling the dice for %s...\n", name1);
		
		
		if (i >= 0 && i < 3) {
			randNum[i] = randomNumber();
			printf("--Dice %d: %d\n", ++dice, randNum[i]);
			sum1 += randNum[i];
		}
		
		if (dice == 3) {
			printf("\n");
			dice = 0;
			printf("Rolling the dice for %s...\n", name2);
		}
			
		if (i >= 3 && i < 6) {
			randNum[i] = randomNumber();
			printf("--Dice %d: %d\n", ++dice, randNum[i]);
			sum2 += randNum[i];
		}
		
		if (i == 5) {
			printf("\nCalculating the total scores...\n\n");
			
			// Resetting score if 3 sixes or total equals 18
			if (sum1 == 18) {
				sum1 = 0;
			}
			
			// Resetting score if 3 sixes or total equals 18
			if (sum2 == 18) {
				sum2 = 0;
			}
			
			printf("Total score for %s: %d\n", name1, sum1);
			printf("Total score for %s: %d\n", name2, sum2);
			
			// Determine the winner
			if (sum1 != sum2) {
				
				if (sum1 > sum2) {
					printf("\nAnd the winner is... %s! Congratulations!\n", name1);
				}
				
				else {
					printf("\nAnd the winner is... %s! Congratulations!\n", name2);
				}
			}
			
			// In case of a draw, compare individual dice values
			if (sum1 == sum2) {
				
				printf("\n\'It's a Draw!\'\n");
				
				// Compare dice values of both players
				for (int i = 0; i < 3; i++) {
					
					dice = i + 1;
					
					// Dice Value (Player 1) == Dice Value (Player 2)
					if (randNum[i] == randNum[i+3]) {
						printf("\nEvaluating Dice %d of both players...", dice);
						printf("\nIt's a Draw! Again");
						continue;
					}
					
					else if (randNum[i] > randNum[i+3]) {
						printf("\nEvaluating Dice %d of both players...", dice);
						printf("\nAnd the winner is... %s! Congratulations!\n", name1);
						break;
					}
					
					else if (randNum[i] < randNum[i+3]) {
						printf("\nEvaluating Dice %d of both players...", dice);
						printf("\nAnd the winner is... %s! Congratulations!\n", name2);
						break;
					}
				}
			}	
	
		}
		
	}
	return 0;
}
