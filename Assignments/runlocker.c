// 1st student = opens all
// 2nd student = closes lockers on 2,4,6,8,10 and so on - even lockers
// 3rd student = opens the closed lockers, and closes the opened lockers on 3,6,9,12,15 and so on - every third locker
// 4th student = opens the closed lockers, and closes the opened lockers on 4,8,12,16 and so on - every fourth locker

/*                  person #
            --------------------
  locker #  1 2 3 4 5 6 7 8 9 10
     1      +
     2      + -
     3      +   -
     4      + -   +
     5      +       -
     6      + - +     -
     7      +           -
     8      + -   +       -
     9      +   -           +
    10      + -     +         -

I have used "+" for "opened" and "-" for "closed" */

#include <stdio.h>

// Function to simulate the locker opening scenario and count the open lockers
int openLocks(int number_of_lockers, int number_of_students) {
    int open_count = 0;

    // Loop through each locker
    for (int locker = 1; locker <= number_of_lockers; locker++) {
        int students_touch_count = 0;
        
        for (int student = 1; student <= number_of_students; student++) {
            
            if (locker % student == 0) {
                students_touch_count++;
            }
        }

        // Check if the locker is open or closed based on how many students touched it
        if (students_touch_count % 2 == 1) {
            open_count++;
        }
    }

    return open_count;
}

int mostTouchableLocker(int number_of_lockers, int number_of_students) {
	
	int student_touch, student_any_locker, most_touchable_locker;
	student_touch = 0;		// counts how many students have touched a locker
	student_any_locker = 0;		// counts the number of students that have touched any locker
	most_touchable_locker = 1;	// stores the locker number that has been touched by the most students
	
	for (int m = 1; m <= number_of_lockers; m++) {
        
        	for (int n = 1; n <=number_of_students; n++) {
			
			if (m %n == 0) {
				student_touch++;
        		}
        	}
        	
		if (student_touch >= student_any_locker) {
			student_any_locker = student_touch;
			most_touchable_locker = m;
			student_touch = 0;
		}
		
		else {
			student_touch = 0;
		}
			
	}
	
	return most_touchable_locker;

}

int Prime(int n) {
    if (n <= 1) {return 0;}
    if(n<=3){
   return 1;}
   if (n % 2 == 0 || n % 3 == 0 ){
       return 0;
   }
  for (int i=5;i*i<=n;i +=6){
      if(n%i==0 || n%(i+2)==0){return 0;
  } 
}
return 1;}

int openLocks_t3(int number_of_lockers, int number_of_students) {
    int openLockers = 0;
  
    for (int locker = 1; locker <=number_of_lockers ; locker++) {
        int lockerState = 1;
        
        for (int student = 2; student <=number_of_students; student++) {
            if (Prime(student)) {
                lockerState = 0; 
            } else if (locker % student == 0) {
                lockerState = !lockerState; 
            }
        }
        
        openLockers += lockerState;
    }
    
    return openLockers;
}

int openLocks_t4(int number_of_lockers ,int number_of_students) {

}

void test1(int arr[][3], int size)
{
    printf("\n\nTask 1 Results\n\n");
    int passed = 0;
    int failed = 0;
    int val;
    for (int i = 0; i < size; i++)
    {
        val = openLocks(arr[i][0], arr[i][1]);
        if (val == arr[i][2])
            passed++;
        else
        {
            failed++;
            printf("Test Failed\n");
            printf("Lockers = %d\n", arr[i][0]);
            printf("Students= %d\n", arr[i][1]);
            printf("Expected= %d\n", arr[i][2]);
            printf("Result =  %d", val);
            printf("\n-------------------------------------");
            printf("\n\n");
        }
    }
    printf("\n\n");
    printf("Total Passed: %d\n", passed);
    printf("Total Failed: %d\n", failed);
    printf("\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

void test2(int arr[][3], int size)
{
    printf("\n\nTask 2 Results\n\n");
    int passed = 0;
    int failed = 0;
    int val;
    for (int i = 0; i < size; i++)
    {
        val = mostTouchableLocker(arr[i][0], arr[i][1]);
        if (val == arr[i][2])
            passed++;
        else
        {
            failed++;
            printf("Test Failed\n");
            printf("Lockers = %d\n", arr[i][0]);
            printf("Students= %d\n", arr[i][1]);
            printf("Expected= %d\n", arr[i][2]);
            printf("Result =  %d", val);
            printf("\n-------------------------------------");
            printf("\n\n");
        }
    }
    printf("\n\n");
    printf("Total Passed: %d\n", passed);
    printf("Total Failed: %d\n", failed);
    printf("\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

void test3(int arr[][3], int size)
{
    printf("\n\nTask 3 Results\n\n");
    int passed = 0;
    int failed = 0;
    int val;
    for (int i = 0; i < size; i++)
    {
        val = openLocks_t3(arr[i][0], arr[i][1]);
        if (val == arr[i][2])
            passed++;
        else
        {
            failed++;
            printf("Test Failed\n");
            printf("Lockers = %d\n", arr[i][0]);
            printf("Students= %d\n", arr[i][1]);
            printf("Expected= %d\n", arr[i][2]);
            printf("Result =  %d", val);
            printf("\n-------------------------------------");
            printf("\n\n");
        }
    }
    printf("\n\n");
    printf("Total Passed: %d\n", passed);
    printf("Total Failed: %d\n", failed);
    printf("\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

void test4(int arr[][3], int size)
{
    printf("\n\nTask 4 Results\n\n");
    int passed = 0;
    int failed = 0;
    int val;
    for (int i = 0; i < size; i++)
    {
        val = openLocks_t4(arr[i][0], arr[i][1]);
        if (val == arr[i][2])
            passed++;
        else
        {
            failed++;
            printf("Test Failed\n");
            printf("Lockers = %d\n", arr[i][0]);
            printf("Students= %d\n", arr[i][1]);
            printf("Expected= %d\n", arr[i][2]);
            printf("Result =  %d", val);
            printf("\n-------------------------------------");
            printf("\n\n");
        }
    }
    printf("\n\n");
    printf("Total Passed: %d\n", passed);
    printf("Total Failed: %d\n", failed);
    printf("\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

int main()
{
    int arr1[10][3] = {{10,10,3},
                      {100,100,10},
                      {100,72,34},
                      {70,100,8},
                      {10000,1000,5228},
                      {0,0,0},
                      {1,0,0},
                      {10000,10000,100},
                      {10000,2000,5187},
                      {17000,2154,8989}};
    int arr2[10][3] = {{10,10,10},
                      {20,10,20},
                      {72,100,72},
                      {100,70,60},
                      {150,40,120},
                      {15,7,12},
                      {1500,450,1260},
                      {100,100,96},
                      {17000,2154,15120},
                      {10000,10000,9240}};
    int arr3[10][3] = {{10,10,3},
                      {100,100,3},
                      {100,95,6},
                      {1000,60,16},
                      {1000,10000,3},
                      {10000,95,598},
                      {100,12,8},
                      {1500,450,3},
                      {1700,2154,1},
                      {10000,60,166}};

    int arr4[10][3] = {{10,10,6},
                      {100,100,39},
                      {100,95,41},
                      {100,96,40},
                      {1000,10000,463},
                      {10000,95,5827},
                      {100,12,74},
                      {1000,97,657},
                      {1700,2154,818},
                      {1000,1,1000}};
    test1(arr1,10);
    test2(arr2,10);
    test3(arr3,10);
    test4(arr4,10);
    return 0;
}
