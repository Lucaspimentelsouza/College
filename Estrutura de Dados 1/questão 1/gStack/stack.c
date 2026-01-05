#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void initializeStack(Stack *stack, int elementSize) {
    stack->top = NULL;
    stack->elementSize = elementSize;
}

int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

void push(Stack *stack, void *element) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = malloc(stack->elementSize);
    memcpy(newNode->data, element, stack->elementSize);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack *stack, void *element) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = stack->top;
    memcpy(element, temp->data, stack->elementSize);
    stack->top = stack->top->next;
    free(temp->data);
    free(temp);
}

void peek(Stack *stack, void *element) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    memcpy(element, stack->top->data, stack->elementSize);
}

void destroyStack(Stack *stack) {
    while (!isEmpty(stack)) {
        Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp->data);
        free(temp);
    }
}

