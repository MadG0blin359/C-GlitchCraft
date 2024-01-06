#include <stdio.h>

int main() {
	int max = 20+1;					// Maximum password character limit, Plus 1 for new line(\n) character
	int min = 8+1;					// Minimum password character limit, Plus 1 for new line(\n) character
	char saved_password[max];		// Array to store user created password
	char login_password[max];		// Array to store and check/compare with the previously created password 
	int character_count = 0;		// Count total characters
	int save_upper_count = 0;		// Count only uppercase characters
	int save_lower_count = 0;		// Count only lowercase characters
	int save_digit_count = 0;		// Count only integer characters
	int save_special_count = 0;		// Count only special characters
	int save_space_count = 0;		// Count only space characters
	int login_match_count = 0;		// Count matching characters in both arrays

	// Display the new password requirements to user
	printf("\nPassword Must Contain :\n8-20 characters\nAt least 1 uppercase\nAt least 1 lowercase\nAt least 1 digit\nAt least 1 special character\n");
	printf("\n--Create Password: ");	// Prompt the user to create password
	
	// Loop to store user input and take necessary measures
	for (int i = 0; i < max; i++) {
		scanf("%c", &saved_password[i]);
		character_count++;
		
		if (saved_password[i] == '\n') {
			character_count--;			// Not counting the new line character
			break;
		}

		else if (saved_password[i] >= 65 && saved_password[i] <= 90) {
			save_upper_count++;			// Counting uppercase characters
		}

		else if (saved_password[i] >= 97 && saved_password[i] <= 122) {
			save_lower_count++;			// Counting lowercase characters
		}

		else if (saved_password[i] >= 48 && saved_password[i] <= 57) {
			save_digit_count++;			// Counting integer characters
		}

		else if (saved_password[i] >= 33 && saved_password[i] <= 47) {
			save_special_count++;		// Counting special characters
		}

		else if (saved_password[i] == ' ') {
			save_space_count++;			// Counting space characters
		}
	}
	
	if (character_count > max) {
		printf("Character Limit Exceeded! Maximum character count must be 20\n");
	}
	
	else if (character_count < min) {
		printf("Minimum character count must be 8!\n");
	}

	else if (save_space_count != 0) {
		printf("\n\nPassword must contain any spaces\n");
	}

	else if (save_upper_count == 0) {
		printf("Password Must Contain : Atleast 1 uppercase character\n");
	}
	
	else if (save_lower_count == 0) {
		printf("Password Must Contain : Atleast 1 lowercase character\n");
	}

	else if (save_digit_count == 0) {
		printf("Password Must Contain : Atleast 1 digit\n");
	}

	else if (save_special_count == 0) {
		printf("Password Must Contain : Atleast 1 special Character\n");
	}

	else {
		printf("Password Saved Successfully!\n\n");
		
		for (int i = 3; i >= 0; i--) {
			printf("--Enter Password to login: ");
			
			for (int j = 0; j < max; j++) {
				scanf("%c", &login_password[j]);
				
				if (login_password[j] == '\n') {
					break;
				}

				// Check if the password matches
				if (saved_password[j] != '\0' && login_password[j] == saved_password[j]) {
					login_match_count++;		
				}
			}
			
			if (login_match_count == character_count) {
				printf("\nCorrect Password! You Hacked NASA\n");
				break;
			}
			
			else {
				if (i > 0) {
					printf("Wrong Password! You are Gay\n");
					printf("\nOnly %d tries left\n\n", i);
				}
				
				else if (i == 0) {
					printf("Account Locked!\n");
				}
			}
		}
	}

	return 0;
}
