#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **words = NULL;
    int w_size = -1;
    char word[100];
    while (scanf("%s", word) == 1)
    {
        w_size++;
        words = realloc(words, (w_size + 1) * sizeof(char *));
        words[w_size] = (char *)malloc(strlen(word));
        strcpy(words[w_size], word);
        if (getchar() == '\n')
            break;
    }

    int alp1[26];
    int alp2[26];
    int maxx = 0;
    for (int i = 0; i <= w_size; i++)
    {
        for (int j = 0; j <= w_size; j++)
        {
            if (i == j)
                continue;
            for (int k = 0; k < 26; k++)
            {
                alp1[k] = 0;
                alp2[k] = 0;
            }
            for (int l = 0; l < strlen(words[i]); l++)
            {
                alp1[words[i][l] - 'a']++;
            }
            for (int l = 0; l < strlen(words[j]); l++)
            {
                alp2[words[j][l] - 'a']++;
            }
            int check = 1;
            for (int l = 0; l < 26; l++)
            {
                if (alp1[l] != 0 && alp2[l] != 0)
                {
                    check = 0;
                    break;
                }
            }
            if (check == 1 && maxx < strlen(words[i]) * strlen(words[j]))
            {
                maxx = strlen(words[i]) * strlen(words[j]);
            }
        }
    }
    printf("%d", maxx);
    return 0;
}
