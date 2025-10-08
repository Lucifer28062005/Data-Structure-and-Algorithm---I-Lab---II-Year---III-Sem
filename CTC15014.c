#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack implementation for characters
typedef struct {
    char *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (char *)malloc(sizeof(char) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack *stack, char ch) {
    if (stack->top < stack->capacity - 1)
        stack->data[++(stack->top)] = ch;
}

char pop(Stack *stack) {
    if (stack->top >= 0)
        return stack->data[(stack->top)--];
    return '\0';  // Return null char if stack is empty
}

char peek(Stack *stack) {
    if (stack->top >= 0)
        return stack->data[stack->top];
    return '\0';
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Main function to check balanced brackets
char * BalancedBrackets(char *str) {
    int len = strlen(str);
    Stack *stack = createStack(len);

    for (int i = 0; i < len; i++) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(stack) || !isMatchingPair(pop(stack), ch)) {
                free(stack->data);
                free(stack);
                return "Not balanced";
            }
        }
    }

    char *result = isEmpty(stack) ? "Balanced" : "Not balanced";
    free(stack->data);
    free(stack);
    return result;
}

// Driver code
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s \"bracket_string\"\n", argv[0]);
        return 1;
    }

    char *str = argv[1];
    printf("%s\n", BalancedBrackets(str));
    return 0;
}
