#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para realizar o Insertion Sort em uma sublista com gap
void insertion(int vetor[], int inicio, int intervalo, int tamanho) {
    int i, j, aux;
    for (i = inicio + intervalo; i < tamanho; i += intervalo) {
        aux = vetor[i];
        j = i;
        // Inserir o elemento atual na sublista ordenada anterior com o intervalo
        while (j >= intervalo && vetor[j - intervalo] > aux) {
            vetor[j] = vetor[j - intervalo];
            j -= intervalo;
        }
        vetor[j] = aux;
    }
}


void shellsort(int vetor[], int tamanho) {
    int intervalo = 1;
    int i;
    // sequência de Knuth
    while (intervalo <= tamanho / 3) {
        intervalo = 3 * intervalo + 1;
    }

    while (intervalo > 0) {
        for (i = 0; i < intervalo; i++) {
            // app para cada sublista
            insertion(vetor, i, intervalo, tamanho);
        }
        intervalo = (intervalo - 1) / 3; 
    }

    //for (i = 0; i < tamanho; i++) {
     //   printf("%d ", vetor[i]);
    //}
}

int main() {
    clock_t inicio, fim;
    double tempo_execucao;
    
    int *vetor, tamanho, i;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    vetor = (int *) malloc(tamanho * sizeof(int));
    
    if (vetor == NULL) {
        printf("Erro de alocação de memória\n\n");
        return 1;
    }
    
    srand(time(NULL));
    
  
    for (i = 0; i < tamanho; i++) {
        vetor[i] = (rand() * RAND_MAX + rand()) % 1000000;
    }
    
    printf("Vetor antes de organizar: \n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    printf("\n\nVetor depois de organizar: \n");
    
    inicio = clock();
    shellsort(vetor, tamanho);
    fim = clock();
    
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n\nTempo de execução: %.3f segundos\n", tempo_execucao);
    
    free(vetor);
    
    return 0;
}
