#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *createNode(int data){
    Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insertNode(Node* head, int data){
    Node *newNode = createNode(data);
    if (head != NULL)
    {
        Node *current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
    else
        head = newNode;
    return head;
}

Node *deleteNode(Node *head, int key){
    Node *current = head, *prev = NULL;

    if (current != NULL && current->data == key)
    {
        Node *temp = current;
        head = head->next;
        free(temp);
        return head;
    }

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Key not found in the list.\n");
        return head;
    }

    prev->next = current->next;
    free(current);
    return head;
}

void printList(Node *head){
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    Node *head = NULL;

    head = insertNode(head, 5);
    head = insertNode(head, 3);
    head = insertNode(head, 8);
    head = insertNode(head, 10);

    printf("Linked list after insertion: ");
    printList(head);

    int key = 3;
    head = deleteNode(head, key);

    printf("Linked list after deleting %d: ", key);
    printList(head);

    return 0;
}
