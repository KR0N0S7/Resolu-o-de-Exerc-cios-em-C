#include <stdio.h>

void moverDisco(int n, char origem, char destino){
	printf("Movendo disco %d de %c para %c...\n", n, origem, destino);
}

void hanoi(int n, char origem, char auxiliar, char destino){
	if(n>=1){
		hanoi(n-1, origem, destino, auxiliar);
		moverDisco(n, origem, destino);
		hanoi(n-1, auxiliar, origem, destino);
	}
}

int main(void){
	int n;
	
	printf("Quantos discos o problema possui? ");
	scanf("%d", &n);
	
	hanoi(n, 'A', 'B', 'C');
}
