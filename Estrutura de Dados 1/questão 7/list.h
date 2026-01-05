#ifndef LIST_H
#define LIST_H

typedef struct Node {
    char city[50];
    int population;
    struct Node* next;
} Node;

typedef struct {
    Node* head_2000;
    Node* head_1990;
} MultiLinkedList;

// Função para criar um novo nó
Node* create_node(const char* city, int population);

// Função para inserir um nó de forma ordenada na lista correspondente ao ano
void insert_ordered(Node** head, const char* city, int population);

// Função para inserir dados na lista multi-encadeada
void insert_data(MultiLinkedList* list, const char* city, int population_2000, int population_1990);

// Função para imprimir a lista correspondente ao ano
void print_list(Node* head, int year);

// Função para inicializar a lista multi-encadeada
MultiLinkedList* create_multi_linked_list();

// Função para liberar a memória da lista
void free_list(Node* head);
void free_multi_linked_list(MultiLinkedList* list);

#endif

