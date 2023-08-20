#include "stdlib.h"
#include "stdio.h"

typedef struct coordinate {
    int x;
    int y;
} Coordinate; 

typedef struct node {
    Coordinate* value;
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

void queue_push(Queue* queue, Coordinate* value)
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

Coordinate* queue_pull(Queue *queue)
{
    Node* node = queue->begin;
    Coordinate* value = node->value;
    queue->begin = queue->begin->next;
    free(node);
    return value;
}

void queue_show(Queue *queue) {
    Node *node_ptr;
    node_ptr = queue->begin;
    printf("\nQueue: ");
    while(node_ptr != NULL) {
        printf("(%d, %d) ", node_ptr->value->x, node_ptr->value->y);
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
    for (int i = 0; i < vector_size; i++) {
        printf("%d", vector[i]);
        if (i != vector_size - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

Coordinate* create_coordinate(int x, int y)
{
    Coordinate *cor = (Coordinate *) malloc(sizeof(Coordinate));
    cor->x = x;
    cor->y = y;
    return cor;
}

void free_matrix_2_dimensions(int width, int height, int **m) {
    for (int i = 0; i < width; i++) {
        free(m[i]);
    }
    free(m);
}

void free_matrix_3_dimensions(int width, int height, int ***m) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            free(m[i][j]);
        }
        free(m[i]);
    }
    free(m);
}


int bfs(int dimension, int** m, Coordinate p, Coordinate q)
{
    int ***visited;
    Queue* queue;
    Coordinate* cor;
    int i, j, x, y, k;

    if (m[q.x][q.y]) {
        return -1;
    }

    visited = (int ***) malloc(dimension * sizeof(int **));
    for(int i = 0; i < dimension; i++) {
       visited[i] =  (int **) malloc(dimension * sizeof(int *));
       for(int j = 0; j < dimension; j++) {
            visited[i][j] = (int *) malloc(2 * sizeof(int));
            visited[i][j][0] = -1; 
            visited[i][j][1] = -1; 
       }
    }
    queue = queue_create();
    visited[p.x][p.y][0] = 1;
    queue_push(queue, &p);
    while(!queue_is_empty(queue)) {
        cor = queue_pull(queue);
        for(int i = 0; i < 4; i++) {
            x = i & 1 ? cor->x : cor->x + (!i ? 1 : -1);
            y = !(i & 1) ? cor->y : cor->y + (i ? 1 : -1);
            if (x >= dimension || y >= dimension || x < 0 || y < 0 || m[x][y] || visited[x][y][1] >= 0) {
                continue;
            }
            visited[x][y][0] = cor->x;
            visited[x][y][1] = cor->y;
            queue_push(queue, create_coordinate(x, y));
        }
    }
    x = q.x;
    y = q.y;
    k = 0;
    while(x != p.x || y != p.y) {
        i = visited[x][y][0]; 
        j = visited[x][y][1]; 
        x = i;
        y = j;
        if (x == -1) {
            k = -1;
            break;
        }
        k++;
    }
    free_matrix_3_dimensions(dimension, dimension, visited);
    free(queue);
    free(cor);
    return k;
}

//     0 1 2 3
//     | | | |
// 0 - 0 1 0 0
// 1 - 0 1 1 0
// 2 - 0 0 0 1
// 3 - 0 0 0 0

int main()
{
    int dimension;
    int **m;

    dimension = 4;

    m = (int **) malloc(dimension * sizeof(int *));
    for(int i = 0; i < dimension; i++) {
        m[i] =(int *) malloc(dimension * sizeof(int));
        for(int j = 0; j < dimension; j++) {
            m[i][j] = 0;
        }
    }
    m[0][1] = 1;
    m[1][1] = 1;
    m[1][2] = 1;
    m[2][3] = 1;

    int result = bfs(dimension, m, *create_coordinate(0,0), *create_coordinate(3,2));
    printf("%d\n", result);
    free_matrix_2_dimensions(dimension, dimension, m);
    return 0;
}