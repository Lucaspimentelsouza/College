#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reHeapUp(int vet[], int i) {
    int pai = (i - 1) / 2;

    //se chegou na raiz ou se filho for > que o pai
    if (i > 0 && vet[i] > vet[pai]) {
        trocar(&vet[i], &vet[pai]);

        //chama para o pai
        reHeapUp(vet, pai);
    }
}

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
        reHeapDown(vet, n, maior); //ajusta o heap após a troca
    }
}

void heapsort_construir(int vet[], int n) {
	int i;
    for (i = 1; i < n; i++) {
        reHeapUp(vet, i);
    }
}

void heapsort_remover(int vet[], int n){
	int i;
	for (i = n - 1; i > 0; i--) {
        trocar(&vet[0], &vet[i]);
        reHeapDown(vet, i, 0);
    }
}

void imprimirVet(int vet[], int n) {
	int i;
    for (i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main() {
	int n, i;
	
	printf("Tamanho do vetor: ");
	scanf("%d", &n);
	
    int *vet = (int *)malloc(n * sizeof(int));
	srand(time(NULL));
	
	for(i = 0; i < n; i++){
	vet[i] = (rand() * RAND_MAX + rand() % 1000000);
	}
	
	printf("Vetor gerado:\n");
	//imprimirVet(vet, n);
	
	clock_t inicio = clock ();
	heapsort_construir(vet, n);
	clock_t fim = clock ();
	
	
	//tempodeordenacao = clock ();
	printf("Arvore de heapmax em vetor (apos o reheapup):\n");
    //imprimirVet(vet, n);
    //tempodeordenacao = clock () - tempodeordenacao;
    
    clock_t inicio2 = clock ();
    heapsort_remover(vet, n);
    clock_t fim2 = clock ();
    
    printf("Vetor de remoção (reheapdown):\n");
	//imprimirVet(vet, n);
	
	double time = (double)(fim - inicio) / CLOCKS_PER_SEC * 1000;
	double time2 = (double)(fim2 - inicio2) / CLOCKS_PER_SEC * 1000;
	printf("Tempo de execucao: %f milisegundos\n", time + time2);
	
return 0;
}
