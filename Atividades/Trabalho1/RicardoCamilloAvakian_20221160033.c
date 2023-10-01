// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "RicardoCamilloAvakian_20221160033.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2) { // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	} else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
// Função auxiliar para validar se ano é o não bissexto (SIM = 1 // NAO = 0)
int validaAnoBissexto(int anoBissexto) {
  if ((anoBissexto % 400 == 0) || (anoBissexto % 4 == 0 && anoBissexto % 100 != 0)) {
    return 1;
  }
  else {
    // printf("Error nao passou do validaAnoBissexto linha 157\n");
    return 0;
  }
}

int q1(char data[]) {
  // int datavalida = 1;
  int i;
  // Strings para armazenar cada parte da data informada
  char strDia[3];
  char strMes[3];
  char strAno[5];
  
  //Verifica se a string tem o tamanho correto
  // if (strlen(data) != 6 || strlen(data) != 7 || strlen(data) != 8 || strlen(data) != 10){
  //   printf("Error nao passou do if de tamanho de strlen linha 171\n");
  //   return 0;
  // }

  // Verifica se a string contém apenas números e o char '/'   
  for (i = 0; i < strlen(data); i++) {
    if (data[i] == '/') {
      continue;
    }
    if (data[i] < '0' || data[i] > '9') {
      // printf("Error nao passou do for/if de verificacao de numeros apenas na linha 177\n");
      return 0;
    }
  }

  //quebrar a string data em strings strDia, strMes, strAno
  for (i = 0; data[i] != '/'; i++) {
    strDia[i] = data[i];
  }
  
  // testa o dia se esta com 1 ou 2 digitos, caso tenha apenas um digito acrescenta o '0' como primeiro digito
  if (i == 1) {
    strDia[1] = strDia[0];
    strDia[0] = '0';
    strDia[2] = '\0';
  } 
  else if (i == 2) {
    strDia[i] = '\0';
  }
  else {
    // printf("Error nao passou do if/else de teste dia com 1 ou 2 digitos linha 192\n");
    return 0;
  }

  int j = i + 1;
  i = 0;

  for (; data[j] != '/'; j++) {
    strMes[i] = data[j];
    i++;
  }

  // testa o mes se esta com 1 ou 2 digitos, caso tenha apenas um digito acrescenta o '0' como primeiro digito
  if (i == 1) {
    strMes[1] = strMes[0];
    strMes[0] = '0';
    strMes[2] = '\0';
  } 
  else if (i == 2) {
    strMes[i] = '\0';
  }
  else {
    // printf("Error nao passou do if/else de teste mes com 1 ou 2 digitos linha 214\n");
    return 0;
  }

  j = j + 1;
  i = 0;
  for (; data[j] != '\0'; j++) {
    strAno[i] = data[j];
    i++;
  }
  // testa o ano se esta com 2 ou 4 digitos e acrescenta o ano 2000 caso ano tenha sido informado com 2 digitos
  if (i == 2) {
    strAno[2] = strAno[0];
    strAno[3] = strAno[1];
    strAno[4] = '\0';
    strAno[0] = '2';
    strAno[1] = '0';
  } 
  else if (i == 4) {
    strAno[i] = '\0';
  } 
  else {
    // printf("Error nao passou do if/else de teste ano com 2 ou 4 digitos linha 234\n");
    return 0;
  }

  // Inicio da minha logica
  int dia, mes, ano;

  // Separa os campos da data 
  dia = (strDia[0] - '0') * 10 + (strDia[1] - '0');
  mes = (strMes[0] - '0') * 10 + (strMes[1] - '0');
  ano = (strAno[0] - '0') * 1000 + (strAno[1] - '0') * 100 +
        (strAno[2] - '0') * 10 + (strAno[3] - '0');

  // Verifica se o dia está no intervalo válido
  if (dia < 1 || dia > 31) {
    // printf("Error nao passou do if teste dia linha 258\n");
    return 0;
  }

  // Verifica se o mês está no intervalo válido
  if (mes < 1 || mes > 12) {
    // printf("Error nao passou do if teste mes linha 264\n");
    return 0;
  }


  // Verificar se quantidade de dias de um mes esta dentro do intervalo maximo para os meses de fevereiro, abril, junho, setembro e novembro em anos não bissextos
  if (!validaAnoBissexto(ano) && dia > 28) {
    switch (mes) {
    case 2:
      // printf("Error nao passou do if/swith validacao dia linha 274\n");
      return 0;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if (dia > 30) {
        // printf("Error nao passou do if/swith validacao dia linha 282\n");
        return 0;
      }
      break;
    default:
      break;
    }
  }
    else if (validaAnoBissexto(ano) && dia > 29) {
      switch (mes) {
      case 2:
        // printf("Error nao passou do if/swith validacao dia linha 292\n");
        return 0;
        break;
      case 4:
      case 6:
      case 9:
      case 11:
        if (dia > 30) {
          // printf("Error nao passou do if/swith validacao dia linha 300\n");
          return 0;
        }
        break;
      default:
        break;
      }
    }
    else {
      return 1;
    }
  // Se todos os testes forem aprovados, a data é válida
  return 1;
  // Termino da minha logica
}

