#include <stdio.h>  
  
int main() { 
	
	// Variable 'r' is number of rows, and variable 'c' is number of columns
	int r = 5, c = 5; 
	
	// Loops to display the first pattern
	for (int i = 1; i <= r; i++) {  
	     
		// Loop to add spaces before asterisks
		for (int j = 1; j < i; j++) {
		
			printf(" ");  
		
		}
	       
		// Loop to print asterisks
		for (int k = 1; k <= c; k++) {  
		
			printf("*");  
	       
		}
	       
		// Decrease the number of columns
		c--;  
	     
		// Move to the next line
		printf("\n");  
		
		}  
	    
	    
	int d = 1;  
	
	// Loops to display the second pattern 
	for(int i = 5; i >= 1; i--) {
	      
		// Loop to add spaces before asterisks
		for(int j = 1; j < i; j++) { 
		  
			printf(" ");
		   
		}
	      
		// Loop to print asterisks
		for(int k = 1; k <= d; k++) {
		 
	   		printf("*");  
	   
		}  
		
		// Increase the number of asterisks
		d++;
		
		// Move to the next line
		printf("\n");
	    
	    }
	    
	    return 0;  
}
