#include <stdio.h>

#define MAX 10005

int stack[MAX];
int top_idx = -1;

void push(int x) {
    if (top_idx < MAX - 1) {
        stack[++top_idx] = x;
    }
}

int pop() {
    if (top_idx >= 0) {
        return stack[top_idx--];
    }
    return -1; // Error case, but assume not empty
}

void insert_bottom(int x) {
    if (top_idx == -1) {
        push(x);
        return;
    }
    int temp = pop();
    insert_bottom(x);
    push(temp);
}

void reverse_stack() {
    if (top_idx == -1) {
        return;
    }
    int temp = pop();
    reverse_stack();
    insert_bottom(temp);
}

int main() {
    int N;
    scanf("%d", &N);
    
    // Read and push elements (loop here is for input, reversal is recursive)
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }
    
    // Reverse the stack recursively
    reverse_stack();
    
    // Print the reversed stack from bottom to top (loop for output)
    if (top_idx >= 0) {
        printf("%d", stack[0]);
        for (int i = 1; i <= top_idx; i++) {
            printf(" %d", stack[i]);
        }
    }
    printf("\n");
    
    return 0;
}
