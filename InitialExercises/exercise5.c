#include <stdio.h>

/* 
Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor

Create a program that reads a person's age and informs whether they are of legal age or a minor.

*/

int main() {
  
  int idade;
  
  printf("Por favor informe a idade: ");
  scanf("%d", &idade);

  (idade >= 18)? printf("Maior de idade\n") : printf("Menor de idade\n");

  return 0;
  
}