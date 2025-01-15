#include <stdio.h>
#include <stdlib.h>

int check_swap(int *interval_one, int *interval_two)
{
    if (interval_one[0] > interval_two[0])
        return 1;
    if (interval_one[0] == interval_two[0] && interval_one[1] > interval_two[1])
        return 1;
    return 0;
}

void swap_intervals(int **interval_one, int **interval_two)
{
    int temp_start = (*interval_one)[0], temp_end = (*interval_one)[1];
    (*interval_one)[0] = (*interval_two)[0];
    (*interval_one)[1] = (*interval_two)[1];
    (*interval_two)[0] = temp_start;
    (*interval_two)[1] = temp_end;
}

void sort_intervals(int **intervals, int intervalsSize)
{
    for (int i = 0; i < intervalsSize; i++)
    {
        for (int j = i + 1; j < intervalsSize; j++)
        {
            if (check_swap(intervals[i], intervals[j]))
            {
                swap_intervals(&intervals[i], &intervals[j]);
            }
        }
    }
}

int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    int **merged_intervals = NULL;
    sort_intervals(intervals, intervalsSize);
    *returnSize = 0;
    for (int i = 0; i < intervalsSize; i++)
    {
        if (i == 0 || intervals[i][0] > merged_intervals[(*returnSize) - 1][1])
        {
            merged_intervals = (int **)realloc(merged_intervals, ((*returnSize) + 1) * sizeof(int *));
            merged_intervals[*returnSize] = (int *)malloc(2 * sizeof(int));
            merged_intervals[*returnSize][0] = intervals[i][0];
            merged_intervals[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        }
        else
        {
            if (intervals[i][1] > merged_intervals[*returnSize - 1][1])
                merged_intervals[*returnSize - 1][1] = intervals[i][1];
        }
    }
    *returnColumnSizes = intervalsColSize;
    return merged_intervals;
}

void solution()
{
    printf("Enter matrix size:\n");
    int matrixSize, matrixColSize = 2;
    printf("Enter number of rows: ");
    scanf("%d", &matrixSize);

    printf("Enter elements of matrix:\n");
    int **matrix = (int **)malloc(matrixSize * sizeof(int *));
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = (int *)malloc(matrixColSize * sizeof(int));
        printf("Enter elements at start of interval %d: ", i);
        scanf("%d", &matrix[i][0]);
        printf("Enter elements at end of interval %d: ", i);
        scanf("%d", &matrix[i][1]);
    }

    int *mergeSize = (int *)malloc(sizeof(int));
    int **mergeColSize = (int **)malloc(sizeof(int *));
    int **merged_matrix = merge(matrix, matrixSize, &matrixColSize, mergeSize, mergeColSize);

    printf("Matrix before transformation:\n");
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        free(matrix[i]);
        printf("\n");
    }
    free(matrix);

    printf("Matrix after transformation:\n");
    for (int i = 0; i < *mergeSize; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\t", (merged_matrix)[i][j]);
        }
        printf("\n");
        free(merged_matrix[i]);
    }
    free(merged_matrix);
    free(mergeSize);
    free(mergeColSize);
}

int main()
{
    solution();
    return 0;
}
