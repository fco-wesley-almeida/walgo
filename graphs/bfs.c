#include "stdlib.h"
#include "stdio.h"

struct LinkedListNode; 

typedef struct Vertex {
    int value;
    struct LinkedListNode* linkedList; // Use the forward declared struct
} Vertex;

typedef struct LinkedListNode {
    Vertex *vertex;
    struct LinkedListNode* next;
} LinkedListNode;

typedef struct Graph {
    int size;
    Vertex* vertices;
} Graph;


Graph* create_graph()
{
    Graph* graph_ptr = (Graph*) malloc(sizeof(Graph)); 
    graph_ptr->size = 0;
    graph_ptr->vertices = (Vertex*) malloc(100 * sizeof(Vertex));
    return graph_ptr;
}

Vertex* create_vertex(Graph* graph, int value) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->value = value;
    vertex->linkedList = NULL;
    graph->vertices[graph->size] = *vertex;
    return &graph->vertices[graph->size++]; 
}

int create_node(Graph* graph, Vertex* vertex_source, Vertex* vertex_target) {
    if(vertex_source == vertex_target) {
        perror("It is not possible to create a circular node.");
        return 0;
    }
    LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    node->vertex = vertex_target;
    node->next = NULL;
    if (vertex_source->linkedList == NULL) {
        vertex_source->linkedList = node;
    } else {
        LinkedListNode* node_ptr = vertex_source->linkedList;
        while (node_ptr->next != NULL) {
            node_ptr = node_ptr->next;
        }
        node_ptr->next = node;
    }
    return 1;
}

void show_graph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        printf("Vertex = %d", graph->vertices[i].value);
        LinkedListNode* node_ptr = graph->vertices[i].linkedList;
        while (node_ptr != NULL) {
            printf(" => %d", node_ptr->vertex->value);
            node_ptr = node_ptr->next;
        }
        printf("\n");
    }
}


typedef struct node {
    Vertex* value;
    struct node *next;
} Node;

typedef struct queue {
    Node *begin; 
    Node *end; 
} Queue;

Queue* queue_create()
{
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->begin = NULL;
    queue->end = NULL;
    return queue;
}

int queue_is_empty(Queue *queue)
{
    int is_empty = queue->begin == NULL;
    return is_empty;
}

void queue_push(Queue* queue, Vertex* value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    if (queue->begin == NULL) {
        queue->begin = node;
    } 
    if (queue->end == NULL) {
        queue->end = node;
    } else {
        queue->end->next = node;
        queue->end = node;
    }
}

Vertex* queue_pull(Queue *queue)
{
    Node* node = queue->begin;
    Vertex* value = node->value;
    queue->begin = queue->begin->next;
    free(node);
    return value;
}

void queue_show(Queue *queue) {
    Node *node_ptr;
    node_ptr = queue->begin;
    printf("\nQueue: ");
    while(node_ptr != NULL) {
        printf("%d ", node_ptr->value->value);
        node_ptr = node_ptr->next;
    }
}

int vector_contains(int length, int *arr, int value) {
    for(int i = 0; i < length; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

void vector_print(int vector_size, int* vector)
{
    for (int i = 0; i < vector_size; i++) 
    {
        printf("%d", vector[i]);
        if (i != vector_size - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}


int* bfs(Graph* graph, Vertex* v)
{
    int* visited = (int *) malloc(graph->size * sizeof(int));
    int* output = (int *) malloc(graph->size * sizeof(int));
    int output_index;
    Queue *queue;
    LinkedListNode* node_ptr;
    Vertex* adjacent_vertex;

    for(int i = 0; i < 10; i++) {
        visited[i] = 0;
    }
    visited[v->value] = 1;

    output_index = 0;
    output[output_index++] = v->value;

    queue = queue_create();
    queue_push(queue, v);

    while(!queue_is_empty(queue)) {
        adjacent_vertex = queue_pull(queue);
        for(node_ptr = adjacent_vertex->linkedList; node_ptr != NULL; node_ptr = node_ptr->next) {
            if (visited[node_ptr->vertex->value]) {
                continue;
            }
            output[output_index++] = node_ptr->vertex->value;
            visited[node_ptr->vertex->value] = 1;
            queue_push(queue, node_ptr->vertex);
        }
    }
    free(visited);
    free(queue);
    return output;
}

int main()
{
    Graph* graph;
    int* output;
    Vertex **v; 
    
    v = (Vertex **) malloc(15 * sizeof(Vertex *));
    graph = create_graph();
    for(int i = 1; i <= 9; i++) {
        v[i] = create_vertex(graph, i);
    }
    create_node(graph, v[1], v[2]);
    create_node(graph, v[1], v[9]);
    create_node(graph, v[9], v[3]);
    create_node(graph, v[9], v[7]);
    create_node(graph, v[3], v[4]);
    create_node(graph, v[3], v[5]);
    create_node(graph, v[3], v[6]);
    create_node(graph, v[5], v[8]);
    create_node(graph, v[7], v[6]);
    create_node(graph, v[7], v[8]);
    output = bfs(graph, v[1]);
    vector_print(graph->size, output);
    free(graph);
    free(output);
    free(v);
    return 0;
}