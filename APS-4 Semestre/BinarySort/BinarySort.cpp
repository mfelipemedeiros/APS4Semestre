#include <iostream>
#include <time.h>
using namespace std;
#define TAM 5

int v[TAM];

int binarySearch(int item, int low, int high)
{
	if(high <= low)
		return (item > v[low])? (low +1): low;
	int mid = (low + high)/2;
	if(item == v[mid])
		return mid+1;
	if (item > v[mid])
		return  binarySearch(item, mid+1,high);
	return binarySearch(item, low, mid-1);
}

void BinaryInsertionSort()
{
	int i, loc, j, k, selected;
	for (i =1; i < TAM; i++){
		j = i - 1;
		selected = v[i];
		loc = binarySearch(selected, 0, j);
		while (j >= loc){
			v[j+1] = v[j];
			j--;
		}
		v[j+1]=selected;
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
	
	BinaryInsertionSort();
	
	printf("Vetor ordenado\n");
	imprimeVetor();
	
	double Tempo = (clock() - tempo) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo, "\n");
    getchar();
	system("pause");
	return 0;
}
