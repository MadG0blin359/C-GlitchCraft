#include <stdio.h>

int main() {
	float principal, CI;
	float const rate = 12;
	
	printf("Enter the account balance = ");
	scanf("%g", &principal);
	
	CI = principal*( 1 + (rate/100)) - principal;
	
	printf("Compound Interest on %g is %g in 1 year", principal, CI);
	
	return 0;
}
