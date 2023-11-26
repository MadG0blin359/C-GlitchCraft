#include <stdio.h>

int main() {
  int size = 10;
  int arr[size];

  printf("Enter any 10 integers: ");

  for (int i = 0; i < size; i++) {
    
    scanf("%d", &arr[i]);

    int duplicate = 0;
    for (int j = 0; j < i; j++) {  // Change condition to j < i

      if (arr[i] == arr[j]) {

        duplicate++;
        break;

      }

    }

    if (duplicate == 1) {
        continue;
    }

    printf("%d ", arr[i]);
    
  }

  return 0;  // Added for completeness
}

