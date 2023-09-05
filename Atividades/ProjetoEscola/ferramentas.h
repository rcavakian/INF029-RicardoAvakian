#ifndef FERRAMENTAS_H
#define FERRAMENTAS_H

/// @brief Função para copiar um vetor de char (string) para outro 
/// @param char_origem 
/// @param char_destino 
void copiar_string(char *char_origem, char *char_destino);

/// @brief Função para ler uma string 
/// @param buffer variavel onde string deve ser armazenada
/// @param length tamano da string
void ler_texto(char *buffer, int length);

/// @brief  Função que limpa o buffer de entrada
void limpar_buffer();

#endif