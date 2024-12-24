#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int diagonalSum = 0;
    for (int i = 0; i < rows && i < cols; i++) {
        diagonalSum += matrix[i][i];
    }

    printf("Sum of the diagonal elements: %d\n", diagonalSum);
    return 0;
}
