#include<stdio.h>
//area of a circle
int main() {
	float radius, area;
	printf("Enter the value of radius \n");
	scanf("%f", &radius);

	const float pi = 3.14;
	printf("Area of the circle is %f \n", area = pi*radius*radius);
	return 0; }
