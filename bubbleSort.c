#include <stdio.h>

void swap(int *n1, int *n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

void bubble_sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

int main()
{
    int size;
    printf("Enter size of array\n");
    scanf("%d", &size);

    int array[size];
    printf("Enter elements of array\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    bubble_sort(array, size);
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
