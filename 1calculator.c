#include <stdio.h>
#include <stdlib.h>

// Max size for expression
#define MAX_SIZE 1000

// Definition for operator stack
typedef struct
{
    int top;
    char data[MAX_SIZE];
} operator;

// Definition for operand stack
typedef struct
{
    int top;
    int data[MAX_SIZE];
} operand;

// Funtion associated with operator stack
void push_operator(operator* stk, char val)
{
    // Error handling
    if (stk->top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stk->top++;
    stk->data[stk->top] = val;
}

void pop_operator(operator* stk)
{
    // Error handling
    if (stk->top == -1)
    {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }

    stk->top--;
}

// Funtion associated with operand stack
void push_operand(operand *stk, int val)
{
    // Error handling
    if (stk->top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }

    stk->top++;
    stk->data[stk->top] = val;
}

void pop_operand(operand *stk)
{
    // Error handling
    if (stk->top == -1)
    {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    stk->top--;
}

// Operator precedance checking function
int precedance(char operator)
{
    // Associativity of + & - being same
    if (operator== '+' || operator== '-')
        return 0;

    // Associativity of * & / being same
    if (operator== '*' || operator== '/')
        return 1;
}

// Function for solving binary operations
void solve_operator(operand * or, operator* op)
{
    // Extracting variables from operand stack
    int num1 = or->data[or->top];
    pop_operand(or);
    int num2 = or->data[or->top];
    pop_operand(or);

    // Extracting operator from operator stack
    char operator= op->data[op->top];
    pop_operator(op);

    // Result evaluation
    int result;
    switch (operator)
    {
    case '+':
        result = num2 + num1;
        break;

    case '-':
        result = num2 - num1;
        break;

    case '*':
        result = num2 * num1;
        break;

    case '/':

        // Checking division by 0 condition
        if (num1 == 0)
        {
            printf("Error: Division by zero");
            exit(EXIT_FAILURE);
        }

        result = num2 / num1;
        break;
    }

    // Pushing result in operand stack
    push_operand(or, result);
}

// Function for evaluating the expression
int evaluate_expression(char *expression)
{

    // Declaring operator & operand stack
    operator operatorStack;
    operatorStack.top = -1;
    operand operandStack;
    operandStack.top = -1;

    // Parsing the expression
    int i;
    for ( i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];

        // Ignoring white spaces
        if (isspace(ch))
            continue;

        // Handling integers in expression
        else if (isdigit(ch))
        {
            int num = 0;
            while (isdigit(expression[i]) || isspace(expression[i]))
            {
                if (isdigit(expression[i]))
                {
                    num *= 10;
                    num += expression[i] - '0';
                }
                i++;
            }
            i--;
            push_operand(&operandStack, num);
        }

        // Handling operators in the expression
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (operatorStack.top != -1 && precedance(ch) <= precedance(operatorStack.data[operatorStack.top]))
            {
                solve_operator(&operandStack, &operatorStack);
            }
            push_operator(&operatorStack, ch);
        }

        // Handling other characters
        else
        {
            printf("Invalid expression\n");
            exit(EXIT_FAILURE);
        }
    }

    while (operatorStack.top != -1)
    {
        solve_operator(&operandStack, &operatorStack);
    }

    // Last element in operand stack holds the result
    return operandStack.data[operandStack.top];
}

int main()
{
    // Expression declaration & input
    char expression[MAX_SIZE];
    printf("Enter the expression:\n");
    fgets(expression, MAX_SIZE, stdin);

    // Output generation & display
    int result = evaluate_expression(expression);
    printf("The result of the expression is: %d", result);
    getch();
    return 0;
}
