#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
typedef struct no {
	Item item;
	struct no *prox;
} *Lista;

Lista no(Item x, Lista p) {
	Lista n = malloc(sizeof(struct no));
	n -> item = x;
	n -> prox = p;
	return n;
}

void exibe(Lista L) {
	printf("[");
	while(L != NULL) {
		printf("%d, ", L -> item);
		L = L -> prox;
	}
	printf("\b\b]");
}

void destroi(Lista *L) {
	while(*L) {
		Lista n = *L;
		*L = n -> prox;
		free(n);
	}
}

bool pertence(int x, Lista L) {
	int i = 0;
	while(L != NULL){
		i = L -> item;
		if(x == i){
			return 1;
		}
		L = L -> prox;
	}
	
	return 0;
}

int main(void) {
	Lista R = no(3, no(1, no(5, no(7, no(9, NULL)))));
	int x, ask = 0;
	
	do{
		printf("Elemento a procurar: ...");
		scanf("%d", &x);
		if(pertence(x, R)==1){
			printf("O elemento esta armazenado na lista.");
		} else {
			printf("O elemento NAO esta armazenado na lista.");
		}
		printf("\n\nDeseja continuar procurando?... \n1 - sim\n2 - nao\n");
		scanf("%d", &ask);
	}while(ask==1);
		
	destroi(&R);
	return 0;
}
