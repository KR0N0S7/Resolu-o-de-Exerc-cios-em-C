#include <stdio.h>
#include <stdlib.h>
#include "pilhaInt.h"

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

void inversa(Lista L) {
	int last = 0;
	Pilha P = pilha(5);
	if(L == NULL) puts("\b Lista vazia.");
	while(L != NULL) {
		last = L -> item;
		empilha(last, P);
		L = L -> prox;
	}
	printf("[");
	while(!vaziap(P)) {
		printf("%d, ", desempilha(P));
	}
	printf("\b\b]");
}

int main(void) {
	Lista R = no(3, no(1, no(5, no(7, no(9, NULL)))));
	printf("Lista R = "); exibe(R);
	printf("\nLista inversa R = "); inversa(R);

	destroi(&R);
	return 0;
}
