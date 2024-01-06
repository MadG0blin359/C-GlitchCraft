#include <stdio.h>

struct players {
	// Variables to store the player data
	float distance;
	int minute;
	int second;
};

void main() {
	struct players p1, p2;
	
	printf("\n\t\tWho Won?");
	printf("\n\t\t--------\n");
	
	// Prompt the user to enter each of the required data for both players to calculate the winner
	printf("\n--Enter the distance covered by Player 1 : ");
	scanf("%f", &p1.distance);

	printf("--Enter Minutes : ");
	scanf("%d", &p1.minute);
	
	printf("--Enter Seconds : ");
	scanf("%d", &p1.second);
	
	printf("\n--Enter the distance covered by Player 2 : ");
	scanf("%f", &p2.distance);

	printf("--Enter Minutes : ");
	scanf("%d", &p2.minute);
	
	printf("--Enter Seconds : ");
	scanf("%d", &p2.second);
	
	float time1, time2;
	
	// Calculate the time it took the players to finish the race
	time1 = (p1.minute*60 + p1.second) / p1.distance;
	time2 = (p2.minute*60 + p2.second) / p2.distance;
	
	printf("\nThe winner is...\n");
	
	// Determine the winner and display the final result
	if (time1 < time2) {
		printf("\n\tPlayer 1!\n--Distance : %g\n--Minutes  : %d\n--Second   : %d\n", p1.distance, p1.minute, p1.second);
	}
	
	else {
		printf("\n\tPlayer 2!\n--Distance : %g\n--Minutes  : %d\n--Second   : %d\n", p2.distance, p2.minute, p2.second);
	}

}
