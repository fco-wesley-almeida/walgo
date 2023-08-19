#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct stack {
    Node *top; 
} Stack;

Stack* create_stack()
{
    Stack* stack = (Stack *) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = value;
    if (stack->top == NULL) {
        node->next = NULL;
    } else {
        node->next = stack->top;
    }
    stack->top = node;
}

int pull(Stack* stack)
{
    Node* node = stack->top;
    stack->top = stack->top->next;
    int value = node->value;
    free(node);
    return value;
}

void show(Stack* stack)
{
    Node* node_ptr;
    node_ptr = stack->top;
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
    Stack* stack = create_stack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    show(stack);
    pull(stack);
    pull(stack);
    show(stack);
    free(stack);
    return 1;
}


