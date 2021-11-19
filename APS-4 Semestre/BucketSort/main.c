#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lista 7   
#define b 6  
#define intervalo 10  

struct Node {
  int data;
  struct Node *next;
};

void BucketSort(int arr[]);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);

void BucketSort(int arr[]) {
  int i, j;
  struct Node **n;

  n = (struct Node **)malloc(sizeof(struct Node *) * b);

  for (i = 0; i < b; ++i) {
    n[i] = NULL;
  }


  for (i = 0; i < lista; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = n[pos];
    n[pos] = current;
  }


  for (i = 0; i < b; i++) {
    printf("B[%d]: ", i);
    printn(n[i]);
    printf("\n");
  }


  for (i = 0; i < b; ++i) {
    n[i] = InsertionSort(n[i]);
  }

  printf("-------------\n");
  printf("Depois de ordenado\n");
  for (i = 0; i < b; i++) {
    printf("B[%d]: ", i);
    printn(n[i]);
    printf("\n");
  }


  for (j = 0, i = 0; i < b; ++i) {
    struct Node *node;
    node = n[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  return;
}

struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getBucketIndex(int value) {
  return value / intervalo;
}

void print(int ar[]) {
  int i;
  for (i = 0; i < lista; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}


void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}


int main(void) {
    clock_t tempo;
    tempo = clock();
  int array[lista] = {42, 32, 33, 52, 37, 47, 51};

  printf("Array inicial: ");
  print(array);
  printf("-------------\n");

  BucketSort(array);
  printf("-------------\n");
  printf("Array ordenado: ");
  print(array);
    double Tempo = (clock() - tempo) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nTempo gasto: %g ms.", Tempo, "\n");
    getchar();
	system("pause");
  return 0;
}
