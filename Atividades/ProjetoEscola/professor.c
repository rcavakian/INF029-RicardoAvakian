#include <stdio.h>
#include "professor.h"
#include "data_nascimento.h"

void imprimirProfessor(Professor professor) {
    char * data = malloc(11 * sizeof(char));
    tempo_para_texto(&professor.dataNascimento, data, 11);
    printf("\nNome: %s // Matricula: %d // Sexo: %c\nData de nascimento: %s // CPF: %s\n", professor.nome, professor.matricula, professor.sexo, data, professor.cpf);
}

void imprimirListaProfessores(Professor listaProfessores[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        imprimirProfessor(listaProfessores[i]); 
    }
}
