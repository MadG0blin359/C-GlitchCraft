#include <stdio.h>

// Define Your both functions here

// Nothing below

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
                      {1000,60,1},
                      {1000,10000,3},
                      {10000,95,598},
                      {100,12,8},
                      {1500,450,3},
                      {1700,2154,1},
                      {1000,60,61}};

    int arr4[10][3] = {{10,10,6},
                      {100,100,39},
                      {100,95,41},
                      {1000,96,40},
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
