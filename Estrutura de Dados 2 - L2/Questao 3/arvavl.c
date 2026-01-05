#include "arvavl.h"
#include <stdlib.h>
#include <stdio.h>

struct NO{
	int info;
	int alt;
	struct NO *esq;
	struct NO *dir;
};

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int altura_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return (alt_esq + 1);
    }else{
        return (alt_dir + 1);
    }
}

int alt_NO(struct NO* no){
	if(no == NULL)
		return -1;
	else
		return no->alt;
}

//retorna o fator de balanceamento de um no
int fatorBalanceamento_NO(struct NO* no){
	return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

//retorna o maior dentre dois valores
int maior(int x, int y){
	if(x > y)
		return x;
	else
		return y;
}

void RotacaoLL(ArvAVL *A){
	struct NO *B;
	B = (*A)->esq;
	(*A)->esq = B->dir;
	B->dir = *A;
	(*A)->alt = maior(alt_NO((*A)->esq), alt_NO((*A)->dir)) + 1;
	B->alt = maior(alt_NO(B->esq), (*A)->alt) + 1;
	*A = B;
}

void RotacaoRR(ArvAVL *A) {
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->alt = maior (alt_NO((*A)->esq), alt_NO((*A)->dir)) + 1;
    B->alt = maior (alt_NO(B->dir), (*A)->alt) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A){
	RotacaoRR(&(*A)->esq);
	RotacaoLL(A);
}

void RotacaoRL(ArvAVL *raiz){
	RotacaoLL(&(*raiz)->dir);
	RotacaoRR(raiz);
}

int insere_ArvAVL (ArvAVL *raiz, int valor) {
  int res;
  if (*raiz == NULL) { //�rvore vazia ou n� folha
    struct NO *novo;
    novo = (struct NO*)malloc(sizeof(struct NO));
    if (novo == NULL)
      return 0;
    novo->info = valor;
    novo->alt = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;
    return 1;
  }
  struct NO *atual = *raiz;
  if (valor < atual->info) {
    if ((res = insere_ArvAVL (&(atual->esq), valor)) == 1) {
      if (fatorBalanceamento_NO (atual) >= 2) {
        if (valor < (*raiz)->esq->info)
          RotacaoLL (raiz);
        else
          RotacaoLR (raiz);
      }
    }
  }else{
    if (valor > atual->info) {
      if ((res = insere_ArvAVL (&(atual->dir), valor)) == 1) {
        if (fatorBalanceamento_NO(atual) >= 2) {
          if((*raiz)->dir->info < valor)
            RotacaoRR(raiz);
          else
            RotacaoRL (raiz);
        }
      }
    }else //Valor duplicado!!
    return 0;
  }
  atual->alt = maior(alt_NO(atual->esq), alt_NO(atual->dir))+1;
  return res;
}


struct NO* procuraMenor (struct NO* atual) {
  struct NO* no1 = atual;
  struct NO* no2 = atual->esq;
  while (no2 != NULL) {
    no1 = no2;
    no2 = no2->esq;
  }
  return no1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor) {
    if (*raiz == NULL) // valor n existe
        return 0;
    int res;
    if (valor == (*raiz)->info) {
        if ((res = remove_ArvAVL(&(*raiz)->esq, valor)) == 1) {
            if (fatorBalanceamento_NO(*raiz) > 2) {
                if (alt_NO((*raiz)->dir->esq) <= alt_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    }
    if ((*raiz)->info < valor) {
        if ((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1) {
            if (fatorBalanceamento_NO(*raiz) >= 2) {
                if (alt_NO((*raiz)->esq->dir) <= alt_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
    }
    if ((*raiz)->info == valor) {
        if (((*raiz)->esq == NULL) || (*raiz)->dir == NULL) {
            // n� tem 1 filho ou nenhum
            struct NO *oldNode = (*raiz);
            if ((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNode);
        } else { // n� tem 2 filhos
            struct NO* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if (fatorBalanceamento_NO(*raiz) >= 2) {
                if (alt_NO((*raiz)->esq->dir) <=
                    alt_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
        if (*raiz != NULL)
        	(*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;
    return 1;
    }
	(*raiz)->alt = maior(alt_NO((*raiz)->esq), alt_NO((*raiz)->dir)) + 1;

	return res;
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL || *raiz == NULL)
        return;
    printf("%d ", (*raiz)->info);
    preOrdem_ArvAVL(&((*raiz)->esq));
    preOrdem_ArvAVL(&((*raiz)->dir));

}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL || *raiz == NULL) return;
    emOrdem_ArvAVL(&((*raiz)->esq));
    printf("%d ", (*raiz)->info);
    emOrdem_ArvAVL(&((*raiz)->dir));

}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL|| *raiz == NULL) return;
    posOrdem_ArvAVL(&((*raiz)->esq));
    posOrdem_ArvAVL(&((*raiz)->dir));
    printf("%d ", (*raiz)->info);
}

void imprimeHorizontal(struct NO* no, int espacamento) {
    if (no == NULL) return;

    // Aumenta o espaçamento para o próximo nível
    espacamento += 25;

    // Processa o subárvore direita primeiro (para imprimir no topo da tela)
    imprimeHorizontal(no->dir, espacamento);

    // Imprime o nó atual com o espaçamento apropriado
    printf("\n");
    for (int i = 10; i < espacamento; i++) {
        printf(" "); // Espaços para alinhar
    }
    printf("[%d] %d [%d]\n", alt_NO(no),  no->info, fatorBalanceamento_NO(no));

    // Processa o subárvore esquerda depois (para imprimir abaixo na tela)
    imprimeHorizontal(no->esq, espacamento);
}

void imprimeArvoreHorizontal(ArvAVL* raiz) {
    if (raiz == NULL || *raiz == NULL) {
        printf("Arvore vazia.\n");
        return;
    }
    imprimeHorizontal(*raiz, 0);
}
