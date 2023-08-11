/*
Cadastro de Disciplinas (Nome, Código, Semestre, Professor)
◦ Inserir/Excluiralunodeumadisciplina
*/
#include "professor.h"
#include "aluno.h"
#define TAM_matriculados 3


void incluirAluno(Aluno aluno) {
    // TODO incluir codigo para testar se capacidade da turma esta cheia ou não.
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