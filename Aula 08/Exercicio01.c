#include <stdio.h>

int i, j;

void troca(int v[], int i, int j) {
	int x = v[i];
	v[i] = v[j];
	v[j] = x;
}

void bsort(int v[], int n){
	for(i = 1; i <= n; i++)
		for(j = 0; j < n-1; j++)
			if(v[j] > v[j+1])
				troca(v, j, j+1);
}

void exibe(int v[], int n){
	for(i = 0; i < n; i++)
		printf("%d\t", v[i]);
}

int main(void){
	int v[10] = {83, 31, 91, 46, 27, 20, 96, 25, 96, 80};
	bsort(v, 10);
	exibe(v, 10);
	return 0;
}

