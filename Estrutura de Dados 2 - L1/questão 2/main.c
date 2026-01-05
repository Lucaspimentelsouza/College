#include <stdio.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para restaurar a propriedade de heap de baixo para cima (up)
void reHeapUp(int vet[], int n, int i) {
    int pai = (i - 1) / 2; // Índice do pai

    // Enquanto não chegarmos à raiz (i > 0) e o filho for maior que o pai
    if (i > 0 && vet[i] > vet[pai]) {
        trocar(&vet[i], &vet[pai]);

        // Recursivamente chama para o pai
        reHeapUp(vet, n, pai);
    }
}

/*
void reHeapDown(int vet[], int n, int i) {
    int maior = i; 
    int esquerda = 2 * i + 1; 
    int direita = 2 * i + 2;  

    if (esquerda < n && vet[esquerda] > vet[maior])
        maior = esquerda;

    if (direita < n && vet[direita] > vet[maior])
        maior = direita;

    if (maior != i) {
        trocar(&vet[i], &vet[maior]);

        // Recursivamente ajusta o sub-heap afetado
        reHeapDown(vet, n, maior);
    }
}
*/

void heapsort(int vet[], int n) {
	int i;
    for (i = 1; i < n; i++)
        reHeapUp(vet, n, i);

/*
    for (int i = n - 1; i > 0; i--) {
        trocar(&vet[0], &vet[i]);
        reHeapDown(vet, i, 0);
    }
    */
}

void imprimirArray(int vet[], int n) {
	int i;
    for (i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int numeroExiste(int vet[], int tamanho, int numero) {
    int i;
	for (i = 0; i < tamanho; i++) {
        if (vet[i] == numero)
            return 1;  //existe
    }
    return 0;  //n existe
}

int main() {
    int n, i, numero;
	n = 10;
	int m = 100;
	int k = 10;
	int j = 0;

    srand(time(NULL));
    
    int *p = (int *)malloc(n * sizeof(int)); //prioridade
	int *o = (int *)malloc(n * sizeof(int)); //ordem de chegada
    int *vet = (int *)malloc(n * sizeof(int)); 
	
    for (i = 0; i < n; i++) {
        p[i] = rand() % 7 + 1;
    }
    
    while (j < n) {
        numero = rand() % 10;
        
        //verifica se o número já foi inserido no array
        if (!numeroExiste(o, j, numero)) {
            o[j] = numero;
            j++;
        }
	}
    
    printf("Prioridade-OrdemDeChegada:\n");
	for (i = 0; i < n; i++)
        printf(" %d-%d ,", p[i], o[i]);
    printf("\n");
    
    for(i = 0; i < n; i++){
		vet[i] = (m * p[i]) + (k - o[i]); ///////////////////////
	}
	
    printf("Vetor após combinar a prioridade com a ordem de chegada:\n");
    imprimirArray(vet, n);
	
	clock_t inicio = clock();
    heapsort(vet, n);
    clock_t fim = clock();

    printf("Vetor após a construção do heap máximo:\n");
    imprimirArray(vet, n);

    free(vet);
    
    double time = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;
	printf("Tempo de execucao: %f milisegundos\n", time);
	
    return 0;
}
