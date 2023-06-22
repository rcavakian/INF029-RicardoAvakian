#include <stdio.h>

/* 
Faça um programa que leia a idade de duas pessoas e imprima a soma das idades

Create a program that reads the age of two people and prints the sum of their ages.

*/

int main() {
  
  int idade_1;
  int idade_2;
  int somaIdades;
  
  printf("Por favor informe a idade da primeira pessoa: ");
  scanf("%d", &idade_1);
  printf("Por favor informe a idade da segunda pessoa: ");
  scanf("%d", &idade_2);

  somaIdades = idade_1 + idade_2;

  printf("A soma das duas idades é : %d\n", somaIdades);

  return 0;
  
}