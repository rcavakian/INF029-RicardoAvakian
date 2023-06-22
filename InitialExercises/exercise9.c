#include <stdio.h>
/*
Faça um programa que leia 10 números do usuário e informe quais deles são primos. Além disso, mostre a soma de todos os números primos existentes.

Create a program that reads 10 numbers from the user and informs which of them are prime. Additionally, show the sum of all the prime numbers present.

*/
int main()
{
    int numero, divisor, primo, soma, x;
    x = 1;
    soma = 0;

    while (x <= 10)
    {
        printf("Digite um numero inteiro para saber se é primo: ");
        scanf("%d", &numero);
        
        // precisa colocar condicao para excluir o 1 e o 2

        // 1ª condição que exclui o 1 e qualquer numero negativo 
        if (numero == 1 || numero <= 0)
        {
            printf("Número %d não é primo\n\n", numero);
            x++;
            continue;
        }

        // 2ª condiação que avalia caso o numero seja o 2 ou o 3
        if (numero == 2 || numero == 3) 
        {
            printf("Número %d é primo\n\n", numero);
            soma += numero;
            x++;
            continue;
        }
        
        // 3ª condição que avalia se o numero é par 
        if (numero % 2 == 0)
        {
            printf("Número %d não é primo\n\n", numero);
        }
        // 4ª condição que avalia quando um numero é impar 
        else
        {
            divisor = numero / 2;
            for (int i = divisor; i > 1; i--)
            {
                if (numero % i == 0)
                {
                    primo = 0;
                }
            }
            // 5ª condição que avalia se o numero é primo
            if (primo == 0)
            {
                printf("Número %d não é primo\n\n", numero);
            }

            // 6ª condição que avalia se o numero é primo
            else
            {
                printf("Numero %d é primo\n\n", numero);
                soma += numero;
            }
        }
        primo = 1;
        x++;
    }
    printf("Soma dos numeros primos: %d\n", soma);

    return 0;
}