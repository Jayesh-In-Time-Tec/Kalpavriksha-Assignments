#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
} LinkedList;

typedef struct stk
{
    LinkedList *head;
    int size;
} stack_struct;

stack_struct *stack1, *stack2;

int is_empty(stack_struct *stack)
{
    return stack->head == NULL;
}

int size(stack_struct *stack)
{
    return stack->size;
}

void push(stack_struct *stack, int data)
{
    LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = data;
    stack->size++;

    if (is_empty(stack))
    {
        node->next = NULL;
        stack->head = node;
        return;
    }

    node->next = stack->head;
    stack->head = node;
}

void pop(stack_struct *stack)
{
    stack->size--;
    LinkedList *to_delete = stack->head;
    stack->head = stack->head->next;
    free(to_delete);
}

int peek_stack(stack_struct *stack)
{
    return stack->head->data;
}

void enqueue(int data)
{
    while (size(stack1) != 0)
    {
        int top = peek_stack(stack1);
        pop(stack1);
        push(stack2, top);
    }
    push(stack1, data);
    while (size(stack2) != 0)
    {
        int top = peek_stack(stack2);
        pop(stack2);
        push(stack1, top);
    }
    printf("ELement added successfully\n");
}

void dequeue()
{
    if (size(stack1) == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    pop(stack1);
    printf("ELement popped from queue\n");
}

void peek()
{
    if (size(stack1) == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", peek_stack(stack1));
}

void free_stack(stack_struct *stack)
{
    LinkedList *trav = stack->head;
    while (trav)
    {
        LinkedList *to_delete = trav;
        trav = trav->next;
        free(to_delete);
    }
}

int main()
{
    stack1 = (stack_struct *)malloc(sizeof(stack_struct));
    stack2 = (stack_struct *)malloc(sizeof(stack_struct));
    stack1->head = NULL;
    stack1->size = 0;
    stack2->head = NULL;
    stack2->size = 0;
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
            if (is_empty(stack1))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;

        case 5:
            printf("Size of queue is: %d\n", size(stack1));
            break;
        }
    }

    free_stack(stack1);
    free_stack(stack2);

    return 0;
}
