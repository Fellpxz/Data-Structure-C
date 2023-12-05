/*
1. Introdução:
O Selection Sort é um algoritmo de ordenação simples que divide a lista em duas partes: a parte ordenada e a parte não ordenada. O algoritmo seleciona repetidamente o menor elemento da parte não ordenada e o troca com o primeiro elemento não ordenado. Esse processo é repetido até que toda a lista esteja ordenada.

2. Funcionamento:

Divisão da Lista: A lista é dividida em duas partes, a parte ordenada e a parte não ordenada.
Seleção do Menor Elemento: O menor elemento da parte não ordenada é selecionado.
Troca: O menor elemento é trocado com o primeiro elemento da parte não ordenada.
Iteração: Esse processo é repetido até que toda a lista esteja ordenada.
*/

#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[indiceMenor]) {
                indiceMenor = j;
            }
        }
        trocar(&arr[indiceMenor], &arr[i]);
    }
}

void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, tamanho);

    selectionSort(arr, tamanho);

    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);

    return 0;
}
