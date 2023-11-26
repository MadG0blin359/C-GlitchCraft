#include <stdio.h>
float arithematicseries(float a, float n, float d);

int main() {
	float a, n, d;
	
	printf("Enter the first term of the series = ");
	scanf("%g", &a);
	
	printf("Enter the number of term (n) or the nth term = ");
	scanf("%g", &n);
	
	printf("Enter the common difference of the consecutive terms = ");
	scanf("%g", &d);
	
	printf("The sum of the series is = %g\n", arithematicseries(a, n, d));

	return 0;
}

float arithematicseries(float a, float n, float d) {
	float sum;
	
	sum = (n/2)*(2*a + (n - 1)*d);
	
	return sum;
}
