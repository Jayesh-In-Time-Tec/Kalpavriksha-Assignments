#include<stdio.h>
#include<string.h>

char matrix[10][102][51];

int is_digit(char character) {
    return character >= '0' && character <= '9';
}

int string_length(char* string){
    int length=0;
    while(*string++!='\0')length++;
    return length;
}

int take_input(char *input_message, int min_value,int max_value) {
    char input_array[100];
    int is_valid;
    int value = 0;

    while (1) {
        printf("%s", input_message);
        scanf("%s", input_array);

        is_valid = 1;
        for (int index = 0; input_array[index] != '\0'; index++) {
            if (!is_digit(input_array[index])) {
                is_valid = 0;
                break;
            }
        }

        if (is_valid) {
            value = 0;
            for (int index = 0; input_array[index] != '\0'; index++) {
                value = value * 10 + (input_array[index] - '0');
                if (value > max_value) {
                    is_valid = 0;
                    break;
                }
            }
            if (value < min_value || value > max_value) {
                is_valid = 0;
            }
        }

        if (!is_valid) {
            printf("Invalid input! Please enter a valid positive integer between %d and %d.\n", min_value, max_value);
        } else {
            break;
        }
    }

    return value;
}

int is_vowel(char character){
    return character=='a'||character=='e'||character=='i'||character=='o'
    ||character=='u' || character=='A'||character=='E'||character=='I'||
    character=='O' ||character=='U';
}

int is_alphabet(char character){
    return (character>='a' && character<='z')||
     (character>='A' && character<='Z');
}

int check_name(char* name){
    if(string_length(name)>50){
        printf("Name length should not exeed 50\n");
        return 0;
    }
    while(*name!='\0'){
        if(!is_alphabet){
            printf("Enter name with alphabets only\n");
            return 0;
        }
        name++;
    }
    return 1;
}

void take_matrix_input(int rows,int columns,int *count
,int *size){
    printf("Enter the names:\n");
    for(int row=0;row<rows;row++){
        for(int column=0;column<columns;column++){
            printf("Name at (%d %d):",row,column);
            while(1){
                scanf("%s",matrix[row][column]);
                if(check_name(matrix[row][column])){
                    break;
                }
                else{
                    printf("Enter valid name: ");
                }
            }
            if(is_vowel(matrix[row][column][0])){
                *count=*count+1;
            }
            if(string_length(matrix[row][column])>*size)*size=string_length(matrix[row][column]);
        }
    }
}

void display_matrix(int rows,int columns){
    printf("The 2d array of names is:\n");
    for(int row=0;row<rows;row++){
        for(int column=0;column<columns;column++){
            printf("%s\t",matrix[row][column]);
        }
        printf("\n");
    }
}

void display_longest_name(int rows,int columns,int size){
    printf("The longest name is: ");
    for(int row=0;row<rows;row++){
        for(int column=0;column<columns;column++){
            if(strlen(matrix[row][column])==size){
                printf("%s\n",matrix[row][column]);
                return;
            }
        }
    }
}

void solution(){
    int rows=take_input("Enter the number of rows: ",1,10);
    int columns=take_input("Enter the number of columns: ",1,101);
    int count=0,size=0;
    take_matrix_input(rows,columns,&count,&size);
    display_matrix(rows,columns);
    printf("Number of vowels: %d\n",count);
    display_longest_name(rows,columns,size);
}

int main(){
    solution();
    return 0;
}
