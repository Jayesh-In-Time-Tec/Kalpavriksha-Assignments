#include <stdio.h>
#include <stdlib.h>

int diagonalSum(int **mat, int matSize, int *matColSize)
{
    int start_row = 0, end_row = matSize - 1, row = 0, diagonal_sum = 0;
    while (row < matSize)
    {
        if (start_row == end_row)
        {
            diagonal_sum += mat[row][start_row];
        }
        else
        {
            diagonal_sum += mat[row][start_row] + mat[row][end_row];
        }
        start_row++;
        end_row--;
        row++;
    }
    return diagonal_sum;
}

void solution()
{
    printf("Enter matrix size:\n");
    int matrixSize, matrixColSize;
    printf("Enter number of rows: ");
    scanf("%d", &matrixSize);
    printf("Enter number of columns: ");
    scanf("%d", &matrixColSize);

    printf("Enter elements of matrix:\n");
    int **matrix = (int **)malloc(matrixSize * sizeof(int *));
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = (int *)malloc(matrixColSize * sizeof(int));
        for (int j = 0; j < matrixColSize; j++)
        {
            printf("Enter elements at (%d,%d): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    diagonalSum(matrix, matrixSize, &matrixColSize);

    printf("Diagonal sum of matrix: %d\n", diagonalSum(matrix, matrixSize, &matrixColSize));

    for (int i = 0; i < matrixSize; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    solution();
    return 0;
}
