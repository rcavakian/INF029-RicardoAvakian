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
#include "ferramentas.h"


#define TAM_ALUNOS 3
#define TAM_PROFESS 3
#define TAM_LINHA 80
#define CADASTRO_SUCESSO -1
#define CADASTRO_NAO_REALIZADO -2
#define MATRICULA_INVALIDA -3
#define MATRICULA_NAO_LOCALIZADA -4
#define ATUALIZACAO_SUCESSO -5
#define EXCLUSAO_SUCESSO -6
#define LISTA_VAZIA -7

int main() {

  File *start_file;
  Aluno listaAlunos[TAM_ALUNOS];
  Professor listaProfessores[TAM_PROFESS];
  int contadorAlunos = 0;
  int contadorProfessores = 0;
  int opcao;

  printf("\n**\tProjeto Escola\t**\n\n");
  start_file = fopen("base_dados.txt", "r");

  if (start_file) {
    printf("Não existente, o arquivo \"base_dados.txt\" é. Ao encerrar o programa, CRIADO ele será, e as informações nele serão salvas.");
  }
  else {
    //TODO: LER O ARQUIVO E ENCHER AS LISTAS 'ALUNOS' E 'PROFESSORES' 
    // Tamanho do CHAR = Tamanho char nome(40) + tamanho int matricula (11) + tamanho char cpf(11) + 
    // tamanho char data de nascimento(10) + char sexo (1) = 71 + ';'(5) + Letra identificação (1) = 77
    int contador_alunos = 0;
    int contador_professores = 0;
    char linha[TAM_LINHA];

    // Verificar quantos alunos e professores tem cadastrados para poder 
    if (fgets(linha, sizeof(line), start_file) != NULL) {
      while (!feof(start_file)) {
        if (linha[0] == 'A') {
          contador_alunos++;
        }
        else if (linha[0] == 'P') {
          contador_professores++;
        }
        else {
          continue;
        }
      }
      
    }
    for (int i = 0; i < contador_alunos; i++) {
      while (!feof(start_file)) {
      fgets(linha, TAM_LINHA, start_file);
      // TODO: implementar logica para analisar e fragmentar char linha [] e inserir em cada lista
      char classificacao = linha[0];
      char nome[40];
      int matricula;
      char cpf[12];
      char dataNascimento[11];
      char sexo;

      switch (classificacao) {
      case 'A':
        //TODO: quebrar char linha[] e inserir na listaAlunos[] utilizar um loop for já que é sabido de antemão quantos ';' teremos (6)
        char *token = strtok(linha, ";");
        for (int i = 0; i < 6; i++) {
          if (i = 0) {
            token = (NULL, ";");
            continue;
          }

          else {
            switch (i) {
            case 1:
              //strncpy(nome, token, sizeof(token));
              copiar_string(token, listaProfessores[i].nome);
              token = (NULL, ";");
              break;
            case 2:
              char *endptr;
              listaProfessores[i].matricula = strtol(token, &endptr, 10);
              token = (NULL, ";");
              break;
            case 3:
              listaProfessores[i].sexo = token;
              token = (NULL, ";");
              break;
            case 4:
              //strncpy(cpf, token, sizeof(token));
              copiar_string(token, listaProfessores[i].cpf);
              token = (NULL, ";");
              break;
            case 5:
              //strncpy(dataNascimento, token, sizeof(token));
              // Aqui precisa tratar a informação armazenada se em string(dd/mm/aaaa) ou time_t(lli) 

              break;
            default:
              break;
            }
          } 
        }
        break;
      case 'P':
        //TODO: quebrar char linha[] e inserir na listaProfessores[]
        break;
      default:
        break;
      }
    }
      
    }
    
    


  }
  do {
    opcao = menu_principal();
    switch (opcao) {
      int matricula;
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
            printf("\n\t!! INVALIDA, a matrícula do professor está. !!\n");
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
          printf("\nProfessor ATUALIZADO com SUCESSO!\n");
          break;
        }
        else {
          printf("\n!!\nProfessor NÃO localizado\t!!\n");
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
      }
    } while (opcaoProfessor != 5);
      break;
    case 3:
      printf("\n**\tMódulo Disciplina\t**\n\n");
      break;
    case 4:
      printf("\n**\tPrograma finalizado\t**\n\n");
      fp = fopen("base_dados.txt", "w");

      //TODO: implementar nesse switch logica para salvar dados das listas no arquivo txt.
      // formato arquivo txt: 'A' para Aluno e 'P' para Professor separar cada campo por ';' e cadastrar 
      // na ordem que vem na propria struct: Nome, matricula, sexo, CPF e data de nascimento


      break;
    default:
      printf("\n!!\tOpção inválida\t!!\n\n");
      break;
    } 
  } while (opcao != 4);
  return 0;
}