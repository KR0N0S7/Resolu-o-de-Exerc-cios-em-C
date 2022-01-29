#include <stdio.h>
#include <stdlib.h>
#include "pilhaInt.h"
#define TAM 20


float aux, n;
char ask='s';

int main(void){

	Pilha A = pilha(TAM);
	Pilha B = pilha(TAM);
	
	do{
		printf("\nEntrar com um numero: ");
		scanf("%d", &n);
		
		empilha(n, A);
				
		printf("Deseja continuar? [s/n]... ");
		scanf("%s", &ask);
		
	}while(ask=='s');

	while (!vaziap(A)){
    	aux = desempilha(A);
       	      	
    	while (!vaziap(B) && topo(B) > aux){
    		empilha(desempilha(B), A);
		}
		
		empilha(aux, B);
	}
	
	while (!vaziap(B)){
		empilha(desempilha(B), A);
	}
		
	printf("Pilha: \n");
	while(!vaziap(A))
		printf("\t%d\n", desempilha(A));
	
	destroip(&A);
	destroip(&B);
	
	return 0;
}



