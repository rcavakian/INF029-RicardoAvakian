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

  FILE *start_file;
  Aluno listaAlunos[TAM_ALUNOS];
  Professor listaProfessores[TAM_PROFESS];
  int contadorAlunos = 0;
  int contadorProfessores = 0;
  int opcao;

  printf("\n**\tProjeto Escola\t**\n\n");
  start_file = fopen("base_dados.txt", "r");
  printf("\nAbriu arquivo");

  if (start_file) {
    printf("Não existente, o arquivo \"base_dados.txt\" é. Ao encerrar o programa, CRIADO ele será, e as informações nele serão salvas.");
  }
  else {
    //TODO: LER O ARQUIVO E ENCHER AS LISTAS 'ALUNOS' E 'PROFESSORES' 
    // Tamanho do CHAR = Tamanho char nome(40) + tamanho int matricula (11) + tamanho char cpf(11) + 
    // tamanho char data de nascimento(10) + char sexo (1) = 71 + ';'(5) + Letra identificação (1) = 77
    printf("\nEntrou no else...");
    int contador_alunos = 0;
    int contador_professores = 0;
    char linha[TAM_LINHA];
    char *token = strtok(linha, ";");

    // Verificar quantos alunos e professores tem cadastrados para poder utilizar nos proximos loops(for)
    if (fgets(linha, sizeof(linha), start_file) != NULL) {
      while (!feof(start_file)) {
        if (linha[0] == 'A') {
          contador_alunos++;
        }
        else {
          contador_professores++;
        }
      }
    }

    // Loop 'for' para armazenar cada trecho da linha na listaAlunos
    for (int i = 0; i < contador_alunos; i++) {
      while (!feof(start_file)) {
        fgets(linha, TAM_LINHA, start_file);
        // TODO: implementar logica para analisar e fragmentar char linha [] e inserir em cada lista
        if (linha[0] == 'A') {
          // TODO: quebrar char linha[] e inserir na listaAlunos[] utilizar um loop for já que é sabido de antemão quantos ';' teremos (6)
          for (int i = 0; i < 6; i++)
          {
            if (i == 0) {
              token = (NULL, ";");
              continue;
            }
            else
            {
              switch (i)
              {
              case 1:
                copiar_string(token, listaAlunos[i].nome);
                token = (NULL, ";");
                break;
              case 2:
                listaAlunos[i].matricula = strtol(token, NULL, 10);
                token = (NULL, ";");
                break;
              case 3:
                copiar_string(token, &listaAlunos[i].sexo);
                token = (NULL, ";");
                break;
              case 4:
                copiar_string(token, listaAlunos[i].cpf);
                token = (NULL, ";");
                break;
              case 5:
                listaAlunos[i].dataNascimento = texto_para_tempo(token);
                token = (NULL, ";");
                break;
              default:
                break;
              }
            }
          }
        }     
      }
    }

    // Loop 'for' para armazenar cada trecho da linha na listaProfessores
    for (int i = 0; i < contador_professores; i++) {
      while (!feof(start_file)) {
        fgets(linha, TAM_LINHA, start_file);
        // TODO: implementar logica para analisar e fragmentar char linha [] e inserir em cada lista
        if (linha[0] == 'A') {
          // TODO: quebrar char linha[] e inserir na listaProfessores[] utilizar um loop for já que é sabido de antemão quantos ';' teremos (6)
          for (int i = 0; i < 6; i++)
          {
            if (i == 0) {
              token = (NULL, ";");
              continue;
            }
            else
            {
              switch (i)
              {
              case 1:
                copiar_string(token, listaProfessores[i].nome);
                token = (NULL, ";");
                break;
              case 2:
                // char *endptr;
                listaProfessores[i].matricula = strtol(token, NULL, 10);
                token = (NULL, ";");
                break;
              case 3:
                copiar_string(token, &listaProfessores[i].sexo);
                token = (NULL, ";");
                break;
              case 4:
                copiar_string(token, listaProfessores[i].cpf);
                token = (NULL, ";");
                break;
              case 5:
                listaProfessores[i].dataNascimento = texto_para_tempo(token);
                token = (NULL, ";");
                break;
              default:
                break;
              }
            }
          }
        }         
      }
    }
  }
  fclose(start_file);

  // Loop para execurtar o menu principal do sistema escola
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
      start_file = fopen("base_dados.txt", "w+");
      //TODO: implementar nesse switch logica para salvar dados das listas no arquivo txt.
      // formato arquivo txt: 'A' para Aluno e 'P' para Professor separar cada campo por ';' e cadastrar 
      // na ordem que vem na propria struct: Nome, matricula, sexo, CPF e data de nascimento(armazenar como string dd/mm/aaaa)
      // 1 - concatenar todos os dados com essa logica e armazenar em uma string linha
      // https://www.youtube.com/watch?v=7pWQWqGnVso&list=PLa75BYTPDNKZWYypgOFEsX3H2Mg-SzuLW&index=48
      // 2 - Escrever linha por linha com o comando fprintf 'w' e colocar no final um '\n' para poder pular de linha
      // 3 Ultimo passo é criar uma função para poder modularizar a gravação das duas listas no arquivo de texto
      // ordem a ser escrita no arquivo: nome, matricula, sexo, cpf, dataNascimento
        
      for (int i = 0; i < contadorAlunos; i++) {
        char dataNascimentoString[12];
        tempo_para_texto(&listaAlunos[i].dataNascimento, dataNascimentoString, 12);
        fprintf(start_file, "A;%s;%d;%c;%s;%s\n", listaAlunos[i].nome, listaAlunos[i].matricula, listaAlunos[i].sexo, listaAlunos[i].cpf, dataNascimentoString);
      }
      for (int i = 0; i < contadorProfessores; i++) {
        char dataNascimentoString[12];
        tempo_para_texto(&listaProfessores[i].dataNascimento, dataNascimentoString, 12);
        fprintf(start_file, "P;%s;%d;%c;%s;%s", listaProfessores[i].nome, listaProfessores[i].matricula, listaProfessores[i].sexo, listaProfessores[i].cpf, dataNascimentoString);
        if (i < contadorProfessores - 1) {
          fputs("\n", start_file);
        }
      }
      fclose(start_file);
      break;
    default:
      printf("\n!!\tOpção inválida\t!!\n\n");
      break;
    } 
  } while (opcao != 4);
  return 0;
}