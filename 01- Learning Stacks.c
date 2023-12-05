#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Aprendendo a codar pilhas, PUSH e POP!
*/

// Estruturas!

typedef struct {
    int day, month, year;
} Data;

typedef struct {
    char name[50];
    Data data;
} Person;

typedef struct node {
    Person person;
    struct node *next;
} Node;

Person read_person() {
    Person person;

    printf("\nDigite nome e data de nascimento (DD/MM/YYYY): \n");
    scanf("%49[^\n]%d%d%d", person.name, &person.data.day, &person.data.month, &person.data.year);
    return person;
}

// Função para operação PUSH (EMPILHAR)
Node *push(Node *top) {
    Node *new = malloc(sizeof(Node));

    if (new) {
        new->person = read_person();
        new->next = top;

        return new;
    } else {
        printf("\nERROR: Out of memory");
        return NULL;
    }
}

Node *pop(Node **top) {
    if(top != NULL){
        Node *remove = *top;
        *top = remove->next;
        return remove;
    }
    else
        printf("\n Stack is empty");
    return NULL;
}

void write_person(Person person) {
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", person.name, person.data.day, person.data.month, person.data.year);
}

void imprimir_pilha(Node *top){
    printf("\n--------- PILHA ----------\n");
    while(top){
        write_person(top->person);
        top = top->next;
    }
    printf("\n--------- FIM PILHA ----------\n");
}

int main() {

    // Essa aqui vai ser nossa PILHA! Lembrando que todas as operações que realizamos são feitas no topo
    Node *remove, *top = NULL;
    int option;

    do {
        printf("\n0- Sair\n1- Empilhar\n2- Desempilhar\n3- Imprimir\n");
        scanf("%d", &option);
        getchar();  // Limpar o caractere de nova linha do buffer de entrada

        switch (option) {
        case 1:
            top = push(top);
            break;
        case 2:
            remove = pop(&top);
            if(remove){
                printf("\nElemento removido com sucesso\n");
                write_person(remove -> person);
            }
            else
                printf("\nSem nó a remover");
            break;
        case 3:
            imprimir_pilha(top);
            break;
        default:
            if (option != 0)
                printf("\nOpção inválida!!!\n");
        }
    } while (option != 0);

    return 0;
}
