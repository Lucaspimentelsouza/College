#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node* create_node(void* data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_ordered(GenericList* list, void* data) {
    Node* new_node = create_node(data);
    if (list->head == NULL || list->compare(data, list->head->data) <= 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL && list->compare(data, current->next->data) > 0) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void print_list(const GenericList* list) {
    Node* current = list->head;
    while (current != NULL) {
        list->print(current->data);
        current = current->next;
    }
}

GenericList* create_generic_list(CompareFunc compare, PrintFunc print) {
    GenericList* list = (GenericList*)malloc(sizeof(GenericList));
    list->head = NULL;
    list->compare = compare;
    list->print = print;
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

void free_generic_list(GenericList* list) {
    free_list(list->head);
    free(list);
}

