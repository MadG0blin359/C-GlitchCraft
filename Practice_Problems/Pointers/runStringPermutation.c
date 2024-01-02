#include <stdio.h>

// Function to swap characters
void changePosition(char *ch1, char *ch2) {
	char tmp;
	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}

// Function to generate permutations of a string
void generatePermutations(char *str, int start_num, int end_num) {
	if (start_num == end_num) {
		printf("%s  ", str);
	}

	else {
		for (int i = start_num; i <= end_num; i++) {
			changePosition((str + start_num), (str + i)); 		// Swap characters at positions start and i
			generatePermutations(str, start_num + 1, end_num); 	// Recursively generate permutations for the rest of the string
			changePosition((str + start_num), (str + i)); 		// Restore the original string by swapping back
		}
	}


}

int main() {
	int size = 5;
	char str[size];
	
	printf("\n\tPointer : Generate permutations of a given string :");
	printf("\n\t---------------------------------------------------\n");
	
	printf("\nEnter any string (without spaces) : ");
	scanf("%s", str);

	int length = 0;

	for (int i = 0; i < sizeof(str); i++) {
		if (str[i] != '\0') {
			length++;
		}
		
		else {
			break;
		}
	}
	
	printf("\nThe permutations of the string are : \n");
	generatePermutations(str, 0, length - 1); // Call function to generate permutations
	printf("\n");
	
	return 0;
}
