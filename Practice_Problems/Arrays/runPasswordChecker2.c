#include <stdio.h>

int main() {
	// Declare variables
	int const limit = 15;
	int size = 40;
	char new_password[size];
	char confirm_password[size];
	int character_count = 0;
	
	// Prompt the user to enter new password
	printf("\nPassword must contain:\n8-15 characters\nAt least 1 uppercase\n");
	printf("\n--Create New Password: ");
	// Read the password as a string
	scanf("%s", new_password);
	
	// Check character limit of the password
	if (sizeof(new_password) > limit || sizeof(new_password) < 8) {
		printf("Invalid Password!\n");
	}
	
	
	else {
		// prompt the user to enter the passward again for confirmation
		printf("\n--Confirm Password: ");
		scanf("%s", confirm_password);
			
			int correct = 0, upper = 0;
			// Loop to check the both the passwrods match
			for (int i = 0; i < sizeof(new_password); i++) {
				if (new_password[i] == confirm_password[i]) {
					correct++;
				
				// Condition to check uppercase
				if (new_password[i] >= 65 && new_password[i] <= 90) {
					upper++;
				}
						
				}
			}
			
			// Display invalid
			if (upper == 0) {
					printf("Invalid Password!\n");
					
			}
			
			// Display the message
			if (upper != 0 && correct == sizeof(new_password)) {
				printf("Password Changed Successfully!\n\n");
				
			}
			
			
			}

	return 0;
}
