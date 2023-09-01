#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"
#include "data_nascimento.h"
#include "professor.h"
#include "disciplina.h"
#include "menus.h"
#include "menu_professor.h"
#include "cpf.h"

#define TAM_ALUNOS 3
#define TAM_PROFESS 3
#define CADASTRO_SUCESSO -1
#define CADASTRO_NAO_REALIZADO -2
#define MATRICULA_INVALIDA -3
#define MATRICULA_NAO_LOCALIZADA -4
#define ATUALIZACAO_SUCESSO -5
#define EXCLUSAO_SUCESSO -6
#define LISTA_VAZIA -7

int main() {

  Aluno listaAlunos[TAM_ALUNOS];
  Professor listaProfessores[TAM_PROFESS];
  int contadorAlunos = 0;
  int contadorProfessores = 0;
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
          break;
      case 2:
          resposta_retorno = menu_listar_alunos(listaAlunos, contadorAlunos);
          if (resposta_retorno == LISTA_VAZIA) {
            printf("\n!\tLista de alunos VAZIA\t!\n");
          } 
          else {
            imprimirListaAlunos(listaAlunos, contadorAlunos); 
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
        break;
      case 4:
        resposta_retorno = excluir_aluno(listaAlunos, contadorAlunos);
        if (resposta_retorno == MATRICULA_INVALIDA)
          printf("\n!!\tMatricula do aluno INVALIDA\t!!\n");
        else if (resposta_retorno == EXCLUSAO_SUCESSO) {
          contadorAlunos--;
          printf("\n!!\tAluno exlcuido com SUCESSO\t!!\n");
        }
        else 
          printf("\n!!\tMatricula não localizada\t!!\n");
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
      int opcaoProfessor;
      do {
        opcaoProfessor = menu_professor();
        switch (opcaoProfessor) {
          int resposta_retorno;
        case 1:
          resposta_retorno = cadastrar_professor(listaProfessores, contadorProfessores);
          if (resposta_retorno == CADASTRO_NAO_REALIZADO) {
            printf("\n!! Lista de professores CHEIA !!\n");
          }
          else if (resposta_retorno == MATRICULA_INVALIDA) {
            printf("\n\t!! Matricula do professor INVALIDA !!\n");
          }
          else {
            contadorProfessores++;
          }
          break;
      case 2:
          resposta_retorno = menu_listar_professor(listaProfessores, contadorProfessores);
          if (resposta_retorno == LISTA_VAZIA) {
            printf("\n!\tLista de professores VAZIA\t!\n");
          } 
          else {
            imprimirListaProfessores(listaProfessores, contadorProfessores); 
          }
          break;
      case 3:
        resposta_retorno = atualizar_professor(listaProfessores, contadorProfessores);
        if (resposta_retorno == MATRICULA_INVALIDA) {
          printf("\n!!\tMatricula do professor INVALIDA\t!!\n");
          break;
        }
        else if (resposta_retorno == ATUALIZACAO_SUCESSO) {
          printf("\Professor ATUALIZADO com SUCESSO!\n");
          break;
        }
        else {
          printf("\n!!\Professor NÃO localizado\t!!\n");
          break;
        }
        break;
      case 4:
        resposta_retorno = excluir_professor(listaProfessores, contadorProfessores);
        if (resposta_retorno == MATRICULA_INVALIDA)
          printf("\n!!\tMatricula do professor INVALIDA\t!!\n");
        else if (resposta_retorno == EXCLUSAO_SUCESSO) {
          contadorProfessores--;
          printf("\n!!\tProfessor exlcuido com SUCESSO\t!!\n");
        }
        else 
          printf("\n!!\tMatricula não localizada\t!!\n");
        break;
      case 5:
        printf("\n");
        break;
      default:
        printf("\n!!\tOpção inválida\t!!\n\n");
        break;
      } while (opcaoProfessor != 5);
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