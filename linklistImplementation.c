#include <stdio.h>
#include <stdlib.h>

typedef struct linklist
{
    int data;
    struct linklist *next;
} Linklist;

Linklist *initialize_node();

void add_to_end(Linklist **head);
void add_at_begining(Linklist **head);
void add_at_position(Linklist **head);
void display_list(Linklist *head);
void update_at_position(Linklist *head);
void delete_first_element(Linklist **head);
void delete_last_element(Linklist **head);
void delete_at_position(Linklist **head);

void operate(Linklist **head);

void free_list_memory(Linklist **head);

int main()
{
    Linklist *head = NULL;
    printf("Enter the number of operations to be performed: ");
    int operations;
    scanf("%d", &operations);

    for (int operation = 1; operation <= operations; operation++)
    {
        printf("\n\nOperation number (%d):", operation);
        operate(&head);
    }
    printf("All operations completed successfully\n\n");

    free_list_memory(&head);

    return 0;
}

Linklist *initialize_node()
{
    int data;
    printf("\nEnter value for node: ");
    scanf("%d", &data);

    Linklist *node = (Linklist *)malloc(sizeof(Linklist));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_to_end(Linklist **head)
{
    Linklist *node = initialize_node();

    if (*head == NULL)
    {
        *head = node;
        printf("Element added successfully\n");
        return;
    }

    Linklist *temporary_node = *head;

    while (temporary_node->next != NULL)
    {
        temporary_node = temporary_node->next;
    }
    temporary_node->next = node;
    printf("Element added successfully\n");
}

void add_at_begining(Linklist **head)
{
    if (*head == NULL)
    {
        add_to_end(head);
        return;
    }

    Linklist *node = initialize_node();
    node->next = *head;
    *head = node;
    printf("Element added successfully\n");
}

void add_at_position(Linklist **head)
{
    int position;
    printf("\nEnter valid position to add element: ");
    scanf("%d", &position);

    if (position == 1)
    {
        add_at_begining(head);
        return;
    }

    Linklist *temporary_node = *head;
    position -= 2;
    while (temporary_node && position--)
    {
        temporary_node = temporary_node->next;
    }

    if (!temporary_node)
    {
        printf("Invalid position\n");
        return;
    }

    Linklist *node = initialize_node();
    node->next = temporary_node->next;
    temporary_node->next = node;
    printf("Element added successfully\n");
}

void display_list(Linklist *head)
{
    printf("\nList display:\n");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void update_at_position(Linklist *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int position, data;
    printf("\nEnter a position to update element: ");
    scanf("%d", &position);
    printf("Enter value for node: ");
    scanf("%d", &data);

    if (position == 1)
    {
        head->data = data;
        printf("Updation successfull\n");
        return;
    }

    Linklist *temporary_node = head;
    while (temporary_node && --position)
    {
        temporary_node = temporary_node->next;
    }

    if (!temporary_node)
    {
        printf("Position does not exist\n");
        return;
    }
    temporary_node->data = data;
    printf("Updation successfull\n");
}

void delete_first_element(Linklist **head)
{
    if (!*head)
    {
        printf("List is empty\n");
        return;
    }

    Linklist *node_to_delete = *head;
    *head = (*head)->next;
    free(node_to_delete);
    printf("Deletion successfull\n");
}

void delete_last_element(Linklist **head)
{
    if (!*head)
    {
        printf("List is empty\n");
        return;
    }

    if (!(*head)->next)
    {
        Linklist *node_to_delete = *head;
        *head = NULL;
        free(node_to_delete);
        printf("Deletion successfull\n");
        return;
    }

    Linklist *temporary_node = *head;
    while (temporary_node->next->next)
    {
        temporary_node = temporary_node->next;
    }
    Linklist *node_to_delete = temporary_node->next;
    temporary_node->next = NULL;
    free(node_to_delete);
    printf("Deletion successfull\n");
}

void delete_at_position(Linklist **head)
{
    int position;
    printf("\nEnter a position to delete the element: ");
    scanf("%d", &position);

    if (position == 1)
    {
        delete_first_element(head);
        return;
    }

    position--;
    Linklist *temporary_node = *head;
    while (temporary_node && --position)
    {
        temporary_node = temporary_node->next;
    }
    if (!temporary_node || !temporary_node->next)
    {
        printf("Position does not exist\n");
        return;
    }

    Linklist *node_to_delete = temporary_node->next;
    temporary_node->next = temporary_node->next->next;
    free(node_to_delete);
    printf("Deletion successfull\n");
}

void operate(Linklist **head)
{
    printf("\nEnter a choice:\n");
    printf("\n1. Add an element to the end of list:\n");
    printf("\n2. Add an element to the begining of list:\n");
    printf("\n3. Add an element at a position in the list:\n");
    printf("\n4. Display the list\n");
    printf("\n5. Update an element at a position in the list\n");
    printf("\n6. Delete element at the begining of list\n");
    printf("\n7. Delete element at the end of list\n");
    printf("\n8. Delete element at a position in the list\n");

    int choice;
    while (1)
    {
        printf("\nEnter your choice (1-8):");
        if (scanf("%d", &choice) == 1 && choice < 9 && choice > 0)
            break;
        else
        {
            printf("Invalid choice. ");
        }
    }

    switch (choice)
    {
    case 1:
        add_to_end(head);
        break;

    case 2:
        add_at_begining(head);
        break;

    case 3:
        add_at_position(head);
        break;

    case 4:
        display_list(*head);
        break;

    case 5:
        update_at_position(*head);
        break;

    case 6:
        delete_first_element(head);
        break;

    case 7:
        delete_last_element(head);
        break;

    case 8:
        delete_at_position(head);
        break;

    default:
        printf("Invalid choice\n");
        break;
    }
}

void free_list_memory(Linklist **head)
{
    while (*head)
    {
        Linklist *to_delete_node = *head;
        *head = (*head)->next;
        free(to_delete_node);
    }
}
