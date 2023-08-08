#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Crie um struct para definir uma pessoa com nome, id, sexo
Crie um vetor de 10 posições, que seja do tipo pessoa
Cadastre cada uma das pessoas
Imprima cada uma das pessoas
*/

struct Pessoa {
	char nome[50];
	int id;
	char sexo;
};

void ler_texto(char *buffer, int length);

void limpar_buffer();


int main () {

	struct Pessoa pessoas[10];

	for (int i = 0; i < 10; i++) {
		printf("Digite nome, ID e sexo da %da pessoa:\n", i+1);
		printf("Nome: ");
		ler_texto(pessoas[i].nome, 50);
		printf("ID: ");
		scanf("%d", &pessoas[i].id);
		printf("Sexo: ");
		limpar_buffer();
		scanf("%c", &pessoas[i].sexo);
		limpar_buffer();
	}

	for (int i = 0; i < 10; i++) {
		printf("Dados da %da. pessoa: Nome - %s , ID - %d e Sexo - %c \n", i+1, pessoas[i].nome, pessoas[i].id, pessoas[i].sexo);
	}

	



	return 0;
}

void ler_texto(char *buffer, int length) {
	fgets(buffer, length, stdin);
	strtok(buffer, "\n");
}

void limpar_buffer() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}