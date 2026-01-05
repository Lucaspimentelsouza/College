#include "stack.h"
#include <stdio.h>


int main() {
	StaticStack *S = StaticStack_criar(5);
	int top_val;
	
	StaticStack_mostrar(S);
	
	//puts("\nElemento do topo");
	//top_val = StaticStack_checartopo(S);
	//printf("top_val = %d\n", top_val);
	
	//puts("\nRemovendo");
	//top_val = StaticStack_remover(S);
	//printf("top_val = %d\n", top_val);
	
	puts("\nAdicionando 0, 10, 20");
	StaticStack_inserir(S, 0);
	StaticStack_inserir(S, 10);
	StaticStack_inserir(S, 20);
	StaticStack_mostrar(S);
	
	puts("\nElemento do topo");
	top_val = StaticStack_checartopo(S);
	printf("top_val = %d\n", top_val);
	
	puts("\nRemovendo");
	top_val = StaticStack_remover(S);
	printf("top_val = %d\n", top_val);
	
	puts("\nAdicionando 20, 30, 40");
	StaticStack_inserir(S, 20);
	StaticStack_inserir(S, 30);
	StaticStack_inserir(S, 40);
	StaticStack_mostrar(S);
	
	//puts("\nAdicionando 50");
	//StaticStack_inserir(S, 50);
	//StaticStack_mostrar(S);
	
	StaticStack_destruir(&S);
	
return 0;
}
