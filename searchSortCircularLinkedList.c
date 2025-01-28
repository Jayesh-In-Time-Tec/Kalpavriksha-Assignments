#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
} linked_list;

void swap(int *first_number, int *second_number)
{
    int temporary = *first_number;
    *first_number = *second_number;
    *second_number = temporary;
}

void add_node(linked_list **head, int data)
{
    linked_list *new_node = (linked_list *)malloc(sizeof(linked_list));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        (*head)->next = *head;
        return;
    }
    linked_list *traverse_node = *head;
    while (traverse_node->next != *head)
    {
        traverse_node = traverse_node->next;
    }
    traverse_node->next = new_node;
    new_node->next = *head;
}

void sort_list(linked_list *head)
{
    linked_list *current_node = head;
    do
    {
        linked_list *smallest_node = current_node;
        linked_list *next_node = current_node->next;
        while (next_node != head)
        {
            if (next_node->data < smallest_node->data)
            {
                smallest_node = next_node;
            }
            next_node = next_node->next;
        }
        swap(&current_node->data, &smallest_node->data);
        current_node = current_node->next;
    } while (current_node->next != head);
}

void display_list(linked_list *head)
{
    linked_list *traverse_node = head;
    do
    {
        printf("%d ", traverse_node->data);
        traverse_node = traverse_node->next;
    } while (traverse_node != head);

    printf("\n");
}

int search_list(linked_list *head, int target)
{
    linked_list *traverse_node = head;
    int index = 0;
    do
    {
        if (traverse_node->data > target)
            return -1;
        if (traverse_node->data == target)
            return index;
        index++;
        traverse_node = traverse_node->next;
    } while (traverse_node != head);
    return -1;
}

int main()
{
    int data, target;
    linked_list *head = NULL;
    printf("Circular Linked List(unsorted): ");
    while (scanf("%d", &data) == 1)
    {
        add_node(&head, data);
        if (getchar() == '\n')
            break;
    }

    printf("Target: ");
    scanf("%d", &target);

    sort_list(head);
    printf("Sorted List:\n");
    display_list(head);
    printf("Element present at: %d", search_list(head, target));

    return 0;
}
