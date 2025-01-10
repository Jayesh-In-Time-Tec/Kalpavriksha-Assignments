#include<stdio.h>

int matrix[100][100];

void swap(int *number1,int *number2);
void matrix_level_rotation(int size);
void row_wise_rotation_left(int size);
void row_wise_rotation_right(int size);
void column_wise_rotation_up(int size);
void column_wise_rotation_down(int size);
void take_matrix_input(int *size);
void display_matrix(int size);
void menu_system(int size);
void solution();

int main() {
	solution();
	return 0;
}

void swap(int *number1,int *number2) {
	*number1=*number1^*number2;
	*number2=*number1^*number2;
	*number1=*number1^*number2;
}

void matrix_level_rotation(int size) {
    for(int row=0; row<size; row++) {
        for(int column=row+1; column<size; column++) {
            swap(&matrix[row][column], &matrix[column][row]);
        }
    }
    for(int row=0; row<size; row++) {
        for(int column=0; column<size/2; column++) {
            swap(&matrix[row][column],&matrix[row][size-column-1]);
        }
    }
    display_matrix(size);
}

void row_wise_rotation_left(int size) {
    for(int row=0; row<size; row++) {
        int first_element = matrix[row][0];
        for(int column=0; column<size-1; column++) {
            matrix[row][column] = matrix[row][column+1];
        }
        matrix[row][size-1] = first_element;
    }
    display_matrix(size);
}

void row_wise_rotation_right(int size) {
    for(int row=0; row<size; row++) {
        int last_element = matrix[row][size-1];
        for(int column=size-1; column>0; column--) {
            matrix[row][column] = matrix[row][column-1];
        }
        matrix[row][0] = last_element;
    }
    display_matrix(size);
}

void column_wise_rotation_up(int size) {
    for(int column=0; column<size; column++) {
        int top_element = matrix[0][column];
        for(int row=0; row<size-1; row++) {
            matrix[row][column] = matrix[row+1][column];
        }
        matrix[size-1][column] = top_element;
    }
    display_matrix(size);
}

void column_wise_rotation_down(int size) {
    for(int column=0; column<size; column++) {
        int bottom_element = matrix[size-1][column];
        for(int row=size-1; row>0; row--) {
            matrix[row][column] = matrix[row-1][column];
        }
        matrix[0][column] = bottom_element;
    }
    display_matrix(size);
}

void take_matrix_input(int *size) {
    printf("Enter size of matrix\n");
    while(scanf("%d", size) == 1 && *size>100) {
        printf("Size cannot be greater than 100\n");
    }
    for(int row=0; row<*size; row++) {
        for(int column=0; column<*size; column++) {
            scanf("%d", &matrix[row][column]);
        }
    }
}

void display_matrix(int size) {
    for(int row=0; row<size; row++) {
        for(int column=0; column<size; column++) {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }
}


void menu_system(int size) {
	int choice;
	printf("Choose from the below options to transform & display matrix\n");
	do {
		printf("1. Matrix-Level Rotation\n");
		printf("2. Row-Wise Rotation (Left)\n");
		printf("3. Row-Wise Rotation (Right)\n");
		printf("4. Column-Wise Rotation (Up)\n");
		printf("5. Column-Wise Rotation (Down)\n");
		printf("6. Exit program\n");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			matrix_level_rotation(size);
			break;
		case 2:
			row_wise_rotation_left(size);
			break;
		case 3:
			row_wise_rotation_right(size);
			break;
		case 4:
			column_wise_rotation_up(size);
			break;
		case 5:
			column_wise_rotation_down(size);
			break;
		case 6:
			printf("Exiting program!!!\n");
			break;
		default:
			printf("Invalid input.\n");
		}
	} while(choice!=6);
}

void solution() {
	int size;
	take_matrix_input(&size);
	display_matrix(size);
	menu_system(size);
}
