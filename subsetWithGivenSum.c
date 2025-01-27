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

void print_subset_with_k_sum(int *array, int size, int index, int target, int *subset, int subset_size)
{
    if (target == 0)
    {
        for (int i = 0; i < subset_size; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("\n");
    }

    for (int i = index; i < size; i++)
    {
        if (index != i && array[i] == array[i - 1])
            continue;

        subset[subset_size] = array[i];
        print_subset_with_k_sum(array, size, i + 1, target - array[i], subset, subset_size + 1);
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
    print_subset_with_k_sum(array, size, 0, target, subset, 0);

    return 0;
}
