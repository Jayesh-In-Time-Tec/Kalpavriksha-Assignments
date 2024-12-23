#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "text.txt"

typedef struct {
    int id;
    char *name;
    int age;
} User;

void error_handler(char *message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}

int is_valid_name(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

int is_valid_id_or_age(int value) {
    return value > 0;
}

void initialize_file() {
    FILE *file_pointer = fopen(FILE_NAME, "a");
    if (file_pointer == NULL) {
        error_handler("Error: Couldn't load the file\n");
    }
    fclose(file_pointer);
}

void create_user() {
    FILE *file_pointer = fopen(FILE_NAME, "a+");
    if (file_pointer == NULL) {
        error_handler("Error: Creating new user\n");
    }

    User user;
    user.name = (char *)malloc(256 * sizeof(char));
    if (user.name == NULL) {
        error_handler("Error: Memory allocation failed\n");
    }

    printf("Enter user details\n");

    do {
        printf("Enter ID: ");
        if (scanf("%d", &user.id) != 1 || !is_valid_id_or_age(user.id)) {
            printf("Invalid ID. Please enter a positive integer.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    } while (1);

    int id, age, found = 0;
    char *name = (char *)malloc(256 * sizeof(char));
    if (name == NULL) {
        error_handler("Error: Memory allocation failed\n");
    }

    while (fscanf(file_pointer, "%d", &id) == 1) {
        fgetc(file_pointer);
        fgets(name, 256, file_pointer);
        char *age_str = strrchr(name, ' ');
        if (age_str != NULL) {
            *age_str = '\0';
            age = atoi(age_str + 1);
        }

        if (id == user.id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Error: User with ID %d already exists.\n", user.id);
        fclose(file_pointer);
        free(user.name);
        free(name);
        return;
    }

    do {
        printf("Enter Name: ");
        getchar();
        fgets(user.name, 256, stdin);
        user.name[strcspn(user.name, "\n")] = '\0';
        if (!is_valid_name(user.name)) {
            printf("Invalid Name. Please enter alphabets and spaces only.\n");
            continue;
        }
        break;
    } while (1);

    do {
        printf("Enter Age: ");
        if (scanf("%d", &user.age) != 1 || !is_valid_id_or_age(user.age)) {
            printf("Invalid Age. Please enter a positive integer.\n");
            while (getchar() != '\n');
            continue;
        }
        break;
    } while (1);

    fprintf(file_pointer, "%d %s %d\n", user.id, user.name, user.age);
    fclose(file_pointer);

    free(user.name);
    free(name);
    printf("User created successfully!\n");
}

void read_users() {
    FILE *file_pointer = fopen(FILE_NAME, "r");
    if (file_pointer == NULL) {
        error_handler("Error: Reading users\n");
    }

    printf("Users:\n");
    int id, age;
    char *name = (char *)malloc(256 * sizeof(char));
    if (name == NULL) {
        error_handler("Error: Memory allocation failed\n");
    }

    while (fscanf(file_pointer, "%d", &id) == 1) {
        fgetc(file_pointer);
        fgets(name, 256, file_pointer);
        char *age_str = strrchr(name, ' ');
        if (age_str != NULL) {
            *age_str = '\0';
            age = atoi(age_str + 1);
        }
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }

    free(name);
    fclose(file_pointer);
}

void update_user() {
    FILE *file_pointer = fopen(FILE_NAME, "r");
    if (file_pointer == NULL) {
        error_handler("Error: Updating file\n");
    }

    FILE *temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {
        error_handler("Error: Creating temporary file\n");
    }

    int id, found = 0;
    printf("Enter User ID to update: ");
    scanf("%d", &id);

    User user;
    user.name = (char *)malloc(256 * sizeof(char));
    if (user.name == NULL) {
        error_handler("Error: Memory allocation failed\n");
    }

    while (fscanf(file_pointer, "%d", &user.id) == 1) {
        fgetc(file_pointer);
        fgets(user.name, 256, file_pointer);
        char *age_str = strrchr(user.name, ' ');
        if (age_str != NULL) {
            *age_str = '\0';
            user.age = atoi(age_str + 1);
        }

        if (user.id == id) {
            found = 1;

            do {
                printf("Enter new Name: ");
                getchar();
                fgets(user.name, 256, stdin);
                user.name[strcspn(user.name, "\n")] = '\0';
                if (!is_valid_name(user.name)) {
                    printf("Invalid Name. Please enter alphabets and spaces only.\n");
                    continue;
                }
                break;
            } while (1);

            do {
                printf("Enter new Age: ");
                if (scanf("%d", &user.age) != 1 || !is_valid_id_or_age(user.age)) {
                    printf("Invalid Age. Please enter a positive integer.\n");
                    while (getchar() != '\n');
                    continue;
                }
                break;
            } while (1);
        }

        fprintf(temp_file, "%d %s %d\n", user.id, user.name, user.age);
    }

    free(user.name);
    fclose(file_pointer);
    fclose(temp_file);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("User updated successfully!\n");
    } else {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}

void delete_user()
{
    FILE *file_pointer = fopen(FILE_NAME, "r");
    if (file_pointer == NULL)
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

    while (fscanf(file_pointer, "%d", &user.id) == 1)
    {
        fgetc(file_pointer);
        fgets(user.name, 256, file_pointer);
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
    fclose(file_pointer);
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

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input! Please enter a valid choice (1-5).\n");
            continue;
        }

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