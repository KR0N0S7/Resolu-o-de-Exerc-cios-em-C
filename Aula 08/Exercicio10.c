#include <stdio.h>

int m = 0;

int rbsearch(int x, int v[], int p, int u){
	int m;
	m = (p+u)/2;
	if (x == v[m]) return 1;
	else if ( p>u ) return 0;
	if( x < v[m]) return rbsearch(x, v, p, u-1);
	else return rbsearch(x, v, p+1, u);
}

int main (void){
	int v[8] = {19, 27, 31, 48, 52, 66, 75, 80};
	printf("27: %d\n", rbsearch(27, v, 0, 8));
	printf("51: %d\n", rbsearch(51, v, 0, 8));
	return 0;
}

