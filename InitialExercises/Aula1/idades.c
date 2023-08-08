#include <stdio.h>
#define TAM 10
// ler 10 idades e imprimir as idades que forem maios que a media de todas

int main(int argc, char const *argv[]) {
  
	int idades[TAM];
  float media, soma;

  soma = 0;

  for (int i = 0; i < TAM; i++) {
    printf("Digite a %da idade: ", i+1);
    scanf("%d", &idades[i]);
    soma += idades[i];
  }

  media = soma / TAM;

  printf("\nIdades informadas:\n");
  
  for (int i = 0; i < TAM; i++) {
    printf("%da idade : %d\n", i+1, idades[i]);
  }
  
  printf("\nMedia = %.1f\n", media);
  
  for (int i = 0; i < TAM; i++) {
    if (idades[i] > media) {
      printf("%da idade : %d\n", i+1, idades[i]);
    }
  } 

	return 0;
}