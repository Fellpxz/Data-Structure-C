/*
Recursividade é um conceito fundamental em programação, onde uma função chama a si mesma durante sua execução. Uma função recursiva geralmente resolve um problema menor do que o original e combina as soluções desses subproblemas para obter a solução do problema original. A ideia principal é dividir um problema maior em subproblemas menores e resolver esses subproblemas.

Caso Base:
Todo algoritmo recursivo deve ter um "caso base" ou "condição de parada". É a condição que indica quando a função deve parar de se chamar recursivamente. Sem um caso base, a função continuaria chamando a si mesma indefinidamente, resultando em um estouro de pilha.

Caso Geral:
O "caso geral" é a parte da função que expressa a solução do problema em termos de subproblemas menores. Ele deve ser formulado de tal maneira que, à medida que a função se chama recursivamente, ela se aproxima do caso base.

Pilha de Chamadas:
Cada chamada recursiva é empilhada na pilha de chamadas. À medida que as chamadas são resolvidas (atingem o caso base), elas são desempilhadas. A ordem em que as chamadas são desempilhadas é crucial para garantir que a função funcione corretamente.
*/

#include <stdio.h>

// 1. Fatorial
int fatorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fatorial(n - 1);
}

// 2. Soma de Números
int somaNaturais(int n) {
    if (n == 0)
        return 0;
    else
        return n + somaNaturais(n - 1);
}

// 3. Soma de Elementos em uma Lista
int somaLista(int lista[], int tamanho) {
    if (tamanho == 0)
        return 0;
    else
        return lista[tamanho - 1] + somaLista(lista, tamanho - 1);
}

// 4. Fibonacci
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// 5. Potência
int potencia(int base, int expoente) {
    if (expoente == 0)
        return 1;
    else
        return base * potencia(base, expoente - 1);
}

// 6. Inversão de String
void inverterString(char str[], int inicio, int fim) {
    if (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;
        inverterString(str, ++inicio, --fim);
    }
}

// 7. Verificação de Palíndromo
int palindromo(char str[], int inicio, int fim) {
    if (inicio >= fim)
        return 1;
    if (str[inicio] == str[fim])
        return palindromo(str, ++inicio, --fim);
    else
        return 0;
}

// 8. Torre de Hanoi
void torreHanoi(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }
    torreHanoi(n - 1, origem, auxiliar, destino);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    torreHanoi(n - 1, auxiliar, destino, origem);
}

// 9. Soma de Dígitos
int somaDigitos(int num) {
    if (num == 0)
        return 0;
    else
        return num % 10 + somaDigitos(num / 10);
}

// 10. Sequência de Ackermann
int ackermann(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return ackermann(m - 1, 1);
    else
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    // Exemplo de uso
    printf("Fatorial de 5: %d\n", fatorial(5));
    printf("Soma dos primeiros 5 naturais: %d\n", somaNaturais(5));

    // ... chame outras funções aqui ...

    return 0;
}
