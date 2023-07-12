#include <stdio.h>

#define MAX_SIZE 10

void subtractMatrices(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void displayMatrix(int mat[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[MAX_SIZE][MAX_SIZE];
    int mat2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    printf("Enter the number of rows (max %d): ", MAX_SIZE);
    scanf("%d", &rows);

    printf("Enter the number of columns (max %d): ", MAX_SIZE);
    scanf("%d", &cols);

    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    subtractMatrices(mat1, mat2, result, rows, cols);

    printf("Matrix 1:\n");
    displayMatrix(mat1, rows, cols);

    printf("Matrix 2:\n");
    displayMatrix(mat2, rows, cols);

    printf("Subtraction Result:\n");
    displayMatrix(result, rows, cols);

    return 0;
}

