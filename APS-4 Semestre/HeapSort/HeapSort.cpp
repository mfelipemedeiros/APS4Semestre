#include <iostream>
#include <time.h>
using namespace std;
#define TAM 5

int v[TAM];

void heapify(int n, int i)
{
	int maior = i; 
	int E = 2*i + 1;
	int D =2*i + 2;
	

	if(E < n && v [E] > v[maior])
		maior = E;
	

	if(D < n && v[D] > v[maior])
		maior = D;
	

	if(maior !=i)
	{
		swap(v[i], v[maior]);
		

		heapify(n, maior);
	}
}

void heapSort(int n)
{

	for(int i = n / 2 - 1; i >= 0; i--)
	{
	
		heapify(n,i);
	}
	

	for (int i=n-1; i>0; i--)
	{

		swap(v[0], v[i]);
		

		heapify(i,0);
	}
}


void lerVetor(){
int i;
	for	(i=0;i<TAM;i++){
		printf("\nv[%d]: ",i);
		scanf("%d",&v[i]);
	}
		
}


void imprimeVetor(){
	int i;
		for(i=0;i<TAM;i++)
			printf("\nv[%d] : %d",i,v[i]);	
	
}



int main()
{
    clock_t tempo;
    tempo = clock();
	lerVetor();
	
	heapSort(TAM);
	
	printf("Vetor ordenado\n");
	imprimeVetor();
	double Tempo = (clock() - tempo) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo, "\n");
    getchar();
	system("pause");
}

