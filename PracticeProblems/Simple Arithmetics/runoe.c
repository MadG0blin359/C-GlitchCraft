#include <stdio.h>

int main() {
	int num;
	
	printf("Enter any number = ");
	scanf("%d", &num);
	
	num = num%2;
	
	if (num == 0)
		{
		printf("The entered number is even\n");
		}
	else
		{
		printf("The entered number is odd\n");
		}

	return 0;
}
