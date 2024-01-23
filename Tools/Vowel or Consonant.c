#include <stdio.h>

int main() {
	char input;
	
	// Prompt the user to enter an alphabet
	printf("Enter any Alphabet = ");
	scanf("%c", &input);
	
	// Check if the input is a lowercase alphabet
	if (input>='a' && input<='z') {	
	
		// Check if the lowercase alphabet is a vowel
		if (input==97 || input==101 || input==105 || input==111 || input==117) {
		printf("The alphabet is a lowercase and a \'Vowel\'\n");
		}
		
		// If it's not a vowel, it's a consonant
		else {
		printf("The alphabet is a lowercase and a \'Consonant\'\n");
		}
	}
	
	// Check if the input is an uppercase alphabet
	else if (input>='A' && input<='Z') {
		
		// Check if the uppercase alphabet is a vowel
		if (input==65 || input==69 || input==73 || input==79 || input==85) {
		printf("The alphabet is a uppercase and a \'Vowel\'\n");
		}
		
		// If it's not a vowel, it's a consonant
		else {
		printf("The alphabet is a uppercase and a \'Consonant\'\n");
		}
	}
	
	// If the input is not a valid alphabet
	else if (input<'a' || input>'z' || input<'A' || input>'Z') {
		printf("Invalid input. Enter an Alphabet\n");
	}
	
	// Return 0 to indicate successful program execution
	return 0;
}
