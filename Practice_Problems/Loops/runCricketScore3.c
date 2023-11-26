// ODI Cricket Match Score Card
#include <stdio.h>

int main() {
    int input, runs = 0, total_runs = 0, ball_num = 0, over = 0, wicket = 0;
    char exit;

	// starting ball number is 1. When user presses '3' at the very start of the program, '0' balls will be displayed.
    	ball_num++;

    for (;;) {
    	// Display menu options
        printf("\n\t\t--MENU--");
        printf("\nPress \'1\' to Open Update Runs Program\n");
        printf("Press \'2\' to Update Wicket\n");
        printf("Press \'3\' to Show Match Stats\n");
        printf("Press \'0\' to Exit the Program Completely\n");
        printf("\nPress = ");
        scanf("%d", &input);

        if (input == 1) {
        // Start updating runs
        
            // 50 overs (300 balls) in a ODI match
		for (ball_num; ball_num <= 300; ball_num++) {
			// Prompt the user for runs scored 
			printf("\nAdd runs (0-6) for ball \'%d\' = ", ball_num);
			scanf("%d", &runs);

			if (runs >= 0 && runs <= 6) {
				// Update total runs
				total_runs += runs;
				printf("Updated runs = %d\n", total_runs);

				if (ball_num %6 == 0) {
					// Display the completion of an over
		                	over++;
		                	printf("\n\t\tOver %d Completed!\n\n", over);
		            	}
		        }
		        
		        else if (runs != 0 || runs != 1 || runs != 2 || runs != 3 || runs != 4 || runs != 5 || runs != 6) {
			    // Handle invalid input
			    printf("Not one of the specified runs. Invalid Input\n");
			    total_runs -= runs;
			    ball_num++;
			    break;
                	}
                	
                if (runs >= 0 && runs <= 6) {
                	// Ask whether to continue
	                printf("Press \'n\' to Exit to Menu OR \'y\' to continue adding runs: (y/n): ");
        	        scanf(" %c", &exit);  	
		
			if (exit == 'n') {
				// Exit the run update program
				printf("\n\n\tMatch Stats:\n--Total runs = %d\n--Total Balls = %d\n--Total Over(s) = %d\n--Total Wicket(s) = %d\n", total_runs, ball_num, over, wicket);
				ball_num++;
		            	break;
                	}
                	
                	else if (exit == 'y') {
                		// Continue the run update program
                		
                	}
		
			if (exit != 'n' && exit != 'y') {
                	// Handle invalid input
			
				for (exit != 'n' && exit != 'y';;) {
				printf("\n--Invalid Input--\n\n");
				
				// Ask again whether to continue
			        printf("Press \'n\' to Exit to Menu OR \'y\' to continue adding runs: (y/n): ");
			        scanf(" %c", &exit);
			        
			        	if (exit == 'n') {
						// Exit the run update program
						printf("\n\n\tMatch Stats:\n--Total runs = %d\n--Total Balls = %d\n--Total Over(s) = %d\n--Total Wicket(s) = %d\n", total_runs, ball_num, over, wicket);
					    	break;
		        		}
		        		
		        		else if (exit == 'y') {
						// Continue the run update program
					    	break;
		        		}
		        	}
               		}
		}
            }
        }
        
        else if (input == 2) {
        	// Update wicket count
		wicket++;
		printf("\n\tTotal Wicket(s) = %d\n", wicket);
        }
        
        else if (input == 3) {
        	// Display match statistics
		printf("\n\tMatch Stats:\n--Total runs = %d\n--Total Balls = %d\n--Total Over(s) = %d\n--Total Wicket(s) = %d\n", total_runs, ball_num, over, wicket);
                    
	}
        
        else if (input == 0) {
		// Exit the program
		break;
        }
        
        else if (input<0 || input>3) {
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
