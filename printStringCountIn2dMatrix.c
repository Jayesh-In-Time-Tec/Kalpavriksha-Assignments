#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    int count;
} string_structure;

int string_length(char *character)
{
    int length = 0;
    while (character[length++] != '\0')
        ;
    return length;
}

int string_compare(char *string1, char *string2)
{
    while (*string1 != '\0' && *string2 != '\0')
    {
        if (*string1 != *string2)
            return *string1 - *string2;
        string1++;
        string2++;
    }
    return *string1 - *string2;
}

void string_copy(char *to_copy, char *from_copy)
{
    while (*from_copy != '\0')
    {
        *to_copy = *from_copy;
        to_copy++;
        from_copy++;
    }
    *to_copy = '\0';
}

void print_string_count(char ***matrix, int row_count, int column_count)
{
    string_structure *names = (string_structure *)malloc(row_count * column_count * sizeof(string_structure));
    int names_size = 0;
    printf("\n\nStrings count greater than 1:\n");
    for (int row = 0; row < row_count; row++)
    {
        for (int column = 0; column < column_count; column++)
        {
            char *name = matrix[row][column];
            int found = -1;
            for (int row = 0; row < names_size; row++)
            {
                if (string_compare(names[row].name, name) == 0)
                {
                    found = row;
                    break;
                }
            }
            if (found != -1)
            {
                names[found].count++;
            }
            else
            {
                names[names_size].name = (char *)malloc((string_length(name) + 1) * sizeof(char));
                string_copy(names[names_size].name, name);
                names[names_size++].count = 1;
            }
        }
    }
    for (int row = 0; row < names_size; row++)
    {
        if (names[row].count > 1)
        {
            printf("%s : %d\n", names[row].name, names[row].count);
        }
    }
    printf("\n\n");
}

void free_matrix_memory(char ****matrix, int row_count, int column_count)
{
    for (int row = 0; row < row_count; row++)
    {
        for (int column = 0; column < column_count; column++)
        {
            free((*matrix)[row][column]);
        }
        free((*matrix)[row]);
    }
    free(*matrix);
}

void take_matrix_input(char ****matrix, int *row_count, int *column_count)
{
    printf("\n\nEnter size of matrix\n");
    printf("Enter number of rows in matrix: ");
    scanf("%d", row_count);
    printf("Enter number of columns in matrix: ");
    scanf("%d", column_count);

    *matrix = (char ***)malloc(*row_count * sizeof(char **));
    printf("\n\nEnter elements of matrix:\n");
    for (int row = 0; row < *row_count; row++)
    {
        (*matrix)[row] = (char **)malloc(*column_count * sizeof(char *));
        for (int column = 0; column < *column_count; column++)
        {
            char name[50];
            printf("Enter element at (%d %d): ", row, column);
            scanf("%s", name);
            (*matrix)[row][column] = (char *)malloc((string_length(name) + 1) * sizeof(char));
            string_copy((*matrix)[row][column], name);
        }
    }
}

void solution()
{
    char ***matrix = NULL;
    int row_count, column_count;
    take_matrix_input(&matrix, &row_count, &column_count);

    print_string_count(matrix, row_count, column_count);
    free_matrix_memory(&matrix, row_count, column_count);
}

int main()
{
    solution();

    return 0;
}
