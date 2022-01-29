#include <stdio.h>
#include <ctype.h>
#include "pilhaChar.h"
#include "fila.h"

int i = 0;

int main(void){
	char text[256];
	char textUpper[256];
	
	Fila F = fila(256);
	Pilha P = pilha(256);
	printf("\nFrase? ");
	gets(text);
	
	for(i=0; text[i]; i++){
		textUpper[i] = toupper(text[i]);
		if(isalpha(textUpper[i])){
			enfileira(textUpper[i],F);
			empilha(textUpper[i],P);
		}
	}
		
	while(!vaziaf(F) && desenfileira(F)==desempilha(P));
	if(vaziaf(F)) puts ("A frase e palindroma");
	else puts("A frase nao e palindroma");
	destroif(&F);
	destroip(&P);
	return 0;
}
