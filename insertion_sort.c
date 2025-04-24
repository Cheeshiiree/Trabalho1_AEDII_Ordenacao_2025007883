/*
 * Anna Beatryz Costa - 2025007883
 * Algoritmo: Insertion Sort
 * Ordenação por inserção, eficiente para pequenas entradas.
 */

#include <stdio.h>
#include "insertion_sort.h"

/*
 * Função: insertionSort
 * ---------------------
 * Ordena um vetor de inteiros usando o algoritmo de inserção.
 *
 * array: vetor de inteiros a ser ordenado
 * size: tamanho do vetor
 */
void insertionSort(int *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

int comparacoes_insertion = 0;
int movimentacoes_insertion = 0;

void insertionSortCont(int *array, int size)
{
    comparacoes_insertion = 0;
    movimentacoes_insertion = 0;
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        comparacoes_insertion++;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            movimentacoes_insertion++;
            j--;
            comparacoes_insertion++;
        }
        array[j + 1] = key;
        movimentacoes_insertion++;
    }
}