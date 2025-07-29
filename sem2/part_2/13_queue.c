#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

struct Queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(struct Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool isFull(struct Queue *queue)
{
    return (queue->rear == MAX_SIZE - 1);
}

bool isEmpty(struct Queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

int size(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        return 0;
    }
    return queue->rear - queue->front + 1;
}

void enqueue(struct Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
    }
    else
    {
        if (isEmpty(queue))
        {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = value;
        printf("Enqueued %d into the queue\n", value);
    }
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int dequeuedValue = queue->items[queue->front];
        if (queue->front == queue->rear)
        {
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front++;
        }
        printf("Dequeued %d from the queue\n", dequeuedValue);
        return dequeuedValue;
    }
}

int front(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return queue->items[queue->front];
    }
}

int rear(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return queue->items[queue->rear];
    }
}

int main()
{
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    printf("Front element of the queue: %d\n", front(&queue));
    printf("Rear element of the queue: %d\n", rear(&queue));
    printf("Size of the queue: %d\n", size(&queue));

    dequeue(&queue);
    dequeue(&queue);

    printf("Front element of the queue: %d\n", front(&queue));
    printf("Rear element of the queue: %d\n", rear(&queue));
    printf("Size of the queue: %d\n", size(&queue));

    return 0;
}
