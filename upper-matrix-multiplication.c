// Multiplication of upper triangular matrices without using 2D arrays
// Written in Code::Blocks using the GCC compiler

#include <stdio.h> // Standard input-output library
#include <stdlib.h> // Standard library for various functions

int main() {

    FILE *input = fopen("input.txt", "r"); // Opening input.txt for reading

    if (input == NULL) {
        fprintf(stderr, "Error opening the file.\n"); // Error message when there is no file to read
        return 1;
    }

    int N; // Dimension of the upper triangular (square) matrices that will be taken from the input
    fscanf(input, "%d", &N); // Read dimension N of upper matrices from the input file

    // Allocate memory for matrices A, B, and the result matrix (matrixC)
    int *matrixA = (int *)malloc(N * N * sizeof(int));
    int *matrixB = (int *)malloc(N * N * sizeof(int));
    int *matrixC = (int *)malloc(N * N * sizeof(int));

    for (int i = 0; i < N * (N + 1) / 2; i++) {
        fscanf(input, "%d", &matrixA[i]); // Read the content of matrixA from the input file
    }

    for (int i = 0; i < N * (N + 1) / 2; i++) {
        fscanf(input, "%d", &matrixB[i]); // Read the content of matrixB from the input file
    }

    fclose(input); // Close the input file after reading

    // Perform matrix multiplication and store the result in matrixC
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += matrixA[i * N + k - (i * (i + 1)) / 2] * matrixB[k * N + j - (k * (k + 1)) / 2];
            }
            matrixC[i * N + j - (i * (i + 1)) / 2] = sum; // Index formulas calculated by using series summation
        }
    }

    printf("\n"); // Adding a blank line at the beginning for formatting convenience

    for (int i = 0; i < N * (N + 1) / 2; i++) {
        printf("%d ", matrixC[i]); // Print the resulting matrix in the 1D format
    }

    printf("\n\n\n"); // Seperating the 1D and 2D representations of matrixC with blank lines

    // Display the resulting matrixC in the specified format
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= i) {
                printf("%d", matrixC[i * N + j - (i * (i + 1)) / 2]); // Index formula calculated by using series summation
            } else {
                printf("0"); // Filling "empty" indices with zeros without allocating space for them in the array
            }
            if (j < N - 1) {
                printf("\t"); // Separating every value with tab characters for formatting
            }
        }
        printf("\n");
        if (i < N - 1) {
            printf("\n"); // Seperating the rows with blank lines for formatting
        }
    }

    // Free the memory allocated for the matrices to avoid memory leaks
    free(matrixA);
    free(matrixB);
    free(matrixC);

    return 0; // End of the main function and thus the program
}
