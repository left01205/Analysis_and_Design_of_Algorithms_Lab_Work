#include <stdio.h>

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to multiply two matrices
void multiplyMatrices(int firstMatrix[][3], int secondMatrix[][3], int result[][3], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnSecond; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < columnFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    // Example usage of GCD function
    int num1 = 56, num2 = 98;
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));

    // Example usage of matrix multiplication
    int firstMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int secondMatrix[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int result[3][3];
    multiplyMatrices(firstMatrix, secondMatrix, result, 3, 3, 3, 3);

    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}