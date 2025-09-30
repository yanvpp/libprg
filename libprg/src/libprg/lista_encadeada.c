#include <iso646.h>

#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void adicionar_na_lista_encadeada(no_t **inicio, int valor) {
    no_t *novo_no = criar_lista_encadeada(valor); // cria a lista encadeada (nó)
    novo_no->proximo = *inicio; // o novo nó passa a apontar para o elemento que já existia
    *inicio = novo_no; // e o início passa a apontar para o novo nó
}

void adicionar_na_lista_encadeada_circular(no_t **inicio, int valor) {
    no_t *novo_no = criar_lista_encadeada_circular(valor); // cria a lista encadeada circular (nó)
    novo_no->proximo = *inicio; // o novo nó passa a apontar para o elemento que já existia
    *inicio = novo_no; // e o início passa a apontar para o novo nó
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

    while (atual) { // enquanto tiver um atual
        if (atual->valor == valor) {
            // se o valor do atual for igual ao valor solicitado
            if (anterior) { // se tiver anterior
                anterior->proximo = atual->proximo; // o próximo do anterior será o próximo do atual
            } else { // se não tiver anterior
                *inicio = atual->proximo;
            }
            free(atual); // libera o local da memória do elemento removido ~~ remove o elemento
            break; // se achou, quebra o while
        }
        anterior = atual;
        atual = atual->proximo;
    }
}