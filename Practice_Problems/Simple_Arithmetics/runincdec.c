#include<stdio.h>
int increment();
int decrement();

int main() {
	int num1, num2;
	printf("Enter the 1st number = ");
	scanf("%d", &num1);
	
	printf("Enter the 2nd number = ");
	scanf("%d", &num2);
	
	printf("%d + %d = %d\n", num1, num2, increment(num1, num2));
	printf("%d - %d = %d\n", num1, num2, decrement(num1, num2));
	
	return 0; }
	
int increment(int num1, int num2) {
	return num1 += num2; }
	
int decrement(int num1, int num2) {
	return num1 -= num2; }
