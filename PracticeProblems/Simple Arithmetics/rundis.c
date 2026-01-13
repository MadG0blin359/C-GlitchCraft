#include<stdio.h>
#include<math.h>

int main() {
	int x1; 
	int y1;			
	int x2;
	int y2;		//variables declared x1,y1,x2,y2
	
	printf("Enter the x1 value = ");	// Prompt the user to enter the value for y1
	scanf("%d", &x1);	// Read & store the value for x1 from the user
	
	printf("Enter the y1 value = ");	// Prompt the user to enter the value for y1
	scanf("%d", &y1);	// Read & store the value for y1 from the user
	
	printf("Enter the x2 value = ");	// Prompt the user to enter the value for y1
	scanf("%d", &x2);	// Read & store the value for x2 from the user
	
	printf("Enter the y2 value = ");	// Prompt the user to enter the value for y1
	scanf("%d", &y2);	// Read & store the value for y2 from the user
	
	float distance = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));	//Declaring & Defining the distance formula as a variable
	
	printf("Distance between the two points is %f \n", distance); // to compile the file in the Ubuntu terminal, run: gcc filename.c -o filename2.c -lm (-lm is for the sqrt, without this the file can't be compiled)
	return 0; }
	
