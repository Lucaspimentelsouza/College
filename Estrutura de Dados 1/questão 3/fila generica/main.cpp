#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void print_int(void* data) {
    printf("%d ", *(int*)data);
}

void print_str(void* data) {
    printf("%s ", (char*)data);
}

int main() {
    Queue* int_queue = create_queue();
    
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        enqueue(int_queue, &values[i]);
    }
    
    printf("\nDequeuing numeros inteiros:\n");
    while (!is_empty(int_queue)) {
        int* value = (int*)dequeue(int_queue);
        print_int(value);
    }
    printf("\n");

    free_queue(int_queue);
    
    
    
    Queue* str_queue = create_queue();
    
    char* words[] = {"uva", "laranja", "banana", "kiwi", "pera"};
    for (int i = 0; i < 5; i++) {
        enqueue(str_queue, words[i]);
    }
    
    printf("\nDequeuing string elements:\n");
    while (!is_empty(str_queue)) {
        char* word = (char*)dequeue(str_queue);
        print_str(word);
    }
    printf("\n");

    free_queue(str_queue);
    
    return 0;
}

