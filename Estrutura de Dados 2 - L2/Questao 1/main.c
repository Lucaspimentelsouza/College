#include "arvavl.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvbin.h"

#define NUM_ELEMENTS 10000

int main() {
    int num, i, altura, altura2;
    ArvBin *arvore = cria_ArvBin();
    ArvAVL *arvoreAVL = cria_ArvAVL();

    if (!arvore) {
        printf("Erro ao criar a arvore binaria.\n");
        return 1;
    }

    if (!arvoreAVL) {
        printf("Erro ao criar a arvore AVL.\n");
        return 1;
    }

    srand(time(NULL));

    printf("Inserindo %d numeros inteiros aleatorios na arvore binaria...\n", NUM_ELEMENTS);
    for (i = 0; i < NUM_ELEMENTS; i++) {
        num = rand() % 1000000;
        //printf("%d\n", num);
        insere_ArvBin(arvore, num);
        insere_ArvAVL(arvoreAVL, num);
    }

    altura = altura_ArvAVL(arvoreAVL);
    altura2 = altura_ArvBin(arvore);
    printf("Altura da arvore AVL apos inserir %d elementos: %d\n", NUM_ELEMENTS, altura);
    printf("Altura da arvore Binaria apos inserir %d elementos: %d\n", NUM_ELEMENTS, altura2);

    return 0;
}
