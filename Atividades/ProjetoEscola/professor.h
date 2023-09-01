#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <time.h>

/**
 * @brief Uma estrutura (struct) utilizado para efetuar cadastro de professores da escola.  
 * 
 * Esta estrutura contém os seguintes campos: nome, matricula, sexo, CPF e data de nascimento.
 */ 
typedef struct Professor{
  char nome[40];                
  int matricula;                
  char sexo;                    
  char cpf[11];                 
  time_t dataNascimento;
} Professor;

/// @brief Função para imprimir tipo Professor
/// @param professor do tipo Professor
void imprimirProfessor(Professor professor);

/// @brief Função para imprimir lista de professor
/// @param professor do tipo Professor
/// @param tamanho do tipo int
void imprimirListaProfessores(Professor listaProfessores[], int tamanho);

#endif