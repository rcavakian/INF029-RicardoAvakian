#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data_nascimento.h"
#include "aluno.h"



/* Material 
 sobre struct https://www.inf.pucrs.br/~pinho/LaproI/Structs/Structs.htm#:~:text=Para%20passar%20uma%20struct%20por%20valor%20basta%20declar%C3%A1-la,%2F%2F%20Define%20o%20nome%20do%20novo%20tipo%20criado
*/

// void print_product(Product * product){
//     char * date = malloc(11 * sizeof(char));
//     time_2_text(&product->due_date, date, 11);
//     printf("Nome: %s # Preco: %.2f # Data Validade:%s\n",
//     product->name, product->price, date);
// }

// void print_all_products(Supermarket * sup, int qnt){
//     for(int i = 0; i < qnt; i = i + 1){
//         print_product(sup->products[i]);
//     }
// }

void imprimirAluno(Aluno aluno) {
    char * data = malloc(11 * sizeof(char));
    tempo_para_texto(&aluno.dataNascimento, data, 11);
    printf("Nome: %s // Matricula: %d // Sexo: %c // Data de nascimento: %s // CPF: %s\n", aluno.nome, aluno.matricula, aluno.sexo, data, aluno.cpf);
}

void imprimirListaAlunos(Aluno listaAlunos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        imprimirAluno(listaAlunos[i]); 
    }
}

