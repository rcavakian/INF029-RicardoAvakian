#include <stdio.h>
#include "aluno.h"
#include "data_nascimento.h"
#include "professor.h"
#include "disciplina.h"

#define TAM_alunos 3

int main() {

  Aluno listaAlunos[TAM_alunos];
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
          printf("\n!! Lista de alunos CHEIA !!\n");
        }
        else {
          printf("Digite a matricula do aluno: ");
          int matricula;
          scanf("%d", &matricula);
          if (matricula <= 0) {
            printf("\n\t!! Matricula do aluno INVALIDA !!\n");
            break;
          }
          else {
            listaAlunos[contadorAlunos].matricula = matricula;
            listaAlunos[contadorAlunos].ativo = 1;
            printf("\nAluno matrícula %d cadastrado com sucesso!\n", listaAlunos[contadorAlunos].matricula);
            contadorAlunos++;
          }
        }
        break;
      case 2:
        printf("\n2 - Listar Alunos\n\n");
        if (contadorAlunos == 0) {
          printf("\n!\tLista de alunos VAZIA\t!\n");
        } else {
          for (int i = 0; i < contadorAlunos; i++) {
            if (listaAlunos[i].ativo)
              printf("%dª - Matricula: %d\n", i+1, listaAlunos[i].matricula);
          } 
        }
        break;
      case 3:
        printf("\n3 - Atualização de Aluno\n\n");
        break;
      case 4:
        printf("\n4 - Exclusão de Aluno\n\n");
        printf("Digite a matricula do aluno: ");
          int matricula;
          scanf("%d", &matricula);
          int matricula_localizada = 0;
          if (matricula <= 0) {
            printf("\n!!\tMatricula do aluno INVALIDA\t!!\n");
            break;
          }
          else {
            for (int i = 0; i < contadorAlunos; i++) {
              if (matricula == listaAlunos[i].matricula) {
                listaAlunos[i].ativo = 0;
                matricula_localizada = 1;
                for (int j = i; j < contadorAlunos - 1; j++) {
                  listaAlunos[j].matricula = listaAlunos[j + 1].matricula;
                  listaAlunos[j].sexo = listaAlunos[j + 1].sexo;
                  listaAlunos[j].ativo = listaAlunos[j + 1].ativo;
                }
                contadorAlunos--;
                break;
              }
            }
            if (matricula_localizada) {
              printf("\n!!\tAluno exlcuido com SUCESSO\t!!\n");
            }
            else {
              printf("\n!!\tMatricula não localizada\t!!\n");
            }
          }

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