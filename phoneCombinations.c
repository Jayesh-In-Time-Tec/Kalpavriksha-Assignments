#include <stdio.h>
#include <stdlib.h>

int string_length(char *string)
{
    int length = 0;
    while (string[++length] != '\0')
        ;
    return length;
}

void string_copy(char *to_string, char *from_string)
{
    int index = 0;
    while (from_string[index] != '\0')
    {
        to_string[index] = from_string[index];
        index++;
    }
    to_string[index] = '\0';
}

void find_all_combinations(char *digits, char *word_map[], char ***all_combinations, char string[],
                           int *returnSize, int iterator)
{
    if (iterator == string_length(digits))
    {
        string[iterator] = '\0';

        *all_combinations = realloc(*all_combinations, (*returnSize + 1) * sizeof(char *));

        (*all_combinations)[*returnSize] = malloc((string_length(digits) + 1) * sizeof(char));
        string_copy((*all_combinations)[*returnSize], string);

        (*returnSize)++;
        return;
    }

    char *word = word_map[digits[iterator] - '2'];
    for (int i = 0; i < string_length(word); i++)
    {
        string[iterator] = word[i];
        find_all_combinations(digits, word_map, all_combinations, string, returnSize, iterator + 1);
    }
}

char **letterCombinations(char *digits, int *returnSize)
{
    if (digits == NULL || string_length(digits) == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    char *word_map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **all_combinations = NULL;
    char string[string_length(digits) + 1];
    *returnSize = 0;

    find_all_combinations(digits, word_map, &all_combinations, string, returnSize, 0);

    return all_combinations;
}

void solution()
{
    char digits[10];
    printf("Enter digits with length less than 5 in range(2-9): ");
    scanf("%s", digits);
    int returnSize;
    char **all_combinations = letterCombinations(digits, &returnSize);
    printf("Possible combinations:\n");
    for (int i = 0; i < returnSize; i++)
    {
        if (i == 0)
            printf("[");
        printf("%s", all_combinations[i]);
        if (i != returnSize - 1)
        {
            printf(",\t");
        }
        else
            printf("]\n");
    }
}

int main()
{
    solution();
    return 0;
}
