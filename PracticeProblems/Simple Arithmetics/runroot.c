#include<stdio.h>


float sqrt_custom(float num) {

float x0= num/2;
float x1= (x0 + num / x0) /2;
float x2= (x1 + num / x1) /2;
float x3= (x2 + num / x2) /2;
float x4= (x3 + num / x3) /2;
float x5= (x4 + num / x4) /2;
return x4;
}


int main() {

	int x1,y1,x2,y2;
	
	printf("Enter a value for x1 \n"); 
	scanf("%i", &x1);
	
	printf("Enter a value for x2 \n"); 
	scanf("%i", &x2);
	
	printf("Enter a value for y1 \n");
	scanf("%i", &y1);
	
	printf("Enter a value for y2 \n");
	scanf("%i", &y2);
	
	float formula= (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
	
	float distance= sqrt_custom(formula);
	
	printf("Distance is %g\n", distance);
	
	return 0;
}
