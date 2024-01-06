#include <stdio.h>

// Function to check if a number is perfect
int check_perfect(int num) {
    int sum = 1;
    
    for (int i = 2; i * i <= num; i++) {
    
        if (num %i == 0) {
    
            if (i * i != num)
                sum = sum + i + num / i;
    
            else
                sum = sum + i;
        }
    
    }
    
	// Return '1' if the sum of divisors is equal to the number itself, indicating a perfect number
	return sum == num && num != 1;
}

int main() {
	
	int num = 1;
	int count = 0;

	// Loop until 4 perfect numbers are found
	while (count < 4) {
    
        if (check_perfect(num)) {
        
		// Display the perfect number
		printf("%d is a perfect number\n", num);
            
		int sum = 0;
            
		// Loop to find divisors and calculate the sum
		for (int i = 1; i <= num / 2; i++) {
            
			if (num %i == 0) {
			printf("%d+", i);
                    
			sum += i;
                
                }
            
            }
            
		// Display the sum of divisors
		printf("\b=%d\n\n", sum);
		count++;
        
        }
        
	num++;
    }

	return 0;
}
