#include <stdio.h>

int main() {
	int size = 5000;
	char arr[size];
	int total_vowels = 0;
	int total_character = 0;
	int filtered_character = 0;
    
	printf("Write anything (5000 characters limit) - Filter out vowels:\n\n");
    
	// Loop to take user input while simultaneously checking for multiple if conditions 
	for (int i = 0; i < size; i++) {
		scanf("%c", &arr[i]);
		
		// If enter key is pressed, break the loop
		if (arr[i] == '\n') {
			break;
		}
		
		total_character++;
        
		// Check for vowels, both uppercase and lowercase
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U') {
			total_vowels++;
			continue;
		}
        
		// If and Else conditions to count remaining characters  
		if (arr[i] == ' ' || arr[i] == '\t') {
			printf(" ");
			filtered_character++;
        }
        	
		else {
			printf("%c", arr[i]);
			filtered_character++;
		}
	
	}
    
	// Display the following calculated metrics
    printf("\n\nTotal Vowels: %d", total_vowels);
    printf("\nTotal Characters: %d", total_character);
	printf("\nFiltered characters: %d\n", filtered_character);

	return 0;

}
