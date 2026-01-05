#include "arvavl.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 10

int main() {
    int i, num;
    ArvAVL *arvoreAVL = cria_ArvAVL();

    if (!arvoreAVL) {
        printf("Erro ao criar a arvore AVL.\n");
        return 1;
    }
    srand(time(NULL));

    printf("\n\nInserindo %d numeros inteiros aleatorios na arvore binaria e AVL...\n", NUM_ELEMENTS);
    insere_ArvAVL(arvoreAVL, 70);
    insere_ArvAVL(arvoreAVL, 60);
    insere_ArvAVL(arvoreAVL, 80);
    insere_ArvAVL(arvoreAVL, 50);
    insere_ArvAVL(arvoreAVL, 65);
    insere_ArvAVL(arvoreAVL, 75);
    insere_ArvAVL(arvoreAVL, 45);

    /*
    for (i = 0; i < NUM_ELEMENTS; i++) {
        num = rand() % 1000;
        printf("%d ", num);
        insere_ArvAVL(arvoreAVL, num);
    }
    */

    imprimeArvoreHorizontal(arvoreAVL);

    return 0;
}