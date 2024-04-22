#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node *insertNode(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to delete a node with a given key from the linked list
struct Node *deleteNode(struct Node *head, int key)
{
    struct Node *current = head, *prev = NULL;

    // If the key is found at the head
    if (current != NULL && current->data == key)
    {
        struct Node *temp = current;
        head = head->next;
        free(temp);
        return head;
    }

    // Search for the key to be deleted
    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    // If the key was not found
    if (current == NULL)
    {
        printf("Key not found in the list.\n");
        return head;
    }

    // Unlink the node from the linked list
    prev->next = current->next;
    free(current);
    return head;
}

// Function to print the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Inserting elements into the linked list
    head = insertNode(head, 5);
    head = insertNode(head, 3);
    head = insertNode(head, 8);
    head = insertNode(head, 10);

    printf("Linked list after insertion: ");
    printList(head);

    // Deleting an element from the linked list
    int key = 3;
    head = deleteNode(head, key);

    printf("Linked list after deleting %d: ", key);
    printList(head);

    return 0;
}
