#include <stdio.h>

/* 
Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas

Create a program that reads the age of two people and prints the sum of their ages.

*/

int main() {
  
  int number_1;
  int number_2;
  int swap; 
  
  printf("Por favor informe o primeiro numero: ");
  scanf("%d", &number_1);
  printf("Por favor informe o segundo numero: ");
  scanf("%d", &number_2);

  swap = number_1;
  number_1 = number_2;
  number_2 = swap;
  
  printf("Apos a troca o primeiro numero passou para: %d\n", number_1);
  printf("Apos a troca o segundo numero passou para: %d\n", number_2);
  

  return 0;
  
}