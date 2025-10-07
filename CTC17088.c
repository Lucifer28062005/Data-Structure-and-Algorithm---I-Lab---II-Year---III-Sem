#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of circular linked list
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (*head == NULL) {
        newNode->next = newNode;  // Points to itself
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

// Function to delete a node with given value
void delete(struct Node** head, int value) {
    if (*head == NULL) return; // Empty list
    struct Node *curr = *head, *prev = NULL;

    // Single node case
    if (curr->data == value && curr->next == *head) {
        free(curr);
        *head = NULL;
        return;
    }

    // Deleting head node
    if (curr->data == value) {
        struct Node* last = *head;
        while (last->next != *head)
            last = last->next;
        last->next = curr->next;
        *head = curr->next;
        free(curr);
        return;
    }

    // Deleting non-head node
    prev = curr;
    curr = curr->next;
    while (curr != *head) {
        if (curr->data == value) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Function to display circular linked list
void display(struct Node* head) {
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
        scanf("%d %d", &op, &value);
        if (op == 1)
            insert(&head, value);
        else if (op == 2)
            delete(&head, value);
    }

    display(head);
    return 0;
}
