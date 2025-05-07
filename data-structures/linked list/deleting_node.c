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

// Function to delete the first occurrence of a given key in the linked list
struct Node *deleteNode(struct Node *head, int key) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    // If key is found at head
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", key);
        return head;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the linked list
    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return head;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", key);
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
    int key;

    // Create a linked list
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Initial linked list: ");
    display(head);

    printf("\nEnter the element to delete: ");
    scanf("%d", &key);

    head = deleteNode(head, key);

    printf("Updated linked list: ");
    display(head);

    return 0;
}
