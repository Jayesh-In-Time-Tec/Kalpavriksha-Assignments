#include <stdio.h>
#include <stdlib.h>

struct queueUsingArray
{
    int front;
    int back;
    int size;
    int *array;
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
    if (size() == 0)
    {
        queue.front++;
    }
    queue.array[++queue.back] = data;
    queue.size++;
    printf("Element added to queue\n");
}

void dequeue()
{
    if (size() == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    queue.front++;
    queue.size--;
    printf("Element poped from queue successfully\n");
}

void peek()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Element at front: %d\n", queue.array[queue.front]);
}

int main()
{
    queue.front = -1;
    queue.back = -1;
    queue.size = 0;

    int operations;
    printf("Enter number of operations:\n");
    scanf("%d", &operations);
    queue.array = (int *)malloc(operations * sizeof(int));

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
            if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 5)
                break;
            while (getchar() != '\n')
                ;
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
            printf("Size of Queue is: %d\n", size());
            break;
        }
    }

    return 0;
}
