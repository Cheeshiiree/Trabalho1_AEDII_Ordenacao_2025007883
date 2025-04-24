/*
 * Anna Beatryz Costa - 2025007883
 * Algoritmo: Counting Sort
 * Ordenação eficiente para dados inteiros em intervalo conhecido.
 */

#include <stdio.h>
#include <stdlib.h>
#include "counting_sort.h"

/*
 * Função: countingSort
 * --------------------
 * Ordena um vetor de inteiros usando Counting Sort.
 *
 * array: vetor de inteiros a ser ordenado
 * size: tamanho do vetor
 * k: valor máximo possível nos elementos do vetor
 */
void countingSort(int *array, int size, int k)
{
    int *output = (int *)malloc(size * sizeof(int));
    int *count = (int *)calloc(k + 1, sizeof(int));

    if (output == NULL || count == NULL)
    {
        printf("Erro ao alocar memória para o Counting Sort.\n");
        exit(1);
    }

    // Conta a frequência dos elementos
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    // Soma acumulada
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    // Gera o vetor ordenado
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copia de volta
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }

    free(output);
    free(count);
}

int comparacoes_counting = 0;
int movimentacoes_counting = 0;

void countingSortCont(int *array, int size, int k)
{
    comparacoes_counting = 0;
    movimentacoes_counting = 0;

    int *output = malloc(size * sizeof(int));
    int *count = calloc(k + 1, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
        movimentacoes_counting++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
        movimentacoes_counting++;
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
        movimentacoes_counting += 2;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
        movimentacoes_counting++;
    }

    free(output);
    free(count);
}