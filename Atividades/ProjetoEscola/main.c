#include <stdio.h>
#include "aluno.h"
#define TAM_alunos 3

int main() {

  Aluno listaAlunos[TAM_alunos];
  listaAlunos[1].sexo = 'F';
  printf("\n%c\n", listaAlunos[1].sexo);

  return 0;
}