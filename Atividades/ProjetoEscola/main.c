#include <stdio.h>
#include "aluno.h"
#include "data_nascimento.h"
#include "professor.h"
#include "disciplina.h"
#include "menus.h"

#define TAM_ALUNOS 3
#define CADASTRO_SUCESSO -1
#define CADASTRO_NAO_REALIZADO -2
#define MATRICULA_INVALIDA -3
#define MATRICULA_NAO_LOCALIZADA -4
#define ATUALIZACAO_SUCESSO -5


int main() {

  Aluno listaAlunos[TAM_ALUNOS];
  int contadorAlunos = 0;
  int opcao;
  printf("\n**\tProjeto Escola\t**\n\n");
  do {
    opcao = menu_principal();
    switch (opcao) {
      int matricula;
      int matricula_localizada = 0;
    case 1:
      printf("\n**\tMódulo Aluno\t**\n");
      int opcaoAluno;
      do {
        opcaoAluno = menu_aluno();
        switch (opcaoAluno) {
          int resposta_retorno;
        case 1:
          resposta_retorno = cadastrar_aluno(listaAlunos, contadorAlunos);
          if (resposta_retorno == CADASTRO_NAO_REALIZADO) {
            printf("\n!! Lista de alunos CHEIA !!\n");
          }
          else if (resposta_retorno == MATRICULA_INVALIDA) {
            printf("\n\t!! Matricula do aluno INVALIDA !!\n");
          }
          else {
            contadorAlunos++;
          }
          // printf("\n1 - Cadastro de Aluno\n");
          // if (contadorAlunos == TAM_ALUNOS) {
          //   printf("\n!! Lista de alunos CHEIA !!\n");
          // }
          // else {
          //   printf("Digite a matricula do aluno: ");
          //   // int matricula;
          //   scanf("%d", &matricula);
          //   if (matricula <= 0) {
          //     printf("\n\t!! Matricula do aluno INVALIDA !!\n");
          //     break;
          //   }
          //   else {
          //     listaAlunos[contadorAlunos].matricula = matricula;
          //     printf("\nAluno matrícula %d cadastrado com sucesso!\n", listaAlunos[contadorAlunos].matricula);
          //     contadorAlunos++;
          //   }
          // }
          break;
        case 2:
          printf("\n2 - Listar Alunos\n\n");
          if (contadorAlunos == 0) {
            printf("\n!\tLista de alunos VAZIA\t!\n");
          } 
          else {
            for (int i = 0; i < contadorAlunos; i++) {
              printf("%dª - Matricula: %d\n", i+1, listaAlunos[i].matricula);
            }  
          }
          break;
      case 3:
        resposta_retorno = atualizar_aluno(listaAlunos, contadorAlunos);
        if (resposta_retorno == MATRICULA_INVALIDA) {
          printf("\n!!\tMatricula do aluno INVALIDA\t!!\n");
          break;
        }
        else if (resposta_retorno == ATUALIZACAO_SUCESSO) {
          printf("\nAluno ATUALIZADO com SUCESSO!\n");
          break;
        }
        else {
          printf("\n!!\tAluno NÃO localizado\t!!\n");
          break;
        }
        // printf("\n3 - Atualização de Aluno\n\n");
        // printf("Digite a matricula do aluno a ser atualizado: ");
        // scanf("%d", &matricula);
        // if (matricula <= 0) {
        //   printf("\n!!\tMatricula do aluno INVALIDA\t!!\n");
        //   break;
        // }
        // else {
        //    for (int i = 0; i < contadorAlunos; i++) {
        //       if (matricula == listaAlunos[i].matricula){
        //         printf("\nDigite a NOVA matrícula: ");
        //         scanf("%d", &matricula);
        //         listaAlunos[i].matricula = matricula;
        //         matricula_localizada = 1;
        //         break;
        //       }
        //     }
        //     if (matricula_localizada)
        //       printf("\nAluno ATUALIZADO com SUCESSO!\n");
        //     else 
        //       printf("\nAluno NÃO localizado!\n");
        // }
        break;
      case 4:
        printf("\n4 - Exclusão de Aluno\n\n");
        printf("Digite a matricula do aluno a ser excluído: ");
          // int matricula;
          scanf("%d", &matricula);
          // int matricula_localizada = 0;
          if (matricula <= 0) {
            printf("\n!!\tMatricula do aluno INVALIDA\t!!\n");
            break;
          }
          else {
            for (int i = 0; i < contadorAlunos; i++) {
              if (matricula == listaAlunos[i].matricula) {
                matricula_localizada = 1;
                for (int j = i; j < contadorAlunos - 1; j++) {
                  listaAlunos[j].matricula = listaAlunos[j + 1].matricula;
                  listaAlunos[j].sexo = listaAlunos[j + 1].sexo;
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