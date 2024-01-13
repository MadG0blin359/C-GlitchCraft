#include <stdio.h>

int main() {
	int ascii = 65;
	char alpha;
	char *ptr;
	ptr = &alpha;

	// Displaying the purpose of the program
	printf("\nPointer : Print all the alphabets:");
	printf("\n----------------------------------\n");

	printf("The Alphabets are : \n");
	
	for (int i = 0; i < 26 ; i++) {
		*ptr = ascii + i;
		printf("%c ", alpha);
		
	}
	
	printf("\n\n");

	return 0;
}
