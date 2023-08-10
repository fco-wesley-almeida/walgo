#include "stdlib.h"
#include "stdio.h"

typedef struct Graph {
    int vertices;
    int edges;
    int **matrix; 
} Graph;

Graph create_graph(int qtd_vertices)
{
    Graph graph;
    graph.vertices = qtd_vertices;
    graph.edges = 0;
    graph.matrix = (int **) malloc(sizeof(int *) * qtd_vertices);
    for(int i = 0; i < qtd_vertices; i++){
        graph.matrix[i] = (int *) malloc(sizeof(int) * qtd_vertices);
        for (int j = 0; j < qtd_vertices; j++) {
            graph.matrix[i][j] = 0;
        }
    }
    return graph;
}

void create_edge(Graph graph, int vertex_src, int vertex_target)
{
    if (!graph.matrix[vertex_src][vertex_target]) {
        graph.matrix[vertex_src][vertex_target] = 1;
        graph.edges++;
    }
}

void show_graph(Graph graph) {
    for(int i = 0; i < graph.vertices; i++){
        for (int j = 0; j < graph.vertices; j++) {
            printf("%d ", graph.matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Graph graph = create_graph(4);
    create_edge(graph, 0, 2);
    create_edge(graph, 0, 3);
    create_edge(graph, 1, 0);
    create_edge(graph, 1, 2);
    show_graph(graph);
    free(graph.matrix);
    return 1;
}



