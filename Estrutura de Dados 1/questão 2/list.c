#include "list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _doubly_node{
	int val;
	struct _doubly_node *prev;
	struct _doubly_node *next;
}DoublyNode, Node;

typedef struct _doubly_linked_list{
	DoublyNode *begin;
	DoublyNode *end;
	int size;
}DoublyLinkedList, List;

Node *Node_create(int val){
	Node *node = (Node*) calloc(1, sizeof(Node));
	node->prev = NULL;
	node->next = NULL;
	node->val = val;
	
	return node;
}

List *List_create(){
	List *L = (List*) calloc(1, sizeof(List));
	L->begin = NULL;
	L->end = NULL;
	L->size = 0;
	
	return L;
}

void List_destroy(List **L_ref){
	List *L = *L_ref;
	
	Node *p = L->begin;
	
	while(p != NULL){
		Node *aux = p;
		p = p->next;
		free(aux);
	}
	free(L);
	
	*L_ref = NULL;
}

bool List_is_empty(const List *L){
	return L->size == 0;
}

int List_size(const List *L){
	return L->size;
}

void List_add_first(List *L, int val){
	Node *p = Node_create(val);
	if(List_is_empty(L)){
		L->begin = p;
		L->end = p;
	}
	else{
		p->next = L->begin;
		L->begin->prev = p;
		L->begin = p;
	}
	L->size++;
}

void List_add_last(List *L, int val){
	Node *p = Node_create(val);
	if(List_is_empty(L)){
		L->begin = p;
		L->end = p;
	}
	else{
		L->end->next = p;
		p->prev = L->end; //vai fazer o valor adicionado apontar para o anterior
		L->end = p;
	}
	L->size++;
}

void List_print(const List *L){
	Node *p = L->begin;
	printf("L -> ");
	
	while(p != NULL){
		printf("%s -> ", p->val);
		p = p->next;
	}
	printf("NULL\n");
	
	if(L->end == NULL){
		printf("L->end = NULL\n");
	}
	else{
		printf("L->end = %s\n", L->end->val);
	}
	printf("Size: %d\n", L->size);
	puts("");
}

void List_inverted_print(const List *L){
	Node *p = L->end;
	printf("L->end -> ");
	
	while(p != NULL){
		printf("%d -> ", p->val);
		p = p->prev;
	}
	printf("NULL\n");
	
	if(L->end == NULL){
		printf("L->begin = NULL\n");
	}
	else{
		printf("L->begin = %d\n", L->begin->val);
	}
	printf("Size: %d\n", L->size);
	puts("");
}

void List_remove(List *L, int val){
	if(!List_is_empty(L)){
		if(L->begin->val == val){ //se o nó que eu quero remover for o primeiro da lista
			Node *p = L->begin;
			if(L->begin == L->end){ //se isso for verdade significa que a lista só possui um elemento
				L->begin = L->end = NULL;
			}
			else{
				L->begin = p->next;
				L->begin->prev = NULL;
			}
			free(p);
			L->size--;
		}
		else{ //se tiver no meio/final da lista
			Node *p = L->begin->next;
			while(p != NULL){
				if(p->val == val){
					if(L->end == p){ //final
						L->end = p->prev;
						L->end->next = NULL;
						free(p);
						L->size--;
					}
					else{ //meio
						p->prev->next = p->next;
						p->next->prev = p->prev;
						free(p);
						L->size--;
					}
					p = NULL;
				}
				else{
					p = p->next;
				}
			}
		}
	}
}

void List_remove_last(List *L){
	if(!List_is_empty(L)){
		Node *p = L->end;
		
		if(L->size == 1){
			L->begin = L->end = NULL;
		}
		else{
			L->end = L->end->prev;
			L->end->next = NULL;
		}
		free(p);
		L->size--;
	}
}

int List_get_last_val(const List *L){
	if(List_is_empty(L)){
		fprintf(stderr, "ERROR in 'List_get_last_val'\n");
		fprintf(stderr, "A lista esta vazia");
		exit(EXIT_FAILURE);
	}
	
	return L->end->val;
}

