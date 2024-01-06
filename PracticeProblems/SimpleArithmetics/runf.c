#include<stdio.h>
int sum();
int sub();
int mul();
int div();
int mdiv();

int main() {
	int num1,num2;
	printf("Enter the first integer = ");
	scanf("%d", &num1);
	printf("Enter the second integer = ");
	scanf("%d", &num2);
	
	printf("\n%d + %d = %d\n", num1, num2, sum(num1, num2));
	printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
	printf("%d x %d = %d\n", num1, num2, mul(num1, num2));
	printf("%d / %d = %d\n", num1, num2, div(num1, num2));
	printf("Remainder %d / %d = %d\n", num1, num2, mdiv(num1, num2));
	
	return 0; }
	

int sum(int num1, int num2) {
	return num1+num2; }

int sub(int num1, int num2) {
	return num1-num2; }

int mul(int num1, int num2) {
	return num1*num2; }
	
int div(int num1, int num2) {
	return num1/num2; }
	
int mdiv(int num1, int num2) {
	return num1%num2; }
