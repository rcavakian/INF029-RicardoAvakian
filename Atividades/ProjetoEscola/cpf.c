#include "cpf.h"
#include <string.h>
#define CPF_VALIDO 0
#define CPF_INVALIDO 1


/// @brief Função para validar CPF
/// @param cpf char []
/// @return 0 para CPF Valido e 1 para CPF Invalido
int validar_cpf(char cpf[])
{
    // Verificar se a informacao digitado tem 11 caracteres
    if (strlen(cpf) < 11) {
        return CPF_INVALIDO;
    }

    /*
    Converter os 11 caracteres em algarismos do tipo int e dividir em 2 grupos: 
    primeiro grupo com os 9 primeiros algarismos e o segundo com os 2 digitos
    */ 
    int cpf_numerico_grupo1[12];
    int cpf_numerico_grupo2[12];
    for (int i = 0; i < 12; i++) {
        if (i < 9) {
            cpf_numerico_grupo1[i] = cpf[i] - '0';
        }
        else
            cpf_numerico_grupo2[i] = cpf[i] - '0';
    }

    /*
    Fazer o calculo do primeiro digito utilizando modulo 11 
    Calcule o primeiro dígito verificador usando o algoritmo conhecido como "Módulo 11":
    1. Multiplique cada dígito do primeiro grupo pela sequência de pesos decrescentes: 
    10, 9, 8, ..., 2.
    2. Some os resultados das multiplicações.
    3. O resultado da soma deve ser dividido por 11.
    4. O dígito verificador será 11 subtraído do resto da divisão. Se o resultado for 
    maior que 9, o dígito verificador será 0.
    */ 
    int soma = 0;
    int modulo = 10;
    int primeiro_digito = 0;
    for (int i = 0; i < 9; i++) {
        soma += (modulo * cpf_numerico_grupo1[i]);
        modulo--;
    }

    primeiro_digito = (soma % 11) - 11;
    if (primeiro_digito > 9) {
        primeiro_digito = 0;
    }

    /*
    Fazer o calculo do segundo digito utilizando modulo 
    Calcule o segundo dígito verificador usando o mesmo algoritmo "Módulo 11", 
    mas incluindo o primeiro dígito verificador calculado no passo anterior como 
    parte dos cálculos. 
    */
    int segundo_digito = 0;
    segundo_digito = (soma + primeiro_digito) % 11 - 11;
    if (segundo_digito > 9) {
        segundo_digito = 0;
    }

    if (primeiro_digito == cpf_numerico_grupo2[0] && segundo_digito == cpf_numerico_grupo2[1]) {
        return CPF_VALIDO;
    }
    else 
        return CPF_INVALIDO;

}