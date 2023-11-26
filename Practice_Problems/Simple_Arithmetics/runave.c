#include<stdio.h>

int main() {
	int distance;
	float litters;
	
	printf("Insert the distance travelled in km = ");
	scanf("%d", &distance);
	
	printf("Insert the fuel spent in litters = ");
	scanf("%f", &litters);
	
	float average = distance/litters;	
	printf("The bike\'s average consumption is %.2f (km/lt)\n", average);
	
	return 0; }
