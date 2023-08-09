#include <stdio.h>

/*
Faça um programa que tenha uma função que recebe um número inteiro e retorna 
o fatorial deste número. Esta função deve ainda verificar se é possível calcular 
o fatorial, se não for, ela deve de alguma forma retornar para a main que deu 
algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial 
dele, ou se não é possível calcular o fatorial.
*/

int fatorial(int numero) {
    if (numero == 0) {
        return 1;
    }
    else if (numero < 0) {
        return -1;
    }
    else {
        return numero * fatorial(numero - 1);
    }
}

int main() {

    int numero, resultado;
    
    printf("\nDigite um numero inteiro e positivo para obter o seu fatorial: ");
    scanf("%d", &numero);


    if (numero <= 0) {
        printf("\nNumero informado inválido\n");
    }
    else {
        resultado = fatorial(numero);
        printf("\nResultado = %d\n\n", resultado);
    }

}