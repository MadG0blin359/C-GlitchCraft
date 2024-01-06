#include<stdio.h>
#include<math.h>

// Function to calculate the distance between two points
float calculateDistance(int x1, int y1, int x2, int y2) {
    
    return sqrt((x2 - x1)*(x2 - x1)+(y2 - y1)*(y2 - y1));
}

int main() {
	int x1, y1, x2, y2;		//variables declared x1,y1,x2,y2
	
	printf("Enter the coordinates of the first point (x1, y1): ");	// Prompt the user to enter the value for x1 and y1
	scanf("%d %d", &x1, &y1);	// Read & store the value for x1 from the user
	
	printf("Enter the coordinates of the second point (x2, y2): ");	// Prompt the user to enter the value for x2 and y2
	scanf("%d %d", &x2, &y2);	// Read & store the value for x2 from the user
	
	float distance = calculateDistance(x1, y1, x2, y2);	    // Call the calculateDistance function to calculate the distance
	
	printf("The distance between the points (%d, %d) and (%d, %d) is approximately %f units\n", x1, x2, y1, y2, distance); 	// Display the result

	return 0; 
}	


