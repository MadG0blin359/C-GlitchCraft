#include <stdio.h>
#include <math.h>

int mainMenu() {
	printf("Press 1 for Addition of any two integers\n");
	printf("Press 2 for calculating area of a circle\n");
	printf("Press 3 for calculating square root\n");
	printf("Press 4 to exit\n");
	printf("Press 5 for showing the menu again\n");	
}

int main(void) {
	int num;
	
	mainMenu();
	scanf("%d", &num);
	
	if(num==1) {
		int num1, num2;
		printf("Enter first integer = ");
		scanf("%d", &num1);
		
		printf("Enter second integer = ");
		scanf("%d", &num2);
		
		printf("Addition of %d & %d is  %d\n", num1, num2, num1+num2);
	}
	
	else if(num==2) {
		int r;
		float const pi = 3.14;
		
		printf("Enter the value of radius = ");
		scanf("%d", &r);
		
		printf("Area of the circle is %g\n", pi*r*r);
	}
	
	else if(num==3) {
		float sqNum;
		
		printf("Enter any integer to calculate its square root = ");
		scanf("%f", &sqNum);
		
		printf("Square root of %g is %g\n", sqNum, sqrt(sqNum));
	}
	
	else if(num==4) {
		printf("\'Program Terminated\'\n");
	}
	
	else if(num==5) {
		mainMenu();
	}
	
	else if(num>5 || num<=0) {
		printf("You have entered an invalid value\n");
	}
}
