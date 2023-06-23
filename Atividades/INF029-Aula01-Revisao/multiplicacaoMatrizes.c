#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa no qual o usuário vai informar duas os valores de 
matrizes 3x2 e 2x3. Você deve apresentar uma terceira matriz que é o 
resultado da multiplicação das duas matrizes iniciais.
*/

int main() {

	int matrizA[3][2], matrizB[2][3], matrizC[3][3];
	int resultado = 0;

	printf("Por favor informe os valores da primeira matriz: \n");
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("Numero[%d][%d]: ", i, j);
			scanf("%d", &matrizA[i][j]);
		}
	}

	printf("\nPor favor informe os valores da segunda matriz: \n");
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Numero[%d][%d]: ", i, j);
			scanf("%d", &matrizB[i][j]);
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				resultado += matrizA[i][k] * matrizB[k][j];
			}
			matrizC[i][j] = resultado;
			resultado = 0;
		}
		
	}

	printf("\nResultados da multiplicacao: \n");	
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d\t", matrizC[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
