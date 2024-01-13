#include <stdio.h>

int main() {
	// Arrays to store parts of the name separately
	char first_name[10], maiden_name[10], last_name[10];

	printf("Enter your first name: ");
	scanf("%s", first_name);
	
	printf("Enter your maiden name: ");
	scanf("%s", maiden_name);
	
	printf("Enter your last name: ");
	scanf("%s", last_name);
	
	// Display the full name 
	printf("Your full name is: %s %s %s\n", first_name, maiden_name, last_name);


	return 0;
}
