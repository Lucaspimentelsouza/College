#ifndef LIST_H
#define LIST_H

typedef int (*CompareFunc)(const void*, const void*);
typedef void (*PrintFunc)(const void*);

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    CompareFunc compare;
    PrintFunc print;
} GenericList;

Node* create_node(void* data);

void insert_ordered(GenericList* list, void* data);

void print_list(const GenericList* list);

GenericList* create_generic_list(CompareFunc compare, PrintFunc print);

void free_list(Node* head);
void free_generic_list(GenericList* list);

#endif

