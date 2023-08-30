#ifndef ALUNO_H
#define ALUNO_H

#include <time.h>


/**
 * @brief Uma estrutura (struct) utilizado para efetuar cadastro de alunos da escola.  
 * 
 * Esta estrutura contém os seguintes campos: nome, matricula, sexo, CPF, data de nascimento e ativo. 
 * Campo 'ativo' valor '1' para aluno ativo e '0' para aluno inativo.
 */ 
typedef struct Aluno {
  char nome[40];                
  int matricula;                
  char sexo;                    
  char cpf[12]; 
  time_t dataNascimento;
} Aluno;

/// @brief Função para imprimir tipo Aluno
/// @param aluno do tipo Aluno
void imprimirAluno(Aluno aluno);

/// @brief Função para imprimir lista de aluno
/// @param aluno do tipo Aluno
/// @param tamanho do tipo int
void imprimirListaAlunos(Aluno listaAlunos[], int tamanho);

#endif 


