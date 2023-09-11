#include <stdio.h>
#include <string.h>
#include "ferramentas.h"

/// @brief Função para copiar um vetor de char (string) para outro 
/// @param char_origem 
/// @param char_destino 
void copiar_string(char *char_origem, char *char_destino) {

    while (*char_origem != '\0') {
        *char_destino = *char_origem;
        ++char_origem;
        ++char_destino;
    }
    *char_destino = '\0';
}

/// @brief Função para ler uma string 
/// @param buffer variavel onde string deve ser armazenada
/// @param length tamano da string
void ler_texto(char *buffer, int length) {
	fgets(buffer, length, stdin);
	strtok(buffer, "\n");
}

/// @brief  Função que limpa o buffer de entrada
void limpar_buffer() {
    char ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}
