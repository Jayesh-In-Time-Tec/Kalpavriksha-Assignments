#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
} LinkedList;

struct Queue
{
    LinkedList *front;
    LinkedList *back;
    int size;
};

struct Queue q1 = {NULL, NULL, 0};
struct Queue q2 = {NULL, NULL, 0};

int is_empty()
{
    return q1.size == 0;
}

int size()
{
    return q1.size;
}

void enqueue(struct Queue *queue, int data)
{
    LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = data;
    node->next = NULL;

    if (queue->size == 0)
    {
        queue->front = node;
        queue->back = node;
    }
    else
    {
        queue->back->next = node;
        queue->back = node;
    }
    queue->size++;
}

int dequeue(struct Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    int removedData = queue->front->data;
    queue->front = queue->front->next;
    queue->size--;
    return removedData;
}

void push(int data)
{
    enqueue(&q2, data);
    while (q1.size > 0)
    {
        enqueue(&q2, dequeue(&q1));
    }

    struct Queue temp = q1;
    q1 = q2;
    q2 = temp;
}

void pop()
{
    if (is_empty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped: %d\n", dequeue(&q1));
}

void top()
{
    if (is_empty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", q1.front->data);
}

int main()
{
    int operations;
    printf("Enter number of operations:\n");
    scanf("%d", &operations);

    while (operations--)
    {
        printf("\nEnter a choice:\n");
        printf("1. Push an element onto the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Retrieve the top element of the stack\n");
        printf("4. Check if the stack is empty\n");
        printf("5. Return the number of elements in the stack\n");

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
            printf("Enter element to push onto the stack: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            top();
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
    return 0;
}
