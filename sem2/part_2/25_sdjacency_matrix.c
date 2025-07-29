#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph
{
    int vertices;
    int **adjMatrix;
};

// Function to create a new graph with given number of vertices
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    if (graph == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    graph->vertices = vertices;

    // Allocate memory for adjacency matrix
    graph->adjMatrix = (int **)malloc(vertices * sizeof(int *));
    if (graph->adjMatrix == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < vertices; i++)
    {
        graph->adjMatrix[i] = (int *)calloc(vertices, sizeof(int));
        if (graph->adjMatrix[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int source, int destination)
{
    if (source < 0 || source >= graph->vertices || destination < 0 || destination >= graph->vertices)
    {
        printf("Invalid vertex.\n");
        return;
    }

    // Add edge between source and destination
    graph->adjMatrix[source][destination] = 1;
    // If graph is undirected, add the edge from destination to source as well
    // graph->adjMatrix[destination][source] = 1;
}

// Function to print the adjacency matrix representation of the graph
void printGraph(struct Graph *graph)
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free memory allocated for the graph
void freeGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
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

    // Print graph
    printGraph(graph);

    // Free memory
    freeGraph(graph);

    return 0;
}
