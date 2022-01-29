#include <stdio.h>

int i, j;

void troca (int v[], int i, int j){
    int x = v[i];
    v[i] = v[j];
    v[j] = x;
}

void bsort(int v[], int n){
	for(i = 0; i <= n; i++)
        for(j = i+1; j < n; ++j)
            if(v[j] > v[i])
                troca(v, j, i);
}

void exibe(int v[], int n){
	for(i = 0; i < n; i++)
		printf("%d\t", v[i]);
}

int main (void){
    
    int v[5] = {48,52,31,19,27};
    bsort(v, 5);
    exibe(v, 5);

    return 0;
}

