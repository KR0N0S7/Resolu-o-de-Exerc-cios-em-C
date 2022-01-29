#include <stdio.h>
#include <stdbool.h>

int i;

void intercala(int v[], int p, int m, int u){
	int w[u-p+1];
	int i=p, j=m+1, k=0;
	while(i<=m && j<=u){
		if(v[i] > v[j]) w[k++] = v[i++];
		else w[k++] = v[j++];
	}
	while(i<=m) w[k++] = v[i++];
	while(j<=u) w[k++] = v[j++];
	for(k=0; k<=u-p; k++) v[p+k] = w[k];
}

void ms(int v[], int p, int u){
	if(p==u) return;
	int m = (p+u)/2;
	ms(v, p, m);
	ms(v, m+1, u);
	intercala(v, p, m, u);
}

void msort(int v[], int n){
	ms(v, 0, n-1);
}

bool verificadorDecrescente(int v[], int sizeV, int r[], int sizeR){
	bool decrescente = true;
	for(i=0; i< sizeV; i++){
		if(v[i] < v[i+1]) decrescente = false;
	}
	for(i=0; i< sizeR; i++){
		if(r[i] < r[i+1]) decrescente = false;
	}
	return decrescente;
}

bool verificadorSequencias(int sizeV, int sizeR){
	bool iguais = 0;
		
	if(sizeV == sizeR){
		iguais = 1;
	} 
	return iguais;
}

void intercalad(int v[], int sizeV, int r[]){
	int n = 0;
	int w[2*sizeV];
	for(i=0; i<sizeV; i++){
		w[n] = v[i];
		n++;
		w[n] = r[i];
		n++;
	}
	msortd(w, 14);
	exibe(w, 2*sizeV);
}

void msd(int v[], int p, int u){
	if(p==u) return;
	int m = (p+u)/2;
	ms(v, p, m);
	ms(v, m+1, u);
	intercala(v, p, m, u);
}

void msortd(int v[], int n){
	msd(v, 0, n-1);
}

void exibe(int v[], int n){
	for(i = 0; i < n; i++)
		printf("%d\t", v[i]);
	printf("\n");
}

int main (void){
	int v[7] = {121, 174, 97, 9, 17, 5, 31};
	int r[7] = {70, 19, 58, 36, 65, 3, 12};
	int sizeV = sizeof(v)/sizeof(v[0]);
	int sizeR = sizeof(r)/sizeof(r[0]);
	int ask = 0;
	
	if(verificadorSequencias(sizeV, sizeR) != 1){
		printf("Os arrays possuem tamanhos distintos!\n");
		return 0;
	} 
	
	if(verificadorDecrescente(v, sizeV, r, sizeR) != 1){
		printf("Os arrays nao estao em ordem, gostaria de ordena-los?\n");
		printf("1 - Sim\n2 - Nao\n... ");
		scanf("%d", &ask);
		if(ask == 2) return 0;
		msort(v, sizeV);
		msort(r, sizeR);
	}
	exibe(v, 7);
	exibe(r, 7);
	intercalad(v, sizeV, r);
}
