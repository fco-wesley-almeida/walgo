// 1 2 3 4
#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int value;
    struct node *next;
} Node;

Node* create_stack()
{
    return NULL;
}

void push(Node* stack, int value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    if (stack == NULL) {
        node->next = NULL;
    } else {
        node->next = stack;
    }
    stack = node;
}

int pull(Node* stack)
{
    int value;
    value = stack->value;
    stack = stack->next;
    // Node* node = stack;
    // Node* node = stack;
    // int value = node->value;
    // free(node);
    // stack = stack->next;
    return value;
}

void show(Node* stack)
{
    Node* node_ptr;
    node_ptr = stack;
    printf("\nStack: ");
    while(node_ptr != NULL)
    {
        printf("%d ", node_ptr->value);
        node_ptr = node_ptr->next;
    }
    printf("\n");
}

int main()
{
    Node* stack = create_stack();
    printf("%d", stack);
    push(stack, 1);
    printf("%d", stack);
    push(stack, 2);
    printf("%d", stack);
    push(stack, 3);
    printf("%d", stack);
    push(stack, 4);
    printf("%d", stack);
    push(stack, 5);
    show(stack);
    printf("%d", stack);
    // pull(stack);
    // pull(stack);
    // show(stack);
    free(stack);
    return 1;
}


