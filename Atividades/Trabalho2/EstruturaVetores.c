#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "EstruturaVetores.h"
#define TAM 10



estruturaAux vetorPrincipal[TAM];
void ordenarVetor(int *vetor, int tamanho);

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
    int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    if (vetorPrincipal[posicao - 1].ponteiroEstrutura != NULL) {
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    // se posição é um valor válido {entre 1 e 10}
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    // o tamanho nao pode ser menor que 1
    if (tamanho < 1) {
        retorno = TAMANHO_INVALIDO;
        return retorno;
    }
    // deu tudo certo, crie
    else {
        // criando estrutura auxiliar no tamanho informado e alocando memoria para a estrutura auxiliar de inteiros
        int *vetorInteiros = malloc(tamanho * sizeof(int));
        // o tamanho ser muito grande
        if (!vetorInteiros) {
            retorno = SEM_ESPACO_DE_MEMORIA;
            return retorno;
        } else {
            // atribuindo a variavel da struct o tamanho da estrutura auxliar
            vetorPrincipal[posicao - 1].tamanho = tamanho;
            // alocando memoria para o pontei        // apontando o ponteiro para a estrutura auxiliar
            vetorPrincipal[posicao - 1].ponteiroEstrutura = vetorInteiros;
            retorno = SUCESSO;
            return retorno;
        }
    }
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    // teste para saber se a posicao inserida esta entre 1 e 10
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno; 
    }
    else {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao - 1].ponteiroEstrutura != NULL) {
            if (vetorPrincipal[posicao - 1].tamanho > vetorPrincipal[posicao -1].quantidade) {
                //insere
                int indice = vetorPrincipal[posicao - 1].quantidade;
                vetorPrincipal[posicao - 1].ponteiroEstrutura[indice] = valor;
                vetorPrincipal[posicao - 1].quantidade++; 
                retorno = SUCESSO;
                return retorno;
            }
            else {
                retorno = SEM_ESPACO;
                return retorno;
            }
        }
        else {
            retorno = SEM_ESTRUTURA_AUXILIAR;
            return retorno;
        }
    }
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso ok
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia ok
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar ok
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar ok
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
    int retorno = 0;
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if (vetorPrincipal[posicao - 1].ponteiroEstrutura == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    else if (vetorPrincipal[posicao - 1].quantidade == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }
    else {
        vetorPrincipal[posicao - 1].quantidade--;
        retorno = SUCESSO;
        return retorno;
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    int retorno = 0;
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if (vetorPrincipal[posicao - 1].ponteiroEstrutura == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    else if (vetorPrincipal[posicao - 1].quantidade == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }
    else {
        int valorLocalizado = 0;
        int indice = vetorPrincipal[posicao - 1].quantidade;
        for (int i = 0; i < indice; i++) {
            if (vetorPrincipal[posicao - 1].ponteiroEstrutura[i] == valor) {
                valorLocalizado = 1;
                // loop para poder deslocar os itens uma posicao a frente para preencher a posicao do valor excluido 
                for (int j = i; j < indice - 1; j++) {
                    vetorPrincipal[posicao - 1].ponteiroEstrutura[j] = vetorPrincipal[posicao - 1].ponteiroEstrutura[j + 1];
                }
                vetorPrincipal[posicao - 1].quantidade--;
                break;
            }
        }
        if (valorLocalizado) {
            retorno = SUCESSO;
            return retorno;
        }
        else {
            retorno = NUMERO_INEXISTENTE;
            return retorno;
        }
    }
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int retorno = 0;
    int indice = posicao - 1;
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if (vetorPrincipal[indice].ponteiroEstrutura == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    else {
        for (int i = 0; i < vetorPrincipal[indice].quantidade; i++) {
            vetorAux[i] = vetorPrincipal[indice].ponteiroEstrutura[i];
        }
        retorno = SUCESSO;
        return retorno;
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int retorno = 0;
    int indice = posicao - 1;
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if (vetorPrincipal[indice].ponteiroEstrutura == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    else {
        for (int i = 0; i < vetorPrincipal[indice].quantidade; i++) {
            vetorAux[i] = vetorPrincipal[indice].ponteiroEstrutura[i];
        }
        ordenarVetor(vetorAux, vetorPrincipal[indice].quantidade);
        retorno = SUCESSO;
        return retorno;
    }
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int retorno = 0;
    int vazias = 0;
    int k = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].quantidade == 0) {
            vazias++;
        }
        else {
            for (int j = 0; j < vetorPrincipal[i].quantidade; j++) {
                vetorAux[k] = vetorPrincipal[i].ponteiroEstrutura[j];
                k++;
            }
        }
    }
    if (vazias == TAM) {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        return retorno;
    }
    else {
        retorno = SUCESSO;
        return retorno;
    }
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int retorno = 0;
    int vazias = 0;
    int j = 0;
    int k = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].quantidade == 0) {
            vazias++;
        }
        else {
            for (j = 0; j < vetorPrincipal[i].quantidade; j++) {
                vetorAux[k] = vetorPrincipal[i].ponteiroEstrutura[j];
                k++;
            }
        }
    }
    if (vazias == TAM) {
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
        return retorno;
    }
    else {
        ordenarVetor(vetorAux, k);
        retorno = SUCESSO;
        return retorno;
    }
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar ok
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar ok
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo ok
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    int retorno = 0;
    int indice = posicao - 1;
    int novoTam = vetorPrincipal[indice].tamanho + novoTamanho;
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if (vetorPrincipal[indice].ponteiroEstrutura == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    else if (novoTam <= 0) {
        retorno = NOVO_TAMANHO_INVALIDO;
        return retorno;
    }
    else {
        vetorPrincipal[indice].ponteiroEstrutura = (int *)realloc(vetorPrincipal[indice].ponteiroEstrutura, novoTam * sizeof(int));
        if (vetorPrincipal[indice].ponteiroEstrutura == NULL) {
            retorno = SEM_ESPACO_DE_MEMORIA;
            // free(vetorPrincipal[indice].ponteiroEstrutura);
            return retorno;
        }
        else {
            vetorPrincipal[indice].tamanho = novoTam;
            if (vetorPrincipal[indice].tamanho < vetorPrincipal[indice].quantidade) {
                vetorPrincipal[indice].quantidade = novoTam;
            }
            retorno = SUCESSO;
            return retorno;
        }
    }
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    int retorno = 0;
    int indice = posicao - 1;
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    else if (vetorPrincipal[indice].ponteiroEstrutura == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    } 
    else if (vetorPrincipal[indice].quantidade == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }
    else {
        retorno = vetorPrincipal[indice].quantidade;
        return retorno;
    }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() {
    int vazia = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].quantidade == 0) {
            vazia++;
        }
    }
    if (vazia == TAM) {
        return NULL;
    }
    else {
        int k = 0;
        No *cabecote = malloc(sizeof(No));
        if (cabecote == NULL) {
            return NULL;
        }
        cabecote->prox = NULL;
        for (int i = 0; i < TAM; i++) {
            // if incluido para testar
            if (vetorPrincipal[i].ponteiroEstrutura == NULL) {
                continue;
            }
            for (int j = 0; j < vetorPrincipal[i].quantidade; j++) {
                inserirNodo(cabecote, vetorPrincipal[i].ponteiroEstrutura[j]);
            }
        }
        return cabecote;
    }
    
}
/*
Funções auxiliares para criar e encher a lista encadeada
*/
No *criarNodo(int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        return NULL;
    }
    novo->conteudo = valor;
    novo->prox = NULL;
    return novo;
}
void inserirNodo(No *cabecote, int valor) {
    No *atual;
    No *novo = criarNodo(valor);
    if (cabecote->prox == NULL) {
        cabecote->prox = novo;
        novo->prox = NULL;
    }
    else {
        atual = cabecote;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}
/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    if (inicio == NULL) {
        return;
    }
    No *atual = inicio->prox;
    int i = 0;
    while (atual != NULL) {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {
    while(*inicio != NULL) {
        No *temporario = *inicio;
        *inicio = (*inicio)->prox;
        free(temporario);
    }
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

// função para imprimir o vetor auxiliar depois de inserido todos elementos
void imprimirVetorAux(int posicao) {
    printf("Printf p/ saber se a função testeInserirComEstrutura() esta funcionando\n");
    printf("Elementos da estrutura auxiliar da posicao %d:\n", posicao);
    for (int i = 0; i < vetorPrincipal[posicao-1].quantidade; i++) {
        printf("%d\t", vetorPrincipal[posicao-1].ponteiroEstrutura[i]);
    }
    printf("\n");
}

void ordenarVetor(int *vetor, int tamanho) {
    int aux, i, j;
    for (i = 1; i < tamanho; i++) {
        aux = vetor[i];
        for (j = i - 1; j >= 0 && vetor[j] > aux; j--) {
            vetor[j + 1] = vetor[j];
        }   
        vetor[j + 1] = aux;
    }
}

void inicializar()
{
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].quantidade = 0;
        vetorPrincipal[i].ponteiroEstrutura = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].ponteiroEstrutura != NULL) {
            free(vetorPrincipal[i].ponteiroEstrutura);
            vetorPrincipal[i].ponteiroEstrutura = NULL;
        } 
    }
}