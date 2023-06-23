#include <stdio.h>

/*

Programa para calcular a serie de Fibonacci

*/


int main()
{
	int fibonacci;
	int seguinte = 1;
	int anterior = 1;

	printf("Digite um numero para calcular a sequencia Fibonacci: ");
	scanf("%d", &fibonacci);

	if (fibonacci == 1) {
		printf("0 ");
	}
	else if (fibonacci == 2) {
		printf("0 1");
	}
	else {
		printf("0 1 ");
		for (int i = 2; i < fibonacci; ++i) {
			int soma = anterior + seguinte;
			anterior = seguinte;
			seguinte = soma;
			printf("%d ", anterior);
		}
	}

	return 0;
}

