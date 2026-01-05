#ifndef HEAP_H
#define HEAP_H


#include <stdbool.h>

typedef struct{
	void** heapAry;
	int last;
	int size;
	int (*compare) (void* arg1, void* arg2);
	int maxSize;
} HEAP;

HEAP* heapCreate(int maxSize, int (*compare) (void* arg1, void* arg2));
bool heapInsert (HEAP* heap, void* data);
bool heapDelete (HEAP* heal, void** dataout);
int heapCount (HEAP* heap);
bool heapFull (HEAP* heap);
bool heapEmpty (HEAP* heap);
void heapDestroy (HEAP* heap);

static void _reheapUp (HEAP* heap, int chilldLoc);
static void _reheapDown (HEAP* heap, int root);
