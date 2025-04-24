/*
 * Anna Beatryz Costa - 2025007883
 * Cabeçalho do algoritmo Quick Sort
 */

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

/*
 * Função: quickSort
 * -----------------
 * Ordena um vetor de inteiros usando o algoritmo Quick Sort (divisão e conquista).
 *
 * array: vetor de inteiros
 * low: índice inicial do intervalo a ordenar
 * high: índice final do intervalo a ordenar
 */

// void quickSort(int *array, int low, int high);

extern int comparacoes_quick;
extern int movimentacoes_quick;

void quickSortCont(int *array, int low, int high);

/*
 * Função: partition
 * -----------------
 * Realiza a partição do vetor com base em um pivô.
 *
 * array: vetor a ser particionado
 * low: índice inicial
 * high: índice final
 *
 * retorna: índice do pivô posicionado corretamente
 */
int partition(int *array, int low, int high);

#endif // QUICK_SORT_H
