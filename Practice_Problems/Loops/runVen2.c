#include <stdio.h>

int calculateBill(int drink_Number, int drink_Quantity, int coke_Available, int pepsi_Available, int sprite_Available, int sevenUP_Available, int coke_Price, int pepsi_Price, int sprite_Price, int sevenUP_Price) {
	
	int total_Bill;
	
	if (drink_Number==1) {
		
		if (drink_Quantity>0 && drink_Quantity<=coke_Available) {
			total_Bill = coke_Price*drink_Quantity;
		
			printf("\nYou have ordered %d Coke(s) for a total of $%d.\n\n", drink_Quantity, total_Bill);
		} 
		
		else if (drink_Quantity>coke_Available) {
			total_Bill = coke_Available*coke_Price;
			
			printf("\nYou have ordered %d Coke(s) for a total of $%d.\n\n", coke_Available, total_Bill);
		}
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

int checkAvailability(int drink_Number, int drink_Quantity, int coke_Available, int pepsi_Available, int sprite_Available, int sevenUP_Available) {
	
if (drink_Quantity>coke_Available || drink_Quantity>pepsi_Available || drink_Quantity>sprite_Available || drink_Quantity>sevenUP_Available) {
	
	if (drink_Number==1) {
	
		if (drink_Quantity>coke_Available) {
		printf("\nUnfortunately, we currently don't have the requested (%d) quantity, but the maximum available quantity has been ordered.\n", drink_Quantity);
		}
	}
	
	else if (drink_Number==2) {
	
		if (drink_Quantity>pepsi_Available) {
		printf("\nUnfortunately, we currently don't have the requested (%d) quantity, but the maximum available quantity has been ordered.\n", drink_Quantity);
		}
	} 
	
	else if (drink_Number==3) {
		
		if (drink_Quantity>sprite_Available) {
		printf("\nUnfortunately, we currently don't have the requested (%d) quantity, but the maximum available quantity has been ordered.\n", drink_Quantity);
		}
	} 
	
	else if (drink_Number==4) {
	
		if (drink_Quantity>sevenUP_Available) {
		printf("\nUnfortunately, we currently don't have the requested (%d) quantity of 7UP, but the maximum available quantity has been ordered.\n", drink_Quantity);
		}
	}
}
	
}

int updateStock(int drink_Quantity, int coke_Available, int pepsi_Available, int sprite_Available, int sevenUP_Available) {
	
	//if (drink_Number==1) {
		
	//}
	
}
void userInput() {
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
	
	checkAvailability(drink_Number, drink_Quantity,0,0,0,0);
	
	
	calculateBill(drink_Number, drink_Quantity,0,0,0,0,0,0,0,0);
	
	updateStock(drink_Quantity, 0, 0, 0, 0);
	
}

int main() {

	int coke_Available, pepsi_Available, sprite_Available, sevenUP_Available;
	coke_Available = 10;
	pepsi_Available = 15;
	sprite_Available = 15; 
	sevenUP_Available = 25; 
	
	int coke_Price=5, pepsi_Price=7, sprite_Price=7, sevenUP_Price=3;
	
	printf("\nWelcome to the Vending Machine!\n\n");
	
	printf("Available Drinks:\n\n");
	printf("1. Coke (Price: $%d, Available: %d)\n\n", coke_Price, coke_Available);
	printf("2. Pepsi (Prince: $%d, Available: %d)\n\n", pepsi_Price, pepsi_Available);
	printf("3. Sprite (Price: $%d, Available: %d)\n\n", sprite_Price, sprite_Available);
	printf("4. 7UP (Prince: $%d, Available: %d)\n\n", sevenUP_Price, sevenUP_Available);
	
	userInput();
	
	checkAvailability(0, 0, coke_Available, pepsi_Available, sprite_Available, sevenUP_Available);
	
	calculateBill(0,0, coke_Available, pepsi_Available, sprite_Available, sevenUP_Available, coke_Price, pepsi_Price, sprite_Price, sevenUP_Price);
	
	updateStock(0, coke_Available, pepsi_Available, sprite_Available, sevenUP_Available);
	
	
	
	return 0;
}
