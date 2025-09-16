//
// Created by aluno on 16/09/2025.
//

#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

lista_linear_t *criar_lista_linear(int capacidade) {
    lista_linear_t *ll = malloc(sizeof(lista_linear_t));

    ll->elementos = malloc(capacidade * sizeof(int));
    ll->tamanho = 0;
    ll->capacidade = capacidade;

    return ll;
}

bool lista_linear_cheia(lista_linear_t *ll) {
    return ll->tamanho == ll->capacidade;
}

bool lista_linear_vazia(lista_linear_t *ll) {
    return ll->tamanho = 0;
}

void inserir_na_lista_linear(lista_linear_t *ll, int valor) {
    if (lista_linear_cheia(ll)) {
        exit(EXIT_FAILURE);
    }
    ll->elementos[ll->tamanho] = valor;
    ll->tamanho++;
}

int buscar_na_lista_linear(lista_linear_t *ll, int valor) {
    if (!lista_linear_vazia(ll)) {
        for (int index = 0; index < ll->tamanho; index++) {
            if (ll->elementos[index] == valor) {
                return index;
            }
        }
    }
    return -1;
}

//remover_na_lista_linear(lista_linear_t *ll, int valor){}

void destruir_lista_linear(lista_linear_t *ll) {
    free(ll->elementos);
    free(ll);
}