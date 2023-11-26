#include <stdio.h>

int main() {
	float C, F;
	
	printf("The temperature input = ");
	scanf("%f", &C);
	
	F = (9.0/5.0)*C+32;
	
	printf("Temperature output = %g\n", F);
	return 0;
}
	
