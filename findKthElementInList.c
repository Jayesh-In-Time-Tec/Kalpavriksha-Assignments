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

int find_kth_element(List *head, int position)
{
    if (position < 1)
    {
        printf("Position does not exists\n");
        return -1;
    }

    while (--position && head)
    {
        head = head->next;
    }

    if (head == NULL)
    {
        printf("Position does not exists\n");
        return -1;
    }
    return head->data;
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
    List *list = NULL;
    create_list(&list);

    int position;
    printf("Enter element position to find: ");
    scanf("%d", &position);

    List *sorted = sort(list);
    display(sorted, "Sorted: ");

    printf("Element at position k: %d", find_kth_element(sorted, position));

    free_list(sorted);

    return 0;
}
