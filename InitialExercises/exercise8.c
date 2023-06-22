#include <stdio.h>
/*
Faça um programa que calcula o fatorial de um número

Create a program that calculates the factorial of a number

*/
int main() {

  int numero, fatorial;

  printf("Digite um numero inteiro para calcular seu fatorial: ");
  scanf("%d", &numero);
    
  if (numero == 0) {
    printf("Fatorial de %d é 1", numero);
  }
  else {
    fatorial = 1;
    for (int i = numero; i >= 1; i--) {
      printf("valor de i = %d\n", i);
      fatorial *= i;
    }
    printf("Fatorial de %d é %d\n", numero, fatorial);
  }
  return 0;
}