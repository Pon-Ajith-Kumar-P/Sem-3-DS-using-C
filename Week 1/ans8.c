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

    int sumAboveDiagonal = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < cols; j++) {
            sumAboveDiagonal += matrix[i][j];
        }
    }

    printf("Sum of the elements above the main diagonal: %d\n", sumAboveDiagonal);
    return 0;
}
