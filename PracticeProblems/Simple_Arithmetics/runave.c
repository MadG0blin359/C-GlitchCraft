#include<stdio.h>

int main() {
	// Variables to store user input
	int distance;
	float litters;
	
	// Prompt the user to enter distance travelled
	printf("Insert the distance travelled in km = ");
	scanf("%d", &distance);		// Read & store the user input
	
	// Prompt the user to enter fuel in litters
	printf("Insert the fuel spent in litters = ");
	scanf("%f", &litters);		// Read & store the user input
	
	// Formula to calculate bike's average fuel consumption
	float average = distance/litters;	
	// Display the calculated result
	printf("The bike\'s average consumption is %.2f (km/lt)\n", average);
	
	return 0; 
	
}
