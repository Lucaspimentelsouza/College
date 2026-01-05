#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node{ // struct do no
	char caractere;
	int data;
	struct Node *prev;
	struct Node *next;
}Node;

typedef struct Queue {
    Node *end;
	Node *begin;
	int size;
} Queue;

Node *Node_create(int val, char caractere);

Queue* createQueue();
void enqueue(Queue *q, int data, char caractere);
int dequeue(Queue *q);
int isEmpty(Queue *q);
void destroyQueue(Queue *q);
int Int_Dequeue(Queue *queue);
char Char_Dequeue(Queue *queue);
bool queue_empty(const Queue *queue);

int prefixa(Queue *queue);
void pegar_elemento(Queue *queue);

#endif

