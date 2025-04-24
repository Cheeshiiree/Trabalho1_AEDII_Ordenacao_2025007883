# Trabalho1_AEDII_Ordenacao_2025007883
 Trabalho 1 de AEDII - Tema CountSort

# Benchmarking de Algoritmos de Ordenação

Este projeto implementa e avalia o desempenho de diferentes algoritmos de ordenação, como **Insertion Sort**, **Quick Sort** e **Counting Sort**, utilizando diferentes tamanhos de entrada e tipos de dados (aleatórios, ordenados, quase ordenados, etc.). O objetivo é medir o tempo de execução, número de comparações e movimentações realizadas por cada algoritmo.

## Estrutura do Projeto

- **`main.c`**: Realiza o benchmarking básico para um tamanho fixo de vetor.
- **`main_benchmark_todos_algoritmos.c`**: Executa benchmarks completos para múltiplos tamanhos de entrada e tipos de dados, gerando um arquivo CSV com os resultados.
- **`animacao.c`**: Apresenta uma animação visual dos algoritmos de ordenação em execução.
- **`ES.c` e `ES.h`**: Contêm funções auxiliares para geração de vetores e manipulação de arquivos.
- **`counting_sort.c`, `insertion_sort.c`, `quick_sort.c`**: Implementações dos algoritmos de ordenação.

## Funcionalidades

1. **Benchmarking Completo**:
   - Mede o tempo médio de execução para diferentes tamanhos de entrada.
   - Testa os algoritmos com entradas aleatórias, ordenadas, quase ordenadas e decrescentes.
   - Gera um arquivo CSV com os resultados.

2. **Animação de Ordenação**:
   - Visualiza o funcionamento dos algoritmos em tempo real.
   - Exibe o vetor como barras verticais que mudam de posição durante a execução.

3. **Geração de Relatórios**:
   - Arquivo de texto (`resultados_ordenacao.txt`) com detalhes de cada execução.
   - Arquivo CSV (`benchmark_todos_algoritmos.csv`) com tempos médios para análise.

## Como Compilar

Use o comando abaixo para compilar o programa principal:

```bash
gcc [main.c](http://_vscodecontentref_/0) counting_sort.c insertion_sort.c quick_sort.c ES.c -o benchmark -lm