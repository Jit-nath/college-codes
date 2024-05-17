#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to delete a node with a given key from the linked list
struct Node *deleteNode(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *current = head;
    struct Node *prev = NULL;

    // If the key is found at the head
    if (current->data == key)
    {
        if (current->next != NULL)
        {
            current->next->prev = NULL;
        }
        free(current);
        return NULL;
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

    // Adjust the links
    prev->next = current->next;
    if (current->next != NULL)
    {
        current->next->prev = prev;
    }

    // Free the memory
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
