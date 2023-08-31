#include <stdio.h>
#define TAM 3
/*
Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números 
do usuário e retornar os três números. A função main deve imprimir esses três números. 
Utilize vetor para fazer o retorno.
*/

int leituraNumeros(int primeiro, int segundo, int terceiro) {
    int vetor[TAM] = { primeiro, segundo, terceiro};
    // vetor[0] = primeiro;
    // vetor[1] = segundo;
    // vetor[2] = terceiro;
    return vetor;
}

int main() {
    int numero1, numero2, numero3;
    int vetor[TAM];

    printf("\nPor favor informe 3 (tres) numeros inteiros.\n");
    scanf("%d%d%d", &numero1, &numero2, &numero3);

    vetor = leituraNumeros(numero1, numero2, numero3);
    
}