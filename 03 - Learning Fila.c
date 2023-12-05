#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

// É ótimo deixar claro que o nó não recebe alterações. E sim as operações!

void inserir_na_fila(No **fila, int num) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;
        if (*fila == NULL) {
            *fila = novo;
        } else {
            // Encontrar o final da fila
            No *aux = *fila;
            while (aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else {
        printf("\nErro ao alocar memória.\n");
    }
}

No* remover_da_fila(No **fila) {
    No *remover = NULL;

    if (*fila) {
        remover = *fila;
        *fila = remover->proximo;
    } else {
        printf("\nFila vazia\n");
    }
    return remover;
}

void imprimir_fila(No *fila) {
    printf("\t-----------FILA-----------\n\t");
    while (fila) {
        printf("%d ", fila->valor);
        fila = fila->proximo;
    }
    printf("\n\t-----------FIM FILA-----------\n");
}

int main() {
    No *r, *fila = NULL;
    int opcao, valor;

    do {
        printf("\t0 - SAIR\n\t1 - INSERIR \n\t2 - REMOVER\n\t3 - IMPRIMIR\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir_na_fila(&fila, valor);
                break;
            case 2:
                r = remover_da_fila(&fila);
                if (r) {
                    printf("Removido: %d\n", r->valor);
                    free(r);
                }
                break;
            case 3:
                imprimir_fila(fila);
                break;
            default:
                if (opcao != 0) {
                    printf("Opção inválida\n");
                }
        }
    } while (opcao != 0);

    return 0;
}