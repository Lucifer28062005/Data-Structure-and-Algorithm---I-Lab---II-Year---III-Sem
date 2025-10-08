#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node of a doubly linked list
struct Node {
    char *data;
    struct Node *prev;
    struct Node *next;
};

char * midPoint(int N, char *Arr[], int ArrLen) {
    if (N == 0 || ArrLen == 0) return "";

    // Create the head node
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = Arr[0];
    head->prev = NULL;
    head->next = NULL;

    struct Node *temp = head;

    // Build the doubly linked list
    for (int i = 1; i < N; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = Arr[i];
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
    }

    // Use slow and fast pointers to find midpoint
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Return the midpoint data
    return slow->data;
}

// Provided function to read comma-separated string array
int readStringArray(char *argsArray, char *arr[]) {
    int col = 0;
    char *token = strtok(argsArray, ",");
    while (token != NULL) {
        arr[col] = token;
        token = strtok(NULL, ",");
        col++;
    }
    return col;
}

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    char *Arr[strlen(argv[2])];
    int ArrLen = readStringArray(argv[2], Arr);
    printf("%s\n", midPoint(N, Arr, ArrLen));
    return 0;
}
