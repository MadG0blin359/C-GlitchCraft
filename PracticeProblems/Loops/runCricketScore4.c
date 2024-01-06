#include <stdio.h>

int main() {
    int input, runs = 0, total_runs = 0, ball_num = 0, over = 0, wicket = 0;
    char exit;
    ball_num++;

    for (;;) {
        // Display menu options
        printf("\n\t\t--MENU--");
        printf("\nPress '1' to Update Runs Program\n");
        printf("Press '2' to Update Wicket\n");
        printf("Press '3' to Show Match Stats\n");
        printf("Press '0' to Exit the Program Completely\n");
        printf("\nPress = ");
        scanf("%d", &input);

        if (input == 1) {
            // Start updating runs

            // 50 overs (300 balls) in an ODI match
            for (ball_num; ball_num <= 300; ball_num++) {
                // Prompt the user for runs scored
                printf("\nAdd runs (0-6) for ball '%d' = ", ball_num);
                if (scanf("%d", &runs) != 1 || runs < 0 || runs > 6) {
                    // Handle invalid input
                    printf("Invalid Input\n");
                    total_runs -= runs;
                    ball_num--;
                } else {
                    // Update total runs
                    total_runs += runs;
                    printf("Updated runs = %d\n", total_runs);

                    if (ball_num % 6 == 0) {
                        // Display the completion of an over
                        over++;
                        printf("\n\t\tOver %d Completed!\n\n", over);
                    }
                }

                // Ask whether to continue
                if (runs > 0 && runs <= 6) { 
                        printf("Press 'n' to Exit to Menu OR 'y' to continue adding runs: (y/n): ");
                        scanf(" %c", &exit);
                }

                if (exit == 'n') {
                    // Exit the run update program
                    break;
                } else if (exit != 'y') {
                    // Handle invalid input
                    for (;;) {
                        printf("\n--Invalid Input--\n\n");
                        // Ask again whether to continue
                        printf("Press 'n' to Exit to Menu OR 'y' to continue adding runs: (y/n): ");
                        scanf(" %c", &exit);
                        if (exit == 'n') {
                            // Exit the run update program
                            break;
                        } else if (exit == 'y') {
                            // Continue the run update program
                            break;
                        }
                    }
                }
            }
        } else if (input == 2) {
            // Update wicket count
            wicket++;
            printf("\n\tTotal Wicket(s) = %d\n", wicket);
        } else if (input == 3) {
            // Display match statistics
            printf("\n\tMatch Stats:\n--Total runs = %d\n--Total Balls = %d\n--Total Over(s) = %d\n--Total Wicket(s) = %d\n", total_runs, ball_num, over, wicket);
        } else if (input == 0) {
            // Exit the program
            break;
        } else if (input < 0 || input > 3) {
            // Handle invalid input
            printf("Invalid Input\n");
        }

        if (wicket >= 10) {
            // Match over after 10 wickets
            printf("\n\tMatch Over!\n--Total runs = %d\n--Total Balls = %d\n--Total Over(s) = %d\n--Total Wicket(s) = %d\n\n", total_runs, ball_num, over, wicket);
            break;
        }
    }

    return 0;
}
