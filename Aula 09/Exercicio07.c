#include <stdio.h>
#include <stdlib.h>

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

int tamanho(Lista L) {
	int t = 0;
	while(L) {
		t++;
		L = L -> prox;
	}
	return t;
}

void anexa(Lista *A, Lista B) {
	if(!B) return;
	while(*A)
		A = &(*A) -> prox;
	*A = B;
}

void destroi(Lista *L) {
	while(*L) {
		Lista n = *L;
		*L = n -> prox;
		free(n);
	}
}

int ultimo(Lista L) {
	int last = 0;
	if(L == NULL) puts("\b Lista vazia.");
	while(L != NULL) {
		last = L -> item;
		L = L -> prox;
	}
	return last;
}

int main(void) {
	Lista Z = NULL;
	Lista R = no(3, no(1, no(5, no(7, no(9, NULL)))));
	printf("Z = "); exibe(Z);
	printf("Ultimo item Z = %d", ultimo(Z));
	printf("\n\nR = "); exibe(R);
	printf("\nUltimo item R = %d", ultimo(R));
	destroi(&R);
	return 0;
}
