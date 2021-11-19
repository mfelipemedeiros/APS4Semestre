#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    clock_t tempo;
    tempo = clock();
int a[100], n, i, j, posicao, aux;
	printf("Insira o numero de elementos \n");
	scanf("%d", &n);
	printf("insira %d Numeros \n", n);
for (i = 0; i < n; i++)
	scanf("%d", &a[i]);

for(i = 0; i < n - 1; i++){
	posicao=i;
	for(j = i + 1; j < n; j++){
if(a[posicao] > a[j]) posicao=j;
	}
if(posicao != i){
	aux=a[i];
	a[i]=a[posicao];
	a[posicao]=aux;
	}
	}
	printf("Lista ordenada: \n");
	for ( i = 0;i<n;i++){
		printf("%d - ", a[i]);
	}
    double Tempo = (clock() - tempo) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo, "\n");
    getchar();
	system("pause");
	return 0;
}
