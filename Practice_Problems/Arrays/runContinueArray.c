#include <stdio.h>

int main() {
  int size = 10;
  int arr[size];

  // Prompt the user to enter any 10 integers
  printf("Enter any 10 integers: ");

  // Loop to take user input
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);

    int duplicate = 0;
    for (int j = 0; j < i; j++) {  // Loop to check for any duplicate from previously entered numbers
      if (arr[i] == arr[j]) {
        duplicate++;
        break;
      }
    }

    // skip the printing if theres a duplicate
    if (duplicate == 1) {
        continue;
    }

    // Display the non-duplicate integers
    printf("%d ", arr[i]);
    
  }

  return 0;  // Added for completeness

}
