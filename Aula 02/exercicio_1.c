#include <stdio.h>
#include <string.h>
#include "pilhaChar.h"

int i;

int main(void){
	
	char c[70];
	char rev[70];
	int len, index, palComeco, palFim;
	Pilha P = pilha(70);
	
	printf("Frase desejada: ");
	gets(c);
	
	len = strlen(c);
	index = 0;
	
	palComeco = len - 1;
	palFim = len - 1;
	
	while(palComeco > 0){
		if(c[palComeco] == ' '){
			i = palComeco + 1;
			while(i <= palFim){
				rev[index] = c[i];
				
				i++;
				index++;
			}
			rev[index++] = ' ';
			palFim = palComeco - 1;
		}
		palComeco--;
	}
	
	for(i=0; i<=palFim; i++){
		rev[index] = c[i];
		index++;
	}
	
	rev[index] = '\0';
	
	printf("%s\n", rev);
	
	for(i=0; rev[i]; i++)
		empilha(rev[i], P);
	printf("Inverso: ");
	while(!vaziap(P))
		printf("%c", desempilha(P));
	destroip(&P);
	return 0;
}

