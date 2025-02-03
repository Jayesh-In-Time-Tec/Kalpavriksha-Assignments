#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
} List;

List *initialize_node(int data)
{
    List *node = (List *)malloc(sizeof(List));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(List **head, int data)
{
    List *node = initialize_node(data);

    if (*head == NULL)
    {
        *head = node;
        return;
    }

    List *temporary = *head;
    while (temporary->next)
    {
        temporary = temporary->next;
    }

    temporary->next = node;
}

void display(List *head, char *string)
{
    printf("%s\n", string);
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void create_list(List **head)
{
    int data;
    printf("Enter list elements: ");
    while (scanf("%d", &data) == 1)
    {
        add_node(head, data);
        if (getchar() == '\n')
            break;
    }
}

void split(List **head)
{
    List *even = initialize_node(-1);
    List *odd = initialize_node(-1);
    List *traversal = *head;

    while (traversal)
    {
        List *position;
        if (traversal->data & 1)
        {
            position = odd;
            while (position->next && position->next->data > traversal->data)
            {
                position = position->next;
            }
        }
        else
        {
            position = even;
            while (position->next && position->next->data < traversal->data)
            {
                position = position->next;
            }
        }

        List *next = traversal->next;
        traversal->next = position->next;
        position->next = traversal;
        traversal = next;
    }

    if (even->next == NULL)
    {
        *head = odd->next;
    }
    else
    {
        *head = even->next;
        while (even->next)
        {
            even = even->next;
        }
        even->next = odd->next;
    }
}

void free_list(List *head)
{
    while (head)
    {
        List *to_delete = head;
        head = head->next;
        free(to_delete);
    }
}

int main()
{
    List *head = NULL;
    create_list(&head);
    display(head, "Input list:");

    split(&head);
    display(head, "List after transformation:");

    free_list(head);

    return 0;
}
