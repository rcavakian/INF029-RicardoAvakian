#include <stdio.h>

/*
Crie um programa que tenha uma função soma e a função main. A função main deve 
ler dois valores, enviar para a função soma. A função soma deve realizar a soma 
e retornar o valor. A Função main deve imprimir o resultado da soma.
*/

int somar(int primeiro, int segundo) {
    return primeiro + segundo;
}

int main() {

    int valor1, valor2, soma;

    printf("Digite dois valores para calcular a soma:\n");
    scanf("%d%d", &valor1, &valor2);

    soma = somar(valor1, valor2);

    printf("\nResultado da soma: %d\n", soma);

    return 0;

}