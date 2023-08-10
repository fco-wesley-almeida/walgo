#include "stdlib.h"
#include "stdio.h"

typedef struct Graph {
    int size;
    Vertex* vertices;
} Graph;


typedef struct Vertex {
    int value;
    LinkedListNode* linkedList;
} Vertex;

typedef struct LinkedListNode {
    int vertex;
    struct LinkedListNode* next;
} LinkedListNode;


Graph* create_graph()
{
    Graph* graph_ptr = (Graph*) malloc(sizeof(Graph)); 
    graph_ptr->size = 0;
    graph_ptr->vertices = (Vertex*) malloc(sizeof(Vertex));
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
    node->vertex = vertex_target->value;
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
            printf(" => %d", node_ptr->vertex);
            node_ptr = node_ptr->next;
        }
        printf("\n");
    }
}
int main()
{
    Graph* graph;
    Vertex* v1;
    Vertex* v2;
    Vertex* v3;
    Vertex* v4;
    Vertex* v5;
    graph = create_graph();
    v1 = create_vertex(graph, 1);
    v2 = create_vertex(graph, 2);
    v3 = create_vertex(graph, 3);
    v4 = create_vertex(graph, 4);
    v5 = create_vertex(graph, 5);
    create_node(graph, v1, v4);
    create_node(graph, v1, v3);
    create_node(graph, v4, v1);
    create_node(graph, v3, v2);
    create_node(graph, v5, v4);
    create_node(graph, v1, v5);
    show_graph(graph);
    free(graph);
    return 0;
}
