#include "data_nascimento.c"
#include "aluno.h"

/**
 * @brief Uma estrutura (struct) utilizado para efetuar cadastro de alunos da escola.  
 * 
 * Esta estrutura contém os seguintes campos: nome, matricula, sexo, CPF e data de nascimento.
 */ 
typedef struct aluno {
  char nome[40];                
  int matricula;                
  char sexo;                    
  char cpf[11];                 
  Data_nascimento dataNascimento;
} Aluno;

/* Material 
 sobre struct https://www.inf.pucrs.br/~pinho/LaproI/Structs/Structs.htm#:~:text=Para%20passar%20uma%20struct%20por%20valor%20basta%20declar%C3%A1-la,%2F%2F%20Define%20o%20nome%20do%20novo%20tipo%20criado
*/