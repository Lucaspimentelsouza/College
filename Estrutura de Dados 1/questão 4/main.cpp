#include <stdio.h>
#include "queue.h"

int main() {
	Queue *queue = createQueue();
    //   -+*9+28*+4863
    
    pegar_elemento(queue);
    
    int result = prefixa(queue);
    
    printf("\nResultado: %d\n", result);
    return 0;
}

