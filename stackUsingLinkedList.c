#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
} LinkedList;

struct stk
{
    LinkedList *head;
    int size;
} stack;

int is_empty()
{
    return stack.head == NULL;
}

int size()
{
    return stack.size;
}

void push(int data)
{
    LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = data;
    stack.size++;
    printf("Element added successfully\n");

    if (is_empty())
    {
        node->next = NULL;
        stack.head = node;
        return;
    }

    node->next = stack.head;
    stack.head = node;
}

void pop()
{
    if (is_empty())
    {
        printf("Stack is empty\n");
        return;
    }
    stack.size--;
    LinkedList *to_delete = stack.head;
    stack.head = stack.head->next;
    free(to_delete);
    printf("Element poped successfully\n");
}

void peek()
{
    if (is_empty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element in stack: %d\n", stack.head->data);
}

void free_stack()
{
    LinkedList *trav = stack.head;
    while (trav)
    {
        LinkedList *to_delete = trav;
        trav = trav->next;
        free(to_delete);
    }
}

int main()
{
    stack.head = NULL;
    int operations;
    printf("Enter number of operations:\n");
    scanf("%d", &operations);

    while (operations--)
    {
        printf("\n\nEnter a choice:\n");
        printf("1.To push an element to the stack:\n");
        printf("2.To pop an element from the stack:\n");
        printf("3.To print the element at top of the stack:\n");
        printf("4.To check is stack is empty:\n");
        printf("5.To print size of stack:\n");

        int choice, data;
        while (1)
        {
            while (getchar() != '\n')
                ;
            if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 5)
                break;
            printf("Enter a valid choice: ");
        }

        switch (choice)
        {
        case 1:
            printf("Enter element to push to the stack: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            if (is_empty())
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;

        case 5:
            printf("Size of stack is: %d\n", size());
            break;
        }
    }

    free_stack();

    return 0;
}
