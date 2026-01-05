#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "queue.h"

Node *Node_create(int data, char caractere){
	Node *node = (Node*) calloc(1, sizeof(Node));
	node->prev = NULL;
	node->next = NULL;
	node->data = data;
	node->caractere = caractere;
	return node;
}

Queue* createQueue() {
    Queue *q = (Queue*) calloc(1, sizeof(Queue));
    q->begin = q->end = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int data, char caractere) {
    Node *p = Node_create(data, caractere);
	p->prev = q->end;
	
	if(queue_empty(q)){
		q->begin = p;
	}
	else{
		q->end->next = p;
	}
	q->end = p;	
	q->size++;
}

bool queue_empty(const Queue *queue){
	return queue->size == 0;
}

int dequeue(Queue *q) {
    if (q->begin == NULL)
        return -1;
    Node *temp = q->begin;
    int data = temp->data;
    q->begin = q->begin->next;
    if (q->begin == NULL)
        q->end = NULL;
    free(temp);
    return data;
}


int isEmpty(Queue *q) {
    return (q->begin == NULL);
}

void destroyQueue(Queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int Int_Dequeue(Queue *queue){
		Node *p = queue->begin;
		int data = p->data;
	if(queue->begin == queue->end){
		queue->begin = NULL;
		queue->end = NULL;
	}
		else{
			queue->begin = p->next;
			queue->begin->prev = NULL;
		}
	free(p);
	queue->size--;
	return data;
}

char Char_Dequeue(Queue *queue){
		Node *p = queue->begin;
		char data = p->caractere; 
	if(queue->begin == queue->end){
		queue->begin = NULL;
		queue->end = NULL;
	}
		else{
			queue->begin = p->next;
			queue->begin->prev = NULL;
		}
	free(p);
	queue->size--;
	return data;
}

int prefixa(Queue *queue){
	int i, z, x, y;
	char ca, d, a = 'a';
	Node *p = queue->begin; // 1 elemento da fila
	//Node *p2 = queue->begin; // 2 elemento da fila
	//Node *p3 = queue->begin; // 3 elemento da fila
	while(queue->size != 1){
	 	p = queue->begin; // sinal
		if(p->caractere != 'a'){ // vendo se e um sinal
			Node *p2 = p->next; // numero 1
			Node *p3 = p2->next; // numero 2
			if(p2->data != 0 && p3->data != 0){ // verifica se e um numero
				d = p->caractere; 	// recebe o sinal
				x = p2->data; // 1 numero
				y = p3->data; // 2 numero
				ca = Char_Dequeue(queue); // desempilhando o sinal
				for(i=0; i<2; i++){	
					z = Int_Dequeue(queue); // desempilhado 2 numeros
				}
					switch(d){
						
					case '+':
						x = x + y;
						break;
					case '-':
						x = x - y;
						break;
					case '*':
						x = x * y;
						break;
					case '/':
						x = x / y;
						break;				
				}
					enqueue(queue, x, 'a'); // empilha o resultado
			}
			else{
				ca = Char_Dequeue(queue); // dempilhar
				enqueue(queue, 0, ca);	 // empilhar 
			}	
		}
			else{
				z = Int_Dequeue(queue); // desempilhar
				enqueue(queue, z, 'a'); // empilhar
			}
	}
	z = Int_Dequeue(queue); // resultado
	return z;
}


void pegar_elemento(Queue *queue){
	char str[100];
    int i, resultado;
    char a;
    char caractere = 'a';
    int data = 0;
    printf("\nEscreva a expressão prefixa: ");
    scanf("%s99[^\n]", &str);
    scanf("%*c");

    for ( i = 0; str[i] != '\0' ; i++) {
        if (str[i] >= '0' && str[i] <= '9') { // verifica se é um dígito
            data = str[i] - '0'; // converte caractere em inteiro
            enqueue(queue, data, 'a'); 
			printf("%d\n", data);
        }
        else{
        		caractere = str[i];
        		enqueue(queue, 0, caractere);
				printf("%c\n", caractere);	
		}
	}
}
