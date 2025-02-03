#include <stdio.h>
#include <string.h>

int main()
{
    char s1[200];
    char stk1[200];
    int ind1 = -1, ind2 = -1;
    char s2[200];
    char stk2[200];
    printf("s: ");
    scanf("%s", s1);
    printf("t: ");
    scanf("%s", s2);

    for (int i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == '#')
        {
            if (ind1 != -1)
                ind1--;
        }
        else
        {
            stk1[++ind1] = s1[i];
        }
    }
    for (int i = 0; i < strlen(s2); i++)
    {
        if (s2[i] == '#')
        {
            if (ind2 != -1)
                ind2--;
        }
        else
        {
            stk2[++ind2] = s2[i];
        }
    }
    if (ind1 != ind2)
    {
        printf("FALSE\n");
        return 0;
    }
    for (int i = 0; i <= ind1; i++)
    {
        if (stk1[i] != stk2[i])
        {
            printf("FALSE\n");
            return 0;
        }
    }
    printf("TRUE\n");

    return 0;
}
