/*
1. Introdução:
O Bubble Sort é um algoritmo de ordenação simples que compara repetidamente pares de elementos adjacentes e os troca se estiverem na ordem errada. Esse processo é repetido até que nenhuma troca seja necessária, indicando que a lista está ordenada.

2. Funcionamento:

Comparação e Troca: O algoritmo compara elementos adjacentes e troca aqueles que estão fora de ordem.
Iteração: Essa comparação e troca são realizadas em passagens sucessivas pela lista até que nenhum elemento precise ser trocado.
*/

#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
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

    bubbleSort(arr, tamanho);

    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);

    return 0;
}
