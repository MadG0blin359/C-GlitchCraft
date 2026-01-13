#include <stdio.h>
int checkfriendly();

int main () {
	int num1 = 6, num2 = 28;
	
	checkfriendly(num1, num2);

return 0;
}

int checkfriendly(int num1, int num2) {
	int divisor1 = (1+2+3+6)/num1;
	int divisor2 = (1+2+4+7+14+28)/num2;
	
	if(divisor1 = divisor2) {
		printf("The pair 6 & 28 is friendly\n");
		}
		
		else {
		printf("The pair 6 & 28 is not friendly\n");
		}
}
