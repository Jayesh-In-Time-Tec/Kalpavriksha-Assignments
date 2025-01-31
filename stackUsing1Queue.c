#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
} LinkedList;

struct queue
{
    LinkedList *front;
    LinkedList *back;
    int size;
} queue;

int is_empty()
{
    return queue.size == 0;
}

int size()
{
    return queue.size;
}

void enqueue(int data)
{
    LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = data;

    if (queue.size == 0)
    {
        node->next = NULL;
        queue.front = node;
        queue.back = node;
    }

    else
    {
        queue.back->next = node;
        queue.back = queue.back->next;
    }

    queue.size++;
}

int dequeue()
{
    if (queue.size == 0)
    {
        return 0;
    }

    queue.size--;
    queue.front = queue.front->next;
    return 1;
}

void peek()
{
    if (queue.size == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", queue.front->data);
}

void push(int data)
{
    enqueue(data);
    for (int i = 0; i < queue.size - 1; i++)
    {
        int data = queue.front->data;
        dequeue();
        enqueue(data);
    }
    printf("Element added successfully\n");
}

void pop()
{
    if (dequeue())
        printf("Element popped successfully\n");
    else
        printf("Stack is empty\n");
}

int main()
{
    queue.front = NULL;
    queue.back = NULL;
    queue.size = 0;
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
            printf("Size of Stack is: %d\n", size());
            break;
        }
    }

    return 0;
}
