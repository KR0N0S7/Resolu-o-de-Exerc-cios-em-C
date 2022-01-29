#include <stdio.h>
#include "fila.h"

int n;

int menor(int v[]){
	int i;
	int min = v[0];
	for(i=0; i<5; i++){
		if(v[i] < min){
			min = v[i];
		} 
	}
	return min;
}

void empurra(int v[], int i){
	Fila F = fila(5);
	int min = menor(v);
	
	for(n = 0; n < 5; n++){
		if(v[n] != min) enfileira(v[n], F);
	}
	enfileira(min, F);
	for(n = 0; n < i; n++)
		printf("%d\t", desenfileira(F));
	destroif(F);
}

int main(void){
	int v[5] = {48, 19, 31, 52, 27};
	empurra(v, 5);
}

