#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_criar(int capacidade);
void StaticStack_destruir(StaticStack **S_ref);

bool StaticStack_vazia(const StaticStack *S);
bool StaticStack_cheia(const StaticStack *S);
int StaticStack_tamanho(const StaticStack *S);

void StaticStack_inserir(StaticStack *S, int val);
int StaticStack_checartopo(const StaticStack *S);
int StaticStack_remover(StaticStack *S);

void StaticStack_mostrar(const StaticStack *S);
#endif
