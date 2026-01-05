#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* end;
    int size;
} Queue;

Queue* create_queue();

void enqueue(Queue* queue, void* data);
void* dequeue(Queue* queue);
int is_empty(Queue* queue);
void free_queue(Queue* queue);

#endif

