#include <stdio.h>


void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//SELECTION SORT
void selectionSort(int vetor[], int tam) {
  for (int i = 0; i < tam - 1; i++) {
    int min = i;
    for (int i = i + 1; i < tam; i++) {

      if (vetor[i] < vetor[min])
        min = i;
    }

    troca(&vetor[min], &vetor[i]);
  }
}


int main() {
  int data[] = {20, 12, 10, 15, 2, -4, 9, 7, -1};
  int tam = tamof(data) / tamof(data[0]);
  selectionSort(data, tam);
  printf("Sorted vetor in Acsending Order:\n");
  printvetor(data, tam);
}