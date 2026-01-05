#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void print_int(const void* data) {
    printf("%d -> ", *(int*)data);
}

int compare_str(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

void print_str(const void* data) {
    printf("%s -> ", *(char**)data);
}

int main() {
    GenericList* int_list = create_generic_list(compare_int, print_int);
    
    int values[] = {5, 2, 9, 1, 5, 6};
    for (int i = 0; i < 6; i++) {
        insert_ordered(int_list, &values[i]);
    }
    
    printf("\nLista de inteiros:\n");
    print_list(int_list);
    free_generic_list(int_list);

    GenericList* str_list = create_generic_list(compare_str, print_str);
    
    char* words[] = {"banana", "laranja", "pera", "uva", "kiwi"};
    for (int i = 0; i < 5; i++) {
        insert_ordered(str_list, &words[i]);
    }

    printf("\nLista de strings:\n");
    print_list(str_list);
    free_generic_list(str_list);

    return 0;
}

