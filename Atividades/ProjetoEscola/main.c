#include <stdio.h>
#include "aluno.h"
#include "data_nascimento.h"
#include "professor.h"
#include "disciplina.h"

#define TAM_alunos 3

int main() {

  int opcao;

  printf("\n\t\tProjeto Escola\n");
  do
  {
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("4 - Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("\n\t\tMódulo Aluno\n");
      break;
    case 2:
      printf("\n\t\tMódulo Professor\n");
      break;
    case 3:
      printf("\n\t\tMódulo Disciplina\n");
      break;
    case 4:
      printf("\n\t\tPrograma finalizado\n");
      break;
    default:
      printf("\n\t\tOpção inválida!\n");
      break;
    }

  } while (opcao != 4);
  

  return 0;
}