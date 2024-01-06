#include <stdio.h>

int main() {
	int m = 300;    
	float fx = 300.600006;                                                                                              
 	char cht = 'z';
	
	printf("\nPointers : Demonstrating the use of & and * operators :\n");
	printf("-------------------------------------------------------\n");
	printf("m : %d\n", m);				// Print the value of m
	printf("fx : %f\n", fx);			// Print the value of fx
	printf("cht : %c\n", cht);			// Print the value of cht
	
	printf("\nUsing & operator :\n");
	printf("------------------\n");
	printf("address of m : %p\n", &m);		// Print the address of m
	printf("address of fx : %p\n", &fx);		// Print the address of fx
	printf("address of cht : %p\n", &cht);		// Print the address of cht
	
	int *pt1;	// Declare an integer pointer pt1
	float *pt2;	// Declare a float pointer pt2
	char *pt3;	// Declare a char pointer pt3
	
	pt1 = &m;	// Assign the address of m to pointer pt1
	pt2 = &fx;	// Assign the address of fx to pointer pt2
	pt3 = &cht;	// Assign the address of cht to pointer pt3
	
	printf("\nUsing & and * operators :\n");
	printf("-------------------------\n");
	printf("Value at address of m = %d\n", *(&m));		// Print the value at the address of m
	printf("Value at address of fx = %f\n", *(&fx));	// Print the value at the address of fx
	printf("Value at address of cht = %c\n", *(&cht));	// Print the value at the address of cht
	
	printf("\nUsing only pointer variable :\n");
	printf("-----------------------------\n");
	printf("address of m = %p\n", pt1);			// Print the address stored in pt1
	printf("address of fx = %p\n", pt2);			// Print the address stored in pt2
	printf("address of cht = %p\n", pt3);			// Print the address stored in pt3
	
	printf("\nUsing only pointer operator :\n");
	printf("-----------------------------\n");
	printf("Value at address of m = %d\n", *pt1);		// Print the value pointed by pt1
	printf("Value at address of fx = %f\n", *pt2);		// Print the value pointed by pt2
	printf("Value at address of cht = %c\n", *pt3);		// Print the value pointed by pt3

	return 0;
}