// função auxiliar na Q2 para determinar quantos dias tem em um mes
int calcularDias(int mes, int ano) {
  switch (mes)
  {
  case 1: 
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
    break;
  case 2:
    if (validaAnoBissexto(ano)){
      return 29;
    }
    else {
      return 28;
    }
  default:
    return -1;
    break;
  }
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]) {

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0) {
      dma.retorno = 2;
      return dma;
    } 
    else if (q1(datafinal) == 0) {
      dma.retorno = 3;
      return dma;
    }
    else {
      // Instanciar dataquebrada para dataInicial e dataFinal
      DataQuebrada dqInicial = quebraData(datainicial);
      DataQuebrada dqFinal = quebraData(datafinal);
      //verifique se a data final não é menor que a data inicial
      if (dqInicial.iAno > dqFinal.iAno) {
        dma.retorno = 4;
        return dma;
      }
      else if (dqInicial.iAno == dqFinal.iAno && dqInicial.iMes > dqFinal.iMes) {
        dma.retorno = 4;
        return dma;
      }
      else if (dqInicial.iAno == dqFinal.iAno && dqInicial.iMes == dqFinal.iMes && dqInicial.iDia > dqFinal.iDia) {
        dma.retorno = 4;
        return dma;
      }
      else { // calcular a diferenca entre as datas
        // calcular numero de anos entre as datas
        //perguntar ao professor se posso colocar tudo em um if com o primeiro if envolto em parenteses 
        //e o else if tambem ambos separados por um ou ||
        printf("\nEntrou no esle para calcular a qtde de anos, meses e dias\n");
        dma.qtdAnos = dqFinal.iAno - dqInicial.iAno;
        if ((dqInicial.iMes > dqFinal.iMes) || (dqInicial.iMes == dqFinal.iMes && dqInicial.iDia > dqFinal.iDia)) {
          dma.qtdAnos -= 1;
        }

        // calcular a diferença de meses entre as datas e armazenar em dma.qtdMeses 
        // dma.qtdMeses = (dqFinal.iMes - 1) + (12 - datainicial.iMes - 1);
        if (dma.qtdAnos == 0 && dqInicial.iDia <= dqFinal.iDia) {
          dma.qtdMeses = dqFinal.iMes - dqInicial.iMes;
          dma.qtdDias = dqFinal.iDia - dqInicial.iDia;
        }
        else if (dma.qtdAnos == 0 && dqInicial.iDia > dqFinal.iDia) {
          dma.qtdMeses = dqFinal.iMes - dqInicial.iMes - 1;
          dma.qtdDias = calcularDias(dqInicial.iMes, dqInicial.iAno) - dqInicial.iDia + dqFinal.iDia;
        }
        else if (dma.qtdAnos >= 1 && dqInicial.iMes >= dqFinal.iMes && dqInicial.iDia > dqFinal.iDia) {
          dma.qtdMeses = (12 - dqInicial.iMes - 1) + (dqFinal.iMes - 1);
          dma.qtdDias = calcularDias(dqInicial.iMes, dqInicial.iAno) - dqInicial.iDia + dqFinal.iDia;        
        }
        else if (dma.qtdAnos >= 1 && dqInicial.iMes >= dqFinal.iMes && dqInicial.iDia <= dqFinal.iDia) {
          dma.qtdMeses = dqFinal.iMes + dqFinal.iMes;
          if (dqInicial.iMes == dqFinal.iMes) {
            dma.qtdMeses = 0;
          }
          dma.qtdDias = dqFinal.iDia - dqInicial.iDia;
        }
        else if (dma.qtdAnos >= 1 && dqInicial.iMes < dqFinal.iMes && dqInicial.iDia <= dqFinal.iDia) {
          dma.qtdMeses = dqFinal.iMes - dqInicial.iMes;
          dma.qtdDias = dqFinal.iDia - dqInicial.iDia;
        }
        else if (dma.qtdAnos >= 1 && dqInicial.iMes < dqFinal.iMes && dqInicial.iDia > dqFinal.iDia) {
          dma.qtdMeses = dqFinal.iMes - dqInicial.iMes - 1;
          dma.qtdDias = calcularDias(dqInicial.iMes, dqInicial.iAno) - dqInicial.iDia + dqFinal.iDia;        
        }

      }
      
      //calcule a distancia entre as datas


      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;
    

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}