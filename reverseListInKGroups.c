#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
} Linklist;

Linklist *head = NULL;

void create_node(int data)
{
    Linklist *node = (Linklist *)malloc(sizeof(Linklist));
    node->data = data;
    node->next = NULL;

    if (head == NULL)
    {
        head = node;
        return;
    }

    Linklist *traverse = head;
    while (traverse->next)
    {
        traverse = traverse->next;
    }
    traverse->next = node;
}

void *reverse(Linklist *start, Linklist *end)
{
    Linklist *previous = NULL;
    Linklist *strt = start;

    while (strt != end)
    {
        Linklist *next = strt->next;
        strt->next = previous;
        previous = strt;
        strt = next;
    }
}

void reverse_k_groups(int groups)
{
    Linklist *traverse = head;
    Linklist *prev_end_node = (Linklist *)malloc(sizeof(Linklist));
    int is_reverse = 1, first_traverse = 1;
    groups--;

    while (traverse)
    {
        int iterator = groups;
        Linklist *strt = traverse;
        while (traverse && iterator--)
        {
            traverse = traverse->next;
        }

        if (traverse == NULL)
            return;

        if (is_reverse)
        {
            Linklist *next_node = traverse->next;
            reverse(strt, traverse->next);
            strt->next = next_node;
            if (first_traverse)
            {
                head = traverse;
                first_traverse = 0;
            }
            prev_end_node->next = traverse;
            traverse = next_node;
            is_reverse = 0;
        }

        else
        {
            prev_end_node = traverse;
            traverse = traverse->next;
            is_reverse = 1;
        }
    }
}

void display()
{
    printf("Transformed list:\n");
    Linklist *traverse = head;

    while (traverse)
    {
        printf("%d->", traverse->data);
        traverse = traverse->next;
    }
    printf("NULL\n");
}

int main()
{
    int data, groups;
    printf("Enter list data: ");
    while (scanf("%d", &data) == 1)
    {
        create_node(data);
        if (getchar() == '\n')
            break;
    }

    printf("Enter group size: ");
    scanf("%d", &groups);

    reverse_k_groups(groups);
    display();

    return 0;
}
