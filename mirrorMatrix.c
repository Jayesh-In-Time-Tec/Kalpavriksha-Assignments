#include <stdio.h>

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main()
{
    int n;
    printf("Enter size of matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter elements of matrix:\n");
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n; column++)
        {
            printf("Enter element at (%d %d): ", row, column);
            scanf("%d", &matrix[row][column]);
        }
    }
    for (int row = 0; row < n; row++)
    {
        for (int column = row + 1; column < n; column++)
        {
            swap(&matrix[row][column], &matrix[column][row]);
        }
    }
    printf("Matrix after transformation\n");
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n; column++)
        {
            printf("%d\t", matrix[row][column]);
        }
        printf("\n");
    }
}
