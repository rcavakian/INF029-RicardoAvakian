#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data_nascimento.h"
#include "aluno.h"

void imprimirAluno(Aluno aluno) {
    char * data = malloc(11 * sizeof(char));
    tempo_para_texto(&aluno.dataNascimento, data, 11);
    printf("\nNome: %s // Matricula: %d // Sexo: %c\nData de nascimento: %s // CPF: %s\n", aluno.nome, aluno.matricula, aluno.sexo, data, aluno.cpf);
}

void imprimirListaAlunos(Aluno listaAlunos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        imprimirAluno(listaAlunos[i]); 
    }
}

