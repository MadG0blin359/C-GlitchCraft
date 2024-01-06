#include <stdio.h>

int convertToNewLine(short num) {
	
	printf("hundred %hi\n", num/100);
	printf("ten %hi\n", (num/10)%10);
	printf("unit %hi\n", num%10);
}

int main() {
	short num;
	
	printf("Enter 3 digit = ");
	scanf("%hi", &num);
	
	if(num>99 && num<=999) {
		convertToNewLine(num);
	}
	
	else {
		printf("You have entered an invalid number\n");
	}
	return 0;
}
