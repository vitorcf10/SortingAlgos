#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
	int aux;
	aux= *a;
	*a = *b;
	*b = aux;
}

int separa2(int v[], int p, int r) {
 int i, j, c = v[r]; // c é o pivô
 i = p;
 for (j = p; j < r; j++)
 if (v[j] <= c) {
 troca(&v[i], &v[j]);
 i++;
 }
 troca(&v[i], &v[r]);
 return i;
}


void quickSortR(int v[], int p, int r) {
 int i;
 if (p < r) { // se vetor corrente tem mais de um elemento
 	i = separa2(v, p, r); // i é posição do pivô após separação
 	quickSortR(v, p, i - 1);
 	quickSortR(v, i + 1, r);
 }
}



int main(){
	int k;
    int vec[4] = {10, 3, 1, 9};
    quickSortR(vec, 0, 3);
     for(k = 0; k<4; k++){
     	printf("%d\n", vec[k]);
	 } 
    return 0;
}
