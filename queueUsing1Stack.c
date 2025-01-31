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
    stack.size--;
    LinkedList *to_delete = stack.head;
    stack.head = stack.head->next;
    free(to_delete);
}

int peek_stack()
{
    return stack.head->data;
}

void enqueue(int data)
{
    push(data);
    printf("Element added successfully\n");
}

void dequeue()
{
    if (size() == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    if (size() == 1)
    {
        printf("Element removed successfully\n");
        pop();
        return;
    }
    int top = peek_stack();
    pop();
    dequeue();
    push(top);
}

void peek()
{
    if (size() == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    if (size() == 1)
    {
        printf("Front element: %d\n", peek_stack());
        return;
    }
    int top = peek_stack();
    pop();
    peek();
    push(top);
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
        printf("1.Add an element to queue:\n");
        printf("2.Remove the front element from queue:\n");
        printf("3.Retrive the front element:\n");
        printf("4.Check if queue is empty:\n");
        printf("5.Return number of elements in queue:\n\n");

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
            printf("Enter element to push to the queue: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            if (is_empty())
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;

        case 5:
            printf("Size of queue is: %d\n", size());
            break;
        }
    }

    free_stack();

    return 0;
}
