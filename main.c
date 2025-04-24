/*
 * Anna Beatryz Costa - 2025007883
 * Benchmarking de algoritmos de ordenação com contagem de comparações e movimentações
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ES.h"
#include "counting_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"

#define TAMANHO_VETOR 100
#define MAX_VALOR 1000

void salvarVetor(FILE *arquivo, const char *algoritmo, int *vet, int tam, double tempo, int comp, int mov)
{
    fprintf(arquivo, "Algoritmo: %s\n", algoritmo);
    fprintf(arquivo, "Tempo: %.2f ms\n", tempo);
    fprintf(arquivo, "Comparacoes: %d\n", comp);
    fprintf(arquivo, "Movimentacoes: %d\n", mov);
    fprintf(arquivo, "Vetor ordenado:\n");
    for (int i = 0; i < tam; i++)
    {
        fprintf(arquivo, "%d ", vet[i]);
    }
    fprintf(arquivo, "\n\n");
}

void copiarVetor(int *origem, int *destino, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        destino[i] = origem[i];
    }
}

int main()
{
    int *original = geraVetorAleatorio(TAMANHO_VETOR, 0, MAX_VALOR, 42);
    int *original_insertion = geraVetorAleatorio(TAMANHO_VETOR, 0, MAX_VALOR, 42);
    int *original_quick = geraVetorAleatorio(TAMANHO_VETOR, 0, MAX_VALOR, 42);
    int *original_counting = geraVetorAleatorio(TAMANHO_VETOR, 0, MAX_VALOR, 42);
    int *vetTemp = (int *)malloc(TAMANHO_VETOR * sizeof(int));

    FILE *saida = fopen("resultados_ordenacao.txt", "w");
    if (saida == NULL)
    {
        printf("Erro ao abrir arquivo de saída.\n");
        return 1;
    }

    FILE *csv = fopen("resultados_ordenacao.csv", "w");
    if (csv == NULL)
    {
        printf("Erro ao criar arquivo CSV.\n");
        return 1;
    }

    fprintf(saida, "Teste com %d elementos\n\n", TAMANHO_VETOR);
    fprintf(csv, "Algoritmo,Tamanho,Tempo(ms),Comparacoes,Movimentacoes\n");

    printf("Vetor original:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++)
    {
        printf("%d ", original[i]);
        fprintf(saida, "%d ", original[i]);
    }
    printf("\n\n");
    fprintf(saida, "\n\n");

    // === Insertion Sort ===
    copiarVetor(original_insertion, vetTemp, TAMANHO_VETOR);
    clock_t start = clock();
    insertionSortCont(vetTemp, TAMANHO_VETOR);
    clock_t end = clock();
    double tempo = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("\nAlgoritmo: Insertion Sort\n");
    printf("Tempo: %.2f ms\n", tempo);
    printf("Comparacoes: %d\n", comparacoes_insertion);
    printf("Movimentacoes: %d\n", movimentacoes_insertion);
    printf("Vetor ordenado:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++)
        printf("%d ", vetTemp[i]);
    printf("\n");

    fprintf(saida, "Algoritmo: Insertion Sort\nTempo: %.2f ms\nComparacoes: %d\nMovimentacoes: %d\n",
            tempo, comparacoes_insertion, movimentacoes_insertion);
    fprintf(saida, "Vetor ordenado:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++)
        fprintf(saida, "%d ", vetTemp[i]);
    fprintf(saida, "\n\n");
    fprintf(csv, "InsertionSort,%d,%.2f,%d,%d\n", TAMANHO_VETOR, tempo, comparacoes_insertion, movimentacoes_insertion);

    // === Quick Sort ===
    copiarVetor(original_quick, vetTemp, TAMANHO_VETOR);
    start = clock();
    quickSortCont(vetTemp, 0, TAMANHO_VETOR - 1);
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("\nAlgoritmo: Quick Sort\n");
    printf("Tempo: %.2f ms\n", tempo);
    printf("Comparacoes: %d\n", comparacoes_quick);
    printf("Movimentacoes: %d\n", movimentacoes_quick);
    printf("Vetor ordenado:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++)
        printf("%d ", vetTemp[i]);
    printf("\n");

    fprintf(saida, "Algoritmo: Quick Sort\nTempo: %.2f ms\nComparacoes: %d\nMovimentacoes: %d\n",
            tempo, comparacoes_quick, movimentacoes_quick);
    fprintf(saida, "Vetor ordenado:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++)
        fprintf(saida, "%d ", vetTemp[i]);
    fprintf(saida, "\n\n");
    fprintf(csv, "QuickSort,%d,%.2f,%d,%d\n", TAMANHO_VETOR, tempo, comparacoes_quick, movimentacoes_quick);

    // === Counting Sort ===
    copiarVetor(original_counting, vetTemp, TAMANHO_VETOR);
    start = clock();
    countingSortCont(vetTemp, TAMANHO_VETOR, MAX_VALOR);
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    printf("\nAlgoritmo: Counting Sort\n");
    printf("Tempo: %.2f ms\n", tempo);
    printf("Comparacoes: %d\n", comparacoes_counting);
    printf("Movimentacoes: %d\n", movimentacoes_counting);
    printf("Vetor ordenado:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++)
        printf("%d ", vetTemp[i]);
    printf("\n");

    fprintf(saida, "Algoritmo: Counting Sort\nTempo: %.2f ms\nComparacoes: %d\nMovimentacoes: %d\n",
            tempo, comparacoes_counting, movimentacoes_counting);
    fprintf(saida, "Vetor ordenado:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++)
        fprintf(saida, "%d ", vetTemp[i]);
    fprintf(saida, "\n\n");
    fprintf(csv, "CountingSort,%d,%.2f,%d,%d\n", TAMANHO_VETOR, tempo, comparacoes_counting, movimentacoes_counting);

    // Finalização
    fclose(saida);
    fclose(csv);
    free(original);
    free(vetTemp);
    free(original_insertion);
    free(original_quick);
    free(original_counting);

    printf("\nResultados salvos em 'resultados_ordenacao.txt' e 'resultados_ordenacao.csv'\n");

    return 0;
}

// Compile com: gcc main.c counting_sort.c insertion_sort.c quick_sort.c ES.c -o benchmark -lm
// Execute com: ./benchmark
// Abra o arquivo 'benchmark_resultados.csv' para visualizar os resultados