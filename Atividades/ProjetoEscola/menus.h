#ifndef MENUS_H
#define MENUS_H

void limpar_buffer();
void ler_texto(char *buffer, int length);
int menu_principal();
int menu_aluno();
int cadastrar_aluno(Aluno listaAlunos[], int contadorAlunos);
int menu_listar_alunos(Aluno listarAlunos[]);
int atualizar_aluno(Aluno listaAlunos[], int contadorAlunos);
int excluir_aluno(Aluno listaAlunos[], int contadorAlunos);
void menu_professor();
void menu_discplina();


#endif