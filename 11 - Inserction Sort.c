/*
1. Introdução:
O Insertion Sort é um algoritmo de ordenação eficiente para um número pequeno de elementos. Ele constrói uma sequência ordenada à medida que percorre a lista e insere cada elemento na posição correta.

2. Funcionamento:

Divisão da Lista: A lista é dividida em duas partes, a parte ordenada e a parte não ordenada.
Seleção e Inserção: A cada iteração, um elemento é selecionado da parte não ordenada e inserido na posição correta na parte ordenada.
Iteração: Esse processo é repetido até que toda a lista esteja ordenada.
*/

#include <stdio.h>

void insertionSort(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = chave;
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

    insertionSort(arr, tamanho);

    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);

    return 0;
}
