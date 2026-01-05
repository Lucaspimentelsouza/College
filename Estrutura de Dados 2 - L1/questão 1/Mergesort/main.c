#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *array, int low, int mid, int high) {
	int i,j ,k;
	
    int size1 = mid - low + 1;
    int size2 = high - mid;

	// os dois vetores auxiliares
    int *array1 = (int *)malloc(size1 * sizeof(int));
    int *array2 = (int *)malloc(size2 * sizeof(int));

    for (i = 0; i < size1; i++) {
        array1[i] = array[low + i];
    }
    for (j = 0; j < size2; j++) {
        array2[j] = array[mid + 1 + j];
    }
	i = j = 0;
	k = low;

    while (i < size1 && j < size2) {
        if (array1[i] <= array2[j]) {
            array[k] = array1[i];
            i++;
        } else {
            array[k] = array2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        array[k] = array1[i];
        i++;
        k++;
    }

    while (j < size2) {
        array[k] = array2[j];
        j++;
        k++;
    }

    free(array1);
    free(array2);
}

void mergesort(int *array, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(array, low, mid);
        mergesort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int main() {
    int tam = 100000;
    int *vetor;
    int i;

    vetor = (int *)malloc(tam * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    srand(time(NULL));

    for (i = 0; i < tam; i++) {
        vetor[i] = (rand() * RAND_MAX + rand()) % 1000000;
    }

    printf("Vetor antes do merge sort:\n");
    for (i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

	clock_t inicio = clock();
    mergesort(vetor, 0, tam - 1);
	clock_t fim = clock();

    printf("Vetor após o merge sort:\n");
    for (i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
	
	double time = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;
	printf("Tempo de execucao: %f milisegundos\n", time);

    return 0;
}
