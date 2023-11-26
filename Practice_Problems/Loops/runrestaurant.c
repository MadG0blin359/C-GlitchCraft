#include <stdio.h>

long displayMenu() {
	double Burger, Pizza, Salad, Pasta, Soda;
	Burger = 5.99; 
	Pizza = 7.99;
	Salad = 4.49;
	Pasta = 8.99;
	Soda = 1.99;

	printf("\n\tWelcome to Our Restaurant!\n");
	printf("Menu:\n");
	printf("1. Burger - $%lg\n", Burger);
	printf("2. Pizza - $%lg\n", Pizza);
	printf("3. Salad - $%lg\n", Salad);
	printf("4. Pasta - $%lg\n", Pasta);
	printf("5. Soda - $%lg\n", Soda);
	
	int choice, quantity;
	printf("\nEnter the item number you want to order: ");
	scanf("%d", &choice);
	
	printf("Enter the quantity: ");
	scanf("%d", &quantity);
	
	printf("\nItem added to your order.\n");

	calculateBill(Burger, Pizza, Salad, Pasta, Soda, choice, quantity);
}

long calculateBill(double Burger, double Pizza, double Salad, double Pasta, double Soda, int) {
	
	

}

int main() {
	
	displayMenu();
	
	char reOrder;
	printf("Do you want to order more items? (Y/N): ");
	scanf(" %c", &reOrder);

	if (reOrder == 'Y') {
		displayMenu();
	
	}

	return 0;
}
