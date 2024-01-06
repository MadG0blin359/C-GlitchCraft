#include <stdio.h>

int main() {
	FILE *fptr;
	
	fptr = fopen("write.txt", "w");
	
	fputs("I dont know\nThis is good", fptr);
	
	fclose(fptr);


	return 0;
}
