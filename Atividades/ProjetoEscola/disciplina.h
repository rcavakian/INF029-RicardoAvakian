#ifndef PROFESSOR_H
#define PROFESSOR_H

/*
Cadastro de Disciplinas (Nome, Código, Semestre, Professor)
◦ Inserir/Excluir aluno de uma disciplina
*/
#include "professor.h"
#include "aluno.h"
#define TAM_matriculados 3


void incluirAluno(Aluno aluno) {
}

/**
* @brief Uma estrutura (struct) para cadastro de disciplinas.
* 
* Esta estrutura contém os seguintes campos: nome, código, semestre e professor.
*/ 
typedef struct {
    char nome[100];
    int codigo;
    int semestre;
    Professor professor;
    Aluno alunosMatriculados[TAM_matriculados];
}Disciplina;

#endif