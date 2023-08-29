#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "professor.h"
#include "aluno.h"
#define TAM_matriculados 3


/**
* @brief Uma estrutura (struct) para cadastro de disciplinas.
* 
* Esta estrutura contém os seguintes campos: nome, código, semestre e professor.
*/ 
typedef struct Disciplina{
    char nome[100];
    int codigo;
    int semestre;
    Professor professor;
    Aluno alunosMatriculados[TAM_matriculados];
}Disciplina;

// void incluirAluno(Aluno aluno) {
// }

#endif