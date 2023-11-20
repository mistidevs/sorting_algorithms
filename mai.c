#include <stdio.h>
#include <stdlib.h>

// Define a basic Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to add a new node at the beginning of the list
void addNodeAtBeginning(Node** head, int newData) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Set data and next for the new node
    newNode->data = newData;
    newNode->next = *head;

    // Update the head to point to the new node
    *head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize an empty linked list
    Node* head = NULL;

    // Add nodes to the linked list
    addNodeAtBeginning(&head, 3);
    addNodeAtBeginning(&head, 2);
    addNodeAtBeginning(&head, 1);

    // Print the linked list
    printf("Original linked list: ");
    printList(head);

    // Manipulate the linked list within a function
    // (Here, we are just adding a node at the beginning again)
    addNodeAtBeginning(&head, 4);

    // Print the modified linked list
    printf("Modified linked list: ");
    printList(head);

    return 0;
}

