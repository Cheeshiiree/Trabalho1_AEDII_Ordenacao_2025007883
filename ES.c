/*
 * Anna Beatryz Costa - 2025007883
 * Funções auxiliares para Entrada e Saída
 * Geração e impressão de vetores de inteiros
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ES.h"

/*
 * Função: imprimeVetor
 * --------------------
 * Imprime todos os elementos de um vetor de inteiros na mesma linha.
 *
 * vet: vetor a ser impresso
 * tam: tamanho do vetor
 */
void imprimeVetor(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

/*
 * Função: geraVetorAleatorio
 * --------------------------
 * Gera um vetor de inteiros aleatórios no intervalo [min, max].
 *
 * tam: quantidade de elementos no vetor
 * min: valor mínimo permitido
 * max: valor máximo permitido
 * semente: valor para inicialização do gerador de números aleatórios
 *
 * retorna: ponteiro para o vetor gerado
 */
int *geraVetorAleatorio(int tam, int min, int max, int semente)
{
    int *vet = (int *)malloc(tam * sizeof(int));
    if (vet == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    srand(semente); // Inicializa a semente

    for (int i = 0; i < tam; i++)
    {
        vet[i] = rand() % (max - min + 1) + min;
    }

    return vet;
}

// --------------------------------------------------------
// Função: geraAleatorios
// Gera vetor com valores aleatórios entre 0 e tam
// --------------------------------------------------------
int* geraAleatorios(int tam, int semente)
{
    int *vetor = (int *)malloc(tam * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    srand(semente);
    for (int i = 0; i < tam; i++)
    {
        vetor[i] = rand() % (tam + 1);
    }

    return vetor;
}

// --------------------------------------------------------
// Função: geraQuaseOrdenados
// Gera vetor com 90% ordenado e 10% desordenado
// --------------------------------------------------------
int* geraQuaseOrdenados(int tam, int porcentagem)
{
    int *vetor = (int *)malloc(tam * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < tam; i++)
    {
        vetor[i] = i;
    }

    int quantidade = (tam * porcentagem) / 100;

    srand(time(NULL));
    for (int i = 0; i < quantidade; i++)
    {
        int idx1 = rand() % tam;
        int idx2 = rand() % tam;
        int temp = vetor[idx1];
        vetor[idx1] = vetor[idx2];
        vetor[idx2] = temp;
    }

    return vetor;
}

// --------------------------------------------------------
// Função: geraOrdenados
// Gera vetor crescente (ordem == 0) ou decrescente (ordem == 1)
// --------------------------------------------------------
int* geraOrdenados(int tam, int ordem)
{
    int *vetor = (int *)malloc(tam * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    if (ordem == 0)
    {
        for (int i = 0; i < tam; i++)
        {
            vetor[i] = i;
        }
    }
    else
    {
        for (int i = 0; i < tam; i++)
        {
            vetor[i] = tam - i;
        }
    }

    return vetor;
}
