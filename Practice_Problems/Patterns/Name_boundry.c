#include <stdio.h>

int main() {
    char name[] = "NAME";
    int rows = 4, cols = 5;
    char display[4][5] = {{'N', 'A', 'M', 'E', '\0'},
                          {'A', ' ', ' ', 'M', '\0'},
                          {'M', ' ', ' ', 'A', '\0'},
                          {'E', 'M', 'A', 'N', '\0'}};

    // Printing the 2D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", display[i][j]);
        }
        printf("\n");
    }

    return 0;
}
