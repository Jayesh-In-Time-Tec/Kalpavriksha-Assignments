#include <stdio.h>
#include <stdlib.h>

enum priority
{
    GENERAL,
    SENIOR_CITIZEN,
    VIP
};

typedef struct psg
{
    int id;
    enum priority level;
    char name[50];
} passenger;

typedef struct queue
{
    passenger passenger_data;
    struct queue *next;
} queue;

queue *head = NULL;

int string_compare(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            return 1;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int get_passenger_level(char *level)
{
    if (string_compare(level, "VIP") == 0)
        return 3;

    if (string_compare(level, "GENERAL") == 0)
        return 1;

    return 2;
}

void enqueue()
{
    queue *node = (queue *)malloc(sizeof(queue));
    char level[50];
    scanf("%d", &node->passenger_data.id);

    scanf("%s", level);
    node->passenger_data.level = get_passenger_level(level);

    getchar();
    scanf("%s", node->passenger_data.name);

    if (head == NULL)
    {
        node->next = NULL;
        head = node;
        return;
    }

    queue *traverse = head;
    queue *previous = NULL;
    while (traverse && traverse->passenger_data.level >= node->passenger_data.level)
    {
        previous = traverse;
        traverse = traverse->next;
    }

    if (previous == NULL)
    {
        node->next = head;
        head = node;
        return;
    }

    previous->next = node;
    node->next = traverse;
}

void print_level(int value)
{
    switch (value)
    {
    case 1:
        printf("GENERAL\n");
        break;

    case 2:
        printf("SENIOR_CITIZEN\n");
        break;

    case 3:
        printf("VIP\n");
        break;
    }
}

void dequeue()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Serving passenger: ");
    printf("ID:%d,\t Name:%s,\t Type:\n", head->passenger_data.id, head->passenger_data.name);
    print_level(head->passenger_data.level);
    head = head->next;
}

void print_list()
{
    queue *traverse = head;
    printf("Waiting passengers:\n");
    while (traverse)
    {
        printf("ID:%d,\t Name:%s,\t Level:", traverse->passenger_data.id, traverse->passenger_data.name);
        print_level(traverse->passenger_data.level);
        traverse = traverse->next;
    }
}

int main()
{
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
