#include<stdio.h>

int main() {
	float days, weeks, months, years;
	days = 1329, weeks = days/7, months = days/30, years = days/365;

	// Display the total years, months, and weeks based on the days 
	printf("Years = %f, Months = %f, Weeks = %f, Days = %f", years, months, weeks, days);

	return 0; 

}
