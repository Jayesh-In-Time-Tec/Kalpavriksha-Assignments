#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10

typedef struct ll
{
    int key;
    int value;
    struct ll *next;
} Node;

Node *hash_table[HASH_SIZE] = {NULL};

int hash_function(int key)
{
    return key % HASH_SIZE;
}

void insert(int key, int value)
{
    int index = hash_function(key);

    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;

    if (hash_table[index] == NULL)
    {
        hash_table[index] = node;
        return;
    }

    Node *temporary = hash_table[index];
    Node *previous = NULL;

    while (temporary)
    {
        if (temporary->key == key)
        {
            temporary->value = value;
            return;
        }
        previous = temporary;
        temporary = temporary->next;
    }

    if (previous == NULL)
    {
        hash_table[index] = node;
    }
    else
    {
        previous->next = node;
    }
}

int search(int key)
{
    int index = hash_function(key);
    Node *temporary = hash_table[index];

    while (temporary)
    {
        if (temporary->key == key)
        {
            return temporary->value;
        }
        temporary = temporary->next;
    }
    return -1;
}

void delete(int key)
{
    int index = hash_function(key);
    Node *temporary = hash_table[index];
    Node *previous = NULL;

    while (temporary && temporary->key != key)
    {
        previous = temporary;
        temporary = temporary->next;
    }

    if (temporary == NULL)
    {
        printf("Key %d not found.\n", key);
        return;
    }

    if (previous == NULL)
    {
        hash_table[index] = temporary->next;
    }
    else
    {
        previous->next = temporary->next;
    }

    printf("Key %d deleted.\n", key);
}

void display()
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        Node *temporary = hash_table[i];
        while (temporary)
        {
            printf("(%d, %d) -> ", temporary->key, temporary->value);
            temporary = temporary->next;
        }
    }
    printf("\n");
}

int valid_entry()
{
    int val = -1;
    while (scanf("%d", &val) == 0 || val < 0)
    {
        printf("Enter a positive integer\n:");
    }
    return val;
}

int main()
{
    while (1)
    {
        int choice, key, value;
        printf("\nEnter choice:\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key and value: ");
            key = valid_entry();
            value = valid_entry();
            insert(key, value);
            break;

        case 2:
            printf("Enter key to search: ");
            key = valid_entry();
            value = search(key);
            if (value != -1)
            {
                printf("Value: %d\n", value);
            }
            else
            {
                printf("Key not found.\n");
            }
            break;

        case 3:
            printf("Enter key to delete: ");
            key = valid_entry();
            delete (key);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
