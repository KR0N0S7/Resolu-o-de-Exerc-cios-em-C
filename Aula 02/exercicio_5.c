#include <stdio.h>
#include <stdlib.h>
#include "pilhaChar.h"

int i;

int main(void){
	system("cls");
	
	Pilha P = pilha(5);
	char s[11];
	printf("\nEmpilhando e Copiando cadeia de char\n");
	for(i=1; i<=3; i++){
		printf(? );
		gets(s);
		empilha(_strdup(s), P);
	}
	while(!vaziap(P)) puts(desempilha(P));
	free(_strdup(s));
	printf("\n");
	return 0;
}
