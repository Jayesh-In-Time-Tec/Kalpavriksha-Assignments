#include <stdio.h>

void swap(char *c1, char *c2)
{
    char temp;
    temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

int string_length(char *string)
{
    int length = 0;
    while (string[++length] != '\0')
        ;
    return length;
}

int check_if_valid(char *s)
{
    int index = 1;
    while (s[index] != '\0')
    {
        if (s[index] == s[index - 1])
            return 0;
        index++;
    }
    return 1;
}

int find_possible_permutation(char *s, int index)
{
    if (index == string_length(s))
    {
        if (check_if_valid(s))
            return 1;
        return 0;
    }
    for (int i = index; i < string_length(s); i++)
    {
        swap(&s[index], &s[i]);
        if (find_possible_permutation(s, index + 1))
            return 1;
        swap(&s[index], &s[i]);
    }
    return 0;
}

char *reorganizeString(char *s)
{
    if (find_possible_permutation(s, 0))
        return s;
    s[0] = '\0';
    return s;
}

void solution()
{
    char s[100];
    printf("Enter the string: ");
    scanf("%s", s);
    if (string_length(s) != 0)
        printf("Rearranged string: %s", reorganizeString(s));
    else
        printf("No arrangement possible\n");
}

int main()
{
    solution();
    return 0;
}
