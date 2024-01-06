#include <stdio.h>

int main () {
	int m = 29, *ab;
	
	// Using operators &(address of) and *(value at address)
	printf("\nAddress of m : %p\n", &m);
	printf("Value of m : %d\n", m);
	
	ab = &m;
	printf("\nNow pointer ab is assigned with the address of m.\n");
	printf("Address of pointer ab : %p\n", &ab);
	printf("Content of pointer ab : %d\n", *ab);

	m = 34;
	printf("\nThe value assigned to m is %d now.\n", m);
	printf("Address of pointer ab : %p\n", &ab);
	printf("Content of pointer ab : %d\n", *ab);
	
	*ab = 7;
	printf("\nThe pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of m : %p\n", &m);
	printf("Value of m : %d\n", m);

	return 0;
}
