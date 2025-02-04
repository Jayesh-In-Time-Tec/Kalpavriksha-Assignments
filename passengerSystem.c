#include <stdio.h>
#include <stdlib.h>

#define MAX 100

enum priority
{
    GENERAL,
    SENIOR_CITIZEN,
    VIP
};

typedef struct
{
    int id;
    enum priority level;
    char name[50];
} passenger;

typedef struct
{
    passenger arr[MAX];
    int size;
} queue;

queue que;

int string_compare(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int get_passenger_level(char *level)
{
    if (string_compare(level, "VIP") == 0)
        return VIP;
    if (string_compare(level, "GENERAL") == 0)
        return GENERAL;
    return SENIOR_CITIZEN;
}

void enqueue()
{
    if (que.size >= MAX)
    {
        printf("Queue is full\n");
        return;
    }

    passenger temporary;
    char level[50];
    scanf("%d", &temporary.id);
    scanf("%s", level);
    temporary.level = get_passenger_level(level);
    getchar();
    scanf("%s", temporary.name);

    int i = que.size - 1;
    while (i >= 0 && que.arr[i].level < temporary.level)
    {
        que.arr[i + 1] = que.arr[i];
        i--;
    }
    que.arr[i + 1] = temporary;
    que.size++;
}

void print_level(int value)
{
    switch (value)
    {
    case GENERAL:
        printf("GENERAL\n");
        break;
    case SENIOR_CITIZEN:
        printf("SENIOR_CITIZEN\n");
        break;
    case VIP:
        printf("VIP\n");
        break;
    }
}

void dequeue()
{
    if (que.size == 0)
    {
        printf("List is empty\n");
        return;
    }

    printf("Serving passenger: ID:%d, Name:%s, Type: ", que.arr[0].id, que.arr[0].name);
    print_level(que.arr[0].level);

    for (int i = 1; i < que.size; i++)
    {
        que.arr[i - 1] = que.arr[i];
    }
    que.size--;
}

void print_list()
{
    if (que.size == 0)
    {
        printf("No waiting passengers\n");
        return;
    }
    printf("Waiting passengers:\n");
    for (int i = 0; i < que.size; i++)
    {
        printf("ID:%d, Name:%s, Level: ", que.arr[i].id, que.arr[i].name);
        print_level(que.arr[i].level);
    }
}

int main()
{
    que.size = 0;
    int operations;
    scanf("%d", &operations);

    while (operations--)
    {
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print_list();
            break;
        }
    }
    return 0;
}
