#include <stdio.h>

// Function to calculate the total bill for the selected coffee
double calculateBill(double quantity, int choice, double esp_price, double latt_price, double capp_price, double moch_price, double ameri_price) {

	double bill;
	// Start a switch statement to select the coffee type based on the 'choice' variable
	switch (choice) { 	
		
	case 1: 
		// Calculate the bill for Espresso and assign it to the 'bill' variable
		bill = quantity*esp_price;
	break;
	
	case 2:
		// Calculate the bill for Latte and assign it to the 'bill' variable
		bill = quantity*latt_price;
	break;
	
	case 3:
		// Calculate the bill for Cappuccino and assign it to the 'bill' variable
		bill = quantity*capp_price;
	break;
	
	case 4:
		// Calculate the bill for Mocha and assign it to the 'bill' variable
		bill = quantity*moch_price;
	break;
	
	case 5:
		// Calculate the bill for Americano and assign it to the 'bill' variable
		bill = quantity*ameri_price;
	break;
	
	default:
		// Handle the case where 'choice' is not in the range 1-5
		printf("\n\tInvalid Input!\n\n");
	break;
	}
	// Return the calculated 'bill'
	return bill;
}

int main() {
	// Prices for different types of coffee
	double esp_price = 2.50, latt_price = 3.00, capp_price = 3.50, moch_price = 4.00, ameri_price = 2.25;
	int choice, quantity;
	
	// Display a welcome message and the prices of different coffee types
	printf("\n\tWelcome to the Coffee Shop!\n");
		printf("Please select your coffee by entering the number: ");
		printf("\n1. Espresso 	- $%.2lg\n", esp_price);
		printf("2. Latte 	- $%.2lg\n", latt_price);
		printf("3. Cappuccino 	- $%.2lg\n", capp_price);
		printf("4. Macho 	- $%.2lg\n", moch_price);
		printf("5. Americano 	- $%.2lg\n", ameri_price);	
		
		// Prompt the user to enter their coffee choice and quantity
		printf("\n--Enter your choice (1-5): ");
		scanf("%d", &choice);
		
		printf("--Enter the quantity: ");
		scanf("%d", &quantity);
	
	// Start a switch statement to handle different coffee choices
	switch (choice) {
		
		double bill;
				
	case 1: 
		// Calculate the bill for Espresso and assign it to the 'bill' variable
		bill = calculateBill(quantity, choice, esp_price, latt_price, capp_price, moch_price, ameri_price);
		// Display the selected coffee and its calculated bill
		printf("\n--You have selected %d Espresso. That will be $%.2lf, please.\n--Enjoy your coffee!\n\n", quantity, bill);
	break;
	
	case 2: 
		// Calculate the bill for Latte and assign it to the 'bill' variable
		bill = calculateBill(quantity, choice, esp_price, latt_price, capp_price, moch_price, ameri_price);
		// Display the selected coffee and its calculated bill
		printf("\n--You have selected %d Latte. That will be $%.2lf, please.\n--Enjoy your coffee!\n\n", quantity, bill);
	break;
	
	case 3: 
		// Calculate the bill for Cappuccino and assign it to the 'bill' variable
		bill = calculateBill(quantity, choice, esp_price, latt_price, capp_price, moch_price, ameri_price);
		// Display the selected coffee and its calculated bill
		printf("\n--You have selected %d Cappuccino. That will be $%.2lf, please.\n--Enjoy your coffee!\n\n", quantity, bill);
	break;
	
	case 4: 
		// Calculate the bill for Mocha and assign it to the 'bill' variable
		bill = calculateBill(quantity, choice, esp_price, latt_price, capp_price, moch_price, ameri_price);
		// Display the selected coffee and its calculated bill
		printf("\n--You have selected %d Mocha. That will be $%.2lf, please.\n--Enjoy your coffee!\n\n", quantity, bill);
	break;
	
	case 5: 
		// Calculate the bill for Americano and assign it to the 'bill' variable
		bill = calculateBill(quantity, choice, esp_price, latt_price, capp_price, moch_price, ameri_price);
		// Display the selected coffee and its calculated bill
		printf("\n--You have selected %d Americano. That will be $%.2lf, please.\n--Enjoy your coffee!\n\n", quantity, bill);
	break;
	
	default:
		// Handle the case where 'choice' is not in the range 1-5
		printf("\n\tInvalid Input!\n\n");
	break;
	}
	// Return 0 to indicate successful program execution
	return 0;
}
