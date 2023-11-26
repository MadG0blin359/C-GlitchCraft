#include <stdio.h>

int availableDrinks(){
	int coke_Available, pepsi_Available, sprite_available, sevenUP_Available;
	coke_Available = 10;
	pepsi_Available = 15;
	sprite_available = 15; 
	sevenUP_Available = 25; 
	
	printf("Available Drinks:\n\n");
	printf("1. Coke (Price: $5, Available: %d)\n\n", coke_Available);
	printf("2. Pepsi (Prince: $7, Available: %d)\n\n", pepsi_Available);
	printf("3. Sprite (Price: $7, Available: %d)\n\n", sprite_available);
	printf("4. 7UP (Prince: $3, Available: %d)\n\n", sevenUP_Available);
	
	
}
int calculateBill(int drink_Number, int drink_Quantity) {
	int coke_Price=5, pepsi_Price=7, sprite_Price=7, sevenUP_Price=3;
	int total_Bill;
	
	if (drink_Number==1) {
		total_Bill = coke_Price*drink_Quantity;
		
		printf("\nYou have ordered %d Coke(s) for a total of $%d.\n\n", drink_Quantity, total_Bill);
	}
	
	else if (drink_Number==2) {
		total_Bill = pepsi_Price*drink_Quantity;
		
		printf("\nYou have ordered %d Pepsi(s) for a total of $%d.\n\n", drink_Quantity, total_Bill);
	}
	
	else if (drink_Number==3) {
		total_Bill = sprite_Price*drink_Quantity;
		
		printf("\nYou have ordered %d Sprite(s) for a total of $%d.\n\n", drink_Quantity, total_Bill);
	}
	
	else if (drink_Number==4) {
		total_Bill = sevenUP_Price*drink_Quantity;
		
		printf("\nYou have ordered %d 7UP(s) for a total of $%d.\n\n", drink_Quantity, total_Bill);
	}
	
}

int checkAvailability(int drink_Quantity, int coke_Available, int pepsi_Available, int sprite_available, int sevenUP_Available) {
	
	if (coke_Available<drink_Quantity) {
		printf("Unfortunately, we currently don't have the requested (%d) quantity, but the maximum available (%d) quantity has been ordered.", drink_Quantity, coke_Available);
	} 
}

int updateStock();
int userInput() {
	int drink_Number, drink_Quantity;
	
	printf("Enter the drink number you want to purchase (1-4): ");
	scanf("%d", &drink_Number);
	
	if (drink_Number<=0 || drink_Number>4) {
		printf("\nInvalid Input.\n");
	}
	
	else {
		printf("\nEnter the quantity you want to buy: ");
		scanf("%d", &drink_Quantity);
	}
	
	calculateBill(drink_Number, drink_Quantity);
	
}

int main() {
	
	printf("\nWelcome to the Vending Machine!\n\n");
	availableDrinks();
	
	userInput();
	
	
	
	
	
	
	return 0;
}
