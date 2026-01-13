#include <stdio.h>

int main() {
	FILE *fptr;
	
	fptr = fopen("write.txt", "a");
	
	fputs("\nIs it working\?", fptr);

	fclose(fptr);

	return 0;
}
