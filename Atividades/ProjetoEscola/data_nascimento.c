#include <string.h>
#include <time.h>
#include "data_nascimento.h"
#define ANO_MINIMO 1970
#define ANO_MAXIMO 2023


/// @brief Função que verifica se a data de nascimento informada é valida 
/// @param char data[] 
/// @return 
int valida_data(char *data) {
  int dia, mes, ano;

  // Verifica se a string tem o tamanho correto
  if (strlen(data) != 10) {
    return 1;
  }

  // Verifica se a string contém apenas números e se as posições 2 e 5 são "-" 
  for (int i = 0; i < strlen(data); i++) {
    if (data[2] == '/' || data[5] == '/') {
        break;
    }
    if (data[i] < '0' || data[i] > '9')
      return 2;

  }

  // Separa os campos da data
  dia = (data[0] - '0') * 10 + (data[1] - '0');
  mes = (data[3] - '0') * 10 + (data[4] - '0');
  ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 +
        (data[8] - '0') * 10 + (data[9] - '0');

  // Verifica se o dia está no intervalo válido
  if (dia < 1 || dia > 31) {
    return 3;
  }

  // Verifica se o mês está no intervalo válido
  if (mes < 1 || mes > 12) {
    return 4;
  }

  // Verifica se o ano está no intervalo válido
  if (ano < ANO_MINIMO || ano > ANO_MAXIMO) {
    return 5;
  }

  // Verificar se quantidade de dias de um mes esta dentro do intervalo maximo para os meses de fevereiro, abril, junho, setembro e novembro em anos não bissextos
  if (!validaAnoBissexto(ano) && dia > 28) {
    switch (mes) {
    case 2:
      return 7;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if (dia > 30) 
        return 8;
      break;
    default:
      break;
    }
  }
    else if (validaAnoBissexto(ano) && dia > 29) {
      switch (mes) {
      case 2:
        return 9;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        if (dia > 30) 
          return 10;
        break;
      default:
        break;
      }
    }
    else {
      return 0;
    }
  // Se todos os testes forem aprovados, a data é válida
  return 0;
}

/// @brief Função para verificar se um ano é bissexto
/// @param anoBissexto do tipo int
/// @return 1 para true e 0 para false
int validaAnoBissexto(int anoBissexto) {
  if (anoBissexto % 400 == 0 || anoBissexto % 4 == 0 && anoBissexto % 100 != 0) {
      return 1;
  }
  else {
    return 0;
  }
}

/// @brief Função para converter un char data[] "01/01/1970" em segundos
/// @param text do tipo char []
/// @return tipo tm da biblioteca time.h
time_t texto_para_tempo(char * text){
    struct tm tmp = {0};
    strptime(text,"%d/%m/%Y",&tmp);
    return mktime(&tmp);
}

/// @brief Função que converte segundos (long long time) em char "01/01/1970"
/// @param time do tipo time_t 
/// @param output do tipo char [] 
/// @param size do tipo int
void tempo_para_texto(time_t * time, char * output, int size){
    struct tm * tmp = localtime(time);
    strftime(output,size, "%d/%m/%Y", tmp);
}
