#include "arvbin.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct NO{
	int info;
	struct NO *esq;
	struct NO *dir;
};

ArvBin* cria_ArvBin(){
	ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
	if(raiz != NULL){
		*raiz = NULL;
	}
	return raiz;
}

void libera_NO(struct NO *no){
	if(no == NULL)
		return;
	libera_NO(no->esq);
	libera_NO(no->dir);
	free(no);
	no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
	if(raiz == NULL)
		return;
	libera_NO(*raiz); //libera cada n�
	free(raiz);
}

int estaVazia_ArvBin(ArvBin *raiz){
	if(raiz == NULL)
		return 1;
	if(*raiz == NULL)
		return 1;
	return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
	if(raiz == NULL)
		return 0;
	if(*raiz == NULL)
		return 0;
	int total_esq = totalNO_ArvBin(&(*raiz)->esq);
	int total_dir = totalNO_ArvBin(&(*raiz)->dir);
	return total_esq + total_dir + 1;
}

int altura_ArvBin(ArvBin *raiz) {
	if(raiz == NULL)
		return 0;
	if(*raiz == NULL)
		return 0;
	int altura_esq = altura_ArvBin(&(*raiz)->esq);
	int altura_dir = altura_ArvBin(&(*raiz)->dir);
	if(altura_esq >= altura_dir)
		return altura_esq+1;
	return altura_dir+1;
}

void preOrdem_ArvBin(ArvBin *raiz){
	if(raiz == NULL || *raiz == NULL)
		return;
	printf("%d ", (*raiz)->info);
	preOrdem_ArvBin(&((*raiz)->esq));
	preOrdem_ArvBin(&((*raiz)->dir));

}

void emOrdem_ArvBin(ArvBin *raiz){
	if(raiz == NULL || *raiz == NULL) return;
	emOrdem_ArvBin(&((*raiz)->esq));
	printf("%d ", (*raiz)->info);
	emOrdem_ArvBin(&((*raiz)->dir));

}

void posOrdem_ArvBin(ArvBin *raiz){
	if(raiz == NULL|| *raiz == NULL) return;
	posOrdem_ArvBin(&((*raiz)->esq));
	posOrdem_ArvBin(&((*raiz)->dir));
	printf("%d ", (*raiz)->info);
}

int insere_ArvBin(ArvBin *raiz, int valor){
	if(raiz == NULL) return 0;
	struct NO* novo;
	novo = (struct NO*) malloc(sizeof(struct NO));
	if(novo == NULL) return 0;
	novo->info = valor;
	novo->dir = NULL;
	novo->esq = NULL;

	if(*raiz == NULL){
		*raiz = novo;
	}else{
		struct NO* atual = *raiz;
		struct NO* ant = NULL;
		while(atual != NULL){
			ant = atual;
			if(valor == atual->info){
				free(novo);
				return 0; //elemento j� existe
			}
			if(valor > atual->info)
				atual = atual->dir;
			else
				atual = atual->esq;
		}
		if(valor > ant->info){
			ant->dir = novo;
		}else{
			ant->esq = novo;
		}
	}
	//printf("imprimido: %d \n", novo->info);
	return 1;
}

struct NO* remove_atual(struct NO* atual){
	struct NO *no1, *no2;
	if(atual->esq == NULL){
		no2 = atual->dir;
		free(atual);
		return no2;
	}
	no1 = atual;
	no2 = atual->esq;
	while(no2->dir != NULL){
		no1 = no2;
		no2 = no2->dir;
	}
	if(no1 != atual){
		no1->dir = no2->esq;
		no2->esq = atual->esq;
	}
	no2->dir = atual->dir;
	free(atual);
	return no2;
}

int remove_ArvBin(ArvBin *raiz, int valor){
	if(raiz == NULL){
		return 0;
	}
	struct NO* ant = NULL;
	struct NO* atual = *raiz;
	while(atual != NULL){
		if(valor == atual->info){
			*raiz = remove_atual(atual);
		}else{
			if(ant->dir == atual){
				ant->dir = remove_atual(atual);
			}else{
				ant->esq = remove_atual(atual);
			}
		}
		return 1;
	}
	ant = atual;
	if(valor > atual->info){
		atual = atual->dir;
	}else{
		atual = atual->esq;
	}
	return 0;
}

int consulta_ArvBin(ArvBin *raiz, int valor){
	if(raiz == NULL){
		return 0;
	}
	struct NO* atual = *raiz;
	while(atual != NULL){
		if(valor == atual->info){
			return 1;
		}
		if(valor > atual->info){
			atual = atual->dir;
		}else{
			atual = atual->esq;
		}
	}
	return 0;
}

void preenche_matriz(struct NO *raiz, char **matriz, int nivel, int col, int espacamento, int largura) {
	if (raiz == NULL) return;

	// Converte o número do nó para string e insere na matriz
	char buffer[10];
	sprintf(buffer, "%d", raiz->info); // Converte o número para texto
	for (int i = 0; buffer[i] != '\0' && col + i < largura; i++) {
		matriz[nivel][col + i] = buffer[i]; // Copia o texto para a matriz
	}

	// Preenche os filhos esquerdo e direito
	preenche_matriz(raiz->esq, matriz, nivel + 1, col - espacamento / 2, espacamento / 2, largura);
	preenche_matriz(raiz->dir, matriz, nivel + 1, col + espacamento / 2, espacamento / 2, largura);
}


void imprime_arvore(ArvBin *raiz) {
	if (raiz == NULL || *raiz == NULL) {
		printf("Árvore vazia!\n");
		return;
	}

	int h = altura_ArvBin(raiz);       // Altura da árvore
	int largura = (1 << h) * 3;        // Largura da matriz proporcional à altura
	char **matriz = (char **)malloc(h * sizeof(char *)); // Aloca a matriz (linhas)

	// Inicializa a matriz com espaços
	for (int i = 0; i < h; i++) {
		matriz[i] = (char *)malloc(largura * sizeof(char));
		memset(matriz[i], ' ', largura - 1); // Preenche cada linha com espaços
		matriz[i][largura - 1] = '\0';       // Adiciona o terminador de string
	}

	preenche_matriz(*raiz, matriz, 0, largura / 2, largura / 4, largura); // Preenche a matriz com os valores da árvore

	// Imprime a matriz linha por linha
	for (int i = 0; i < h; i++) {
		printf("%s\n", matriz[i]);
		free(matriz[i]); // Libera cada linha da matriz
	}
	free(matriz); // Libera a matriz
}


