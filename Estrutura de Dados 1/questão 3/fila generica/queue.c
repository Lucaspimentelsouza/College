#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->end = NULL;
    queue->size = 0;
    return queue;
}

Node* create_node(void* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//enfileirar
void enqueue(Queue* queue, void* data) {
    Node* new_node = create_node(data);
    if (queue->end == NULL) {
        queue->front = new_node;
        queue->end = new_node;
    } else {
        queue->end->next = new_node;
        queue->end = new_node;
    }
    queue->size++;
}

void* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    Node* temp = queue->front;
    void* data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->end = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

int is_empty(Queue* queue) {
    return queue->size == 0;
}

void free_queue(Queue* queue) {
    Node* current = queue->front;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}

