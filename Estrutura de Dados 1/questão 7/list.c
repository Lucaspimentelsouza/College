#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* create_node(const char* city, int population) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->city, city);
    new_node->population = population;
    new_node->next = NULL;
    return new_node;
}

// Função para inserir um nó de forma ordenada na lista correspondente ao ano
void insert_ordered(Node** head, const char* city, int population) {
    Node* new_node = create_node(city, population);
    if (*head == NULL || (*head)->population <= new_node->population) {
        new_node->next = *head;
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->population > new_node->population) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insert_data(MultiLinkedList* list, const char* city, int population_2000, int population_1990) {
    insert_ordered(&list->head_2000, city, population_2000);
    insert_ordered(&list->head_1990, city, population_1990);
}

void print_list(Node* head, int year) {
    printf("\n\nCensus population %d: \n", year);
    Node* current = head;
    while (current != NULL) {
        printf("%s: %d \n", current->city, current->population);
        current = current->next;
    }
}

MultiLinkedList* create_multi_linked_list() {
    MultiLinkedList* list = (MultiLinkedList*) malloc(sizeof(MultiLinkedList));
    list->head_2000 = NULL;
    list->head_1990 = NULL;
    return list;
}

void free_list(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void free_multi_linked_list(MultiLinkedList* list) {
    free_list(list->head_2000);
    free_list(list->head_1990);
    free(list);
}

