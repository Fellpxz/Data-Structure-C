/*
O Quicksort é um algoritmo eficiente de ordenação que segue a abordagem de dividir para conquistar. Ele funciona selecionando um elemento como pivô e particionando o array em duas partes, de modo que os elementos menores que o pivô estejam à sua esquerda, e os elementos maiores estejam à sua direita. Em seguida, o Quicksort é aplicado recursivamente às duas partes.

Aqui está uma descrição do algoritmo Quicksort:

Escolha do Pivô:

Selecione um elemento do array como pivô. Pode ser o primeiro, o último ou algum elemento aleatório.
Particionamento:

Reorganize os elementos do array de modo que os elementos menores que o pivô estejam à esquerda, e os elementos maiores estejam à direita. O pivô ocupa sua posição final.
Recursão:

Aplique o Quicksort recursivamente para as subpartes à esquerda e à direita do pivô.
Conquista:

A ordem final é obtida quando as subpartes tornam-se arrays vazios ou de um único elemento.
*/

#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
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

    quicksort(arr, 0, tamanho - 1);

    printf("Array ordenado: ");
    imprimirArray(arr, tamanho);

    return 0;
}
