#include <time.h>
#include <stdio.h>

void printArray(int array[], int size) {
	int i;
  for ( i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size) {
	int step;
  for ( step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;


    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}


int main() {
    clock_t tempo;
    tempo = clock();
  int data[] = {10, 1, 3, 5, 12};  
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  printf("Numeros ordenados: \n");
  printArray(data, size);
      double Tempo = (clock() - tempo) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo, "\n");
    getchar();
	system("pause");
}
