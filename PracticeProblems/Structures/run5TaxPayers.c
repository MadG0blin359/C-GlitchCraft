#include <stdio.h>

struct TaxPayer {
	// Variables to store citizens data
	double income, tax_rate, taxes;
};

int main() {
	int size = 5;
	struct TaxPayer citizen[size];

	printf("\n\tCalculate Annual Tax");
	printf("\n\t--------------------\n");

	// Loop to iterate for 5 citizens
	for (int i = 0; i < size; i++) {
		printf("\n--Enter annual income of citizen %d : ", i+1);
		scanf("%lf", &citizen[i].income);
		
		printf("--Enter tax rate for citizen %d : ", i+1);
		scanf("%lf", &citizen[i].tax_rate);
		
		citizen[i].taxes = citizen[i].income * citizen[i].tax_rate / 100;
	}
	
	printf("\nTaxes due for this year\n");
	
	// Display the final calculated results
	for (int i = 0; i < size; i++) {
		printf("--For citizen %d : %lg\n", i+1, citizen[i].taxes);
	}

	return 0;
}
