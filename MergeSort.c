#include <stdio.h>
#include <stdlib.h>

void intercala1(int v[], int p, int q, int r) {
int i, j, k, tam;
i = p; j = q; k = 0; tam = r - p;
int *w = malloc(tam * sizeof(int));
while (i < q && j < r) { // não chegou a fim de nenhum subvetor
if (v[i] <= v[j]) w[k++] = v[i++];
else /* v[i] > v[j] */ w[k++] = v[j++];
}
while (i < q) w[k++] = v[i++];
while (j < r) w[k++] = v[j++];
for (k = 0; k < tam; k++)
v[p + k] = w[k];
free(w);
}


void mergeSortR(int v[], int p, int r) {
int m;
if (p < r) { // se subvetor corrente tem mais de 1 elemento
m = (p + r) / 2; // m = p + (r - p) / 2;
mergeSortR(v, p, m);
mergeSortR(v, m, r);
intercala1(v, p, m, r);
}
}



int main(){
	int k;
    int vec[4] = {10, 3, 1, 9};
    mergeSortR(vec, 0, 4);
     for(k = 0; k<4; k++){
     	printf("%d\n", vec[k]);
	 } 
    return 0;
}
