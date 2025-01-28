#include <stdio.h>

void merge(int *array, int l, int m, int h)
{
    int n1 = m - l + 1, n2 = h - m;
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = array[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        arr2[i] = array[m + 1 + i];
    }
    int i1 = 0, i2 = 0, ind = l;
    while (i1 < n1 && i2 < n2)
    {
        if (arr1[i1] <= arr2[i2])
        {
            array[ind] = arr1[i1++];
        }
        else
        {
            array[ind] = arr2[i2++];
        }
        ind++;
    }
    while (i1 < n1)
    {
        array[ind++] = arr1[i1++];
    }
    while (i2 < n2)
    {
        array[ind++] = arr2[i2++];
    }
}

void merge_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int mid = low + ((high - low) >> 1);
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge(array, low, mid, high);
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
    merge_sort(array, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
