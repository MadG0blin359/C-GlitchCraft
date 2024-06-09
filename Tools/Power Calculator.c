#include <stdio.h>

void userOutput(int num, int pow) {

    int result = num;
    // Loop to calculate the power
    for (int i = 1; i < pow; i++) {
        result *= num;
    }

    printf("The result is : %d", result);
}

void userInput(int num, int pow) {
    printf("\nEnter any number : ");
    scanf("%d", &num);

    printf("Enter power : ");
    scanf("%d", &pow);

    // Calling the function to display the result
    userOutput(num, pow);

}

int main () {

    int num, pow;

    // Calling the function to prompt and take user input
    userInput(num, pow);

    return 0;
}