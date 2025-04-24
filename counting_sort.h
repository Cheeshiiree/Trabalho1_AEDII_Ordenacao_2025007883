/*
 * Anna Beatryz Costa - 2025007883
 * Cabeçalho do algoritmo Counting Sort
 */

#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

/*
 * Função: countingSort
 * --------------------
 * Ordena um vetor de inteiros usando Counting Sort.
 *
 * array: vetor de inteiros a ser ordenado
 * size: tamanho do vetor
 * k: maior valor esperado no vetor (define o intervalo de contagem)
 */

// void countingSort(int *array, int size, int k);

extern int comparacoes_counting;
extern int movimentacoes_counting;

void countingSortCont(int *array, int size, int k);

#endif // COUNTING_SORT_H
