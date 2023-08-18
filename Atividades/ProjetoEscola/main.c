#include <stdio.h>
#include "aluno.h"
#include "data_nascimento.h"
#include "professor.h"
#include "disciplina.h"

#define TAM_alunos 3

int main() {

  int listaAlunos[TAM_alunos];
  int contadorAlunos = 0;
  int opcao;

  printf("\n**\tProjeto Escola\t**\n\n");
  do {
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("4 - Sair\n");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("\n**\tMódulo Aluno\t**\n\n");
      int opcaoAluno;
      do {
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Aluno\n");
        printf("3 - Atualizar Aluno\n");
        printf("4 - Listar Aluno\n");
        printf("5 - Voltar MENU anterior\n");
        printf("\nOpção: "); 
        scanf("%d", &opcaoAluno);

      } while (opcaoAluno != 5);

      switch (opcaoAluno) {
      case 1:
        printf("\n1 - Cadastrar Aluno\n"); 
        break;
      case 2:
        printf("\n2 - Listar Aluno\n");
        break;
      case 3:
        printf("\n3 - Atualizar Aluno\n");
        break;
      case 4:
        printf("\n4 - Listar Aluno\n");
        break;
      case 5:
        printf("\n");
        break;
      
      default:
        printf("\n!!\tOpção inválida\t!!\n\n");
        break;
      }
      break;
    case 2:
      printf("\n**\tMódulo Professor\t**\n\n");
      break;
    case 3:
      printf("\n**\tMódulo Disciplina\t**\n\n");
      break;
    case 4:
      printf("\n**\tPrograma finalizado\t**\n\n");
      break;
    default:
      printf("\n!!\tOpção inválida\t!!\n\n");
      break;
    }

  } while (opcao != 4);
  

  return 0;
}