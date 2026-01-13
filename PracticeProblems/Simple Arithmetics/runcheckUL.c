#include <stdio.h>

int main() {
	char alph;
	
	printf("Enter a character = ");
	scanf("%c", &alph);
	
	if(alph>=65 && alph<=90) {
		printf("The given character is a uppercase alphabet, converted to lowercase %c\n", alph+32);
			
	} 
	
	else if(alph>=97 && alph<=122) {
		printf("The given character is a lowercase alphabet, converted to uppercase %c\n", alph-32);
	}
	
	else {
		printf("you did not entered an alphabet\n");
	}
	return 0;	
}
	
