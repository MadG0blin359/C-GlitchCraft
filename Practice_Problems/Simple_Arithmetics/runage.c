#include <stdio.h>

int main() {
	int age;
	
	// Prompt the user to enter their age
	printf("Enter your age = ");
	scanf("%d", &age);
	
	// Check if the age is between 0 and 12 (child)
	if (age>=0 && age<=12) {
		printf("You are a \'Child\'\n");
	}
	
	// Check if the age is between 13 and 19 (teenager)
	else if (age>=13 && age<=19) {
		printf("You are a \'Teenager\'\n");
	}
	
	// Check if the age is between 20 and 64 (adult)
	else if (age>=20 && age<=64) {
		printf("You are an \'Adult\'\n");
	}
	
	// Check if the age is greater than 65 (senior)
	else if (age>65) {
		printf("You are a \'Senior\'\n");
	}
	
	return 0;
}
