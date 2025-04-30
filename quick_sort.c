/*
 * Anna Beatryz Costa - 2025007883
 * Algoritmo: Quick Sort 
 * Ordenação eficiente baseada em divisão e conquista.
 */

 #include <stdio.h>
 #include "quick_sort.h"
 
 // Contadores de comparações e movimentações para análise de desempenho
 int comparacoes_quick = 0;
 int movimentacoes_quick = 0;
 
 /*
  * Função: swap
  * ------------
  * Troca dois elementos inteiros. Auxiliar para a partição.
  */
 void swap(int* a, int* b) {
     int temp = *a;
     *a = *b;
     *b = temp;
     movimentacoes_quick += 3; // Incrementa movimentações na troca
 }
 
 /*
  * Função: partitionCont
  * ---------------------
  * Realiza a partição do vetor com base no pivô (primeiro elemento),contando comparações e movimentações
  *
  * array: vetor a ser particionado
  * low: índice inicial
  * high: índice final
  *
  * retorna: índice final do pivô
  */
 int partitionCont(int *array, int low, int high) {
     // Pivô é o primeiro elemento
     int pivot = array[low];
     // 'pos' guarda a posição final correta do pivô
     int pos = low;
 
     // Percorre o vetor a partir do segundo elemento do subarray
     for (int aux = low + 1; aux <= high; aux++) {
         comparacoes_quick++; // Conta a comparação
         // Se encontrar um elemento menor que o pivô
         if (array[aux] < pivot) {
             pos++; // Incrementa a posição final do pivô
             // Se 'pos' e 'aux' são diferentes, significa que houve elementos maiores
             // antes deste menor, então realiza a troca para manter menores à esquerda
             if (pos != aux) {
                 swap(&array[pos], &array[aux]);// Troca os elementos
             }
         }
          // Se o elemento for maior ou igual, não faz nada
     }
 
     // Ao final, troca o pivô (que estava em array[low]) com array[pos]
     // para colocar o pivô em sua posição final correta.
     // Só troca se a posição final for diferente da inicial
     if (low != pos) {
        swap(&array[low], &array[pos]);
     }
 
     return pos; // Retorna a posição onde o pivô foi colocado
 }
 
 /*
  * Função: quickSortCont
  * ---------------------
  * Ordena o vetor recursivamente com Quick Sort, contando comparações e movimentações.
  *
  * array: vetor de inteiros
  * low: início do intervalo
  * high: fim do intervalo
  */
 void quickSortCont(int *array, int low, int high) {
     if (low < high) {
         // Chama a função de partição
         int pi = partitionCont(array, low, high);
 
         // Ordena recursivamente as duas sub-partes
         quickSortCont(array, low, pi - 1);
         quickSortCont(array, pi + 1, high);
     }
 }
 
 