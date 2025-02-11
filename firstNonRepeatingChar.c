#include <stdio.h>
#include <string.h>

typedef struct c
{
    char ch;
    int ind;
    int count;
} map;

int main()
{
    char string[100000];
    scanf("%s", string);
    map mp[26];
    int m_ind = -1;

    for (int i = 0; i < strlen(string); i++)
    {
        char ch = string[i];
        int ind = -1;
        for (int j = 0; j <= m_ind; j++)
        {
            if (mp[j].ch == ch)
            {
                ind = j;
                break;
            }
        }
        if (ind != -1)
        {
            mp[ind].count++;
        }
        else
        {
            mp[++m_ind].ch = ch;
            mp[m_ind].count = 1;
            mp[m_ind].ind = m_ind;
        }
        int find = -1;
        for (int j = 0; j <= m_ind; j++)
        {
            if (mp[j].ch == ch && mp[j].count == 1)
            {
                find = j;
                break;
            }
        }
        if (find != -1)
        {
            printf("%c", mp[find].ch);
        }
        else
            printf("-1");
    }

    return 0;
}
