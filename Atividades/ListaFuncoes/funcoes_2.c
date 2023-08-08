#include <stdio.h>

/*
Crie um programa que tenha uma função subtrai e a função main. 
A função main deve ler três valores, enviar para a função subtrai. 
A função subtrai deve realizar a subtração dos três valores 
(primeiro menos o segundo menos o terceiro) e retornar o valor. 
A Função main deve imprimir o resultado da subtração.
*/

int subtrair(int primeiro, int segundo, int terceiro) {
    return primeiro - segundo - terceiro;
}

int main() {

    int valor1, valor2, valor3, resultado;

    printf("Digite três valores para calcular a subtração dos mesmos: \n");
    scanf("%d%d%d", &valor1, &valor2, &valor3);

    resultado = subtrair(valor1, valor2, valor3);

    printf("Resultado da subtração: %d\n", resultado);
}