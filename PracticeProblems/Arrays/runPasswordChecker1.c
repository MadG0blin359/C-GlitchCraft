#include <stdio.h>

int main() {
	int max = 20+1;					// Maximum password character limit, Plus 1 for new line(\n) character
	int min = 8+1;					// Minimum password character limit, Plus 1 for new line(\n) character
	char new_password[max];			// Array to store user created password
	char confirm_password[max];		// Array to store and check/compare with the previously created password 
	int character_count = 0;		// Count total characters
	int character_match = 0;		// Count matching characters in both arrays
	
	// Prompt the user to enter new password
	printf("\nPassword Must Contain:\n8-15 characters\n");
	printf("\n--Create New Password: ");
	
	// Loop to store user input for new password
	for (int i = 0; i < max; i++) {
		scanf("%c", &new_password[i]);
		character_count++;

		if (new_password[i] == '\n') {
			character_count--;			// Not counting the new line character
			break;
		}
	}
	
	// Check character limit of the password
	if (character_count > max || character_count < min) {
		printf("Invalid Password!\n");
	}
	
	else {
		do {
			// Reset the counter for iteration
			character_match = 0;

			// prompt the user to enter the passward again for confirmation
			printf("\n--Confirm Password: ");
			
			// Loop to store user input for confirmation password
			for (int i = 0; i < max; i++) {
				scanf("%c", &confirm_password[i]);

				if (confirm_password[i] == '\n') {
					break;
				}

				// Check if both the passwords match
				if (new_password[i] != '\0' && confirm_password[i] == new_password[i]) {
					character_match++;
				}
			}
			
			// Display the message
			if (character_match == character_count) {
				printf("Password Changed Successfully!\n\n");
			}

			else {
				printf("Password Doesn't Match!\n");
			}
				
		}

		while (character_match != character_count);
	}

	return 0;
}
