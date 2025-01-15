#include <stdio.h>

int string_length(char *string)
{
    int length = 0;
    while (string[++length] != '\0')
        ;
    return length;
}

int is_not_repeating(char *s, int start, int end)
{
    int character_array[256] = {0};
    for (int i = start; i <= end; i++)
    {
        if (character_array[s[i]])
        {
            return 0;
        }
        character_array[s[i]]++;
    }
    return 1;
}

int lengthOfLongestSubstring(char *s)
{
    if (string_length(s) == 0)
        return 0;
    int max_length = 1;
    for (int i = 0; i < string_length(s); i++)
    {
        for (int j = i + 1; j < string_length(s); j++)
        {
            if (max_length < j - i + 1 && is_not_repeating(s, i, j))
            {
                max_length = j - i + 1;
            }
        }
    }
    return max_length;
}

void solution()
{
    char s[100];
    printf("Enter the string: ");
    scanf("%s", s);
    printf("Length of longest substring with non repeating character: %d", lengthOfLongestSubstring(s));
}

int main()
{
    solution();
    return 0;
}
