#include<stdio.h>
int main() {
	int a=5, b=15, resulta, resultb;	// Declare & Define 4 integer variables
	
	printf("Before swapping a = %d & b = %d\n", a, b);	// Display the values before swapping them
	
	// Swap the values by multiplying them with 0 and then adding aother variable
	resulta=(a*0)+b;
	resultb=(b*0)+a;
	printf("After swapping a = %d & b = %d\n", resulta, resultb);	// Display the swapped values
	return 0;	// Return 0 to indicate successful program execution
}
