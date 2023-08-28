#include <stdio.h>
#include "aluno.h"
#include "menus.h"

#define TAM_ALUNOS 3
#define CADASTRO_SUCESSO -1
#define CADASTRO_NAO_REALIZADO -2
#define MATRICULA_INVALIDA -3

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

int cadastrar_aluno(Aluno listaAlunos[], int contadorAlunos) {
    printf("\n1 - Cadastro de Aluno\n");
        if (contadorAlunos == TAM_ALUNOS) {
          return CADASTRO_NAO_REALIZADO;
        }
        else {
          printf("Digite a matricula do aluno: ");
          int matricula;
          scanf("%d", &matricula);
          if (matricula <= 0) {
            return MATRICULA_INVALIDA;
          }
          else {
            listaAlunos[contadorAlunos].matricula = matricula;
            printf("\nAluno matrícula %d cadastrado com sucesso!\n", listaAlunos[contadorAlunos].matricula);
            return CADASTRO_SUCESSO;
          }

        }
}
void menu_professor() {

}
void menu_discplina() {

}