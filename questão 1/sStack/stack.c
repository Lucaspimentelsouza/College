#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct _static_stack {
	int *dados;
	int capacidade;
	int topo;
} StaticStack;

StaticStack *StaticStack_criar(int capacidade){
	StaticStack *S = (StaticStack*) calloc(1, sizeof(StaticStack));
	
	S->capacidade = capacidade;
	S->topo = -1;
	S->dados = (int*) calloc(S->capacidade, sizeof(int));
	
	return S;
}

void StaticStack_destruir(StaticStack **S_ref){
	StaticStack *S = *S_ref;
	
	free(S->dados);
	free(S);
	
	*S_ref = NULL;
}

bool StaticStack_vazia(const StaticStack *S){
	return S->topo == -1;
}
bool StaticStack_cheia(const StaticStack *S){
	return S->topo == (S->capacidade - 1);
}

int StaticStack_tamanho(const StaticStack *S){
	return S->topo + 1;
}

void StaticStack_inserir(StaticStack *S, int val){
	if(StaticStack_cheia(S)){
			fprintf(stderr, "Error in 'StaticStack_inserir'\n");
			fprintf(stderr, "A pilha esta cheia\n");
			exit(EXIT_FAILURE);
	}
	S->topo++;
	S->dados[S->topo] = val;
}

int StaticStack_checartopo(const StaticStack *S){
	if(StaticStack_vazia(S)){
			fprintf(stderr, "Error in 'StaticStack_checartopo'\n");
			fprintf(stderr, "A pilha esta vazia\n");
			exit(EXIT_FAILURE);
	}
	return S->dados[S->topo];
}

int StaticStack_remover(StaticStack *S){
	if(StaticStack_vazia(S)){
			fprintf(stderr, "Error in 'StaticStack_retirar'\n");
			fprintf(stderr, "A pilha esta vazia\n");
			exit(EXIT_FAILURE);
	}
	int val = S->dados[S->topo];
	S->topo--;
	
	return val;
}

void StaticStack_mostrar(const StaticStack *S){
	printf("Capacidade: %ld\n", S->capacidade);
	printf("Topo: %ld\n", S->topo);
	
	for(long i = 0; i <= S->topo; i++){
		printf("%d, ", S->dados[i]);
	}
	puts("");
}



