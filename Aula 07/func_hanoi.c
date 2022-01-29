#include <stdio.h>

void hanoi(int n, char origem, char aux, char destino){
    if(n>0){
        hanoi(n-1,origem,destino,aux);
        printf("\nMova o disco %d da base %c para a base %c", n, origem, destino);
        hanoi(n-1, aux, origem, destino);
    }

}

int main (void){
    int n;
    printf("Numero de discos? ");
    scanf("%d", &n);
    printf("\nSolucao:");
    hanoi(n,'A','B','C');
    printf("\n");
    return 0;
}