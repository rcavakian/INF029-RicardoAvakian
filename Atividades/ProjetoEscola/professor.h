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
  time_t data_Nascimento;
} Professor;

#endif