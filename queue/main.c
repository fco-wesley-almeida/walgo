#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct queue {
    Node *begin; 
    Node *end; 
} Queue;

Queue* create_queue()
{
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->begin = NULL;
    queue->end = NULL;
    return queue;
}

void push(Queue* queue, int value)
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

int pull(Queue *queue)
{
    Node* node = queue->begin;
    int value = node->value;
    queue->begin = queue->begin->next;
    free(node);
    return value;
}

void show(Queue *queue) {
    Node *node_ptr;
    node_ptr = queue->begin;
    printf("\nQueue: ");
    while(node_ptr != NULL) {
        printf("%d ", node_ptr->value);
        node_ptr = node_ptr->next;
    }
    printf("\n");
}

int main()
{
    Queue* queue = create_queue();
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    push(queue, 4);
    push(queue, 5);
    show(queue);
    pull(queue);
    pull(queue);
    show(queue);
    free(queue);
    return 0;
}


