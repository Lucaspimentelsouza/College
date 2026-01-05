#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void counting_sort(int *A, int *B, int n, int k) {
	int i, j;
    int *C = (int *)malloc((k + 1) * sizeof(int));
    
    for (i = 0; i <= k; i++) {
        C[i] = 0;
    }

    for (j = 0; j < n; j++) {
        C[A[j]]++; //montando vetor de acordo com o quanto ele tem de cada numero
    }

    for (i = 1; i <= k; i++) {
        C[i] += C[i - 1]; //acumulado
    }

    for (j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

}

int main() {
    int i, n, k;

    srand(time(NULL));

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    printf("Digite o valor maximo para os numeros: ");
    scanf("%d", &k);

    int *A = (int *)malloc(n * sizeof(int));
    int *B = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        A[i] = rand() % (k + 1);  
    }

    printf("Vetor original:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    counting_sort(A, B, n, k);

    printf("Vetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    return 0;
}

