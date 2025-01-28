#include <stdio.h>

void swap(int *n1, int *n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

void insertion_sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1])
        {
            swap(&array[j], &array[j + 1]);
            j--;
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
    insertion_sort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
