#include <stdio.h>

/* 
Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar

Create a program that reads two values entered by the user and swaps the values in the variables without using an auxiliary variable.

*/

int main() {
  
  int number_1;
  int number_2;
  
  printf("Por favor informe o primeiro numero: ");
  scanf("%d", &number_1);
  printf("Por favor informe o segundo numero: ");
  scanf("%d", &number_2);

  number_1 = number_1 + number_2;
  number_2 = number_1 - number_2;
  number_1 = number_1 - number_2;
  
  printf("Apos a troca o primeiro numero passou para: %d\n", number_1);
  printf("Apos a troca o segundo numero passou para: %d\n", number_2);
  

  return 0;
  
}