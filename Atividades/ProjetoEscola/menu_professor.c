#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "professor.h"
#include "menus.h"
#include "data_nascimento.h"
#include "cpf.h"
#include "menu_professor.h"

#define TAM_PROFESSORES 3
#define CADASTRO_SUCESSO -1
#define CADASTRO_NAO_REALIZADO -2
#define MATRICULA_INVALIDA -3
#define MATRICULA_NAO_LOCALIZADA -4
#define ATUALIZACAO_SUCESSO -5
#define EXCLUSAO_SUCESSO -6
#define LISTA_VAZIA -7
#define CPF_VALIDO 11
#define CPF_INVALIDO 10

/// @brief Função para ler uma string 
/// @param buffer variavel onde string deve ser armazenada
/// @param length tamano da string
void ler_texto(char *buffer, int length) {
	fgets(buffer, length, stdin);
	strtok(buffer, "\n");
}

// Função que limpa o buffer de entrada
void limpar_buffer() {
    char ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

/// @brief Função para imprimir o meno Professor do sistema
/// @return opcaoProfessor do tipo int
int menu_professor(){
    int opcaoProfessor;
    printf("\n1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    printf("5 - Voltar MENU anterior\n");
    printf("\nOpção: ");
    scanf("%d", &opcaoProfessor);
    return opcaoProfessor;
}

/// @brief Função para efetuar cadastro de professor 
/// @param listaProfessores 
/// @param contadorProfessores 
/// @return 
int cadastrar_professor(Professor listaProfessores[], int contadorProfessores) {
    printf("\n1 - Cadastro de Professor\n");
    Professor professor;
        if (contadorProfessores == TAM_PROFESSORES) {
          return CADASTRO_NAO_REALIZADO;
        }
        else {
          //char data_digitada[11];
          // char cpfDigitado[12];
          int validacaoData = 1;
          int validacaoCPF = 0;

          limpar_buffer();

          // Cadastrar Nome
          printf("\nDigite NOME: ");
          ler_texto(professor.nome, sizeof(professor.nome));
          //professor.nome[strcspn(professor.nome, "\n")] = '\0';

          // Cadastrar CPF
          while (validacaoCPF != CPF_VALIDO) {
            char cpfDigitado[12];
            printf("\nDigite o CPF do professor (APENAS NUMEROS/ALGARISMOS): ");
            ler_texto(cpfDigitado, 12);

            // Verificar se a informacao digitado tem 11 caracteres
            if (strlen(cpfDigitado) != 11) {
              printf("!!\tCPF FALTA algarismos !!");
            }
            else {
              // Validar CPF
              validacaoCPF = validar_cpf(cpfDigitado);
              limpar_buffer();
              if (validacaoCPF != CPF_VALIDO) {
                printf("!!\tCPF NAO VALIDADO\t!!");
                continue;
              }
              else {
                strcpy(professor.cpf, cpfDigitado);
              }
            }
          }

          // Cadastrar Matricula
          printf("\nDigite a MATRICULA: ");
          scanf("%d", &professor.matricula);
          limpar_buffer();

          // Cadastrar Sexo
          printf("\nDigite o SEXO: ");
          scanf("%c", &professor.sexo);
          limpar_buffer();

          // Cadastrar Data de nascimento
          while (validacaoData != 0) {
            char data_digitada[11];
            printf("\nDigite DATA de NASCIMENTO no formato dd/mm/aaaa(d = dia; m = mes; a = ano): ");
            ler_texto(data_digitada, 11);

            // Validar o tamanho do char[]
            if (strlen(data_digitada) != 10) {
              printf("!!\tData INCOMPLETA!!");
              continue;
            }
            else {
              validacaoData = valida_data(data_digitada);
              // if para caso a data não retorne como não validada volte a pedir nova data
              if (validacaoData != 0) {
                limpar_buffer();
                printf("!!\tData INVALIDA  !!");
                continue;           
              }
              else {
                professor.dataNascimento = texto_para_tempo(data_digitada);
              }
            }
          }
  
          if (professor.matricula <= 0) {
            return MATRICULA_INVALIDA;
          }
          else {
            listaProfessores[contadorProfessores] = professor;
            printf("\nProfessor matrícula %d cadastrado com sucesso!\n", listaProfessores[contadorProfessores].matricula);
            return CADASTRO_SUCESSO;
          }

        }
}

/// @brief Função para Listar professores cadastrados
/// @param listaProfessores
/// @param contadorProfessores
/// @return 
int menu_listar_professor(Professor listaProfessores[], int contadorProfessores) {
        printf("\n2 - Listar Professor\n\n");
        if (contadorProfessores == 0){
          return LISTA_VAZIA;
        }
        else
          return 1;
}

/// @brief Função para Atualizar a matricula de um professor 
/// @param listaProfessores
/// @param contadorProfessores
/// @return 
int atualizar_professor(Professor listaProfessores[], int contadorProfessores) {
  int matricula;
  int matricula_localizada = 0;
  printf("\n3 - Atualização de Professor\n\n");
  printf("Digite a matricula do professor a ser atualizado: ");

  scanf("%d", &matricula);
  if (matricula <= 0) {
    return MATRICULA_INVALIDA;
  }
  else {
    for (int i = 0; i < contadorProfessores; i++)
    {
      if (matricula == listaProfessores[i].matricula)
      {
        printf("\nDigite a NOVA matrícula: ");
        scanf("%d", &matricula);
        listaProfessores[i].matricula = matricula;
        matricula_localizada = 1;
        break;
      }
    }
    if (matricula_localizada)
      return ATUALIZACAO_SUCESSO;
    else {
      return MATRICULA_NAO_LOCALIZADA;
    }
  }
}

/// @brief Função para excluir Professor da lista
/// @param listaProfessores 
/// @param contadorProfessores 
/// @return 
int excluir_professor(Professor listaProfessores[], int contadorProfessores) {
  printf("\n4 - Exclusão de Aluno\n\n");
  printf("Digite a matricula do professor a ser excluído: ");
  int matricula;
  scanf("%d", &matricula);
  int matricula_localizada = 0;
  if (matricula <= 0) {
    return MATRICULA_INVALIDA;
  }
  else {
    for (int i = 0; i < contadorProfessores; i++) {
      if (matricula == listaProfessores[i].matricula) {
        matricula_localizada = 1;
        for (int j = i; j < contadorProfessores - 1; j++) {
          listProfessores[j].matricula = listProfessores[j + 1].matricula;
          listProfessores[j].sexo = listProfessores[j + 1].sexo;
        }
        break;
      }
    }
    if (matricula_localizada) {
      return EXCLUSAO_SUCESSO;
    }
    else {
      return MATRICULA_NAO_LOCALIZADA;
    }
  }
}


