#include "heap.h"

#include "math.h"

HEAP* heapCreate (int maxSize, int (*compare) (void* arg1, void* arg2)){
	HEAP* heap;
	
	heap = (HEAP*) malloc(sizeof(HEAP));
	
	if(!heap){
		return NULL;
	}
	heap->size = 0;
	heap->last = -1;
	heap->compare = compare;
	
	heap->maxSize = (int) pow (2, ceil(log2(maxSize))) -1;
	heap->heapAry = (void*) calloc(heap->maxSize, sizeof(void*));
	
	return heap;
}

bool heapInsert(HEAP* heap, void* data){
	if(heap->size = 0){
		heap->size = 1;
		heap->last = 0;
		heap->heapAry[heap->last] = data;
		return true;
	}
	if(heap->last == (heap->maxSize - 1)){
		return false;
		++(heap->last);
		++(heap->size);
		heap->heapAry[heap->last] = data;
		_reheapUp (heap, heap->last);
		return true;
	}
}

void _reheapUp (HEAP* heap, int childLoc){
	int parent;
	void** heapAry;
	void* hold;
	
	if(childLock){
		heapAry = heap->heapAry;
		parent = (childLoc - 1) / 2;
		if(heap->compare(heapAry[childLoc], heapAry[parent]) > 0){
			hold = heapAry[parent];
			heapAry[parent] = heapAry[childLoc];
			heapAry[childLoc] = hold;
			_reheapUp (heap, parent);
		}
	}
	return;
}

bool heapDelete (HEAP* heap, void** dataOut){
	if(heap->size == 0){
		return false;
	}
	*dataOut = heap->heapAry[0];
	heap->heapAry[0] = heap->heapAry[heap->last];
	(heap->last)--;
	(heap->size)--;
	_reheapDown (heap, 0);
	return true;
}

void _reheapDown (HEAP* heap, int root){
	void* hold;
	void* leftdata;
	void* rightdata;
	int largeLoc;
	int last;
	
	last = heap->last;
	if((root * 2 + 1) <= last){
		leftdata = heap->heapAry[root * 2 + 1];
		if((root * 2 + 2) <= last){
			rightdata = heap->heapAry[root * 2 + 2];
		}
		else{
			rightdata = NULL;
		}
		
		if((!rightdata) || heap->compare (leftdata, rightdata) > 0){
			largeLoc = root * 2 + 1;
		}
		else{
			largeLoc = root * 2 + 2;
		}
		
		if(heap->compare (heap->heapAry[root], heap->heapAry[largeLoc]) < 0){
			hold = heap->heapAry[root];
			heap->heapAry[root] = heap->heapAry[largeLoc];
			heap->heapAry[largeLoc] = hold;
			_reheapDown (heap, largeLoc);
		}
	}
	return;
}







