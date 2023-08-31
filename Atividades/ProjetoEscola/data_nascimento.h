#ifndef DATA_NASCIMENTO_H
#define DATA_NASCIMENTO_H

int valida_data(char *data);
int validaAnoBissexto(int ano);
time_t texto_para_tempo(char * text);
void tempo_para_texto(time_t * time, char * output, int size);
void limpar_buffer();

#endif 