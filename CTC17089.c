#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void insert(int x) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->prev = tail;
    newnode->next = NULL;
    if (tail != NULL) {
        tail->next = newnode;
    } else {
        head = newnode;
    }
    tail = newnode;
}

void delete_val(int x) {
    struct Node* curr = head;
    while (curr != NULL) {
        if (curr->data == x) {
            if (curr->prev != NULL) {
                curr->prev->next = curr->next;
            } else {
                head = curr->next;
            }
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            } else {
                tail = curr->prev;
            }
            free(curr);
            return;
        }
        curr = curr->next;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 1) {
            insert(x);
        } else if (op == 2) {
            delete_val(x);
        }
    }
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
