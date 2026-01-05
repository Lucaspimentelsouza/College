#include <stdio.h>
#include <string.h>
#include "stack.h"

int main() {
    //int array[] = {1, 2, 3, 4, 5};
    char array[] = {"Alo"};
    //int size = sizeof(array) / sizeof(array[0]);
	int size = strlen(array);
	printf("%d", strlen(array));
    
    printf("\nOriginal: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", array[i]);
    }
    printf("\n");
    
    return 0;
}

