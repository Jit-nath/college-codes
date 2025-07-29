#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node
{
    int dest;
    struct Node *next;
};

// Structure to represent the adjacency list
struct AdjList
{
    struct Node *head;
};

// Structure to represent the graph
struct Graph
{
    int vertices;
    struct AdjList *array;
};

// Function to create a new node
struct Node *createNode(int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with given number of vertices
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    if (graph == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    graph->vertices = vertices;

    // Create an array of adjacency lists. Size of the array is the number of vertices.
    graph->array = (struct AdjList *)malloc(vertices * sizeof(struct AdjList));
    if (graph->array == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < vertices; i++)
    {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Function to perform Breadth-First Search (BFS)
void BFS(struct Graph *graph, int startVertex)
{
    int visited[graph->vertices];
    for (int i = 0; i < graph->vertices; i++)
    {
        visited[i] = 0; // Mark all vertices as not visited
    }

    // Create a queue for BFS
    int queue[graph->vertices];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

    while (front != rear)
    {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex currentVertex
        // If an adjacent vertex has not been visited, then mark it visited and enqueue it
        struct Node *temp = graph->array[currentVertex].head;
        while (temp != NULL)
        {
            int adjVertex = temp->dest;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Function to perform Depth-First Search (DFS) starting from a given vertex
void DFSUtil(struct Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node *temp = graph->array[vertex].head;
    while (temp != NULL)
    {
        int adjVertex = temp->dest;
        if (!visited[adjVertex])
        {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform Depth-First Search (DFS)
void DFS(struct Graph *graph, int startVertex)
{
    int visited[graph->vertices];
    for (int i = 0; i < graph->vertices; i++)
    {
        visited[i] = 0; // Mark all vertices as not visited
    }

    printf("Depth-First Traversal starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Function to free memory allocated for the graph
void freeGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *temp = graph->array[i].head;
        while (temp != NULL)
        {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->array);
    free(graph);
}

int main()
{
    int vertices, edges, source, destination;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Create graph
    struct Graph *graph = createGraph(vertices);

    // Input edges
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(graph, source, destination);
    }

    // Perform Breadth-First Search (BFS)
    printf("\n");
    BFS(graph, 0); // Start BFS from vertex 0

    // Perform Depth-First Search (DFS)
    DFS(graph, 0); // Start DFS from vertex 0

    // Free memory
    freeGraph(graph);

    return 0;
}
