/*
Alunos:
Lucas Carvalho Maracaipe - 1920054 
Milena Valenze Carvalho Prieto - 1912479
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//Função para trocas de posição
void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

//função para retornar o tempo de duração
clock_t finalizarCronometro(clock_t tempoInicial)
{
    clock_t difference = clock() - tempoInicial;
    int msec = difference * 1000 / CLOCKS_PER_SEC;
    return msec;
}

//SELECTION SORT
void selectionSort(int vetor[], int tam) {
  int interacoes = 0;
  clock_t tempoInicial = clock();
  for (int i = 0; i < tam - 1; i++) {
    interacoes++;
    int min = i;
    for (int i = i + 1; i < tam; i++) {
      interacoes++;
      if (vetor[i] < vetor[min])
        min = i;
    }

    troca(&vetor[min], &vetor[i]);
  }
  printf("\nInterações Selection Sort: %i", interacoes);

    int msec = finalizarCronometro(tempoInicial);
    printf("\nCrônometro SelectionSort:Tempo: %d segundos e %d milésimos", msec/1000, msec%1000);
}

//=========================================
//BUBBLESORT
void bubbleSort(int vetor[], int tam) {
  int interacoes = 0;
  clock_t tempoInicial = clock();
  for (int j = 0; j < tam - 1; ++j) {
    interacoes++;
    for (int i = 0; i < tam - j - 1; ++i) {
      
      if (vetor[i] > vetor[i + 1]) {
        int aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
        interacoes++;
      }
    }
  }
  printf("Interações Bubble Sort: %i", interacoes);
  int msec = finalizarCronometro(tempoInicial);
  printf("\nCrônometro BubbleSort: Tempo: %d segundos e %d milésimos", msec/1000, msec%1000);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//QUICKSORT

int partition(int vetor[], int menor, int maior) {
  
  int pivo = vetor[maior];
  int i = (menor - 1);

  for (int j = menor; j < maior; j++) {
    if (vetor[j] <= pivo) {
        
      i++;
      
      troca(&vetor[i], &vetor[j]);
    }
  }

  troca(&vetor[i + 1], &vetor[maior]);
  return (i + 1);
}

void quickSort(int vetor[], int menor, int maior) {
  int interacoes = 0;
  if (menor < maior) {
    
    int pi = partition(vetor, menor, maior);
    
    quickSort(vetor, menor, pi - 1);
    
    quickSort(vetor, pi + 1, maior);
  }
  
}

//---------------------------------------------------------------------------------------------------------------------------------------------
//HEAPSORT
  
  void heapify(int vetor[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && vetor[left] > vetor[largest])
      largest = left;
  
    if (right < n && vetor[right] > vetor[largest])
      largest = right;
  
    if (largest != i) {
      troca(&vetor[i], &vetor[largest]);
      heapify(vetor, n, largest);
    }
  }
  
  void heapSort(int vetor[], int n) {
    int interacoes = 0;
    clock_t tempoInicial = clock();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
      heapify(vetor, n, i);
      interacoes++;
    }
  
    for (int i = n - 1; i >= 0; i--) {
      troca(&vetor[0], &vetor[i]);

      heapify(vetor, i, 0);
    }
    printf("Interações Heap Sort: %i", interacoes);
    int msec = finalizarCronometro(tempoInicial);
    printf("\nCronometro Heap:Tempo: %d segundos e %d milésimos", msec/1000, msec%1000);
  }

//==================================================================
//IMPRIMIR
void imprimirVetor(int vetor[], int tam) {
  for (int i = 0; i < tam; ++i) {
    printf("%d  ", vetor[i]);
  }
  printf("\n");
}

//MAIN
int main() {
  int vet[] = {8, 7, 2, 1, 0, 9, 6};
  int vet_bubble[] = {8, 7, 2, 1, 0, 9, 6};
  int vet_selection[] = {8, 7, 2, 1, 0, 9, 6};
  int vet_quick[] = {8, 7, 2, 1, 0, 9, 6};
  int vet_heap[] = {8, 7, 2, 1, 0, 9, 6};
  
  int n = sizeof(vet) / sizeof(vet[0]);
  
  printf("Vetor original:\n");
  imprimirVetor(vet, n);

  printf("Bubble\n");
  bubbleSort(vet_bubble, n);
  printf("\nVetor:\n");
  imprimirVetor(vet_bubble, n);

  printf("Selection\n");
  selectionSort(vet_selection, n);
  printf("\nVetor:\n");
  imprimirVetor(vet_selection, n);

  printf("\n\nVetor Quick\n");
  quickSort(vet_quick, 0, n - 1);
  printf("\nVetor:\n");
  imprimirVetor(vet, n);

  printf("\n\nVetor Heap\n");
  heapSort(vet_heap, n);
  printf("\nVetor:\n");
  imprimirVetor(vet_heap, n);

}