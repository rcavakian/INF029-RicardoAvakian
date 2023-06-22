#include <stdio.h>
/*
Faça um programa que verifique se um número é primo

Create a program that checks whether a number is prime.

*/
int main()
{

  int numero, divisor, primo;

  printf("Digite um numero inteiro para saber se é primo: ");
  scanf("%d", &numero);

  // 1ª condição que exclui o 1 e qualquer numero negativo
  if (numero == 1 || numero <= 0)
  {
    printf("Número %d não é primo\n\n", numero);
    return 0;
  }

  // 2ª condiação que avalia caso o numero seja o 2 ou o 3
  if (numero == 2 || numero == 3)
  {
    printf("Número %d é primo\n\n", numero);
    return 0;
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
        primo = 1;
        return 0;
      }
    }
    (primo == 1) ? printf("Número %d não é primo\n\n", numero) : printf("Numero %d é primo\n\n", numero);
  }

  return 0;
}