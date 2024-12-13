#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "text.txt"

// Structure for storing user data
typedef struct
{
    int id;
    char *name;
    int age;
} User;

// Error handling function
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
        error_handler("Error: Couldn't load the file\n");
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
    user.name = (char *)malloc(256 * sizeof(char));
    if (user.name == NULL)
    {
        error_handler("Error: Memory allocation failed\n");
    }

    printf("Enter user details\n");
    printf("Enter ID: ");
    scanf("%d", &user.id);

    printf("Enter Name: ");
    getchar();
    fgets(user.name, 256, stdin);
    user.name[strcspn(user.name, "\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &user.age);

    fprintf(fptr, "%d %s %d\n", user.id, user.name, user.age);
    fclose(fptr);

    free(user.name);
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

    printf("Users:\n");
    int id, age;
    char *name = (char *)malloc(256 * sizeof(char));
    if (name == NULL)
    {
        error_handler("Error: Memory allocation failed\n");
    }

    while (fscanf(fptr, "%d", &id) == 1)
    {
        fgetc(fptr);
        fgets(name, 256, fptr);
        char *age_str = strrchr(name, ' ');
        if (age_str != NULL)
        {
            *age_str = '\0';
            age = atoi(age_str + 1);
        }
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }

    free(name);
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

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL)
    {
        error_handler("Error: Creating temporary file\n");
    }

    int id, found = 0;
    printf("Enter User ID to update: ");
    scanf("%d", &id);

    User user;
    user.name = (char *)malloc(256 * sizeof(char));
    if (user.name == NULL)
    {
        error_handler("Error: Memory allocation failed\n");
    }

    while (fscanf(fptr, "%d", &user.id) == 1)
    {
        fgetc(fptr); // Skip space
        fgets(user.name, 256, fptr);
        char *age_str = strrchr(user.name, ' ');
        if (age_str != NULL)
        {
            *age_str = '\0';
            user.age = atoi(age_str + 1);
        }

        if (user.id == id)
        {
            found = 1;
            printf("Enter new Name: ");
            getchar();
            fgets(user.name, 256, stdin);
            user.name[strcspn(user.name, "\n")] = '\0';

            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }

        fprintf(temp_file, "%d %s %d\n", user.id, user.name, user.age);
    }

    free(user.name);
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

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL)
    {
        error_handler("Error: Couldn't open temporary file\n");
    }

    int id, found = 0;
    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    User user;
    user.name = (char *)malloc(256 * sizeof(char));
    if (user.name == NULL)
    {
        error_handler("Error: Memory allocation failed\n");
    }

    while (fscanf(fptr, "%d", &user.id) == 1)
    {
        fgetc(fptr); // Skip space
        fgets(user.name, 256, fptr);
        char *age_str = strrchr(user.name, ' ');
        if (age_str != NULL)
        {
            *age_str = '\0';
            user.age = atoi(age_str + 1);
        }

        if (user.id != id)
        {
            fprintf(temp_file, "%d %s %d\n", user.id, user.name, user.age);
        }
        else
        {
            found = 1;
        }
    }

    free(user.name);
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
            printf("Quitting program...\n");
            break;
        default:
            printf("Enter a valid choice\n");
        }
    } while (choice != 5);
}
