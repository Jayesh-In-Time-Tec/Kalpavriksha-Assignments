#include <stdio.h>
#include <stdlib.h>

typedef struct ll
{
    int data;
    struct ll *next;
} List;

List *initialize_node(int data)
{
    List *node = (List *)malloc(sizeof(List));
    node->data = data;
    node->next = NULL;
    return node;
}

void add_node(List **head, int data)
{
    List *node = initialize_node(data);

    if (*head == NULL)
    {
        *head = node;
        return;
    }

    List *temporaryorary = *head;
    while (temporaryorary->next)
    {
        temporaryorary = temporaryorary->next;
    }

    temporaryorary->next = node;
}

void display(List *head, char *string)
{
    printf("\n%s\n", string);
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n\n");
}

void create_list(List **head)
{
    int data;
    printf("Enter list elements: ");
    while (scanf("%d", &data) == 1)
    {
        add_node(head, data);
        if (getchar() == '\n')
            break;
    }
}

List *merge_lists(List *list1, List *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    List *head = list1;
    while (list1->next)
        list1 = list1->next;
    list1->next = list2;
    return head;
}

List *find_middle(List *head)
{
    List *slow = head;
    List *fast = head;
    List *previous;
    do
    {
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    } while (fast && fast->next);
    previous->next = NULL;
    return slow;
}

List *merge(List *head1, List *head2)
{
    List *new_head = initialize_node(-1);
    List *temporary = new_head;
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            temporary->next = head1;
            head1 = head1->next;
        }
        else
        {
            temporary->next = head2;
            head2 = head2->next;
        }
        temporary = temporary->next;
    }
    if (head1)
    {
        temporary->next = head1;
    }
    if (head2)
    {
        temporary->next = head2;
    }
    return new_head->next;
}

List *sort(List *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    List *mid = find_middle(head);
    List *head1 = sort(head);
    List *head2 = sort(mid);
    return merge(head1, head2);
}

int median(List *head)
{
    List *slow = initialize_node(-1);
    slow->next = head;
    List *fast = slow;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL)
        return slow->data;
    return (slow->data + slow->next->data) >> 1;
}

void free_list(List *head)
{
    while (head)
    {
        List *to_delete = head;
        head = head->next;
        free(to_delete);
    }
}

int main()
{
    List *list1 = NULL;
    create_list(&list1);
    display(list1, "List1: ");

    List *list2 = NULL;
    create_list(&list2);
    display(list2, "List2: ");

    List *merged = merge_lists(list1, list2);
    display(merged, "Merged: ");

    List *sorted = sort(merged);
    display(sorted, "Sorted: ");

    printf("Median: %d", median(sorted));

    free_list(sorted);

    return 0;
}
