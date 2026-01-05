#include "arvavl.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvbin.h"

#define NUM_ELEMENTS 10

int main() {
    int num, i;
    ArvBin *arvore = cria_ArvBin();
    ArvAVL *arvoreAVL = cria_ArvAVL();


    srand(time(NULL));

    printf("\n\nInserindo %d numeros inteiros aleatorios na arvore binaria e AVL...\n", NUM_ELEMENTS);
    for (i = 0; i < NUM_ELEMENTS; i++) {
        num = rand() % 1000;
        printf("%d ", num);
        insere_ArvBin(arvore, num);
        insere_ArvAVL(arvoreAVL, num);
    }

    //printf("\nÁrvore Binária (Formato Visual):\n\n\n\n");
    //imprime_arvore(arvore);

    //printf("\n\n\n\n\nÁrvore AVL (Formato Visual):\n\n\n\n");
    //imprime_arvore(arvoreAVL);

    printf("\n\nPreOrdem da Arvore AVL: \n");
    preOrdem_ArvAVL(arvoreAVL);
    printf("\n\nPreOrdem da Arvore binaria: \n");
    preOrdem_ArvBin(arvore);
    printf("\n\nPosOrdem da Arvore AVL: \n");
    posOrdem_ArvAVL(arvoreAVL);
    printf("\n\nPosOrdem da Arvore binaria: \n");
    posOrdem_ArvBin(arvore);
    printf("\n\nEmOrdem da Arvore AVL: \n");
    emOrdem_ArvAVL(arvoreAVL);
    printf("\n\nEmOrdem da Arvore binaria: \n");
    emOrdem_ArvBin(arvore);

    return 0;
}

