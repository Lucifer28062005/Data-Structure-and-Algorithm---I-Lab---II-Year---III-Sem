#include <stdio.h>
#include <stdlib.h>

// Define the structure for doubly circular linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node at the end
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node* last = (*head)->prev;

    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
}

// Function to delete the last node
void deleteLast(struct Node** head) {
    if (*head == NULL) return; // Empty list

    struct Node* last = (*head)->prev;

    // Only one node
    if (last == *head) {
        free(last);
        *head = NULL;
        return;
    }

    struct Node* secondLast = last->prev;
    secondLast->next = *head;
    (*head)->prev = secondLast;
    free(last);
}

// Function to traverse and display the list
void traverse(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int op, value;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &value);
            insert(&head, value);
        } else if (op == 2) {
            deleteLast(&head);
        }
    }

    traverse(head);
    return 0;
}
