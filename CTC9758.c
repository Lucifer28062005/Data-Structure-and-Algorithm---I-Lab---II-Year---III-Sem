#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to return precedence of operators
int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to check if operator is right-associative
int isRightAssociative(char op) {
    return op == '^';
}

// Function to check if character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Main function to convert infix to postfix
char * InfixToPostfix(char *expr) {
    int MAX = strlen(expr);
    char *postfix = (char *)malloc(MAX + 1);  // Output string
    char *stack = (char *)malloc(MAX);        // Operator stack
    int top = -1, k = 0;

    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];

        if (isalnum(ch)) {
            // Operand: add to postfix
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            stack[++top] = ch;
        }
        else if (ch == ')') {
            // Pop until '(' is found
            while (top >= 0 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--; // discard '('
            }
        }
        else if (isOperator(ch)) {
            while (top >= 0 && stack[top] != '(' &&
                ((precedence(stack[top]) > precedence(ch)) ||
                (precedence(stack[top]) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    // Pop remaining operators
    while (top >= 0) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';
    free(stack); // Clean up
    return postfix;
}

// Driver code
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s \"infix_expression\"\n", argv[0]);
        return 1;
    }

    char *expr = argv[1];
    char *postfix = InfixToPostfix(expr);
    printf("%s\n", postfix);
    free(postfix); // Clean up
    return 0;
}
