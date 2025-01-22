#include <stdio.h>
#include <stdlib.h>

typedef struct linklist
{
    int data;
    struct linklist *next;
} List;

void addX(List **head, int val)
{

    List *node = (List *)malloc(sizeof(List));
    node->data = val;
    node->next = NULL;
    if (*head == NULL)
    {
        *head = node;
        return;
    }
    node->next = *head;
    *head = node;
}

int sum_of_window(List *head, int k)
{
    List *temp = head;
    int sum = 0;
    while (k-- && temp)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int main()
{
    List *head = NULL;
    int operations, window;
    scanf("%d", &operations);
    scanf("%d", &window);
    while (operations--)
    {
        while (getchar() != '\n')
            ;
        char choice;
        scanf("%c", &choice);
        if (choice == 'A')
        {
            int val;
            scanf("%d", &val);
            addX(&head, val);
        }
        else if (choice == 'S')
        {
            int sum = sum_of_window(head, window);
            printf("%d\n", sum);
        }
        else
            printf("Invalid\n");
    }

    return 0;
}
