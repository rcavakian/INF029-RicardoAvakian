#include "cpf.h"
#include <string.h>
#define CPF_VALIDO 11
#define CPF_INVALIDO 10


/// @brief Função para validar CPF
/// @param cpf char []
/// @return 0 para CPF Valido e 1 para CPF Invalido
int validar_cpf(char cpf[])
{

    /*
    Converter os 11 caracteres em algarismos do tipo int e dividir em 2 grupos: 
    primeiro grupo com os 9 primeiros algarismos e o segundo com os 2 digitos
    */ 
    int cpf_numerico_grupo1[9];
    int cpf_numerico_grupo2[2];
    for (int i = 0; i < 11; i++) {
        if (i < 9) {
            cpf_numerico_grupo1[i] = cpf[i]  - '0';
        }
        else {
            cpf_numerico_grupo2[i-9] = cpf[i] - '0';
        }
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

    // Cacular primeiro digito (dezena) do CPF
    int resto = (soma % 11) ;
    if (resto < 2) {
        primeiro_digito = 0;
    } else {
        primeiro_digito = 11 - resto;
    }    
    /*
    Fazer o calculo do segundo digito utilizando modulo 
    Calcule o segundo dígito verificador usando o mesmo algoritmo "Módulo 11", 
    mas incluindo o primeiro dígito verificador calculado no passo anterior como 
    parte dos cálculos. 
    */
    int segundo_digito = 0;
    modulo = 11;
    soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (modulo * cpf_numerico_grupo1[i]);
        modulo--;
    }
    segundo_digito = 2 * primeiro_digito + soma;
    resto = (segundo_digito % 11);
    if (resto < 2) {
        segundo_digito = 0;
    } else {
        segundo_digito = 11 - resto;
    }

    if (primeiro_digito == cpf_numerico_grupo2[0] && segundo_digito == cpf_numerico_grupo2[1]) {
        return CPF_VALIDO;
    }
    else 
        return CPF_INVALIDO;

}