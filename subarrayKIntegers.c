#include <stdio.h>

int is_valid_subarray(int *array, int start, int end, int k)
{
    int map[end - start + 1];
    int count = 0, map_ind = -1;
    for (int i = start; i <= end; i++)
    {
        int found = 0;
        for (int j = 0; j <= map_ind; j++)
        {
            if (map[j] == array[i])
            {
                found = 1;
                break;
            }
        }
        if (found != 1)
        {
            count++;
            map[++map_ind] = array[i];
        }
    }
    return count == k;
}

int main()
{
    int array[100];
    int size = 0, k, count_valid = 0;

    while (scanf("%d", &array[size++]) == 1)
    {
        if (getchar() == '\n')
            break;
    }

    scanf("%d", &k);

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (is_valid_subarray(array, i, j, k) == 1)
            {
                count_valid++;
            }
        }
    }

    printf("%d", count_valid);

    return 0;
}
