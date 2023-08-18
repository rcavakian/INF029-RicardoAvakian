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
    printf("\n # MENU PRINCIPAL # \n\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("4 - Sair\n");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("\n**\tMódulo Aluno\t**\n");
      int opcaoAluno;
      do {
        printf("\n1 - Cadastrar Aluno\n");
        printf("2 - Listar Aluno\n");
        printf("3 - Atualizar Aluno\n");
        printf("4 - Excluir Aluno\n");
        printf("5 - Voltar MENU anterior\n");
        printf("\nOpção: "); 
        scanf("%d", &opcaoAluno);

        switch (opcaoAluno) {
      case 1:
        printf("\n1 - Cadastro de Aluno\n");
        if (contadorAlunos == TAM_alunos) {
          printf("Lista de alunos CHEIA");
        }
        else {
          printf("Digite a matricula do aluno: ");
          int matricula;
          scanf("%d", &matricula);
          listaAlunos[contadorAlunos] = matricula;
          printf("\nAluno matrícula %d cadastrado com sucesso!\n", listaAlunos[contadorAlunos]);
          contadorAlunos++;
        }
        break;
      case 2:
        printf("\n2 - Listar Alunos\n\n");
        if (contadorAlunos == 0) {
          printf("\n!\tLista de alunos vazia\t!\n");
        } else {
          for (int i = 0; i < contadorAlunos; i++) {
            printf("%d - Matricula: %d\n", i+1, listaAlunos[i]);
          }
        }
        break;
      case 3:
        printf("\n3 - Atualização de Aluno\n");
        break;
      case 4:
        printf("\n4 - Exclusão de Aluno\n");
        break;
      case 5:
        printf("\n");
        break;
      default:
        printf("\n!!\tOpção inválida\t!!\n\n");
        break;
      }
      } while (opcaoAluno != 5);

      
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