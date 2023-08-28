#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"
#include "menus.h"

#define TAM_ALUNOS 3
#define CADASTRO_SUCESSO -1
#define CADASTRO_NAO_REALIZADO -2
#define MATRICULA_INVALIDA -3
#define MATRICULA_NAO_LOCALIZADA -4
#define ATUALIZACAO_SUCESSO -5
#define EXCLUSAO_SUCESSO -6

/// @brief Função para ler uma string 
/// @param buffer variavel onde string deve ser armazenada
/// @param length tamano da string
void ler_texto(char *buffer, int length) {
	fgets(buffer, length, stdin);
	strtok(buffer, "\n");
}

/// @brief Função para limpar o buffer de entrada
void limpar_buffer() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
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
          limpar_buffer();
          printf("Digite nome do aluno: ");
          ler_texto(aluno.nome, sizeof(40));
          aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

          printf("Digite a matricula do aluno: ");
          limpar_buffer();
          scanf("%d", &aluno.matricula);

          printf("Digite o sexo do aluno: ");
          scanf("%c", &aluno.sexo);
          limpar_buffer();


          printf("Digite o DIA de nascimento do aluno: ");
          scanf("%d", &aluno.dataNascimento.dia);

          printf("Digite o MÊS de nascimento do aluno: ");
          scanf("%d", &aluno.dataNascimento.mes);
          
          printf("Digite o ANO de nascimento do aluno: ");
          scanf("%d", &aluno.dataNascimento.ano);
          
          printf("Digite o CPF do aluno (APENAS NUMEROS/ALGARISMOS): ");
          fgets(aluno.cpf, sizeof(aluno.cpf), stdin);
          limpar_buffer();

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

int menu_listar_alunos(Aluno listarAlunos[], int contadorAlunos) {
  //todo: implementar verificacao se a lista esta vazia ou nao, na sequencia : ListarAlunosporsexo(Masculino/Feminino) ListarAlunosordenadosporNome ListarAlunosordenadospordatadenascimento
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
    // colocar essa mensagem no main.c: printf("\n!!\tMatricula do aluno INVALIDA\t!!\n");
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
      // colocar essa mensagem no main.c printf("\n!!\tAluno exlcuido com SUCESSO\t!!\n");
      return EXCLUSAO_SUCESSO;
    }
    else {
      // colocar essa mensagem no main.c printf("\n!!\tMatricula não localizada\t!!\n");
      return MATRICULA_NAO_LOCALIZADA;
    }
  }
}

void menu_professor() {

}
void menu_discplina() {

}

