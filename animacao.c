#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // Para Sleep()
#include <time.h>

#define TAM 15 // Tamanho do vetor
#define DELAY 600000 // microssegundos para animação (600ms)

// Função para imprimir o vetor como barras verticais
void printVetorAnimado(int *vet, int tam, int pos1, int pos2) {
    system("cls"); // Use "cls" no Windows
    for (int i = 0; i < tam; i++) {
        if (i == pos1 || i == pos2)
            printf(">> ");
        else
            printf("   ");
        for (int j = 0; j < vet[i]; j++) printf("|");
        printf(" (%d)\n", vet[i]);
    }
    Sleep(DELAY / 1000); // Sleep espera milissegundos
}

// Insertion Sort com animação
void insertionSortAnimado(int *vet, int tam) {
    for (int i = 1; i < tam; i++) {
        int chave = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            printVetorAnimado(vet, tam, j, j + 1);
            j--;
        }
        vet[j + 1] = chave;
        printVetorAnimado(vet, tam, j + 1, i);
    }
}

// Quick Sort com animação
void quickSortAnimado(int *vet, int inicio, int fim, int tam) {
    if (inicio < fim) {
        int pivo = vet[fim];
        int i = inicio - 1;
        for (int j = inicio; j < fim; j++) {
            if (vet[j] <= pivo) {
                i++;
                int temp = vet[i];
                vet[i] = vet[j];
                vet[j] = temp;
                printVetorAnimado(vet, tam, i, j);
            }
        }
        int temp = vet[i + 1];
        vet[i + 1] = vet[fim];
        vet[fim] = temp;
        printVetorAnimado(vet, tam, i + 1, fim);

        quickSortAnimado(vet, inicio, i, tam);
        quickSortAnimado(vet, i + 2, fim, tam);
    }
}

// Counting Sort com animação
void countingSortAnimado(int *vet, int tam) {
    int max = vet[0];
    for (int i = 1; i < tam; i++)
        if (vet[i] > max)
            max = vet[i];

    int *count = (int *)calloc(max + 1, sizeof(int));
    int *saida = (int *)malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++) count[vet[i]]++;
    for (int i = 1; i <= max; i++) count[i] += count[i - 1];

    for (int i = tam - 1; i >= 0; i--) {
        saida[count[vet[i]] - 1] = vet[i];
        count[vet[i]]--;
    }

    for (int i = 0; i < tam; i++) {
        vet[i] = saida[i];
        printVetorAnimado(vet, tam, i, -1);
    }

    free(count);
    free(saida);
}

// Gera um vetor aleatório para testes
void gerarVetorAleatorio(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % 30 + 1; // Valores entre 1 e 20
    }
}

//Imprimir o vetor gerado e a semente
void printVetor(int *vet, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

// Menu principal
int main() {
    int semente;
    printf("Digite uma semente: ");
    scanf("%d", &semente);
    srand(semente);
    int vet[TAM];
    int opcao;

    do {
        printf("\n=== ANIMACAO DE ORDENACAO ===\n");
        printf("1 - Insertion Sort\n");
        printf("2 - Quick Sort\n");
        printf("3 - Counting Sort\n");
        printf("0 - Sair\n");
        printf("Escolha um algoritmo: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 3) {
            gerarVetorAleatorio(vet, TAM);
            printf("Usando semente: %d\n", semente);
            printf("\nVetor gerado:\n");
            printVetorAnimado(vet, TAM, -1, -1);
            Sleep(1000); // Sleep espera milissegundos

            switch (opcao) {
                case 1:
                    insertionSortAnimado(vet, TAM);
                    break;
                case 2:
                    quickSortAnimado(vet, 0, TAM - 1, TAM);
                    break;
                case 3:
                    countingSortAnimado(vet, TAM);
                    break;
            }

            printf("\nOrdenacao completa!\n");
            Sleep(2000); // Sleep espera milissegundos
        }

    } while (opcao != 0);

    printf("Encerrando animacao.\n");
    return 0;
}
