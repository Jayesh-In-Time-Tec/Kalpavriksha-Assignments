#include <stdio.h>

int linear_search(int *array, int size, int target)
{
    int index = 0;
    while (index < size && array[index] != target)
    {
        index++;
    }
    if (index < size)
        return index;
    return -1;
}

int main()
{
    int size, target;
    printf("Enter size of array: \n");
    scanf("%d", &size);

    int array[size];
    printf("Enter elements of array: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &array[i]);

    printf("Enter target value:\n");
    scanf("%d", &target);
    int index = linear_search(array, size, target);
    if (index == -1)
        printf("Element does not exists\n");
    else
        printf("ELement exist at position %d", index + 1);
    return 0;
}
