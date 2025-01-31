#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
} LinkedList;

struct que
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
    printf("Element added successfully\n");

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

void dequeue()
{
    if (queue.size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Element popped successfully\n");
    queue.size--;
    queue.front = queue.front->next;
}

void peek()
{
    if (queue.size == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue.front->data);
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
        printf("1.Add an element to the queue:\n");
        printf("2.Remove the front element from the queue:\n");
        printf("3.Retrieve the front element without removing it:\n");
        printf("4.Check if the queue is empty:\n");
        printf("5.Return the number of elements in the queue:\n");

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

    return 0;
}
