#include <stdio.h>

int main() {
	int const limit = 15;
	int size = 40;
	char saved_password[size];
	char login_password[size];
	int character_count = 0;
	
	printf("\nPassword must contain:\n8-20 characters\nAt least 1 uppercase\nAt least 1 lowercase\nAt least 1 digit\nAt least 1 special character\n");
	printf("\n--Create Password: ");
	
	for (int i = 0; i < size; i++) {
		scanf("%c", &saved_password[i]);
		character_count++;
		
		if (saved_password[i] == '\n') {
			break;
		}
	}
	
	if (character_count > limit) {
		printf("Character Limit Exceeded!\n");
	}
	
	else if (character_count < 8) {
		printf("Minimum character count must be 8!\n");
	}
	
	else {
		printf("Password Saved Successfully!\n\n");
		
		for (int i = 3; i >= 0; i--) {
			printf("--Enter Password to login: ");
			
			for (int j = 0; j < size; j++) {
				scanf("%c", &login_password[j]);
				
				if (login_password[j] == '\n') {
					break;
				}
			}
			
			int correct, upper;
			correct = 0;
			upper = 0;
			
			for (int k = 0; k < character_count; k++) {
				// Check if the password matches
				if (login_password[k] == saved_password[k]) {
					correct++;		
				}
				
				// Condition to check uppercase
				if (saved_password[i] >= 65 && saved_password[i] <= 90) {
					upper++;
				}
			}
			
			if (correct == character_count && upper != 0) {
				printf("\nCorrect Password! You Hacked NASA\n");
				break;
			}
			
			else {
				if (i > 0) {
					printf("Wrong Password! You are Gay\n");
					printf("\nOnly %d tries left\n\n", i);
				}
				
				if (i == 0) {
					printf("Account Locked!\n");
				}
			}
		}
	}

	return 0;
}
