#include <stdio.h>
#include <stdlib.h>

// Global Variable
int size = 32;

// Function to generate a financial report
int generateReport(int choice, double income_amount, double expense_amount, int day, int month, int year){
	

	if (choice == 3) {
		
		system("clear");
		
		printf("\n ___________________________________________\n");
		printf("|					      \n");
		printf("|     		DATE   =   %d-%d-%d           \n", day, month, year);
		printf("|___________________________________________\n"); 
		printf("|						\n");
		printf("|     	YOUR INCOME   =      %.2lf PKR\n", income_amount);      
		printf("|     	YOUR EXPENSE  =      %.2lf PKR\n", expense_amount);
		printf("|     	YOUR BALANCE  =      %.2lf PKR\n", income_amount-expense_amount);
		printf("|___________________________________________\n");

	}
	
}

// Function to handle income categories
double incomeCategories(int choice) {
	int income_choice;
	income_choice = 0;
    
	double salary_arr[size], rental_arr[size], sales_arr[size], freelancing_arr[size], real_estate_arr[size], consultation_arr[size], crypto_arr[size], dividend_arr[size], pension_arr[size], other_arr[size];
    
	// Variables for iterating through arrays
    	int ai = 0, bi = 0, ci = 0, di = 0, ei = 0, fi = 0, gi = 0, hi = 0, ii = 0, ji = 0;
    
	do {
		
		// Display income category options
		printf("\n--Select Your Source Of Income\n");
		printf("1. Salary\n");
		printf("2. Rental\n");
		printf("3. Sales\n");
		printf("4. Freelancing\n");
		printf("5. Real Estate\n");
		printf("6. Consultation\n");
		printf("7. Crypto\n");
		printf("8. Dividend\n");
		printf("9. Pension\n");
		printf("10. Other\n");
		printf("Enter your choice: ");
		scanf("%d", &income_choice);	 	// Read user input for income category choice	
		
		switch(income_choice) {
			
			case 1:
			    	printf("\n------------SALARY---------\n");
				printf("Enter amount: ");
				
				for (ai; ai < size; ai++) {
					scanf("%lf", &salary_arr[ai]);
					
					while (salary_arr[ai] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &salary_arr[ai]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
				return salary_arr[ai];
			break;

			case 2:
			    	printf("\n------------RENTAL------------\n");
				printf("Enter amount: ");
				
				for (bi; bi < size; bi++) {
					scanf("%lf", &rental_arr[bi]);
					
					while (rental_arr[bi] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &rental_arr[bi]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
				
				return rental_arr[bi];
				
		    	break;

			case 3:
			    	printf("\n------------SALES------------\n");
				printf("Enter amount: ");
				
				for (ci; ci < size; ci++) {
					scanf("%lf", &sales_arr[ci]);
					
					while (sales_arr[ci] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &sales_arr[ci]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
				
				return sales_arr[ci];
		    	break;

			case 4:
			    	printf("\n------------FREELANCING------------\n");
				printf("Enter amount: ");
				
				for (di; di < size; di++) {
					scanf("%lf", &freelancing_arr[di]);
					
					while (freelancing_arr[di] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &freelancing_arr[di]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
				
				return freelancing_arr[di];
			break;
		    
			case 5:
			    	printf("\n------------REAL ESTATE------------\n");
				printf("Enter amount: ");
				
				for (ei; ei < size; ei++) {
					scanf("%lf", &real_estate_arr[ei]);
					
					while (real_estate_arr[ei] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &real_estate_arr[ei]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
				
				return real_estate_arr[ei];
			break;
		    
			case 6:
			    	printf("\n------------CONSULTATION------------\n");
				printf("Enter amount: ");
				
				for (fi; fi < size; fi++) {
					scanf("%lf", &consultation_arr[fi]);
					
					while (consultation_arr[fi] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &consultation_arr[fi]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
				
				return consultation_arr[fi];
			break;

			case 7:
			    	printf("\n------------CRYPTO------------\n");
				printf("Enter amount: ");
				
				for (gi; gi < size; gi++) {	
					scanf("%lf", &crypto_arr[gi]);
					
					while (crypto_arr[gi] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &crypto_arr[gi]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
				
				return crypto_arr[gi];
			break;

			case 8:
			    	printf("\n------------DIVIDEND------------\n");
				printf("Enter amount: ");
				
				for (hi; hi < size; hi++) {
					scanf("%lf", &dividend_arr[hi]);
					
					while (dividend_arr[hi] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &dividend_arr[hi]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
				
				return dividend_arr[hi];
			break;

			case 9:
			    	printf("\n------------PENSION------------\n");
				printf("Enter amount: ");
				
				for (ii; ii < size; ii++) {
					scanf("%lf", &pension_arr[ii]);
					
					while (pension_arr[ii] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &pension_arr[ii]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
			
				return pension_arr[ii];
			break;

			case 10:
			    	printf("\n------------OTHER------------\n");
				printf("Enter amount: ");
					
				for (ji; ji < size; ji++) {
					scanf("%lf", &other_arr[ji]);
					
					while (other_arr[ji] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &other_arr[ji]);
						
					}
					
					printf("\n\"INCOME Successfully Saved\"\n");
					break;
				}
				
				
				return other_arr[ji];
			break;

			default:
				printf("\n------------Invalid Input!------------\n");

		}
	
	}
	
	while (1);
	
}

// Function to handle expense categories
double expenseCategories(int choice) {
	int expense_choice;
	expense_choice = 0;
	double food_arr[size], education_arr[size], health_arr[size], shopping_arr[size], entertainment_arr[size], vacation_arr[size], bills_arr[size], rent_arr[size], vehicle_arr[size], loan_arr[size], tax_arr[size], misc_arr[size];
	
	// Variables for iterating through arrays
	int ai = 0, bi = 0, ci = 0, di = 0, ei = 0, fi = 0, gi = 0, hi = 0, ii = 0, ji = 0, ki = 0, li = 0;
	
	do { 
			// Display income category options
			printf("\n--Select Your Expense Type\n");   
			printf("1. Food/Grocery\n");
			printf("2. Education\n");
			printf("3. Health\n");
			printf("4. Shopping\n");
			printf("5. Entertainment\n");
			printf("6. Vacation\n");
			printf("7. Bills\n");
			printf("8. Rent\n");
			printf("9. Vehicle Expense\n");
			printf("10. Loan/Debt\n");
			printf("11. Tax\n");
			printf("12. Misc.\n");
			printf("Enter your choice: ");
			scanf("%d", &expense_choice);		// Read user input for income category choice
		
			switch(expense_choice) {
				case 1:
					printf("\n------------FOOD/GROCERY------------\n");
					printf("Enter amount: ");
					
					for (ai; ai < size; ai++) {
						scanf("%lf", &food_arr[ai]);
						
						while (food_arr[ai] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &food_arr[ai]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
					
					
					return food_arr[ai];
				break;

				case 2:
					printf("\n------------EDUCATION------------\n");
					printf("Enter amount: ");
					
					for (bi; bi < size; bi++) {
						scanf("%lf", &education_arr[bi]);
						
						while (education_arr[bi] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &education_arr[bi]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
					
					
					return education_arr[bi];
				break;

				case 3:
					printf("\n------------HEALTH------------\n");
					printf("Enter amount: ");
					
					for (ci; ci < size; ci++) { 
						scanf("%lf", &health_arr[ci]);
						
						while (health_arr[ci] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &health_arr[ci]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
					
					
					return health_arr[ci];
				break;

				case 4:
					printf("\n------------SHOPPING------------\n");
					printf("Enter EXPENSE amount: ");
					
					for (di; di < size; di++) {
						scanf("%lf", &shopping_arr[di]);
						
						while (shopping_arr[di] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &shopping_arr[di]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
					
					
					return shopping_arr[di];
				break;

				case 5:
					printf("\n------------ENTERTAINMENT------------\n");
					printf("Enter EXPENSE amount: ");
					
					for (ei; ei < size; ei++) {
						scanf("%lf", &entertainment_arr[ei]);
						
						while (entertainment_arr[ei] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &entertainment_arr[ei]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
						
					
					return entertainment_arr[ei];
				break;

				case 6:
					printf("\n------------VACATION------------\n");
					printf("Enter amount: ");
					
					for (fi; fi < size; fi++) {
						scanf("%lf", &vacation_arr[fi]);
						
						while (vacation_arr[fi] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &vacation_arr[fi]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
						
					
					return vacation_arr[fi];
				break;

				case 7:
					printf("\n------------BILLS------------\n");
					printf("Enter amount: ");
					
					for (gi; gi < size; gi++) {
						scanf("%lf", &bills_arr[gi]);
						
						while (bills_arr[gi] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &bills_arr[gi]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
						
					
					return bills_arr[gi];
				break;
			    
				case 8:
					printf("\n------------RENT------------\n");
			    		printf("Enter amount: ");
			    		
			    		for (hi; hi < size; hi++) {
						scanf("%lf", &rent_arr[hi]);
						
						while (rent_arr[hi] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &rent_arr[hi]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
						
					
					return rent_arr[hi];
				break;
				
				case 9:
					printf("\n------------VEHICLE EXPENSE------------\n");
			    		printf("Enter amount: ");
			    		
			    		for (ii; ii < size; ii++) {
						scanf("%lf", &vehicle_arr[ii]);
						
						while (vehicle_arr[ii] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &vehicle_arr[ii]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
						
					
					return vehicle_arr[ii];
				break;
			    
				case 10:
					printf("\n------------LOAN/DEBT------------\n");
			    		printf("Enter amount: ");
			    		
			    		for (ji; ji < size; ji++) {
						scanf("%lf", &loan_arr[ji]);
						
						while (loan_arr[ji] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &loan_arr[ji]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
						
					
					return loan_arr[ji];
				break;
				
				case 11:
					printf("\n------------TAX------------\n");
					printf("Enter amount: ");
					
					for (ki; ki < size; ki++) {
						scanf("%lf", &tax_arr[ki]);
						
						while (tax_arr[ki] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &tax_arr[ki]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
						
					
					return tax_arr[ki];
				break;
				
				case 12:
					printf("\n------------MISCELLANEOUS------------\n");
					printf("Enter amount: ");
					
					for (li; li < size; li++) {
						scanf("%lf", &misc_arr[li]);
						
						while (misc_arr[li] < 0) {
						printf("\n------------Invalid Input!------------\n");
						
						printf("\nEnter amount: ");
						scanf("%lf", &misc_arr[li]);
						
					}
						
						printf("\n\"EXPENSE Successfully Saved\"\n");
						break;
					}
						
					
					return misc_arr[li];
				break;
				
				default:
					printf("\n------------Invalid Input!------------\n");

				}
			
			}
	
	while(1);
	
}

int main() {
	// Variables for storing dates, menu choice, income, and expense amounts
	int day = 0, month = 0, year = 0, choice = 0;;
	double income_amount, expense_amount;
	income_amount = 0;
	expense_amount = 0;
    
    	system("clear");
    		
	printf("\n");
	printf("\t\t\t\t\t███████╗██╗  ██╗██████╗ ███████╗███╗   ██╗███████╗██╗  ██╗   ██╗\n");
	printf("\t\t\t\t\t██╔════╝╚██╗██╔╝██╔══██╗██╔════╝████╗  ██║██╔════╝██║  ╚██╗ ██╔╝\n");
	printf("\t\t\t\t\t█████╗   ╚███╔╝ ██████╔╝█████╗  ██╔██╗ ██║███████╗██║   ╚████╔╝ \n");
	printf("\t\t\t\t\t██╔══╝   ██╔██╗ ██╔═══╝ ██╔══╝  ██║╚██╗██║╚════██║██║    ╚██╔╝  \n");
	printf("\t\t\t\t\t███████╗██╔╝ ██╗██║     ███████╗██║ ╚████║███████║███████╗██║   \n");
	printf("\t\t\t\t\t╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝╚═╝   \n");	
	printf("\t\t\t\t\t\t\t\t\b\b\"Master Your Finances\"\n");

	printf("\n\n");

	printf("\n ___________________________________________\n");
	printf("|						\n");
	printf("|     	YOUR INCOME   =      %.2lf PKR\n", income_amount);      
	printf("|     	YOUR EXPENSE  =      %.2lf PKR\n", expense_amount);
	printf("|     	YOUR BALANCE  =      %.2lf PKR\n", income_amount-expense_amount);
	printf("|___________________________________________\n");
	
	do { 
		printf("\nEnter The Date (day month year): ");
		scanf("%d %d %d", &day, &month, &year);
		
		if ((year < 2023 || year > 2030) || (month > 12 || month < 1) || (day < 1 || day > 31)) {
			printf("\n------------Invalid Input!------------\n");
		}
		
	}
	
	while ((year < 2023 || year > 2030) || (month > 12 || month < 1) || (day < 1 || day > 31));
	
	// Displaying menu options
	while(choice != 4) {
		
		printf("\n\n---Menu---\n");
	    	printf("1. Add Income\n");
	    	printf("2. Add Expense\n");
	    	printf("3. Generate Report\n");
	    	printf("4. Exit\n");
	    	printf("Enter your choice: ");
	    	scanf("%d", &choice);
	    
		int i = 0;
		int j = 0;

		switch (choice) {
			case 1:			// Code for handling income addition
				printf("\n**************    ADD INCOME   *****************\n");
				
				
				// Display categories for adding income & return the amount of income
				income_amount += incomeCategories(choice);
				
					char more_income;
					more_income = 0;
				
				do {	
					printf("\nAdd More Income:\n");
					printf("Press 'Y/y' for Yes OR 'N/n' for NO: ");
					scanf(" %c", &more_income);
					
					if (more_income == 'y' || more_income == 'Y') {
						income_amount += incomeCategories(choice);
			        	}
			        	
			        }
			        
			        while (more_income != 'n' && more_income != 'N');
		    		
			break;

			case 2:			// Code for handling expense addition
				printf("\n**************    ADD EXPENSE   *****************\n");
				
				
				// Display categories for adding expense return the amount of expense
				expense_amount += expenseCategories(choice);
				
				char more_expense;
				more_expense = 0;
				
				do {	
					printf("\nAdd More Expense:\n");
					printf("Press 'Y/y' for Yes OR 'N/n' for NO: ");
					scanf(" %c", &more_expense);
					
					if (more_expense == 'y' || more_expense == 'Y') {
						expense_amount += expenseCategories(choice);
			        	}
			        	
			        }
			        
			        while (more_expense != 'n' && more_expense != 'N');
				
		        break;
			
			case 3:				// Generate and display the financial report
		        	generateReport(choice, income_amount, expense_amount, day, month, year);
		        break;
		    
			case 4:						// Display exit message
				printf("\t\t\t\t\t\b████████╗██╗  ██╗ █████╗ ███╗   ██╗██╗  ██╗    ██╗   ██╗ ██████╗ ██╗   ██╗\n");
				printf("\t\t\t\t\t\b╚══██╔══╝██║  ██║██╔══██╗████╗  ██║██║ ██╔╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║\n");
				printf("\t\t\t\t\t\b   ██║   ███████║███████║██╔██╗ ██║█████╔╝      ╚████╔╝ ██║   ██║██║   ██║\n");
				printf("\t\t\t\t\t\b   ██║   ██╔══██║██╔══██║██║╚██╗██║██╔═██╗       ╚██╔╝  ██║   ██║██║   ██║\n");
				printf("\t\t\t\t\t\b   ██║   ██║  ██║██║  ██║██║ ╚████║██║  ██╗       ██║   ╚██████╔╝╚██████╔╝\n");
				printf("\t\t\t\t\t\b   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝       ╚═╝    ╚═════╝  ╚═════╝ \n");
				printf("\t\t\t\t\t\t\t\t\t\b\b\"Have a Nice Day!\"\n");

			break;

			default:
				printf("\n------------Invalid Input!------------\n");
				break;
			
			}
		
	}
	
	return 0;
}
