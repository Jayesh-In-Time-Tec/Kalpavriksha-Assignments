#include <stdio.h>

void swap(int *n1, int *n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

void selection_sort(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (array[j] < array[i])
            {
                swap(&array[i], &array[j]);
            }
        }
    }
}

int main()
{
    int size;
    printf("Enter size of array: \n");
    scanf("%d", &size);

    int array[size];
    printf("Enter elements of array: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    printf("Sorted array:\n");
    selection_sort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
