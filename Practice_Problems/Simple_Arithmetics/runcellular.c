#include <stdio.h>

// Function to display the receipt containing account number, service type, minutes used, and total bill
double displayReceipt(long acc_num, char service_code, long minute_num, long day_minutes, long night_minutes, double total_bill) {
	
	// Display the output
	printf("\n\t--Receipt--");
	// Display the account number
	printf("\nAccount Number:\t\t\t %ld\n", acc_num);
	
	// Display the following output if the service type is Regular
	if (service_code == 'r' || service_code == 'R') {
		printf("Type Of Service:\t\t Regular\n");
	}
	
	// Display the following output if the service type is Premium
	else {
		printf("Type Of Service:\t\t Premium\n");
	}
	
	// Display the following output if the service type is Regular
	if (minute_num > 0) {
		printf("Total Minutes Used:\t\t %ld\n", minute_num);
	}
	
	// Display the following output if the service type is Premium
	else {
		printf("Minutes Used During the Day:\t %ld\n", day_minutes);
		printf("Minutes Used During the Night:\t %ld\n", night_minutes);
		printf("Total Minutes Used:\t\t %ld\n", day_minutes + night_minutes);
	}
	
	// Display the total charges
	printf("Total Charges:\t\t\t $%.2lf\n", total_bill);
}

int main() {
	// Declare the variables to store the user input
	long acc_num, minute_num;
	char service_code;
	// Declare the variable to calculate the total bill
	double total_bill;
	
	// Display the welcome screen
	printf("\n\t******Welcome to Zong Cellular Telephone Company!******\n");
	// Prompt the user to enter the account number
	printf("--Enter your account number: ");
	scanf("%ld", &acc_num);
	// Prompt the user to choose the service type
	printf("--Enter the service code for Regular Service (r/R) OR Premium Service (p/P): ");
	scanf(" %c", &service_code);
	
	// Display Error if the user choice is other than the specified alphabets
	if (service_code != 'r' && service_code != 'R' && service_code != 'p' && service_code != 'P') {
		printf("\nError. Invalid Input!\n\n");
	}
	
	// If the choice of service type is not invalid, prompt the user to enter the number of minutes used
	else if (service_code == 'r' || service_code == 'R') {
		printf("--Enter the number of minutes: ");
		scanf("%ld", &minute_num);
	}
	
	// Calculate the 'Regular' service charges
	if (service_code == 'r' || service_code == 'R') {
		double reg_charges;
		// Fixed charges for regular service
		reg_charges = 10;
		
		// If the number of minutes used is more than the number of free minutes (50) 
		if (minute_num > 50) {
			total_bill = reg_charges + ((minute_num - 50) * 0.20);
		}
		
		// If the number of minutes used is less than or equal to free 50 minutes
		else {
			total_bill = reg_charges;
		}
	}
	
	// Declare the variables to store user input for premium package
	long day_minutes, night_minutes;
	
	// Calculate the 'Premium' srvice charges
	if (service_code == 'p' || service_code == 'P') {
		double prem_charges, day_charges, night_charges;
		long free_day, free_night;
		// Free minutes during the Day & Night
		free_day = 75;
		free_night = 100;
		// Fixed charges for premium service
		prem_charges = 25;
		// Initialize Day & Night charges
		day_charges = 0;
		night_charges = 0;
		
		// Prompt the user to enter the number of minutes used during the day
		printf("--Minutes used during the day (6:00AM to 6:00PM): ");
		scanf("%ld", &day_minutes);
		
		// Prompt the user to enter the number of minutes used during the night
		printf("--Minutes used during the night (6:00PM to 6:00AM): ");
		scanf("%ld", &night_minutes);
		
		// Calculate the day charges if the number of minutes used during the day is more than the 75 free minutes
		if (day_minutes > free_day) {
			day_charges = (day_minutes - free_day) * 0.10;
		}
		
		// Calculate the night charges if the number of minutes used during the night is more than the 100 free minutes
		if (night_minutes > free_night) {
			night_charges = (night_minutes - free_night) * 0.05;
		} 
		
		// Calculate the total charges with day and night charges with initial fixed premium charges (25 dollars)
		if (day_minutes > free_day || night_minutes > free_night) {
			total_bill = prem_charges + day_charges + night_charges;
		}
		
		// Display the initial fixed charges, if the number of minutes used is not more than the free minutes in both day and night
		else if (day_minutes <= free_day && night_minutes <= free_night) {
			total_bill = prem_charges;
		}
	}
	
	// If the user choice for service type is correct, call the function displayReceipt to diplay a list of detials
	if (service_code == 'r' || service_code == 'R' || service_code == 'p' || service_code == 'P') {
		displayReceipt(acc_num, service_code, minute_num, day_minutes, night_minutes, total_bill);
	}

	// Return 0 to indicate successful program execution
	return 0;
}
