/*
 * Anna Beatryz Costa - 2025007883
 * Benchmarking completo para algoritmos de ordenação com múltiplos tamanhos e tipos de entrada.
 * com tempos individuais por algoritmo, tipo de entrada e tempo total.
 * Gera um .csv com tempos médios de execução conforme solicitado pela professora.
 */

//Definir como UTF-8 para evitar problemas com acentuação
#pragma execution_character_set("utf-8")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ES.h"
#include "counting_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"

#define NUM_TAMANHOS 6
#define REPETICOES 5
#define MAX_VALOR 1000000

//int tamanhos[NUM_TAMANHOS] = {100, 1000, 10000, 100000, 1000000, 10000000}; // O tamanho 100000, 1000000 e 10000000 não consegue ser executado em minha máquina então utilizarei tamanhos que consigo executar
int tamanhos[NUM_TAMANHOS] = {100, 1000, 10000, 20000, 25000, 32400}; // Tamanhos reduzidos para evitar estouro de memória
// Tamanho máximo que é possível executar em minha máquina é 32400
int main()
{
    clock_t inicioBenchmark = clock();

    FILE *csv = fopen("benchmark_QIC.csv", "w");
    if (csv == NULL)
    {
        printf("Erro ao criar arquivo CSV.\n");
        return 1;
    }

    fprintf(csv, "Algoritmo,Tamanho,TipoEntrada,TempoMedio(ms)\n");

    const char *nomeAlg[] = {"InsertionSort", "QuickSort", "CountingSort"};

    for (int t = 0; t < NUM_TAMANHOS; t++)
    {
        int tam = tamanhos[t];

        printf("\n======================================\n");
        printf("▶ Testando tamanho: %d elementos\n", tam);
        printf("======================================\n");

        // ===== ALEATÓRIO =====
        printf("• Tipo: Aleatório (%d execuções)\n", REPETICOES);
        clock_t tipoInicio = clock();
        for (int alg = 0; alg < 3; alg++)
        {
            printf("  ➤ Algoritmo: %s\n", nomeAlg[alg]);
            double soma = 0;
            for (int r = 0; r < REPETICOES; r++)
            {
                int *vet = geraAleatorios(tam, r + 1);
                clock_t inicio = clock();

                if (alg == 0)
                    insertionSortCont(vet, tam);
                if (alg == 1)
                    quickSortCont(vet, 0, tam - 1);
                if (alg == 2)
                    countingSortCont(vet, tam, MAX_VALOR);

                clock_t fim = clock();
                double tempoAlg = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
                soma += tempoAlg;
                printf("    🕒 Execução %d: %.2f ms\n", r + 1, tempoAlg);
                free(vet);
            }
            double media = soma / REPETICOES;
            printf("    📊 Média: %.2f ms\n", media);
            fprintf(csv, "%s,%d,Aleatorio,%.2f\n", nomeAlg[alg], tam, media);
        }
        clock_t tipoFim = clock();
        printf("⏱ Tempo para tipo 'Aleatório': %.2f segundos\n", ((double)(tipoFim - tipoInicio)) / CLOCKS_PER_SEC);

        // ===== CRESCENTE =====
        printf("• Tipo: Ordenado Crescente\n");
        tipoInicio = clock();
        for (int alg = 0; alg < 3; alg++)
        {
            printf("  ➤ Algoritmo: %s\n", nomeAlg[alg]);
            int *vet = geraOrdenados(tam, 0);
            clock_t inicio = clock();

            if (alg == 0)
                insertionSortCont(vet, tam);
            if (alg == 1)
                quickSortCont(vet, 0, tam - 1);
            if (alg == 2)
                countingSortCont(vet, tam, MAX_VALOR);

            clock_t fim = clock();
            double tempoAlg = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
            printf("    🕒 Tempo: %.2f ms\n", tempoAlg);
            fprintf(csv, "%s,%d,Crescente,%.2f\n", nomeAlg[alg], tam, tempoAlg);
            free(vet);
        }
        tipoFim = clock();
        printf("⏱ Tempo para tipo 'Crescente': %.2f segundos\n", ((double)(tipoFim - tipoInicio)) / CLOCKS_PER_SEC);

        // ===== DECRESCENTE =====
        printf("• Tipo: Ordenado Decrescente\n");
        tipoInicio = clock();
        for (int alg = 0; alg < 3; alg++)
        {
            printf("  ➤ Algoritmo: %s\n", nomeAlg[alg]);
            int *vet = geraOrdenados(tam, 1);
            clock_t inicio = clock();

            if (alg == 0)
                insertionSortCont(vet, tam);
            if (alg == 1)
                quickSortCont(vet, 0, tam - 1);
            if (alg == 2)
                countingSortCont(vet, tam, MAX_VALOR);

            clock_t fim = clock();
            double tempoAlg = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
            printf("    🕒 Tempo: %.2f ms\n", tempoAlg);
            fprintf(csv, "%s,%d,Decrescente,%.2f\n", nomeAlg[alg], tam, tempoAlg);
            free(vet);
        }
        tipoFim = clock();
        printf("⏱ Tempo para tipo 'Decrescente': %.2f segundos\n", ((double)(tipoFim - tipoInicio)) / CLOCKS_PER_SEC);

        // ===== QUASE ORDENADO =====
        printf("• Tipo: Quase Ordenado (10%% desordenado) - %d execuções\n", REPETICOES);
        tipoInicio = clock();
        for (int alg = 0; alg < 3; alg++)
        {
            printf("  ➤ Algoritmo: %s\n", nomeAlg[alg]);
            double soma = 0;
            for (int r = 0; r < REPETICOES; r++)
            {
                int *vet = geraQuaseOrdenados(tam, 10);
                clock_t inicio = clock();

                if (alg == 0)
                    insertionSortCont(vet, tam);
                if (alg == 1)
                    quickSortCont(vet, 0, tam - 1);
                if (alg == 2)
                    countingSortCont(vet, tam, MAX_VALOR);

                clock_t fim = clock();
                double tempoAlg = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
                soma += tempoAlg;
                printf("    🕒 Execução %d: %.2f ms\n", r + 1, tempoAlg);
                free(vet);
            }
            double media = soma / REPETICOES;
            printf("    📊 Média: %.2f ms\n", media);
            fprintf(csv, "%s,%d,QuaseOrdenado,%.2f\n", nomeAlg[alg], tam, media);
        }
        tipoFim = clock();
        printf("⏱ Tempo para tipo 'Quase Ordenado': %.2f segundos\n", ((double)(tipoFim - tipoInicio)) / CLOCKS_PER_SEC);
    }

    fclose(csv);
    clock_t fimBenchmark = clock();
    double tempoTotal = ((double)(fimBenchmark - inicioBenchmark)) / CLOCKS_PER_SEC;
    printf("\n✅ Benchmark finalizado. Tempo total: %.2f segundos\n", tempoTotal);

    return 0;
}

// Compile com: gcc main_benchmark_todos_algoritmos.c counting_sort.c insertion_sort.c quick_sort.c ES.c -finput-charset=UTF-8 -o benchmark_todos_algoritmos -lm
// Execute com: ./benchmark_todos_algoritmos
// O programa espera receber como argumento o tamanho do vetor a ser ordenado e o número de repetições para cada teste.
// O arquivo de saída "resultados_ordenacao.txt" conterá os tempos de execução, comparações e movimentações para cada algoritmo e tipo de entrada.
// O arquivo CSV gerado conterá os tempos médios de execução para cada algoritmo e tipo de entrada.
// Digite este comando no terminal antes de executar o programa:chcp 65001
// Para garantir que os caracteres especiais sejam exibidos corretamente no terminal do Windows.
