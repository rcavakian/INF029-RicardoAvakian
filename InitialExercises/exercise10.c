#include <stdio.h>
#include <string.h>

/*
Faça um programa que leia os dados de nome, idade, sexo e cpf de 5 pessoas. Ao final imprima tudo. Utilize vetor e struct.

Create a program that reads the data of name, age, gender, and social security number (CPF) from 5 people. At the end, print everything. Use arrays and structures.

*/

struct Pessoa
{
  char nome[30];
  int idade;
  char sexo;
  char cpf[11];
};

void limpar_entrada()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

int main() {

  struct Pessoa pessoas[5];
  struct Pessoa pessoa;

  for (int i = 0; i < 5; i++) {
    printf("Digite nome da %da. pessoa: ", i + 1);
    fgets(pessoas[i].nome, sizeof(pessoa.nome), stdin);

    printf("Digite a idade da %da. pessoa: ", i + 1);
    scanf("%d", &pessoas[i].idade);

    printf("Digite o sexo da %da. pessoa: ", i + 1);
    limpar_entrada();
    scanf("%c", &pessoas[i].sexo);

    printf("Digite o CPF da %da. pessoa: ", i + 1);
    limpar_entrada();
    fgets(pessoas[i].cpf, sizeof(pessoa.cpf), stdin);
    limpar_entrada();
  }
  
  for (int i = 0; i < 5; i++) {
    printf("\n%da. pessoa \nNome: %sIdade: %d\nSexo: %c\nCPF: %s\n", i + 1, pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo, pessoas[i].cpf);
  }

  return 0;
}