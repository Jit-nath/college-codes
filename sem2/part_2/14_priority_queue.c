#include <stdio.h>
#include <stdlib.h>

// Structure for representing a node in the heap
struct Node
{
    int data;
    int priority;
};

// Structure for representing a Priority Queue
struct PriorityQueue
{
    struct Node *heap;
    int capacity;
    int size;
};

// Function to create a new node
struct Node *createNode(int data, int priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    return newNode;
}

// Function to initialize a Priority Queue
struct PriorityQueue *initializePriorityQueue(int capacity)
{
    struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    if (pq == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    pq->capacity = capacity;
    pq->size = 0;
    pq->heap = (struct Node *)malloc(capacity * sizeof(struct Node));
    if (pq->heap == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return pq;
}

// Function to swap two nodes in the heap
void swap(struct Node *a, struct Node *b)
{
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the heap property after insertion
void heapifyUp(struct PriorityQueue *pq, int index)
{
    while (index > 0 && pq->heap[index].priority < pq->heap[(index - 1) / 2].priority)
    {
        swap(&pq->heap[index], &pq->heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to maintain the heap property after deletion
void heapifyDown(struct PriorityQueue *pq, int index)
{
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < pq->size && pq->heap[leftChild].priority < pq->heap[smallest].priority)
    {
        smallest = leftChild;
    }
    if (rightChild < pq->size && pq->heap[rightChild].priority < pq->heap[smallest].priority)
    {
        smallest = rightChild;
    }
    if (smallest != index)
    {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapifyDown(pq, smallest);
    }
}

// Function to insert an element with its priority into the Priority Queue
void enqueue(struct PriorityQueue *pq, int data, int priority)
{
    if (pq->size == pq->capacity)
    {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }
    struct Node *newNode = createNode(data, priority);
    pq->heap[pq->size] = *newNode;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

// Function to remove and return the element with the highest priority from the Priority Queue
struct Node dequeue(struct PriorityQueue *pq)
{
    if (pq->size == 0)
    {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        exit(1);
    }
    struct Node root = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return root;
}

// Function to check if the Priority Queue is empty
int isEmpty(struct PriorityQueue *pq)
{
    return pq->size == 0;
}

// Function to return the size of the Priority Queue
int size(struct PriorityQueue *pq)
{
    return pq->size;
}

int main()
{
    struct PriorityQueue *pq = initializePriorityQueue(10);

    enqueue(pq, 10, 3);
    enqueue(pq, 20, 2);
    enqueue(pq, 30, 5);
    enqueue(pq, 40, 1);

    printf("Size of Priority Queue: %d\n", size(pq));

    while (!isEmpty(pq))
    {
        struct Node node = dequeue(pq);
        printf("Data: %d, Priority: %d\n", node.data, node.priority);
    }

    return 0;
}
