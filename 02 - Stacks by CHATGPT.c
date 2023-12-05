#include <stdio.h>
#include <stdlib.h>

// Definição do nó da pilha
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definição da pilha
typedef struct {
    Node* top; // Ponteiro para o nó no topo da pilha
} Stack;

// Função para inicializar uma pilha vazia
void initializeStack(Stack* stack) {
    stack->top = NULL;
}

// Função para verificar se a pilha está vazia
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Função para adicionar um elemento à pilha (push)
void push(Stack* stack, int data) {
    // Criar um novo nó
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    // Atribuir dados ao nó
    newNode->data = data;

    // Atualizar o próximo nó para apontar para o antigo topo
    newNode->next = stack->top;

    // Atualizar o topo para apontar para o novo nó
    stack->top = newNode;
}

// Função para remover um elemento da pilha (pop)
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Erro: Pilha vazia\n");
        exit(EXIT_FAILURE);
    }

    // Obter o valor do nó no topo
    int data = stack->top->data;

    // Manter uma referência temporária ao nó atual
    Node* temp = stack->top;

    // Atualizar o topo para apontar para o próximo nó
    stack->top = stack->top->next;

    // Liberar a memória alocada para o nó removido
    free(temp);

    // Retornar o valor removido
    return data;
}

// Função para imprimir os elementos da pilha
void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("Pilha: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Função para liberar a memória da pilha
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

int main() {
    // Criar uma pilha
    Stack minhaPilha;
    initializeStack(&minhaPilha);

    // Adicionar elementos à pilha
    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);

    // Imprimir a pilha
    printStack(&minhaPilha);

    // Remover um elemento da pilha
    int elementoRemovido = pop(&minhaPilha);
    printf("Elemento removido: %d\n", elementoRemovido);

    // Imprimir a pilha após a remoção
    printStack(&minhaPilha);

    // Liberar a memória da pilha
    freeStack(&minhaPilha);

    return 0;
}
