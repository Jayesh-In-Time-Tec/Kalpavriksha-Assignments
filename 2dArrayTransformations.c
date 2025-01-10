#include <stdio.h>

int matrix[100][100];

void swap_two_numbers(int *number1, int *number2);

void matrix_level_rotation(int *rows_count, int *columns_count);
void row_wise_rotation_left(int rows_count, int columns_count);
void row_wise_rotation_right(int rows_count, int columns_count);
void column_wise_rotation_up(int rows_count, int columns_count);
void column_wise_rotation_down(int rows_count, int columns_count);
void take_matrix_input(int *rows_count, int *columns_count);
void display_matrix(int rows_count, int columns_count);
void menu_system(int *rows_count, int *columns_count);

void solution();

int main() {
    solution();
    return 0;
}

void swap_two_numbers(int *number1, int *number2) {
    *number1 = *number1 ^ *number2;
    *number2 = *number1 ^ *number2;
    *number1 = *number1 ^ *number2;
}

void matrix_level_rotation(int *rows_count, int *columns_count) {
    int maxx = *rows_count;
    if (*columns_count > maxx) maxx = *columns_count;
    
    for (int row = 0; row < maxx; row++) {
        for (int column = row + 1; column < maxx; column++) {
            swap_two_numbers(&matrix[row][column], &matrix[column][row]);
        }
    }
    
    swap_two_numbers(rows_count, columns_count);
    for (int row = 0; row < *rows_count; row++) {
        for (int column = 0; column < *columns_count / 2; column++) {
            swap_two_numbers(&matrix[row][column], &matrix[row][*columns_count - column - 1]);
        }
    }
    
}

void row_wise_rotation_left(int rows_count, int columns_count) {
    for (int row = 0; row < rows_count; row++) {
        int first_element = matrix[row][0];
        for (int column = 0; column < columns_count - 1; column++) {
            matrix[row][column] = matrix[row][column + 1];
        }
        matrix[row][columns_count - 1] = first_element;
    }
    
}

void row_wise_rotation_right(int rows_count, int columns_count) {
    
    for (int row = 0; row < rows_count; row++) {
        int last_element = matrix[row][columns_count - 1];
        for (int column = columns_count - 1; column > 0; column--) {
            matrix[row][column] = matrix[row][column - 1];
        }
        matrix[row][0] = last_element;
    }
    
}

void column_wise_rotation_up(int rows_count, int columns_count) {
    printf("rows count=%d col count=%d\n",rows_count,columns_count);
    for (int column = 0; column < columns_count; column++) {
        int top_element = matrix[0][column];
        for (int row = 0; row < rows_count - 1; row++) {
            matrix[row][column] = matrix[row + 1][column];
        }
        matrix[rows_count - 1][column] = top_element;
    }
    
}

void column_wise_rotation_down(int rows_count, int columns_count) {
    for (int column = 0; column < columns_count; column++) {
        int bottom_element = matrix[rows_count - 1][column];
        for (int row = rows_count - 1; row > 0; row--) {
            matrix[row][column] = matrix[row - 1][column];
        }
        matrix[0][column] = bottom_element;
    }
    
}

void take_matrix_input(int *rows_count, int *columns_count) {
    printf("Enter size of matrix\n");
    printf("Enter rows count: ");
    while (scanf("%d", rows_count) == 1 && *rows_count > 100) {
        printf("Rows count cannot be greater than 100\n");
    }
    
    printf("Enter columns count: ");
    while (scanf("%d", columns_count) == 1 && *columns_count > 100) {
        printf("Columns count cannot be greater than 100\n");
    }
    
    printf("Enter the elements of the matrix\n");
    for (int row = 0; row < *rows_count; row++) {
        for (int column = 0; column < *columns_count; column++) {
            printf("Enter element at (%d %d): ", row, column);
            scanf("%d", &matrix[row][column]);
        }
    }
    printf("\n\n");
}

void display_matrix(int rows_count, int columns_count) {
    for (int row = 0; row < rows_count; row++) {
        for (int column = 0; column < columns_count; column++) {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }
}

void menu_system(int *rows_count, int *columns_count) {
    int choice;
    do {
        printf("Choose from the below options to transform & display matrix\n");
        printf("1. Matrix-Level Rotation\n");
        printf("2. Row-Wise Rotation (Left)\n");
        printf("3. Row-Wise Rotation (Right)\n");
        printf("4. Column-Wise Rotation (Up)\n");
        printf("5. Column-Wise Rotation (Down)\n");
        printf("6. Exit program\n");
        
        scanf("%d", &choice);
        int rotation_number;
        if(choice>0 && choice<6){
        printf("Enter rotation number: ");
        scanf("%d",&rotation_number);
        }
        
        switch (choice) {
            case 1:
                rotation_number%=4;
                while(rotation_number--){
                    matrix_level_rotation(rows_count, columns_count);
                }
                printf("After transformation matrix:\n");
                display_matrix(*rows_count, *columns_count);
                printf("\n\n");
                break;
                
            case 2:
                rotation_number%=*columns_count;
                while(rotation_number--){
                    row_wise_rotation_left(*rows_count, *columns_count);
                }
                printf("After transformation matrix:\n");
                display_matrix(*rows_count, *columns_count);
                printf("\n\n");
                break;
                
            case 3:
                rotation_number%=*columns_count;
                while(rotation_number--){
                    row_wise_rotation_right(*rows_count, *columns_count);
                }
                printf("After transformation matrix:\n");
                display_matrix(*rows_count, *columns_count);
                printf("\n\n");
                break;
                
            case 4:
                rotation_number%=*rows_count;
                while(rotation_number--){
                    column_wise_rotation_up(*rows_count, *columns_count);
                }
                printf("After transformation matrix:\n");
                display_matrix(*rows_count, *columns_count);
                printf("\n\n");
                break;
                
            case 5:
                rotation_number%=*rows_count;
                while(rotation_number--){
                    column_wise_rotation_down(*rows_count, *columns_count);
                }
                printf("After transformation matrix:\n");
                display_matrix(*rows_count, *columns_count);
                printf("\n\n");
                break;
                
            case 6:
                printf("Exiting program!!!\n");
                break;
            default:
                printf("Invalid input.\n");
        }
    } while (choice != 6);
}

void solution() {
    int rows_count, columns_count;
    take_matrix_input(&rows_count, &columns_count);
    display_matrix(rows_count, columns_count);
    menu_system(&rows_count, &columns_count);
}
