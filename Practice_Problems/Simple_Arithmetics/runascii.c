#include<stdio.h>

int main() {
	char letter1=97;	// Initializing 'letter1' with ASCII value of 'a'
	char letter2='d';	// Initializing 'letter2' with character 'd'
	
	letter1=letter1+23;		// Adding 23 to ASCII value of 'a' to make it letter x
	letter2=letter2+22;		// Adding 22 to ASCII value of 'd' to make it letter z
	
	// Printing the modified characters
	printf("letter1 is %c & letter2 %c \n", letter1, letter2);

	// Return 0 to indicate successful program execution
	return 0; 
	
	}
