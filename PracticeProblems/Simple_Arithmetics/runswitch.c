#include <stdio.h>

int showMenu() {
	printf("Press 1 to display ICT Marks only\n");
	printf("Press 2 to display PF Marks only\n");
	printf("Press 3 to display OOP Marks only\n");
	printf("Press 4 to display the Marks of All Subjects\n");
}

int main() {
	int num, ICT = 78, PF = 69, OOP = 35;
	
	showMenu();
	scanf("%d", &num);
	
	switch(num) {
		case 1:
			printf("ICT Marks %d\n", ICT);
		break;
		
		case 2:
			printf("PF Marks %d\n", PF);
		break;
		
		case 3:
			printf("OOP Marks %d\n", OOP);
		break;
		
		case 4:
			printf("ICT Marks %d\nPF Marks %d\nOOP Marks %d\n", ICT, PF, OOP);
		break;
			
		default:
			printf("Invalid Input\n");
	}
	
	return 0;
}	
