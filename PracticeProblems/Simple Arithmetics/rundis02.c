#include<stdio.h>
#include<math.h>

int main() {
	int x1,x2,y1,y2;	// Variables declared x1,y1,x2,y2
	
	// Prompt the user to enter the first x coordinate
    	printf("Enter the first x-coordinate: ");
    	scanf("%d", &x1);	// Read & store the value of x1 from the user
    
    	// Prompt the user to enter the first y coordinate
    	printf("Enter the first y-coordinate: ");
    	scanf("%d", &y1);	// Read & store the value of y1 from the user
    
    	// Prompt the user to enter the second x coordinate
    	printf("Enter the second x-coordinate: ");
    	scanf("%d", &x2);	// Read & store the value of x2 from the user
    
    	// Prompt the user to enter the second y coordinate
    	printf("Enter the second y-coordinate: ");
    	scanf("%d", &y2);	// Read & store the value of y2 from the user
    
    	// Declare and Define the formula to calculate the distance between the two points
    	float distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    	
    	// Display the calculated distance
    	printf("The distance between the two points is %g \a\n", distance);
    	return 0;}
