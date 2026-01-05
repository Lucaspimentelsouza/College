#ifndef STACK_H
#define STACK_H

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int elementSize;
} Stack;

void initializeStack(Stack *stack, int elementSize);
int isEmpty(Stack *stack);
void push(Stack *stack, void *element);
void pop(Stack *stack, void *element);
void peek(Stack *stack, void *element);
void destroyStack(Stack *stack);

#endif

