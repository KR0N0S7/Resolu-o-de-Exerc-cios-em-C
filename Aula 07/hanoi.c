#include <stdio.h>
#include <conio.h>

void hanoi(int n, char origem, char aux, char dest)
{
	if(n <= 0)
		return;
	if(n == 1) {
		printf("Disco [ %d ] Movido de [ %c ] para [ %c ]\n", n, origem, dest);
		return;
	}
	hanoi(n-1, origem, dest, aux);
	printf("Disco [ %d ] Movido de [ %c ] para [ %c ]\n", n, origem, dest);
	hanoi(n-1, aux, origem, dest);
}

int main(void)
{
	int n = 0;

	printf("Informe o numero de discos: \n");
	scanf("%d", &n);
	
	hanoi(n, 'A','B','C');

	return 0;
}
