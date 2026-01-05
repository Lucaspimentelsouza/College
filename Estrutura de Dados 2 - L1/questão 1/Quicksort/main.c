#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particiona(int *A, int p, int r) {
    int x, i, j, aux;
    x = A[r]; // pivô
    i = p - 1;

    for(j = p; j <= r - 1; j++) { // [4,3,1,5,3]
        if(A[j] <= x) { //j = 1 ; j = 2
            i++; //0 ; 1
            aux = A[i]; //aux = 4 ; aux = 4
            A[i] = A[j]; // A[0] = 3 ; A[1] = 1
            A[j] = aux; // A[1] = 4 ; A[2] = 4
        } // [3,4,1,5,3] ; [3,1,4,5,3]
    }
    aux = A[i + 1]; // aux = 4
    A[i + 1] = A[r]; // A[2] = 3
    A[r] = aux; // A[4] = 4
    
	//[3,1,3,5,4]
    
	return i + 1; // 2
}

void quicksort(int *A, int p, int r) {
    int q;
    if(p < r) {
        q = particiona(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main() {
    int n, i;

    srand(time(NULL));

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    int *vet = (int *)malloc(n * sizeof(int));
    
    if (vet == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    printf("Vetor gerado:\n");
    for(i = 0; i < n; i++) {
        vet[i] = (rand() * RAND_MAX + rand()) % 500000;
        printf("%d ", vet[i]);
    }
    printf("\n");

	clock_t inicio = clock();
    quicksort(vet, 0, n - 1);
	clock_t fim = clock();

    printf("Vetor ordenado:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    free(vet);
    
	double time = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;
    printf("Tempo: %f milisegundos", time);

    return 0;
}
