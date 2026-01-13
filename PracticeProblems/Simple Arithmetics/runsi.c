#include <stdio.h>

int main() {
	float SI, principal, time;
	float const rate = 5;
	
	printf("Enter the account balance = ");
	scanf("%g", &principal);
	
	printf("Enter the number of years = ");
	scanf("%g", &time);
	
	SI = (principal*rate*time)/100;
	
	printf("Simple interest on \'%g\' is \'%g\' \nTotal = \'%g\'\n", principal, SI, SI+principal);
	
	return 0;
}
