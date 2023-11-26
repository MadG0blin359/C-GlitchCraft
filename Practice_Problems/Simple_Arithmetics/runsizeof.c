#include <stdio.h>
#include <stdbool.h>

int main() {
	
	printf("The size of short in bytes = %zu\n", sizeof(short));
	printf("The size of int in bytes = %zu\n", sizeof(int));
	printf("The size of long in bytes = %zu\n", sizeof(long));
	printf("The size of float in bytes = %zu\n", sizeof(float));
	printf("The size of double in bytes = %zu\n", sizeof(double));
	printf("The size of long double in bytes = %zu\n", sizeof(long double));
	printf("The size of character (char) in bytes = %zu\n", sizeof(char));
	printf("The size of boolean (bool) in bytes = %zu\n", sizeof(bool));
	
	return 0;
}
