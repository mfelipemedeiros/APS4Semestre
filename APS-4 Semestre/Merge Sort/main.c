#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge_sort(int i, int j, int a[], int aux[]) {
    clock_t Ticks[2];
    if (j <= i) {
        return;     
    }
    int mid = (i + j) / 2;

    
    merge_sort(i, mid, a, aux);     
    merge_sort(mid + 1, j, a, aux);    

    int inicio = i;       
    int final = mid + 1;      
    int k;      
    for (k = i; k <= j; k++) {
        if (inicio == mid + 1) {      
            aux[k] = a[final];
            final++;
        } else if (final == j + 1) {        
            aux[k] = a[inicio];
            inicio++;
        } else if (a[inicio] < a[final]) {  
            aux[k] = a[inicio];
            inicio++;
        } else {       
            aux[k] = a[final];
            final++;
        }
    }

    for (k = i; k <= j; k++) {      
        a[k] = aux[k];
    }
}


int main() {
    clock_t tempo;
    tempo = clock();
  int a[100], aux[100], n, i, d, swap;
 
  printf("Insira o numero de elementos do array:\n");
  scanf("%d", &n);
 
  printf("insira %d numeros\n", n);
 
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
 
  merge_sort(0, n - 1, a, aux);
 
  printf("Array ordenado:\n");
 
  for (i = 0; i < n; i++)
  
     printf("%d\n", a[i]);
    
    double Tempo = (clock() - tempo) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo, "\n");
    getchar();
	system("pause");
  return 0;
}
