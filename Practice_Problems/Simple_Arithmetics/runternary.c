#include <stdio.h>

int main(void) {
	char input;
	
	printf("Enter any character = ");
	scanf("%c", &input);
	
	((input>=65 && input<=90) || (input>=97 && input<=122))? printf("The character %c is an Alphabet\n", input): printf("The character %c is not an Alphabet\n", input);
	
}
