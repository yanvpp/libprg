#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} no_t;

no_t *criar_lista_encadeada(int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL; // o último nó da lista sempre apontará para NULL

    return no;
}

no_t *criar_lista_encadeada_circular(int valor) {
    no_t *no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = no; // o último nó da lista sempre apontará para o primeiro elemento

    return no;
}

no_t *inicio_lista_encadeada(no_t **inicio)
{
    if (inicio) // se o início for diferente de NULL -- Se a lista não for vazia
    {
        return *inicio; // retorna o valor armazenado aonde o início está apontando
    }
    return NULL; // caso a lista esteja vazia, retorna NULL
}


void adicionar_na_lista_encadeada(no_t **inicio, int valor) {
    no_t *novo_no = criar_lista_encadeada(valor); // cria a lista encadeada (nó)
    novo_no->proximo = *inicio; // o novo nó passa a apontar para o elemento que já existia
    *inicio = novo_no; // e o início passa a apontar para o novo nó
}

void adicionar_na_lista_encadeada_circular(no_t **inicio, int valor) {
    no_t *novo_no = criar_lista_encadeada_circular(valor); // cria a lista encadeada circular (nó)
    novo_no->proximo = *inicio; // o novo nó passa a apontar para o elemento que já existia

    no_t *ultimo = *inicio;

    while (ultimo->proximo != *inicio){ // enquanto o próximo do último for diferente do & do primeiro
        ultimo = ultimo->proximo; // passa para o próximo
    }

    ultimo->proximo = novo_no; // o último passa a apontar para o elemento recém adcionado
    *inicio = novo_no; // e o início passa a ser o nó recém adicionado
}

no_t *buscar_na_lista_encadeada(no_t **inicio, int valor) {
    no_t *atual = *inicio;

    while (atual) {
        // enquanto o valor do atual for diferente de nulo - mesmo que while(atual!=NULL)
        if (atual->valor == valor) {
            // se o valor do atual for igual ao valor
            return atual; // retorna o endereço onde o valor está armazenado
        }
        atual = atual->proximo; // caso não entre no if, passa para o próximo elemento da lista
    }
    return NULL; // retorna que não encontrou o valor em nenhum endereço
}

void remover_da_lista_encadeada(no_t **inicio, int valor) {
    no_t *atual = *inicio;
    no_t *anterior = NULL;

    while (atual) { // enquanto o atual for diferente de NULL
        if (atual->valor == valor) {
            // se o valor do atual for igual ao valor solicitado
            if (anterior) { // se tiver anterior
                anterior->proximo = atual->proximo; // o próximo do anterior será o próximo do atual
            } else { // se não tiver anterior
                *inicio = atual->proximo; //o iníncio passa a ser o próximo do atual
            }
            free(atual); // libera o local da memória do elemento removido ~~ remove o elemento
            break; // se achou, quebra o while
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void destruir_lista_encadeada(no_t **inicio) {
    // no_t *atual = *inicio;
    // no_t *proximo = atual->proximo;
    //
    // while (proximo) { // enquanto o atual for diferente de nulo
    //     free(atual); // limpa o local onde o atual está apontando, não a variável "atual"
    //     atual = proximo; // o atual passa a ser o próximo
    //     proximo = atual->proximo; // o proximo passa a ser o próximo do atual
    // }
    // free (atual); // limpa o valor antes do NULL

    // da maneira que fiz em cima funciona também, mas abaixo está uma forma com menos linhas, mais eficiente

    no_t *atual = *inicio;

    while (atual) {
        no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

void destuir_lista_encadeada_circular(no_t **inicio) {
    no_t *atual = *inicio;

    while (atual) {
        no_t *proximo = atual->proximo;
        free(atual);
        if (proximo == *inicio) break; // se o próximo for o início, interrompe e encerra o código
        atual = proximo;
    }
}