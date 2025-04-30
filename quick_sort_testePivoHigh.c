/*
 * Anna Beatryz Costa - 2025007883
 * Algoritmo: Quick Sort
 * Ordenação eficiente baseada em divisão e conquista.
 */

#include <stdio.h>
#include "quick_sort.h"

/*
 * Função: partition
 * -----------------
 * Reorganiza os elementos do vetor baseado no pivô.
 *
 * array: vetor a ser particionado
 * low: índice inicial
 * high: índice final
 *
 * retorna: índice da posição do pivô
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            // Troca elementos
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Coloca o pivô na posição correta
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

/*
 * Função: quickSort
 * -----------------
 * Ordena o vetor recursivamente com Quick Sort.
 *
 * array: vetor de inteiros
 * low: início do intervalo
 * high: fim do intervalo
 */
void quickSort(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Contadores de comparações e movimentações para análise de desempenho

int comparacoes_quick = 0;
int movimentacoes_quick = 0;

/*
 * Função: partitionCont
 * ---------------------
 * Realiza a partição do vetor com base em um pivô, contando comparações e movimentações.
 *
 * array: vetor a ser particionado
 * low: índice inicial
 * high: índice final
 *
 * retorna: índice do pivô posicionado corretamente
 */
int partitionCont(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        comparacoes_quick++;
        if (array[j] < pivot)
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            movimentacoes_quick += 3;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    movimentacoes_quick += 3;
    return i + 1;
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
void quickSortCont(int *array, int low, int high)
{
    if (low < high)
    {
        int pi = partitionCont(array, low, high);
        quickSortCont(array, low, pi - 1);
        quickSortCont(array, pi + 1, high);
    }
}