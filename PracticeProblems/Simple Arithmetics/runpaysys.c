#include <stdio.h>

int calculateHousingAllowance(int basic_salary) {	// Define Function for calculating Housing Allowance
	return 0.05*basic_salary;	// Return the calculated housing allowance
}
	
int calculateTransportAllowance(int basic_salary) {	// Define Function for calculating Transportation Allowance
	return 0.07*basic_salary;	// Return the calculated transportation allowance
}

int caculateNetSalary(int basic_salary, int housing, int transportation, int security_charges) { 	// Define Function for calculating Net Salary
	return basic_salary+housing+transportation-security_charges; // Return the calculated net salary
}

int main() {
	int basic_salary;	// Declare the variable to store the user input
	int security_charges = 5000;	// Declare and define the fixed security charges
	
	printf("Welcome to the Employee Payroll System!\nEnter the basic salary of the employ: "); // Prompt the user to enter the basic salary of an employee
	scanf("%d", &basic_salary);	// Read and Store the user input
	
	int housing = calculateHousingAllowance(basic_salary);	// Call function and store the calculated value in housing variable
	
	int transportation = calculateTransportAllowance(basic_salary);	// Call the function and store the calculated value in tranportation variable
	
	int net = caculateNetSalary(basic_salary, housing, transportation, security_charges); // Call the function and store the calculated value in net  variable
	
	printf("Employ Details:\nBasic Salary: %d Rs\nHousing Allowance: %d Rs\nTransportation Allowance: %d Rs\nSecurity charges: %d Rs\nNet Salary: %d Rs\n", basic_salary, housing, transportation, security_charges, net); // Display the results
	
	return 0;	// Return 0 to indicate successful program execution
}
