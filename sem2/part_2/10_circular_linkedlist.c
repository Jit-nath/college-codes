#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
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

// Function to insert a node into a circular linked list
struct Node *insertNode(struct Node *last, int data)
{
    if (last == NULL)
    {
        struct Node *newNode = createNode(data);
        newNode->next = newNode; // Circular link for the first node
        return newNode;
    }

    struct Node *newNode = createNode(data);
    newNode->next = last->next;
    last->next = newNode;
    return newNode;
}

// Function to delete a node with a given key from a circular linked list
struct Node *deleteNode(struct Node *last, int key)
{
    if (last == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *current = last->next;
    struct Node *prev = last;

    // If the list contains only one node
    if (current == last && current->data == key)
    {
        free(current);
        return NULL;
    }

    // If the key is found at the head
    if (current->data == key)
    {
        prev->next = current->next;
        free(current);
        return prev;
    }

    // Search for the key to be deleted
    do
    {
        if (current->data == key)
        {
            prev->next = current->next;
            free(current);
            return last;
        }
        prev = current;
        current = current->next;
    } while (current != last->next);

    // If the key was not found
    printf("Key not found in the list.\n");
    return last;
}

// Function to print the circular linked list starting from the last node
void printList(struct Node *last)
{
    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = last->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main()
{
    struct Node *last = NULL;

    // Inserting elements into the circular linked list
    last = insertNode(last, 5);
    last = insertNode(last, 3);
    last = insertNode(last, 8);
    last = insertNode(last, 10);

    printf("Circular linked list after insertion: ");
    printList(last);

    // Deleting an element from the circular linked list
    int key = 3;
    last = deleteNode(last, key);

    printf("Circular linked list after deleting %d: ", key);
    printList(last);

    return 0;
}
