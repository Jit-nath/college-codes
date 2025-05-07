#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at any position in the linked list
struct Node *insertAtPosition(struct Node *head, int data, int position) {
    struct Node *newNode = createNode(data);

    // If position is 1, insert at the beginning
    if (position == 1) {
        newNode->next = head;
        printf("Inserted %d at position %d.\n", data, position);
        return newNode;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    // Traverse the list to find the position
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If position is beyond the end of the list, insert at the end
    if (temp == NULL && prev != NULL) {
        prev->next = newNode;
        printf("Inserted %d at the end.\n", data);
    } else if (temp != NULL) { // Insert at the specified position
        prev->next = newNode;
        newNode->next = temp;
        printf("Inserted %d at position %d.\n", data, position);
    } else { // Invalid position
        printf("Invalid position!\n");
        free(newNode);
    }

    return head;
}

// Function to display the linked list
void display(struct Node *head) {
    printf("Linked list: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int data, position;

    // Create a linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Initial linked list: ");
    display(head);

    printf("\nEnter the data to insert: ");
    scanf("%d", &data);

    printf("Enter the position to insert: ");
    scanf("%d", &position);

    head = insertAtPosition(head, data, position);

    printf("Updated linked list: ");
    display(head);

    return 0;
}