#include<stdio.h>
#include<string.h>

char matrix[10][102][51];

int is_digit(char character) {
    return character >= '0' && character <= '9';
}

int take_input(char *input_message, int min_value,int max_value) {
    char input_array[100];
    int is_valid;
    int value = 0;

    while (1) {
        printf("%s", input_message);
        scanf("%s", input_array);

        is_valid = 1;
        for (int i = 0; input_array[i] != '\0'; i++) {
            if (!is_digit(input_array[i])) {
                is_valid = 0;
                break;
            }
        }

        if (is_valid) {
            value = 0;
            for (int i = 0; input_array[i] != '\0'; i++) {
                value = value * 10 + (input_array[i] - '0');
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
            printf("Invalid input! Please enter a valid positive integer between %d and %lld.\n", min_value, max_value);
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
    while(*name!='\0'){
        if(!is_alphabet){
            return 0;
        }
        name++;
    }
    return 1;
}

void take_matrix_input(int rows,int columns,int *count
,int *size){
    printf("Enter the names:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("Name at (%d %d):",i,j);
            scanf("%s",matrix[i][j]);
            
            if(is_vowel(matrix[i][j][0])){
                *count=*count+1;
                if(strlen(matrix[i][j])>*size)*size=strlen(matrix[i][j]);
            }
        }
    }
}

void display_matrix(int rows,int columns){
    printf("The 2d array of names is:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            printf("%s\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void display_longest_name_with_vowel(int rows,int columns,int size){
    if(size==0){
        printf("No names starts with a vowel\n");
        return;
    }
    printf("The longest name is: ");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            if(strlen(matrix[i][j])==size){
                printf("%s\n",matrix[i][j]);
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
    display_longest_name_with_vowel(rows,columns,size);
}

int main(){
    solution();
    return 0;
}
