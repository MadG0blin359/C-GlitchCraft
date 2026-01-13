#include <stdio.h>

int main() {
	char operator;
	double num1, num2, result;
	
	printf("\n-----------------------------------------------");
	printf("\n\tSimple Arithmetic Calculator\n");
	printf("-----------------------------------------------");
	
	printf("\n\nMathematical Operators:");
	printf("\n--For Addition (+)\n--For Subtraction (-)\n--For Multiplication (*)\n--For Division (/)\n");
	printf("\nSelect any Operator: ");
	scanf(" %c", &operator);
	
	if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
		printf("\nInvalid Input!\n");
	}
	
	else {
		switch(operator) {
		
		case '+':
			printf("\nEnter first number: ");
			scanf("%lg", &num1);
			
			printf("Enter second number: ");
			scanf("%lg", &num2);
	
			result = num1 + num2;
			printf("\nThe sum of %lg & %lg is %lg\n", num1, num2, result);
		break;
		
		case '-':
			printf("\nEnter first number: ");
			scanf("%lg", &num1);
			
			printf("Enter second number: ");
			scanf("%lg", &num2);
			
			result = num1 - num2;
			printf("\nThe difference of %lg & %lg is %lg\n", num1, num2, result);
		break;
		
		case '*':
			printf("\nEnter first number: ");
			scanf("%lg", &num1);
			
			printf("Enter second number: ");
			scanf("%lg", &num2);
			
			result = num1 * num2;
			printf("\nThe multiplication of %lg & %lg is %lg\n", num1, num2, result);
		break;
		
		case '/':
			printf("\nEnter first number: ");
			scanf("%lg", &num1);
			
			printf("Enter second number: ");
			scanf("%lg", &num2);
			
			result = num1 / num2;
			printf("\nThe division of %lg & %lg is %lg\n", num1, num2, result);
		break; 	
		
		default:
			printf("Invalid Input!\n");
		
		}
	}
	
	return 0;
}
