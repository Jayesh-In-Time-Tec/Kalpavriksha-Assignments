#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "text.txt"
#define MAX_NAME_LEN 100

// Structure for storing user data
typedef struct
{
    int id;
    char name[MAX_NAME_LEN];
    int age;
} User;

// Error hanling function
void error_handler(char *message)
{
    printf("%s", message);
    exit(EXIT_FAILURE);
}

// Initialize the file if it doesn't exist
void initialize_file()
{
    FILE *fptr = fopen(FILE_NAME, "a");
    if (fptr == NULL)
    {
        error_handler("Error: Could'nt load the file\n");
    }
    fclose(fptr);
}

// Function to create new user
void create_user()
{
    FILE *fptr = fopen(FILE_NAME, "a");
    if (fptr == NULL)
    {
        error_handler("Error: Creating new user\n");
    }

    User user;
    printf("Enter user details\n");
    printf("Enter  ID: ");
    scanf("%d", &user.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", user.name);
    printf("Enter Age: ");
    scanf("%d", &user.age);

    fprintf(fptr, "%d %s %d\n", user.id, user.name, user.age);
    fclose(fptr);
    printf("User created successfully!\n");
}

// Printing all users
void read_users()
{
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL)
    {
        error_handler("Error: Reading users\n");
    }

    User user;
    printf("Users:\n");
    while (fscanf(fptr, "%d %s %d", &user.id, user.name, &user.age) == 3)
    {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }

    fclose(fptr);
}

// Modifying user using ID
void update_user()
{
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL)
    {
        error_handler("Error: Updating file\n");
    }

    User user;
    int id, found = 0;
    printf("Enter User ID to update: ");
    scanf("%d", &id);

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL)
    {
        error_handler("Error: Creating temporary file\n");
    }

    while (fscanf(fptr, "%d %s %d", &user.id, user.name, &user.age) == 3)
    {
        if (user.id == id)
        {
            found = 1;
            printf("Enter new Name: ");
            scanf(" %[^\n]", user.name);
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp_file, "%d %s %d\n", user.id, user.name, user.age);
    }

    fclose(fptr);
    fclose(temp_file);

    if (found)
    {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("User updated successfully!\n");
    }
    else
    {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}

// Delete a user using ID
void delete_user()
{
    FILE *fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL)
    {
        error_handler("Error: Deleting user\n");
    }

    User user;
    int id, found = 0;
    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL)
    {
        error_handler("Error: Could'nt open temporary file\n");
    }

    while (fscanf(fptr, "%d %s %d", &user.id, user.name, &user.age) == 3)
    {
        if (user.id != id)
        {
            fprintf(temp_file, "%d %s %d\n", user.id, user.name, user.age);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fptr);
    fclose(temp_file);

    if (found)
    {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("User deleted successfully!\n");
    }
    else
    {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}

void main()
{
    int choice;
    initialize_file();

    printf("Enter a choice:\n");
    printf("1. Add a new user\n");
    printf("2. Display all users\n");
    printf("3. Update existing user\n");
    printf("4. Delete existing user\n");
    printf("5. Quit program\n");

    do
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_user();
            break;
        case 2:
            read_users();
            break;
        case 3:
            update_user();
            break;
        case 4:
            delete_user();
            break;
        case 5:
            printf("Quiting program...\n");
            break;
        default:
            printf("Enter a valid choice\n");
        }
    } while (choice != 5);
}
