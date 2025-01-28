#include <stdio.h>

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int pivot(int *array, int l, int h)
{
    int ind1 = l + 1, ind2 = l + 1;
    while (ind2 <= h)
    {
        if (array[ind2] >= array[l])
        {
            ind2++;
        }
        else
        {
            swap(&array[ind2], &array[ind1]);
            ind1++;
            ind2++;
        }
    }
    swap(&array[ind1 - 1], &array[l]);
    return ind1 - 1;
}

void quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int ind = pivot(array, low, high);
        quick_sort(array, low, ind - 1);
        quick_sort(array, ind + 1, high);
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
    quick_sort(array, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
