#include <stdio.h>

/* 
Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor. O programa deve repetir essa ação até que uma idade negativa seja informada

Create a program that reads a person's age and informs whether they are an adult or a minor. The program should repeat this action until a negative age is entered.

*/

int main() {
  
  int idade;

  do {
    printf("Por favor informe a idade: ");
    scanf("%d", &idade);

    if (idade < 0) {
      break;
    } 
    else {
      (idade >= 18)? printf("Maior de idade\n") : printf("Menor de idade\n");
    } 
  } while (idade >=0);
  
  return 0;
  
}