// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int day = 1;
    printf("Mo  Tu  We  Th  Fr  Sa  Su\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            printf("%d\t", day);
            day++;
            
            if (day > 31) {
                break;
            }
            
        }
        
        printf("\n");
        
    }

    return 0;
}