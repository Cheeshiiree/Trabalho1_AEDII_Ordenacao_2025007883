# Tema atribuido
Trabalho 1 de AEDII - Tema CountSort

# Benchmarking de Algoritmos de Ordenação - AED II (CTCO02)

Este projeto foi desenvolvido como parte do Trabalho Prático 1 da disciplina de Algoritmos e Estrutura de Dados II (CTCO02) da Universidade Federal de Itajubá (UNIFEI). O objetivo principal é implementar e realizar um benchmarking comparativo do tempo de execução de três algoritmos de ordenação interna:

1.  **Insertion Sort**
2.  **Quick Sort** (utilizando a estratégia de particionamento com pivô no início, conforme exemplo das aulas)
3.  **Counting Sort**

A análise compara o desempenho desses algoritmos ao ordenar vetores de diferentes tamanhos e com diferentes configurações iniciais (aleatório, crescente, decrescente, quase ordenado).

**Autor:** Anna Beatryz Costa - 2025007883

## Estrutura do Projeto

O projeto está organizado nos seguintes arquivos:

* **Algoritmos de Ordenação:**
    * `insertion_sort.c` / `insertion_sort.h`: Implementação do Insertion Sort (com contagem de comparações/movimentações).
    * `quick_sort.c` / `quick_sort.h`: Implementação do Quick Sort (com partição adaptada do exemplo das aulas e contagem de comparações/movimentações).
    * `counting_sort.c` / `counting_sort.h`: Implementação do Counting Sort (com contagem de movimentações).
* **Entrada/Saída e Geração de Dados:**
    * `ES.c` / `ES.h`: Funções auxiliares para:
        * Gerar vetores aleatórios (`geraAleatorios`).
        * Gerar vetores ordenados (crescente/decrescente) (`geraOrdenados`).
        * Gerar vetores quase ordenados (`geraQuaseOrdenados`).
        * Imprimir vetores (`imprimeVetor`).
* **Executáveis Principais:**
    * `main.c`: Realiza um teste simples com um vetor de tamanho fixo (100), aplicando os três algoritmos e salvando resultados detalhados (tempo, comparações, movimentações) em `resultados_ordenacao.txt` e um resumo em `resultados_ordenacao.csv`.
    * `main_benchmark_todos_algoritmos.c`: Executa o benchmarking completo, testando múltiplos tamanhos de vetor (100 a 32400, ajustados por limitações de hardware) e os quatro tipos de ordenação inicial. Calcula o tempo médio de 5 execuções para entradas aleatórias e quase ordenadas. Salva os tempos médios no arquivo `benchmark_todos_algoritmos.csv`.
    * `animacao.c`: (Opcional) Apresenta uma visualização simples do processo de ordenação para os algoritmos (requer compilação separada e ambiente Windows).
* **Resultados:**
    * `resultados_ordenacao.txt`: Saída detalhada da execução de `main.c`.
    * `resultados_ordenacao.csv`: Saída resumida em CSV da execução de `main.c`.
    * `benchmark_todos_algoritmos.csv`: Saída principal do benchmarking completo (tempos médios) gerada por `main_benchmark_todos_algoritmos.c`.
    * `Windows PowerShell.txt`: Log de exemplo da compilação e execução do benchmarking completo.
* **Outros:**
    * `README.md`: Este arquivo.

## Funcionalidades

1.  **Benchmarking Completo (`main_benchmark_todos_algoritmos.c`)**:
    * Mede o tempo médio de execução (em milissegundos) para os algoritmos Insertion Sort, Quick Sort e Counting Sort.
    * Testa os algoritmos com os seguintes tamanhos de entrada: 100, 1000, 10000, 20000, 25000, 32400.
    * Utiliza quatro tipos de vetores de entrada:
        * Aleatório (média de 5 execuções).
        * Ordenado Crescentemente.
        * Ordenado Decrescentemente.
        * Quase Ordenado (10% desordenado, média de 5 execuções).
    * Gera um arquivo CSV (`benchmark_todos_algoritmos.csv`) com os tempos médios para análise comparativa.

2.  **Teste Básico (`main.c`)**:
    * Executa os três algoritmos em um vetor aleatório de tamanho 100.
    * Registra tempo, número de comparações e número de movimentações para cada algoritmo.
    * Salva os resultados em `resultados_ordenacao.txt` e `resultados_ordenacao.csv`.

3.  **Animação de Ordenação (`animacao.c`)**:
    * Permite visualizar o funcionamento dos algoritmos em tempo real para vetores pequenos.
    * *Nota: Requer ambiente Windows e compilação separada.*

4. **Geração de Relatórios**:
    * Arquivo de texto (`resultados_ordenacao.txt`) com detalhes de cada execução.
    * Arquivo CSV (`benchmark_todos_algoritmos.csv`) com tempos para análise.

## Como Compilar e Executar

É necessário ter o compilador `gcc` instalado.

**Pré-requisito (Windows):** Para garantir a exibição correta de caracteres acentuados no terminal do Windows durante a execução do benchmark, execute o comando `chcp 65001` no prompt antes de rodar o programa.

**1. Benchmarking Completo:**

```bash
# Compilar (garantindo codificação UTF-8 para saída no terminal)
gcc main_benchmark_todos_algoritmos.c counting_sort.c insertion_sort.c quick_sort.c ES.c -finput-charset=UTF-8 -o benchmark_todos_algoritmos -lm

# Executar
./benchmark_todos_algoritmos
```

**2. Teste Básico:**

```bash
# Compilar
gcc main.c counting_sort.c insertion_sort.c quick_sort.c ES.c -o benchmark -lm

# Executar
./benchmark
```

**3. Arquivo de Animação para Curiosidade:**

```bash
# Compilar
gcc animacao.c -o animacao

# Executar
./animacao
```

>[!NOTE]Explicação Breve dos Algoritmos Abordados:
> - *Insertion Sort:* Algoritmo simples, O(n²) no caso médio e pior caso, mas eficiente (próximo a O(n)) para dados quase ordenados. Estável.
> - *Quick Sort:* Algoritmo eficiente do tipo "dividir para conquistar". Complexidade média O(n log n), mas O(n²) no pior caso (que pode ocorrer com dados já ordenados ou inversamente ordenados, dependendo da implementação do pivô). A implementação atual usa o pivô no início. Instável.
> - *Counting Sort:* Algoritmo não baseado em comparação, muito eficiente (O(n+k), onde k é o intervalo dos valores) para inteiros dentro de um intervalo conhecido e razoavelmente pequeno. Não funciona bem para intervalos muito grandes ou dados não inteiros. Estável.