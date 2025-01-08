#include<stdio.h>
#include<string.h>

char matrix[10][102][51];

int take_input(char* input_message,int min_length,int max_length){
    printf("%s",input_message);
    int input;
    while(1){
        if(scanf("%d",&input)!=1 || input<min_length || input>max_length){
            printf("Invalid input. Enter a number between %d & %d: ",min_length
            ,max_length);
            while (getchar() != '\n');
        }
        else break;
    }
    return input;
}

int is_vowel(char character){
    return character=='a'||character=='e'||character=='i'||character=='o'
    ||character=='u' || character=='A'||character=='E'||character=='I'||
    character=='O' ||character=='U';
}

int is_alphabet(char character){
    return character>='a' && character<='z';
}

int check_valid_name(char* name){
    while(*name!='\0'){
        if(!is_alphabet){
            return 0;
        }
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
