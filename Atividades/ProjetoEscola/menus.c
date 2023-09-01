#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"
#include "menus.h"
#include "data_nascimento.h"
#include "cpf.h"

#define TAM_ALUNOS 3
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

/// @brief Menu principal do sistema do Projeto Escola
/// @return tipo int para utilizar no Switch
int menu_principal(){
    int opcao;
    printf("\n # MENU PRINCIPAL # \n\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("4 - Sair\n");
    printf("\nOpção: ");
    scanf("%d", &opcao);
    return opcao;
}

/// @brief Função para imprimir o meno Aluno do sistema
/// @return opcaoAluno do tipo int
int menu_aluno(){
    int opcaoAluno;
    printf("\n1 - Cadastrar Aluno\n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");
    printf("5 - Voltar MENU anterior\n");
    printf("\nOpção: ");
    scanf("%d", &opcaoAluno);
    return opcaoAluno;
}

/// @brief Função para efetuar cadastro de aluno 
/// @param listaAlunos 
/// @param contadorAlunos 
/// @return 
int cadastrar_aluno(Aluno listaAlunos[], int contadorAlunos) {
    printf("\n1 - Cadastro de Aluno\n");
    Aluno aluno;
        if (contadorAlunos == TAM_ALUNOS) {
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
          ler_texto(aluno.nome, sizeof(aluno.nome));
          //aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

          // Cadastrar CPF
          while (validacaoCPF != CPF_VALIDO) {
            //char cpfDigitado[12];
            printf("\nDigite o CPF do aluno (APENAS NUMEROS/ALGARISMOS): ");
            ler_texto(aluno.cpf, 12);

            // Verificar se a informacao digitado tem 11 caracteres
            if (strlen(aluno.cpf) != 11) {
              printf("!!\tCPF FALTA algarismos !!");
            }
            else {
              // Validar CPF
              validacaoCPF = validar_cpf(aluno.cpf);
              limpar_buffer();
              if (validacaoCPF != CPF_VALIDO) {
                printf("!!\tCPF NAO VALIDADO\t!!");
                continue;
              }
            }
          }

          // Cadastrar Matricula
          printf("\nDigite a MATRICULA: ");
          scanf("%d", &aluno.matricula);
          limpar_buffer();

          // Cadastrar Sexo
          printf("\nDigite o SEXO: ");
          scanf("%c", &aluno.sexo);
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
                aluno.dataNascimento = texto_para_tempo(data_digitada);
              }
            }
          }
  
          if (aluno.matricula <= 0) {
            return MATRICULA_INVALIDA;
          }
          else {
            listaAlunos[contadorAlunos] = aluno;
            printf("\nAluno matrícula %d cadastrado com sucesso!\n", listaAlunos[contadorAlunos].matricula);
            return CADASTRO_SUCESSO;
          }

        }
}

int menu_listar_alunos(Aluno listaAlunos[], int contadorAlunos){
        printf("\n2 - Listar Alunos\n\n");
        if (contadorAlunos == 0){
          return LISTA_VAZIA;
        }
        else
          return 1;
}

int atualizar_aluno(Aluno listaAlunos[], int contadorAlunos) {
  int matricula;
  int matricula_localizada = 0;
  printf("\n3 - Atualização de Aluno\n\n");
  printf("Digite a matricula do aluno a ser atualizado: ");

  scanf("%d", &matricula);
  if (matricula <= 0) {
    return MATRICULA_INVALIDA;
  }
  else {
    for (int i = 0; i < contadorAlunos; i++)
    {
      if (matricula == listaAlunos[i].matricula)
      {
        printf("\nDigite a NOVA matrícula: ");
        scanf("%d", &matricula);
        listaAlunos[i].matricula = matricula;
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

int excluir_aluno(Aluno listaAlunos[], int contadorAlunos) {
  printf("\n4 - Exclusão de Aluno\n\n");
  printf("Digite a matricula do aluno a ser excluído: ");
  int matricula;
  scanf("%d", &matricula);
  int matricula_localizada = 0;
  if (matricula <= 0) {
    return MATRICULA_INVALIDA;
  }
  else {
    for (int i = 0; i < contadorAlunos; i++) {
      if (matricula == listaAlunos[i].matricula) {
        matricula_localizada = 1;
        for (int j = i; j < contadorAlunos - 1; j++) {
          listaAlunos[j].matricula = listaAlunos[j + 1].matricula;
          listaAlunos[j].sexo = listaAlunos[j + 1].sexo;
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


void menu_discplina() {

}

