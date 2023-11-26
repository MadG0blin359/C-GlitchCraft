#include <stdio.h>

int main() {
	char arr[5000];
	int size = 5000;
	int total_vowels = 0;
	int total_character = 0;
	int filtered_character = 0;
    
	printf("Write anything (5000 characters limit) - Filter out vowels:\n\n");
    
	for (int i = 0; i < size; i++) {
		scanf("%c", &arr[i]);
		
		if (arr[i] == '\n') {
			break;
		}
		
		total_character++;
        
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U') {
			total_vowels++;
			continue;
		}
        
		if (arr[i] == ' ' || arr[i] == '\n' || arr[i] == '\t') {
			printf(" ");
			filtered_character++;
        	}
        	
        	else {
			printf("%c", arr[i]);
			filtered_character++;
        	}
	
	}
    	
    	printf("\n\nTotal Vowels: %d", total_vowels);
    	printf("\nTotal Characters: %d", total_character);
	printf("\nFiltered characters: %d\n", filtered_character);

	return 0;

}
