#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll
{
    int id;
    char *severity;
    struct ll *next;
} linklist;

linklist *head = NULL;

void string_copy(char *s1, char *s2)
{
    while (*s2 != '\0')
    {
        *s1 = *s2;
    }
}

int string_length(char *string)
{
    int length = 0;
    while (*string != '\0')
    {
        string++;
        length++;
    }
    return length;
}

int priority(char *severity)
{
    if (severity[0] == 'c')
        return 3;
    if (severity[1] == 'e')
        return 2;
    return 1;
}

void create_node(int id, char *string)
{
    linklist *node = (linklist *)malloc(sizeof(linklist));
    node->id = id;
    node->severity = (char *)malloc(string_length(string));
    strcpy(node->severity, string);

    if (head == NULL)
    {
        node->next = NULL;
        head = node;
        return;
    }
    linklist *traverse = head;
    linklist *previous = NULL;
    while (traverse && priority(traverse->severity) >= priority(string))
    {
        previous = traverse;
        traverse = traverse->next;
    }
    if (previous == NULL)
    {
        node->next = head;
        head = node;
        return;
    }
    node->next = traverse;
    previous->next = node;
}

void display()
{
    linklist *traverse = head;
    printf("\n");
    while (traverse)
    {
        printf("%d %s\n", traverse->id, traverse->severity);
        traverse = traverse->next;
    }
    printf("\n");
}

int checkid(int id)
{
    linklist *traverse = head;
    while (traverse)
    {
        if (traverse->id == id)
            return 0;
        traverse = traverse->next;
    }
    return 1;
}

int check_severity(char *string)
{
    return strcmp(string, "serious") == 0 || strcmp(string, "stable") == 0 || strcmp(string, "critical") == 0;
}

int main()
{
    int n;
    printf("Enter number of operations\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter id: ");
        int id;
        while (1)
        {
            scanf("%d", &id);
            if (checkid(id))
                break;
            printf("Enter valid id:\n");
        }

        char string[100];
        printf("Enter condition:\n");
        while (1)
        {
            while (getchar() != '\n')
                ;
            scanf("%s", string);
            if (check_severity(string))
                break;
            printf("Enter valid condition\n");
        }

        create_node(id, string);
    }

    printf("List after sorting:\n");
    display();

    return 0;
}
