/*
 * Anna Beatryz Costa - 2025007883
 * Cabeçalho do algoritmo Insertion Sort
 */

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

/*
 * Função: insertionSort
 * ---------------------
 * Ordena um vetor de inteiros usando o algoritmo de inserção.
 *
 * array: vetor a ser ordenado
 * size: tamanho do vetor
 */

// void insertionSort(int *array, int size);

/*
 * Função: insertionSortCont
 * --------------------------
 * Ordena um vetor de inteiros usando o algoritmo de inserção, contando comparações e movimentações.
 *
 * array: vetor a ser ordenado
 * size: tamanho do vetor
 */
extern int comparacoes_insertion;
extern int movimentacoes_insertion;

void insertionSortCont(int *array, int size);

#endif // INSERTION_SORT_H
