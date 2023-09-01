#ifndef MENU_PROFESSOR_H
#define MENU_PROFESSOR_H

int menu_professor();
int cadastrar_professor(Professor listaProfessores[], int contadorProfessores);
int menu_listar_professor(Professor listaProfessor[], int contadorProfessor);
int atualizar_professor(Professor listaProfessor[], int contadorProfessor);
int excluir_professor(Professor listaProfessores[], int contadorProfessores);

#endif