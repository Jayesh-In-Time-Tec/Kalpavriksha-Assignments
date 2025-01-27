#include <stdio.h>

void swap(int *n1, int *n2)
{
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

void sort(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (array[j] < array[j - 1])
                swap(&array[j], &array[j - 1]);
        }
    }
}

void print_sub_k(int *array, int size, int index, int sum, int target, int *subset, int subset_size)
{
    if (sum == target)
    {
        for (int i = 0; i < subset_size; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    for (int i = index; i < size; i++)
    {
        if (index != i && array[i] == array[i - 1])
            continue;

        subset[subset_size] = array[i];
        print_sub_k(array, size, i + 1, sum + array[i], target, subset, subset_size + 1);
    }
}

int main()
{
    int size, target;
    scanf("%d%d", &size, &target);

    int array[size];
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    sort(array, size);
    int subset[size];
    print_sub_k(array, size, 0, 0, target, subset, 0);

    return 0;
}
