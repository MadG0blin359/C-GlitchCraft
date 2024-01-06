#include <stdio.h>

// Function to calculate the parking bill based on vehicle type and number of days
long calculateBill(char vehicle_type, int days, int moto_cost, int car_cost, int bus_cost) {
	long bill;
	bill = 0;
	
	switch (vehicle_type) {
		case 'M':
		case 'm':
			bill = moto_cost * days;
			break;
		case 'C':
		case 'c':
			bill = car_cost * days;
			break;
		case 'B':
		case 'b':
			bill = bus_cost * days;
			break;
	}
	// Return the calculated bill
	return bill;
}

// Function to get user input for vehicle type and number of days
void getUserInput() {
	char vehicle_type;
	long days, moto_cost, car_cost, bus_cost;;
	moto_cost = 10;
	car_cost = 20;
	bus_cost = 30;
	
	printf("\nParking Area Menu:\n\n");
	printf("--M = Motorcycle: %ld Rs per day\n", moto_cost);
	printf("--C = Car: %ld Rs per day\n", car_cost);
	printf("--B = Bus: %ld Rs per day\n", bus_cost);
	printf("Please Choose Your Vehicle Type (M/C/B): ");
	scanf(" %c", &vehicle_type);
	
	// Check if the vehicle type is valid
	if ((vehicle_type != 'M' && vehicle_type != 'm') && 
	    (vehicle_type != 'C' && vehicle_type != 'c') && 
	    (vehicle_type != 'B' && vehicle_type != 'b')) {
		printf("\nInvalid Vehicle Type\n");
	}
	
	else {
		printf("\nEnter the number of days you want to park your vehicle: ");
		scanf("%ld", &days);
		
		long bill = calculateBill(vehicle_type, days, moto_cost, car_cost, bus_cost);
		
		printf("\nYour total charges will be: %ld\n", bill);
	}
}

int main() {
	printf("\n---------------------------------------------\n");
	printf("\tWelcome to Our Parking Area!\n");
	printf("---------------------------------------------\n");
	// Call the function to get user input
	getUserInput();
	// Return 0 to indicate successful program execution
	return 0;
}
