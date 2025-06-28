#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int N;  // Dimension of the vector
int **transformationMatrix;
int *inputVector;
int *resultVector;

// Thread function to compute each row of the transformed vector
void* computeRow(void* arg) {
    int row = *(int*)arg;
    resultVector[row] = 0; // Initialize result row

    for (int col = 0; col < N; col++) {
        resultVector[row] += transformationMatrix[row][col] * inputVector[col];
    }

    pthread_exit(NULL);
}

int main() {
    printf("Enter the dimension of the vector (N): ");
    scanf("%d", &N);

    // Allocate memory
    transformationMatrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        transformationMatrix[i] = (int*)malloc(N * sizeof(int));

    inputVector = (int*)malloc(N * sizeof(int));
    resultVector = (int*)malloc(N * sizeof(int));

    // User input or random allocation
    srand(time(0));

    int choice;
    printf("Enter 1 for manual input, 2 for random initialization: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the %dD vector:\n", N);
        for (int i = 0; i < N; i++)
            scanf("%d", &inputVector[i]);

        printf("Enter the %dx%d transformation matrix:\n", N, N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &transformationMatrix[i][j]);

    } else {
        // Random initialization
        for (int i = 0; i < N; i++)
            inputVector[i] = rand() % 10;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                transformationMatrix[i][j] = rand() % 10;
    }

    // Display input vector and transformation matrix
    printf("\nInput Vector:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", inputVector[i]);
    printf("\n\nTransformation Matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", transformationMatrix[i][j]);
        printf("\n");
    }

    // Create threads
    pthread_t threads[N];
    int indices[N];

    for (int i = 0; i < N; i++) {
        indices[i] = i;
        pthread_create(&threads[i], NULL, computeRow, &indices[i]);
    }

    // Join threads
    for (int i = 0; i < N; i++)
        pthread_join(threads[i], NULL);

    // Display result
    printf("\nTransformed Vector:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", resultVector[i]);
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < N; i++)
        free(transformationMatrix[i]);
    free(transformationMatrix);
    free(inputVector);
    free(resultVector);

    return 0;
}

