/*
1. Introdução:
O Merge Sort é um algoritmo de ordenação eficiente que utiliza a estratégia "dividir para conquistar". Ele divide a lista em duas metades, ordena cada metade recursivamente e, em seguida, combina as duas metades ordenadas para obter a lista final ordenada.

2. Funcionamento:

Divisão (Divide): O array é dividido ao meio, criando duas sublistas.
Ordenação (Conquer): Cada sublista é ordenada recursivamente usando o Merge Sort.
Combinação (Combine): As sublistas ordenadas são mescladas para formar uma única lista ordenada.
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int baixo, int meio, int alto) {
    int i, j, k;
    int n1 = meio - baixo + 1;
    int n2 = alto - meio;

    // Criação de arrays temporários
    int L[n1], R[n2];

    // Copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[baixo + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Combina os arrays temporários de volta em arr[baixo..alto]
    i = 0;
    j = 0;
    k = baixo;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // Encontra o ponto médio do array
        int meio = baixo + (alto - baixo) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, baixo, meio);
        mergeSort(arr, meio + 1, alto);

        // Combina as partes ordenadas
        merge(arr, baixo, meio, alto);
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

    mergeSort(arr, 0, tamanho - 1);

    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);

    return 0;
}
