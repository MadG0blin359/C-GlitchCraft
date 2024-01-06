#include <stdio.h>
int checkdiv();

int main() {
	int num;
	
	printf("Enter a number to check if it is divisible by 5 or 11 = ");
	scanf("%d", &num);
	
	checkdiv(num);
	
	return 0;
}

int checkdiv(int num) {
	
	
	if ((num%5==0) && (num%11==0)) {
		printf("The given number is divisible by 5 & 11 both\n");
	}
	
	else {
		printf("The given number is not divisible by 5 & 11 both\n");
	}
	
	return 0;
}
