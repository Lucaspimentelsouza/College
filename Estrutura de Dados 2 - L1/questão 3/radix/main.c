#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ordenando com base no dígito específico
void counting_sort_digit(int *A, int *B, int n, int exp, int base) {
    int i, *C;
    C = (int *)malloc(base * sizeof(int));

    for (i = 0; i < base; i++)
        C[i] = 0;

    for (i = 0; i < n; i++)
        C[(A[i] / exp) % base]++; //contagem dos digitos

    for (i = 1; i < base; i++)
        C[i] += C[i - 1]; //acumuluado

    // vetor de saída B
    for (i = n - 1; i >= 0; i--) {
        int indice = (A[i] / exp) % base;
        B[C[indice] - 1] = A[i];
        C[indice]--;
    }

    // copiando (já ordenado)
    for (i = 0; i < n; i++)
        A[i] = B[i];

    
    free(C);
}

void radix_sort(int *A, int n, int d) {
	int i, exp;
    int *B = (int *)malloc(n * sizeof(int));
    int base = 10;  // base decimal (0-9)

    int max_num = A[0];
    for (i = 1; i < n; i++) {
        if (A[i] > max_num)
            max_num = A[i];
    }

    // ordenando cada dígito
    for (exp = 1; max_num / exp > 0; exp *= base) {
        counting_sort_digit(A, B, n, exp, base);
    }

}

int main() {
    int n, i;

    srand(time(NULL));

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        A[i] = rand() % 10000;
    }

    printf("Vetor original:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    radix_sort(A, n, 4);

    printf("Vetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);

    return 0;
}

