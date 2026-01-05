#include "arvLLRB.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 10000

int main(void) {
    int num, i, altura;
    ArvLLRB *arvoreLLRB = cria_ArvLLRB();

    /*
    if (!arvoreLLRB) {
        printf("Erro ao criar a arvore binaria.\n");
        return 1;
    }
    */

    srand(time(NULL));

    printf("Inserindo %d numeros inteiros aleatorios na arvore binaria...\n", NUM_ELEMENTS);
    for (i = 0; i < NUM_ELEMENTS; i++) {
        num = rand() % 1000000;
        //printf("%d\n", num);
        insere_ArvLLRB(arvoreLLRB, num);
    }

    altura = altura_ArvLLRB(arvoreLLRB);
    printf("Altura da arvore RB apos inserir %d elementos: %d\n", NUM_ELEMENTS, altura);

    return 0;
}