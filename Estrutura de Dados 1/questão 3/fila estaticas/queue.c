#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _static_queue{
	int *data;
	int capacity;
	int size;
	int begin;
	int end;
}StaticQueue;

StaticQueue *StaticQueue_create(int capacity){
	StaticQueue *Q = (StaticQueue*) calloc(1, sizeof(StaticQueue));
	Q->capacity = capacity;
	
	Q->data = (int*) calloc(capacity, sizeof(int));
	Q->size = 0;
	Q->begin = 0;
	Q->end= 0;
	
	return Q;	
}

void StaticQueue_destroy(StaticQueue **Q_ref){
	StaticQueue *Q = *Q_ref;
	
	free(Q->data);
	free(Q);
	
	*Q_ref = NULL;
}

bool StaticQueue_is_empty(const StaticQueue *Q){
	return Q->size == 0;
}

bool StaticQueue_is_full(const StaticQueue *Q){
	return Q->size == Q->capacity;
}

int StaticQueue_size(const StaticQueue *Q){
	return Q->size;
}

void StaticQueue_enqueue(StaticQueue *Q, int val){
	if(StaticQueue_is_full(Q)){
		fprintf(stderr, "ERROR in 'StaticQueue_enqueue'\n");
		fprintf(stderr, "A fila esta cheia");
		exit(EXIT_FAILURE);
	}
	
	Q->data[Q->end] = val;
	Q->end = (Q->end + 1) % Q->capacity;
	Q->size++;
}

int StaticQueue_peek(const StaticQueue *Q){
	if(StaticQueue_is_empty(Q)){
		fprintf(stderr, "ERROR in 'StaticQueue_peek'\n");
		fprintf(stderr, "A fila esta vazia");
		exit(EXIT_FAILURE);
	}
	return Q->data[Q->begin];
}

int StaticQueue_dequeue(StaticQueue *Q){
	if(StaticQueue_is_empty(Q)){
		fprintf(stderr, "ERROR in 'StaticQueue_dequeue'\n");
		fprintf(stderr, "A fila esta vazia");
		exit(EXIT_FAILURE);
	}
	int val = Q->data[Q->begin];
	Q->begin = (Q->begin + 1) % Q->capacity;
	Q->size--;
	return val;
}

void StaticQueue_print(const StaticQueue *Q){
	printf("capacity: %d\n", Q->capacity);
	printf("size: %d\n", Q->size);
	printf("begin: %d\n", Q->begin);
	printf("end: %d\n", Q->end);
	
	int i, s;
	for(s = 0, i = Q->begin; s < Q->size; s++, i = (i + 1) % Q->capacity){
		printf("%d, ", Q->data[i]);
	}
	puts("");
}














