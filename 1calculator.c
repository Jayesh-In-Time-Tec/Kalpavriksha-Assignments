#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 1000

int is_space(char character) {
    if(character == ' ' || character == '\n' || character == '\r') return 1;
    return 0;
}

int is_digit(char character) {
    if(character >= '0' && character <= '9') return 1;
    return 0;
}

typedef struct {
    int top;
    char data[INITIAL_SIZE];
} operator_stack;

typedef struct {
    int top;
    int data[INITIAL_SIZE];
} operand_stack;

void push_operator(operator_stack* stack, char value) {
    if (stack->top == INITIAL_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->data[stack->top] = value;
}

void pop_operator(operator_stack* stack) {
    if (stack->top == -1) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    stack->top--;
}

void push_operand(operand_stack* stack, int value) {
    if (stack->top == INITIAL_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->data[stack->top] = value;
}

void pop_operand(operand_stack* stack) {
    if (stack->top == -1) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    stack->top--;
}

int operator_precedence(char operator_character) {
    if (operator_character == '+' || operator_character == '-')
        return 0;
    if (operator_character == '*' || operator_character == '/')
        return 1;
    return -1;
}

void solve_operator(operand_stack* operand_stack_instance, operator_stack* operator_stack_instance) {
    int operand1 = operand_stack_instance->data[operand_stack_instance->top];
    pop_operand(operand_stack_instance);
    int operand2 = operand_stack_instance->data[operand_stack_instance->top];
    pop_operand(operand_stack_instance);

    char operator_character = operator_stack_instance->data[operator_stack_instance->top];
    pop_operator(operator_stack_instance);

    int result;
    switch (operator_character) {
        case '+':
            result = operand2 + operand1;
            break;
        case '-':
            result = operand2 - operand1;
            break;
        case '*':
            result = operand2 * operand1;
            break;
        case '/':
            if (operand1 == 0) {
                printf("Error: Division by zero");
                exit(EXIT_FAILURE);
            }
            result = operand2 / operand1;
            break;
    }

    push_operand(operand_stack_instance, result);
}

int evaluate_expression(char* expression) {
    operator_stack operator_stack_instance;
    operator_stack_instance.top = -1;

    operand_stack operand_stack_instance;
    operand_stack_instance.top = -1;

    int index;
    for (index = 0; expression[index] != '\0'; index++) {
        char character = expression[index];

        if (is_space(character))
            continue;

        else if (is_digit(character)) {
            int number = 0;
            while (is_digit(expression[index])) {
                number *= 10;
                number += expression[index] - '0';
                index++;
            }
            push_operand(&operand_stack_instance, number);

            while (is_space(expression[index])) {
                index++;
            }
            index--;
        }

        else if (character == '+' || character == '-' || character == '*' || character == '/') {
            while (operator_stack_instance.top != -1 && 
                   operator_precedence(character) <= operator_precedence(operator_stack_instance.data[operator_stack_instance.top])) {
                solve_operator(&operand_stack_instance, &operator_stack_instance);
            }
            push_operator(&operator_stack_instance, character);
        } else {
            printf("Invalid expression\n");
            exit(EXIT_FAILURE);
        }
    }

    while (operator_stack_instance.top != -1) {
        solve_operator(&operand_stack_instance, &operator_stack_instance);
    }

    return operand_stack_instance.data[operand_stack_instance.top];
}

int main() {
    char* expression = (char*)malloc(INITIAL_SIZE * sizeof(char));
    if (!expression) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the expression:\n");
    fgets(expression, INITIAL_SIZE, stdin);

    int result = evaluate_expression(expression);
    printf("The result of the expression is: %d", result);

    free(expression);
    return 0;
}
