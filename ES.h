/*
 * Anna Beatryz Costa - 2025007883
 * Cabeçalho para funções de Entrada e Saída (ES.c)
 */

#ifndef ES_H
#define ES_H

/*
 * Função: imprimeVetor
 * --------------------
 * Imprime todos os elementos de um vetor de inteiros.
 *
 * vet: vetor a ser impresso
 * tam: tamanho do vetor
 */
void imprimeVetor(int *vet, int tam);

/*
 * Função: geraVetorAleatorio
 * --------------------------
 * Gera vetor com números aleatórios entre [min, max].
 *
 * tam: tamanho do vetor
 * min: valor mínimo
 * max: valor máximo
 * semente: número para controle de aleatoriedade
 *
 * retorna: ponteiro para o vetor gerado
 */
int *geraVetorAleatorio(int tam, int min, int max, int semente);

/*
 * Função: geraAleatorios
 * ----------------------
 * Gera vetor com números aleatórios entre [0, max].
 *
 * tam: tamanho do vetor
 * semente: número para controle de aleatoriedade
 *
 * retorna: ponteiro para o vetor gerado
 */
int *geraAleatorios(int tam, int semente);
int *geraQuaseOrdenados(int tam, int porcentagem);
int *geraOrdenados(int tam, int ordem);

#endif // ES_H
