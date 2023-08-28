#ifndef ALUNO_H
#define ALUNO_H

#include "data_nascimento.h"

/**
 * @brief Uma estrutura (struct) utilizado para efetuar cadastro de alunos da escola.  
 * 
 * Esta estrutura contém os seguintes campos: nome, matricula, sexo, CPF, data de nascimento e ativo. 
 * Campo 'ativo' valor '1' para aluno ativo e '0' para aluno inativo.
 */ 
typedef struct {
  char nome[40];                
  int matricula;                
  char sexo;                    
  char cpf[11]; 
  Data_nascimento dataNascimento;
} Aluno;

// void imprime_aluno(Aluno aluno);
// int gerar_matricula();

#endif 


