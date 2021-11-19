
#include <time.h>
#include <stdio.h>


void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  
  int pivot = array[high];
  
  int i = (low - 1);
	int j;
  for ( j = low; j < high; j++) {
    if (array[j] <= pivot) {
    	
      i++;
      
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi - 1);
    
    quickSort(array, pi + 1, high);
  }
}

void printArray(int array[], int size) {
	int i;
  for (i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {
    clock_t tempo;
    tempo = clock();
  int data[] = {10, 1, 3, 5, 12};  
  int n = sizeof(data) / sizeof(data[0]);
  

  quickSort(data, 0, n - 1);
  
  printf("Numeros ordenados: \n");
  printArray(data, n);
    double Tempo = (clock() - tempo) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo, "\n");
    getchar();
	system("pause");
}
