#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para trocar dois elementos
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função auxiliar para particionar o array para o QuickSort
int partition(int arr[], int low, int high) {
	int j;
    int pivot = arr[high]; // Pivô
    int i = (low - 1);

    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Implementação do QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função principal do algoritmo Bucket Sort
void bucketSort(int arr[], int n) {
    int i, j;
    int bucketCount = n;  // Criando 'n' buckets (pode ser ajustado dependendo da aplicação)
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));
    
    // Inicializa cada bucket e define os tamanhos iniciais como 0
    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucketSizes[i] = 0;
    }

    // Distribui os elementos nos buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] * bucketCount / (100 + 1);  // Supondo que os valores estejam no intervalo [0, 100]
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Ordena cada bucket com Quick Sort
    for (i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            quickSort(buckets[i], 0, bucketSizes[i] - 1);
        }
    }

    // Concatenando todos os elementos dos buckets no array original
    int index = 0;
    for (i = 0; i < bucketCount; i++) {
        for (j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Libera a memória
    for (i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

int main() {
	int i;
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenação: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Chama o Bucket Sort
    bucketSort(arr, n);

    printf("\nArray após a ordenação: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

